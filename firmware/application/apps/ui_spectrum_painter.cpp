/*
 * Copyright (C) 2023 Bernd Herzog
 *
 * This file is part of PortaPack.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#include "ui_spectrum_painter.hpp"
#include "cpld_update.hpp"
#include "bmp.hpp"
#include "baseband_api.hpp"

#include "ui_fileman.hpp"
#include "io_file.hpp"
#include "file.hpp"
#include "portapack_persistent_memory.hpp"

namespace ui {

SpectrumPainterView::SpectrumPainterView(
    NavigationView& nav)
    : nav_(nav) {
    baseband::run_image(portapack::spi_flash::image_tag_spectrum_painter);

    add_children({
        &labels,
        &tab_view,
        &input_image,
        &input_text,
        &progressbar,
        &field_frequency,
        &field_rfgain,
        &field_rfamp,
        &check_loop,
        &button_play,
        &option_bandwidth,
        &field_duration,
        &field_pause,
    });

    Rect view_rect = {0, 3 * 8, 240, 80};
    input_image.set_parent_rect(view_rect);
    input_text.set_parent_rect(view_rect);

    field_frequency.set_value(target_frequency());
    field_frequency.set_step(5000);
    field_frequency.on_change = [this](rf::Frequency f) {
        this->on_target_frequency_changed(f);
    };
    field_frequency.on_edit = [this, &nav]() {
        auto new_view = nav.push<FrequencyKeypadView>(this->target_frequency());
        new_view->on_changed = [this](rf::Frequency f) {
            this->on_target_frequency_changed(f);
            this->field_frequency.set_value(f);
        };
    };

    tx_gain = 10;
    field_rfgain.set_value(tx_gain);              // Initial default  value (-12 dB's max ).
    field_rfgain.on_change = [this](int32_t v) {  // allow initial value change just after opened file.
        tx_gain = v;
        portapack::transmitter_model.set_tx_gain(tx_gain);
    };

    field_rfamp.set_value(rf_amp ? 14 : 0);      // Initial default value True. (TX RF amp on , +14dB's)
    field_rfamp.on_change = [this](int32_t v) {  // allow initial value change just after opened file.
        rf_amp = (bool)v;
        portapack::transmitter_model.set_rf_amp(rf_amp);
    };

    input_image.on_input_avaliable = [this]() {
        image_input_avaliable = true;
    };

    button_play.on_select = [this](ImageButton&) {
        if (tx_active == false) {
            tx_mode = tab_view.selected();

            if (tx_mode == 0 && image_input_avaliable == false)
                return;

            // Enable Bias Tee if selected
            radio::set_antenna_bias(portapack::get_antenna_bias());

            radio::enable({portapack::receiver_model.tuning_frequency(),
                           3072000U,
                           1750000,
                           rf::Direction::Transmit,
                           rf_amp,
                           static_cast<int8_t>(portapack::receiver_model.lna()),
                           static_cast<int8_t>(portapack::receiver_model.vga())});

            if (portapack::persistent_memory::stealth_mode()) {
                DisplaySleepMessage message;
                EventDispatcher::send_message(message);
            }

            button_play.set_bitmap(&bitmap_stop);

            if (tx_mode == 0) {
                tx_current_max_lines = input_image.get_height();
                tx_current_width = input_image.get_width();
            } else {
                tx_current_max_lines = input_text.get_height();
                tx_current_width = input_text.get_width();
            }

            progressbar.set_max(tx_current_max_lines);
            progressbar.set_value(0);

            baseband::set_spectrum_painter_config(tx_current_width, tx_current_max_lines, false, option_bandwidth.selected_index_value());
        } else {
            stop_tx();
        }
    };

    option_bandwidth.on_change = [this](size_t, ui::OptionsField::value_t value) {
        baseband::set_spectrum_painter_config(tx_current_width, tx_current_max_lines, true, value);
    };

    field_duration.set_value(10);
    field_pause.set_value(5);
}

void SpectrumPainterView::start_tx() {
    tx_current_line = 0;
    tx_active = true;
    tx_timestamp_start = chTimeNow();
}

void SpectrumPainterView::stop_tx() {
    button_play.set_bitmap(&bitmap_play);
    portapack::transmitter_model.disable();
    tx_active = false;
    tx_current_line = 0;
}

void SpectrumPainterView::frame_sync() {
    if (tx_active) {
        if (fifo->is_empty()) {
            int32_t sequence_duration = (field_duration.value() + (check_loop.value() ? field_pause.value() : 0)) * 1000;
            int32_t sequence_time = tx_time_elapsed() % sequence_duration;
            bool is_pausing = sequence_time > field_duration.value() * 1000;

            if (is_pausing) {
                fifo->in(std::vector<uint8_t>(tx_current_width));
            } else {
                auto current_time_line = sequence_time * tx_current_max_lines / (field_duration.value() * 1000);

                if (tx_current_line > current_time_line && !check_loop.value()) {
                    fifo->in(std::vector<uint8_t>(tx_current_width));
                    stop_tx();
                    return;
                }

                tx_current_line = current_time_line;
                progressbar.set_value(current_time_line);

                if (tx_mode == 0) {
                    std::vector<uint8_t> line = input_image.get_line(current_time_line);
                    fifo->in(line);
                } else {
                    std::vector<uint8_t> line = input_text.get_line(current_time_line);
                    fifo->in(line);
                }
            }
        }
    }
}

SpectrumPainterView::~SpectrumPainterView() {
    portapack::transmitter_model.disable();
    hackrf::cpld::load_sram_no_verify();
    baseband::shutdown();
}

void SpectrumPainterView::focus() {
    tab_view.focus();
}

void SpectrumPainterView::on_target_frequency_changed(rf::Frequency f) {
    set_target_frequency(f);
}

void SpectrumPainterView::set_target_frequency(const rf::Frequency new_value) {
    portapack::persistent_memory::set_tuned_frequency(new_value);
}

rf::Frequency SpectrumPainterView::target_frequency() const {
    return portapack::persistent_memory::tuned_frequency();
}

void SpectrumPainterView::paint(Painter& painter) {
    View::paint(painter);

    size_t c;
    Point pos = {0, screen_pos().y() + 8 + footer_location};

    for (c = 0; c < 20; c++) {
        painter.draw_bitmap(
            pos,
            bitmap_stripes,
            ui::Color(191, 191, 0),
            ui::Color::black());
        if (c != 9)
            pos += {24, 0};
        else
            pos = {0, screen_pos().y() + 8 + footer_location + 32 + 8};
    }
}

}  // namespace ui

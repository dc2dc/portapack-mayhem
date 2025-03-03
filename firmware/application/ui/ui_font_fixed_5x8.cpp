/*
 * Copyright (C) 2023 Kyle Reed
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

#include "ui_font_fixed_5x8.hpp"

#include <cstdint>

namespace ui {
namespace font {

namespace {

const uint8_t fixed_5x8_glyph_data[] = {

    // Index: 0 (0x00)  Char: 0x0020 (' ')
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    // Index: 1 (0x01)  Char: 0x0021 ('!')
    0x80,
    0x10,
    0x42,
    0x00,
    0x01,

    // Index: 2 (0x02)  Char: 0x0022 ('"')
    0x40,
    0x29,
    0x00,
    0x00,
    0x00,

    // Index: 3 (0x03)  Char: 0x0023 ('#')
    0x00,
    0xA8,
    0xA7,
    0x9E,
    0x02,

    // Index: 4 (0x04)  Char: 0x0024 ('$')
    0x80,
    0x38,
    0x83,
    0x1C,
    0x01,

    // Index: 5 (0x05)  Char: 0x0025 ('%')
    0x00,
    0x80,
    0x44,
    0x44,
    0x02,

    // Index: 6 (0x06)  Char: 0x0026 ('&')
    0x40,
    0x94,
    0xA1,
    0xCA,
    0x02,

    // Index: 7 (0x07)  Char: 0x0027 (''')
    0x80,
    0x10,
    0x00,
    0x00,
    0x00,

    // Index: 8 (0x08)  Char: 0x0028 ('(')
    0x80,
    0x08,
    0x21,
    0x04,
    0x01,

    // Index: 9 (0x09)  Char: 0x0029 (')')
    0x40,
    0x10,
    0x42,
    0x88,
    0x00,

    // Index: 10 (0x0A)  Char: 0x002A ('*')
    0x00,
    0x28,
    0xE2,
    0x88,
    0x02,

    // Index: 11 (0x0B)  Char: 0x002B ('+')
    0x00,
    0x00,
    0xE2,
    0x08,
    0x00,

    // Index: 12 (0x0C)  Char: 0x002C (',')
    0x00,
    0x00,
    0x00,
    0x88,
    0x00,

    // Index: 13 (0x0D)  Char: 0x002D ('-')
    0x00,
    0x00,
    0xE0,
    0x00,
    0x00,

    // Index: 14 (0x0E)  Char: 0x002E ('.')
    0x00,
    0x00,
    0x00,
    0x80,
    0x00,

    // Index: 15 (0x0F)  Char: 0x002F ('/')
    0x00,
    0x21,
    0x42,
    0x84,
    0x00,

    // Index: 16 (0x10)  Char: 0x0030 ('0')
    0xC0,
    0xA4,
    0xB6,
    0x92,
    0x01,

    // Index: 17 (0x11)  Char: 0x0031 ('1')
    0x80,
    0x18,
    0x42,
    0x88,
    0x03,

    // Index: 18 (0x12)  Char: 0x0032 ('2')
    0xC0,
    0x24,
    0x64,
    0xC2,
    0x03,

    // Index: 19 (0x13)  Char: 0x0033 ('3')
    0xC0,
    0x24,
    0x82,
    0x92,
    0x01,

    // Index: 20 (0x14)  Char: 0x0034 ('4')
    0x00,
    0x31,
    0x95,
    0x1E,
    0x02,

    // Index: 21 (0x15)  Char: 0x0035 ('5')
    0xE0,
    0x85,
    0x83,
    0x92,
    0x01,

    // Index: 22 (0x16)  Char: 0x0036 ('6')
    0xC0,
    0x84,
    0x93,
    0x92,
    0x01,

    // Index: 23 (0x17)  Char: 0x0037 ('7')
    0xE0,
    0x21,
    0x44,
    0x84,
    0x00,

    // Index: 24 (0x18)  Char: 0x0038 ('8')
    0xC0,
    0x24,
    0x93,
    0x92,
    0x01,

    // Index: 25 (0x19)  Char: 0x0039 ('9')
    0xC0,
    0xA4,
    0xE4,
    0x90,
    0x01,

    // Index: 26 (0x1A)  Char: 0x003A (':')
    0x00,
    0x00,
    0x01,
    0x04,
    0x00,

    // Index: 27 (0x1B)  Char: 0x003B (';')
    0x00,
    0x00,
    0x02,
    0x88,
    0x00,

    // Index: 28 (0x1C)  Char: 0x003C ('<')
    0x00,
    0x10,
    0x11,
    0x04,
    0x01,

    // Index: 29 (0x1D)  Char: 0x003D ('=')
    0x00,
    0x00,
    0x07,
    0x1C,
    0x00,

    // Index: 30 (0x1E)  Char: 0x003E ('>')
    0x00,
    0x08,
    0x82,
    0x88,
    0x00,

    // Index: 31 (0x1F)  Char: 0x003F ('?')
    0x80,
    0x28,
    0x44,
    0x00,
    0x01,

    // Index: 32 (0x20)  Char: 0x0040 ('@')
    0xC0,
    0xA4,
    0xD6,
    0x82,
    0x01,

    // Index: 33 (0x21)  Char: 0x0041 ('A')
    0xC0,
    0xA4,
    0xF4,
    0x52,
    0x02,

    // Index: 34 (0x22)  Char: 0x0042 ('B')
    0xE0,
    0xA4,
    0x93,
    0xD2,
    0x01,

    // Index: 35 (0x23)  Char: 0x0043 ('C')
    0xC0,
    0xA4,
    0x10,
    0x92,
    0x01,

    // Index: 36 (0x24)  Char: 0x0044 ('D')
    0xE0,
    0xA4,
    0x94,
    0xD2,
    0x01,

    // Index: 37 (0x25)  Char: 0x0045 ('E')
    0xE0,
    0x85,
    0x13,
    0xC2,
    0x03,

    // Index: 38 (0x26)  Char: 0x0046 ('F')
    0xE0,
    0x85,
    0x13,
    0x42,
    0x00,

    // Index: 39 (0x27)  Char: 0x0047 ('G')
    0xC0,
    0xA4,
    0xD0,
    0x92,
    0x01,

    // Index: 40 (0x28)  Char: 0x0048 ('H')
    0x20,
    0xA5,
    0x97,
    0x52,
    0x02,

    // Index: 41 (0x29)  Char: 0x0049 ('I')
    0xC0,
    0x11,
    0x42,
    0x88,
    0x03,

    // Index: 42 (0x2A)  Char: 0x004A ('J')
    0xC0,
    0x21,
    0x84,
    0x92,
    0x01,

    // Index: 43 (0x2B)  Char: 0x004B ('K')
    0x20,
    0x95,
    0x51,
    0x52,
    0x02,

    // Index: 44 (0x2C)  Char: 0x004C ('L')
    0x20,
    0x84,
    0x10,
    0xC2,
    0x01,

    // Index: 45 (0x2D)  Char: 0x004D ('M')
    0xA0,
    0xBD,
    0x95,
    0x52,
    0x02,

    // Index: 46 (0x2E)  Char: 0x004E ('N')
    0x20,
    0xA5,
    0xD5,
    0x52,
    0x02,

    // Index: 47 (0x2F)  Char: 0x004F ('O')
    0xC0,
    0xA4,
    0x94,
    0x92,
    0x01,

    // Index: 48 (0x30)  Char: 0x0050 ('P')
    0xE0,
    0xA4,
    0x74,
    0x42,
    0x00,

    // Index: 49 (0x31)  Char: 0x0051 ('Q')
    0xC0,
    0xA4,
    0x94,
    0x8A,
    0x02,

    // Index: 50 (0x32)  Char: 0x0052 ('R')
    0xE0,
    0xA4,
    0x74,
    0x52,
    0x02,

    // Index: 51 (0x33)  Char: 0x0053 ('S')
    0xC0,
    0x24,
    0x41,
    0x92,
    0x01,

    // Index: 52 (0x34)  Char: 0x0054 ('T')
    0xC0,
    0x11,
    0x42,
    0x08,
    0x01,

    // Index: 53 (0x35)  Char: 0x0055 ('U')
    0x20,
    0xA5,
    0x94,
    0x92,
    0x03,

    // Index: 54 (0x36)  Char: 0x0056 ('V')
    0x20,
    0xA5,
    0x94,
    0x8A,
    0x00,

    // Index: 55 (0x37)  Char: 0x0057 ('W')
    0x20,
    0xA5,
    0xB4,
    0x5E,
    0x01,

    // Index: 56 (0x38)  Char: 0x0058 ('X')
    0x20,
    0x25,
    0x63,
    0x52,
    0x02,

    // Index: 57 (0x39)  Char: 0x0059 ('Y')
    0x20,
    0xA5,
    0x64,
    0x08,
    0x01,

    // Index: 58 (0x3A)  Char: 0x005A ('Z')
    0xE0,
    0x21,
    0x22,
    0xC2,
    0x03,

    // Index: 59 (0x3B)  Char: 0x005B ('[')
    0xC0,
    0x08,
    0x21,
    0x84,
    0x01,

    // Index: 60 (0x3C)  Char: 0x005C ('\')
    0x40,
    0x08,
    0x42,
    0x10,
    0x02,

    // Index: 61 (0x3D)  Char: 0x005D (']')
    0xC0,
    0x10,
    0x42,
    0x88,
    0x01,

    // Index: 62 (0x3E)  Char: 0x005E ('^')
    0x00,
    0x10,
    0x05,
    0x00,
    0x00,

    // Index: 63 (0x3F)  Char: 0x005F ('_')
    0x00,
    0x00,
    0x00,
    0xC0,
    0x03,

    // Index: 64 (0x40)  Char: 0x0060 ('`')
    0x40,
    0x10,
    0x00,
    0x00,
    0x00,

    // Index: 65 (0x41)  Char: 0x0061 ('a')
    0x00,
    0x00,
    0x83,
    0x9E,
    0x03,

    // Index: 66 (0x42)  Char: 0x0062 ('b')
    0x20,
    0x84,
    0x93,
    0x92,
    0x01,

    // Index: 67 (0x43)  Char: 0x0063 ('c')
    0x00,
    0x00,
    0x17,
    0x82,
    0x03,

    // Index: 68 (0x44)  Char: 0x0064 ('d')
    0x00,
    0x21,
    0x97,
    0x92,
    0x01,

    // Index: 69 (0x45)  Char: 0x0065 ('e')
    0x00,
    0x00,
    0xF3,
    0x82,
    0x01,

    // Index: 70 (0x46)  Char: 0x0066 ('f')
    0x80,
    0x89,
    0x23,
    0x84,
    0x00,

    // Index: 71 (0x47)  Char: 0x0067 ('g')
    0x00,
    0x98,
    0xE4,
    0x90,
    0x01,

    // Index: 72 (0x48)  Char: 0x0068 ('h')
    0x20,
    0x84,
    0x93,
    0x52,
    0x02,

    // Index: 73 (0x49)  Char: 0x0069 ('i')
    0x80,
    0x00,
    0x43,
    0x08,
    0x02,

    // Index: 74 (0x4A)  Char: 0x006A ('j')
    0x00,
    0x01,
    0x86,
    0x90,
    0x01,

    // Index: 75 (0x4B)  Char: 0x006B ('k')
    0x40,
    0x08,
    0x65,
    0x94,
    0x02,

    // Index: 76 (0x4C)  Char: 0x006C ('l')
    0xC0,
    0x10,
    0x42,
    0x08,
    0x02,

    // Index: 77 (0x4D)  Char: 0x006D ('m')
    0x00,
    0x80,
    0xF6,
    0x56,
    0x02,

    // Index: 78 (0x4E)  Char: 0x006E ('n')
    0x00,
    0x80,
    0x93,
    0x52,
    0x02,

    // Index: 79 (0x4F)  Char: 0x006F ('o')
    0x00,
    0x00,
    0x93,
    0x92,
    0x01,

    // Index: 80 (0x50)  Char: 0x0070 ('p')
    0x00,
    0x98,
    0x74,
    0x42,
    0x00,

    // Index: 81 (0x51)  Char: 0x0071 ('q')
    0x00,
    0x98,
    0xE4,
    0x10,
    0x02,

    // Index: 82 (0x52)  Char: 0x0072 ('r')
    0x00,
    0x00,
    0x65,
    0x84,
    0x00,

    // Index: 83 (0x53)  Char: 0x0073 ('s')
    0x00,
    0x00,
    0x66,
    0x90,
    0x03,

    // Index: 84 (0x54)  Char: 0x0074 ('t')
    0x80,
    0x10,
    0x47,
    0x08,
    0x02,

    // Index: 85 (0x55)  Char: 0x0075 ('u')
    0x00,
    0x80,
    0x94,
    0x92,
    0x03,

    // Index: 86 (0x56)  Char: 0x0076 ('v')
    0x00,
    0x80,
    0x94,
    0x8A,
    0x00,

    // Index: 87 (0x57)  Char: 0x0077 ('w')
    0x00,
    0x80,
    0xB4,
    0x5E,
    0x01,

    // Index: 88 (0x58)  Char: 0x0078 ('x')
    0x00,
    0x00,
    0x45,
    0x88,
    0x02,

    // Index: 89 (0x59)  Char: 0x0079 ('y')
    0x00,
    0x00,
    0xE5,
    0x90,
    0x01,

    // Index: 90 (0x5A)  Char: 0x007A ('z')
    0x00,
    0x00,
    0xC7,
    0x84,
    0x03,

    // Index: 91 (0x5B)  Char: 0x007B ('{')
    0x80,
    0x11,
    0x41,
    0x08,
    0x03,

    // Index: 92 (0x5C)  Char: 0x007C ('|')
    0x80,
    0x10,
    0x42,
    0x08,
    0x01,

    // Index: 93 (0x5D)  Char: 0x007D ('}')
    0xC0,
    0x10,
    0x44,
    0x88,
    0x01,

    // Index: 94 (0x5E)  Char: 0x007E ('~')
    0x00,
    0x00,
    0x55,
    0x00,
    0x00,

};

}

const ui::Font fixed_5x8{
    5,
    8,
    fixed_5x8_glyph_data,
    0x20,
    95,
};

} /* namespace font */
} /* namespace ui */

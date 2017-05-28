/* 
 * 8-high FONT FOR RENDERING TO THE LED SCREEN.
 * 8 pixels-per-byte, variable width.
 *
 * By Gaurav Manek, 2014.
 * Based loosely on the font by Louis Roy, based on 7x5 by David Soyez, 2013
 */

#ifndef __FONT8X5_H
#define __FONT8X5_H

#define FONT_8X5_HEIGHT  8

const byte FONT_8X5 [] PROGMEM = {
  0b00000000,                                                   // SPACE
  0b01110000, 0b11111101, 0b01110000,                           // !
  0b11000000, 0b00000000, 0b11000000,                           // "
  0b00100100, 0b11111111, 0b00100100, 0b11111111, 0b00100100,   // #
  0b00100100, 0b01010010, 0b11011011, 0b01001010, 0b00100100,   // $
  0b11000001, 0b11000110, 0b00011000, 0b01100011, 0b10000011,   // %
  0b01101110, 0b10010001, 0b10010010, 0b01100101,               // &
  0b11000000,                                                   // '
  0b00111100, 0b01000010, 0b10000001,                           // (
  0b10000001, 0b01000010, 0b00111100,                           // )
  0b10100000, 0b01000000, 0b10100000,                           // *
  0b00001000, 0b00001000, 0b00111110, 0b00001000, 0b00001000,   // +
  0b00000001, 0b00000010,                                       // ,
  0b00001000, 0b00001000, 0b00001000,                           // -
  0b00000001,                                                   // .
  0b00000011, 0b00001100, 0b00110000, 0b11000000,               // /
  0b01111110, 0b10000001, 0b10000001, 0b10000001, 0b01111110,   // 0
  0b00100001, 0b01000001, 0b11111111, 0b00000001, 0b00000001,   // 1
  0b01000011, 0b10000101, 0b10001001, 0b10010001, 0b01100001,   // 2
  0b01000010, 0b10000001, 0b10010001, 0b10010001, 0b01101110,   // 3
  0b00011000, 0b00101000, 0b01001000, 0b11111111, 0b00001000,   // 4
  0b11110010, 0b10010001, 0b10010001, 0b10010001, 0b10001110,   // 5
  0b01111110, 0b10010001, 0b10010001, 0b10010001, 0b01001110,   // 6
  0b10000000, 0b10000111, 0b10001000, 0b10010000, 0b11100000,   // 7
  0b01101110, 0b10010001, 0b10010001, 0b10010001, 0b01101110,   // 8
  0b01110010, 0b10001001, 0b10001001, 0b10001001, 0b01111110,   // 9
  0b00100100,                                                   // :
  0b00000001, 0b00010110,                                       // ;
  0b00001000, 0b00010100, 0b00100010,                           // <
  0b00010100, 0b00010100, 0b00010100, 0b00010100,               // =
  0b00100010, 0b00010100, 0b00001000,                           // >
  0b01000000, 0b10000000, 0b10001101, 0b10001000, 0b01110000,   // ?
  0b01111110, 0b10000001, 0b10011001, 0b10000101, 0b01111100,   // @
  0b01111111, 0b10001000, 0b10001000, 0b10001000, 0b01111111,   // A
  0b11111111, 0b10010001, 0b10010001, 0b10010001, 0b01101110,   // B
  0b01111110, 0b10000001, 0b10000001, 0b10000001, 0b01000010,               // C
  0b11111111, 0b10000001, 0b10000001, 0b10000001, 0b01111110,               // D
  0b11111111, 0b10010001, 0b10010001, 0b10010001, 0b10000001,               // E
  0b11111111, 0b10010000, 0b10010000, 0b10010000, 0b10000000,               // F
  0b01111110, 0b10000001, 0b10001001, 0b10001001, 0b01001110,               // G
  0b11111111, 0b00010000, 0b00010000, 0b00010000, 0b11111111,               // H
  0b10000001, 0b11111111, 0b10000001,                          // I
  0b10000110, 0b10000001, 0b10000001, 0b11111110,               // J
  0b11111111, 0b00010000, 0b00101000, 0b01000100, 0b10000011,               // K
  0b11111111, 0b00000001, 0b00000001, 0b00000001, 0b00000001,               // L
  0b11111111, 0b01000000, 0b00110000, 0b01000000, 0b11111111,   // M
  0b11111111, 0b01100000, 0b00011000, 0b00000110, 0b11111111,   // N
  0b01111110, 0b10000001, 0b10000001, 0b10000001, 0b01111110,   // O
  0b11111111, 0b10001000, 0b10001000, 0b10001000, 0b01110000,   // P
  0b01111110, 0b10000001, 0b10000101, 0b10000010, 0b01111101,   // Q
  0b11111111, 0b10001000, 0b10001100, 0b10001010, 0b01110001,   // R
  0b01100010, 0b10010001, 0b10010001, 0b10010001, 0b01001110,   // S
  0b10000000, 0b10000000, 0b11111111, 0b10000000, 0b10000000,   // T
  0b11111110, 0b00000001, 0b00000001, 0b00000001, 0b11111110,               // U
  0b11111100, 0b00000010, 0b00000001, 0b00000010, 0b11111100,               // V
  0b11111100, 0b00000011, 0b00011100, 0b00000011, 0b11111100,   // W
  0b11000011, 0b00100100, 0b00011000, 0b00100100, 0b11000011,   // X
  0b11000000, 0b00110000, 0b00001111, 0b00110000, 0b11000000,   // Y
  0b10000111, 0b10001001, 0b10010001, 0b10100001, 0b11000001,               // Z
  0b11111111, 0b10000001,                                       // [
  0b11000000, 0b00110000, 0b00001100, 0b00000011,               // "\"
  0b10000001, 0b11111111,                                       // ]
  0b01000000, 0b10000000, 0b01000000,                           // ^
  0b00000001, 0b00000001, 0b00000001, 0b00000001, 0b00000001,   // _
};

int FONT_8X5_END [] = {
       1,   4,   7,  12,  17,  22,  26,  27,
      30,  33,  36,  41,  43,  46,  47,  51,
      56,  61,  66,  71,  76,  81,  86,  91,
      96, 101, 102, 104, 107, 111, 114, 119,
     124, 129, 134, 139, 144, 149, 154, 159,
     164, 167, 171, 176, 181, 186, 191, 196,
     201, 206, 211, 216, 221, 226, 231, 236,
     241, 246, 251, 253, 257, 259, 262, 267
};

#endif  // __FONT8X4_H
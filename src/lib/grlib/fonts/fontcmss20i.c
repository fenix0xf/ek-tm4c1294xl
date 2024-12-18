//*****************************************************************************
//
// fontcmss20i.c - Font definition for the 20pt Cmss italic font.
//
// Copyright (c) 2011-2020 Texas Instruments Incorporated.  All rights reserved.
// Software License Agreement
//
// Texas Instruments (TI) is supplying this software for use solely and
// exclusively on TI's microcontroller products. The software is owned by
// TI and/or its suppliers, and is protected under applicable copyright
// laws. You may not combine this software with "viral" open-source
// software in order to form a larger program.
//
// THIS SOFTWARE IS PROVIDED "AS IS" AND WITH ALL FAULTS.
// NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT
// NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. TI SHALL NOT, UNDER ANY
// CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR CONSEQUENTIAL
// DAMAGES, FOR ANY REASON WHATSOEVER.
//
// This is part of revision 2.2.0.295 of the Tiva Graphics Library.
//
//*****************************************************************************

//*****************************************************************************
//
// This file is generated by ftrasterize; DO NOT EDIT BY HAND!
//
//*****************************************************************************

#include <stdint.h>
#include <stdbool.h>
#include "lib/grlib/grlib.h"

//*****************************************************************************
//
// Details of this font:
//     Characters: 32 to 126 inclusive
//     Style: cmss
//     Size: 20 point
//     Bold: no
//     Italic: yes
//     Memory usage: 2472 bytes
//
//*****************************************************************************

//*****************************************************************************
//
// The compressed data for the 20 point Cmss italic font.
// Contains characters 32 to 126 inclusive.
//
//*****************************************************************************
static const uint8_t g_pui8Cmss20iData[2271] = {
    5,   9,   0,   23,  80,  19,  7,   162, 82,  81,  97,  82,  82,  81,  97,  82,  82,  81,  240, 66,  82,  240, 240, 160, 15,  7,   129,
    33,  49,  33,  49,  33,  33,  33,  49,  33,  0,   13,  64,  39,  16,  240, 145, 241, 49,  161, 49,  177, 49,  161, 65,  161, 49,  161,
    65,  109, 113, 49,  161, 49,  177, 49,  125, 97,  49,  177, 49,  161, 49,  177, 49,  161, 65,  161, 49,  241, 240, 176, 34,  12,  98,
    149, 82,  17,  33,  81,  33,  114, 33,  114, 18,  114, 17,  133, 148, 148, 129, 18,  113, 34,  113, 34,  49,  49,  18,  66,  33,  17,
    101, 145, 0,   7,   47,  15,  240, 35,  113, 50,  18,  81,  65,  34,  65,  66,  34,  65,  66,  34,  49,  82,  18,  49,  115, 49,  209,
    225, 35,  129, 34,  18,  97,  49,  34,  81,  50,  34,  65,  66,  34,  65,  66,  33,  65,  82,  18,  49,  115, 0,   8,   37,  15,  240,
    99,  178, 18,  161, 34,  146, 34,  146, 18,  162, 17,  179, 194, 97,  83,  82,  66,  17,  66,  66,  34,  49,  66,  50,  33,  82,  67,
    98,  67,  117, 37,  0,   9,   80,  10,  4,   81,  49,  49,  33,  49,  0,   7,   112, 24,  9,   97,  113, 114, 98,  113, 114, 114, 98,
    114, 114, 98,  114, 114, 114, 114, 114, 114, 114, 129, 130, 129, 96,  24,  9,   65,  130, 129, 130, 114, 114, 114, 114, 114, 114, 114,
    98,  114, 114, 98,  114, 113, 114, 98,  113, 113, 128, 19,  10,  65,  145, 97,  33,  33,  50,  20,  82,  101, 66,  17,  18,  97,  145,
    0,   15,  96,  21,  15,  0,   6,   65,  225, 225, 225, 209, 225, 225, 141, 129, 209, 225, 225, 225, 225, 0,   8,   80,  9,   4,   0,
    7,   17,  49,  33,  49,  240, 8,   7,   0,   9,   85,  0,   8,   16,  8,   4,   0,   7,   2,   34,  240, 112, 24,  13,  161, 193, 177,
    177, 193, 177, 193, 177, 193, 177, 193, 177, 193, 177, 193, 177, 193, 177, 193, 177, 193, 192, 32,  11,  240, 180, 97,  50,  66,  50,
    65,  66,  50,  66,  50,  66,  49,  82,  34,  81,  50,  66,  50,  66,  50,  65,  66,  50,  66,  49,  100, 0,   7,   80,  20,  9,   240,
    145, 69,  113, 129, 114, 114, 114, 113, 129, 114, 114, 114, 113, 87,  0,   5,   112, 22,  12,  240, 213, 97,  51,  66,  66,  65,  82,
    162, 146, 162, 146, 146, 146, 146, 145, 146, 168, 0,   8,   23,  11,  240, 180, 82,  50,  65,  66,  146, 130, 130, 115, 162, 162, 146,
    146, 130, 65,  50,  100, 0,   7,   80,  26,  11,  240, 226, 131, 115, 114, 17,  98,  18,  98,  18,  82,  34,  66,  49,  66,  65,  73,
    114, 146, 145, 161, 0,   7,   64,  23,  12,  240, 199, 82,  161, 177, 177, 166, 98,  50,  81,  66,  162, 162, 162, 146, 66,  50,  101,
    0,   8,   32,  29,  11,  240, 196, 82,  49,  66,  146, 130, 146, 19,  68,  34,  51,  50,  50,  66,  50,  66,  50,  65,  66,  50,  66,
    49,  100, 0,   7,   80,  19,  11,  240, 136, 145, 146, 130, 130, 145, 146, 130, 146, 130, 146, 145, 146, 146, 0,   8,   31,  12,  240,
    228, 98,  50,  81,  81,  66,  66,  66,  66,  81,  50,  115, 114, 34,  82,  66,  50,  82,  50,  82,  50,  66,  67,  34,  116, 0,   8,
    32,  29,  12,  240, 228, 98,  49,  82,  66,  66,  66,  50,  82,  50,  82,  50,  82,  50,  67,  51,  35,  84,  18,  146, 161, 161, 101,
    0,   8,   48,  11,  5,   240, 240, 113, 50,  240, 194, 49,  240, 224, 14,  6,   240, 240, 226, 66,  240, 240, 49,  81,  81,  65,  240,
    128, 18,  7,   240, 240, 242, 193, 82,  82,  81,  97,  82,  82,  82,  81,  97,  82,  82,  192, 11,  15,  0,   15,  28,  0,   5,   124,
    0,   15,  48,  20,  9,   0,   7,   50,  240, 17,  114, 113, 129, 114, 98,  98,  114, 98,  114, 114, 50,  53,  192, 20,  9,   165, 49,
    66,  114, 114, 98,  98,  98,  113, 114, 113, 129, 240, 162, 113, 0,   6,   80,  40,  14,  240, 85,  115, 50,  82,  82,  66,  53,  50,
    50,  34,  50,  34,  50,  34,  34,  66,  34,  34,  66,  34,  34,  65,  50,  34,  50,  50,  34,  49,  66,  52,  98,  210, 66,  117, 0,
    9,   64,  33,  13,  240, 82,  178, 161, 17,  146, 18,  129, 34,  114, 34,  114, 34,  98,  50,  98,  50,  82,  66,  88,  66,  98,  49,
    114, 34,  114, 33,  130, 0,   8,   48,  33,  14,  240, 39,  113, 82,  97,  98,  66,  98,  66,  98,  66,  82,  81,  82,  102, 114, 82,
    82,  98,  66,  98,  65,  114, 65,  98,  66,  82,  88,  0,   9,   64,  23,  13,  240, 69,  98,  65,  82,  162, 162, 178, 162, 178, 178,
    178, 178, 178, 194, 179, 65,  117, 0,   8,   96,  34,  15,  240, 55,  130, 67,  97,  98,  97,  114, 66,  114, 66,  114, 66,  114, 65,
    130, 65,  130, 50,  114, 66,  114, 66,  98,  81,  98,  97,  82,  104, 0,   10,  32,  21,  13,  240, 24,  66,  178, 178, 178, 177, 178,
    184, 82,  178, 177, 178, 178, 178, 185, 0,   8,   80,  21,  13,  240, 24,  66,  178, 178, 177, 193, 178, 184, 82,  177, 193, 178, 178,
    178, 178, 0,   9,   64,  27,  13,  240, 69,  98,  65,  82,  162, 162, 178, 177, 178, 178, 178, 68,  50,  98,  50,  98,  66,  82,  67,
    65,  117, 0,   8,   96,  35,  14,  240, 33,  113, 66,  98,  66,  98,  66,  98,  66,  98,  65,  113, 66,  113, 74,  66,  98,  66,  98,
    65,  113, 66,  113, 66,  98,  66,  98,  66,  98,  0,   9,   32,  20,  7,   162, 82,  81,  82,  82,  82,  82,  81,  82,  82,  82,  82,
    81,  82,  82,  240, 240, 160, 22,  11,  240, 65,  146, 146, 146, 145, 161, 146, 146, 146, 145, 161, 146, 146, 65,  50,  85,  0,   7,
    80,  35,  14,  240, 33,  98,  66,  82,  82,  66,  98,  50,  113, 50,  129, 34,  130, 19,  134, 131, 34,  114, 50,  113, 82,  82,  82,
    82,  82,  82,  98,  66,  98,  0,   9,   32,  20,  10,  209, 130, 130, 130, 130, 129, 130, 130, 130, 130, 129, 130, 130, 130, 136, 0,
    6,   64,  55,  17,  240, 82,  130, 67,  115, 67,  115, 68,  84,  65,  18,  81,  18,  65,  18,  66,  17,  66,  18,  65,  33,  66,  33,
    50,  18,  66,  33,  49,  34,  65,  49,  34,  34,  65,  49,  33,  49,  66,  49,  18,  49,  66,  51,  50,  66,  51,  50,  65,  66,  66,
    0,   11,  16,  44,  14,  240, 34,  97,  68,  81,  68,  66,  68,  66,  65,  33,  66,  65,  33,  65,  66,  34,  49,  66,  34,  34,  66,
    49,  34,  65,  65,  34,  65,  66,  17,  66,  66,  17,  66,  68,  66,  83,  65,  99,  0,   9,   32,  34,  15,  240, 100, 146, 51,  98,
    82,  82,  114, 50,  130, 50,  130, 49,  146, 34,  146, 34,  131, 34,  130, 50,  130, 50,  114, 82,  82,  99,  50,  148, 0,   10,  48,
    28,  14,  240, 39,  114, 66,  97,  98,  81,  98,  66,  98,  66,  98,  66,  82,  81,  82,  103, 98,  194, 194, 193, 209, 194, 0,   10,
    32,  38,  15,  240, 100, 146, 51,  98,  82,  82,  114, 50,  130, 50,  130, 49,  146, 34,  146, 34,  146, 34,  130, 50,  130, 50,  50,
    34,  82,  49,  18,  99,  35,  149, 226, 226, 0,   6,   32,  34,  14,  240, 39,  113, 82,  97,  98,  66,  98,  66,  98,  66,  82,  81,
    82,  103, 98,  50,  114, 50,  114, 65,  113, 82,  97,  82,  82,  97,  82,  98,  0,   9,   32,  24,  13,  240, 54,  98,  65,  81,  178,
    178, 179, 180, 165, 179, 178, 178, 178, 49,  98,  66,  66,  102, 0,   8,   112, 19,  14,  236, 114, 194, 193, 209, 194, 194, 194, 193,
    209, 194, 194, 194, 194, 193, 0,   10,  35,  14,  240, 18,  98,  66,  97,  82,  97,  81,  113, 66,  98,  66,  98,  66,  97,  82,  97,
    66,  113, 66,  98,  66,  98,  66,  97,  82,  82,  98,  50,  132, 0,   9,   96,  31,  14,  226, 130, 34,  129, 65,  114, 65,  113, 82,
    82,  82,  81,  98,  66,  98,  65,  114, 50,  129, 49,  145, 34,  146, 17,  163, 179, 178, 0,   10,  57,  19,  240, 66,  98,  97,  34,
    83,  82,  34,  83,  81,  50,  68,  66,  50,  65,  18,  65,  81,  65,  18,  50,  81,  49,  34,  49,  97,  49,  49,  49,  97,  34,  49,
    34,  97,  33,  65,  33,  113, 18,  65,  18,  113, 17,  81,  17,  129, 17,  83,  130, 98,  146, 98,  0,   12,  112, 32,  15,  240, 50,
    98,  82,  82,  114, 65,  130, 49,  161, 34,  164, 194, 210, 195, 178, 18,  146, 34,  130, 66,  98,  82,  97,  114, 65,  130, 0,   9,
    112, 26,  14,  226, 130, 50,  98,  66,  97,  82,  82,  98,  50,  114, 34,  146, 17,  163, 179, 178, 194, 194, 194, 193, 209, 0,   10,
    21,  14,  240, 41,  194, 178, 178, 179, 178, 178, 178, 179, 178, 178, 178, 194, 178, 186, 0,   9,   32,  23,  9,   211, 97,  129, 114,
    114, 113, 129, 114, 114, 113, 129, 129, 114, 114, 113, 129, 129, 114, 114, 115, 96,  15,  7,   129, 33,  49,  33,  33,  33,  49,  33,
    49,  33,  0,   13,  64,  23,  10,  228, 129, 145, 145, 130, 130, 129, 145, 130, 130, 130, 129, 145, 130, 130, 129, 145, 145, 130, 100,
    96,  11,  9,   194, 100, 66,  33,  50,  50,  0,   18,  32,  7,   4,   130, 34,  0,   8,   96,  10,  4,   81,  49,  33,  49,  49,  0,
    7,   112, 20,  10,  0,   9,   20,  81,  50,  130, 130, 70,  50,  49,  50,  50,  50,  50,  54,  0,   6,   96,  28,  11,  225, 161, 146,
    146, 146, 145, 161, 20,  67,  35,  50,  66,  50,  66,  49,  82,  49,  81,  50,  66,  50,  50,  70,  0,   7,   64,  18,  10,  0,   9,
    21,  66,  49,  50,  129, 130, 130, 130, 146, 49,  84,  0,   6,   96,  29,  12,  240, 97,  162, 162, 161, 177, 177, 102, 82,  50,  66,
    65,  81,  81,  66,  81,  66,  66,  66,  66,  67,  34,  100, 17,  0,   8,   16,  19,  11,  0,   10,  5,   82,  50,  50,  66,  41,  34,
    146, 146, 162, 49,  100, 0,   7,   64,  20,  10,  243, 97,  129, 130, 130, 130, 102, 97,  130, 130, 129, 145, 145, 130, 130, 0,   7,
    32,  26,  13,  0,   11,  119, 82,  34,  98,  50,  98,  50,  98,  34,  117, 113, 214, 104, 66,  82,  66,  82,  67,  50,  102, 240, 64,
    28,  10,  194, 130, 129, 145, 145, 130, 134, 66,  50,  50,  50,  49,  66,  34,  65,  50,  50,  50,  50,  49,  66,  49,  65,  0,   6,
    96,  17,  6,   226, 66,  240, 113, 66,  66,  65,  81,  81,  66,  66,  65,  240, 240, 80,  23,  10,  240, 178, 130, 240, 240, 114, 130,
    130, 129, 145, 145, 130, 130, 129, 145, 145, 81,  33,  100, 240, 16,  27,  10,  194, 130, 129, 145, 145, 130, 130, 50,  49,  50,  65,
    33,  99,  101, 82,  33,  81,  50,  65,  50,  65,  66,  0,   6,   80,  20,  6,   145, 66,  66,  65,  81,  81,  81,  66,  65,  81,  81,
    81,  66,  66,  65,  240, 240, 80,  34,  16,  0,   14,  33,  20,  36,  66,  51,  34,  65,  66,  50,  50,  65,  66,  50,  50,  65,  66,
    50,  50,  65,  66,  50,  65,  65,  66,  50,  65,  65,  0,   10,  64,  24,  10,  0,   8,   118, 66,  50,  50,  50,  49,  66,  34,  65,
    50,  50,  50,  50,  49,  66,  49,  65,  0,   6,   96,  23,  11,  0,   10,  4,   98,  34,  66,  66,  34,  82,  34,  82,  34,  82,  34,
    66,  66,  34,  100, 0,   7,   64,  27,  12,  0,   10,  113, 20,  98,  35,  66,  66,  66,  66,  65,  82,  65,  81,  81,  66,  66,  50,
    86,  97,  177, 177, 162, 240, 112, 27,  11,  0,   10,  6,   66,  50,  50,  66,  49,  81,  50,  81,  50,  66,  50,  66,  51,  34,  84,
    17,  161, 146, 146, 145, 240, 16,  18,  8,   0,   7,   18,  18,  49,  17,  82,  97,  98,  98,  97,  113, 113, 0,   5,   112, 17,  10,
    0,   9,   21,  50,  130, 131, 132, 131, 130, 49,  66,  53,  0,   6,   112, 20,  8,   240, 240, 66,  98,  97,  86,  50,  98,  98,  97,
    98,  98,  98,  33,  52,  240, 240, 224, 24,  10,  0,   9,   1,   65,  50,  65,  50,  65,  50,  50,  49,  66,  34,  65,  50,  65,  50,
    50,  55,  0,   6,   80,  22,  10,  0,   8,   98,  66,  34,  65,  50,  50,  65,  49,  81,  34,  81,  33,  100, 99,  114, 0,   7,   16,
    36,  14,  0,   12,  34,  50,  65,  34,  50,  50,  34,  33,  17,  49,  50,  33,  17,  34,  50,  18,  17,  33,  81,  17,  33,  18,  83,
    33,  17,  98,  51,  98,  50,  0,   9,   64,  21,  12,  0,   10,  98,  66,  82,  34,  98,  18,  131, 146, 148, 114, 33,  98,  50,  66,
    81,  0,   8,   25,  12,  0,   10,  98,  66,  66,  65,  97,  50,  97,  49,  113, 34,  114, 17,  131, 147, 161, 177, 161, 162, 131, 240,
    96,  16,  10,  0,   8,   119, 129, 130, 114, 114, 114, 114, 114, 135, 0,   6,   80,  8,   12,  0,   15,  10,  0,   15,  32,  9,   21,
    0,   26,  47,  4,   0,   26,  64,  13,  9,   177, 34,  50,  33,  65,  34,  50,  33,  0,   18,  64,  10,  9,   240, 67,  18,  33,  35,
    0,   19,  64,
};

//*****************************************************************************
//
// The font definition for the 20 point Cmss italic font.
//
//*****************************************************************************
const tFont g_sFontCmss20i = {
    //
    // The format of the font.
    //
    FONT_FMT_PIXEL_RLE,

    //
    // The maximum width of the font.
    //
    18,

    //
    // The height of the font.
    //
    21,

    //
    // The baseline of the font.
    //
    16,

    //
    // The offset to each character in the font.
    //
    {
     0,    5,    24,   39,   78,   112,  159,  196,  206,  230,  254,  273,  294,  303,  311,  319,  343,  375,  395,
     417,  440,  466,  489,  518,  537,  568,  597,  608,  622,  640,  651,  671,  691,  731,  764,  797,  820,  854,
     875,  896,  923,  958,  978,  1000, 1035, 1055, 1110, 1154, 1188, 1216, 1254, 1288, 1312, 1331, 1366, 1397, 1454,
     1486, 1512, 1533, 1556, 1571, 1594, 1605, 1612, 1622, 1642, 1670, 1688, 1717, 1736, 1756, 1782, 1810, 1827, 1850,
     1877, 1897, 1931, 1955, 1978, 2005, 2032, 2050, 2067, 2087, 2111, 2133, 2169, 2190, 2215, 2231, 2239, 2248, 2261,
     },

    //
    // A pointer to the actual font data
    //
    g_pui8Cmss20iData
};

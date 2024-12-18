//*****************************************************************************
//
// fontcmss30i.c - Font definition for the 30pt Cmss italic font.
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
//     Size: 30 point
//     Bold: no
//     Italic: yes
//     Memory usage: 3504 bytes
//
//*****************************************************************************

//*****************************************************************************
//
// The compressed data for the 30 point Cmss italic font.
// Contains characters 32 to 126 inclusive.
//
//*****************************************************************************
static const uint8_t g_pui8Cmss30iData[3303] = {
    5,   13,  0,   50,  48,  26,  10,  240, 147, 115, 114, 130, 130, 115, 115, 114, 130, 130, 115, 114, 130, 130, 130, 114, 240, 240, 115,
    115, 0,   10,  112, 17,  13,  240, 195, 51,  67,  51,  67,  51,  66,  66,  81,  81,  82,  66,  0,   38,  83,  25,  0,   7,   113, 97,
    240, 33,  82,  240, 17,  97,  240, 33,  82,  240, 17,  97,  240, 33,  82,  240, 17,  97,  240, 33,  82,  240, 18,  81,  240, 33,  97,
    159, 6,   177, 97,  240, 18,  81,  240, 33,  97,  240, 33,  82,  240, 17,  97,  191, 6,   146, 81,  240, 33,  82,  240, 18,  81,  240,
    33,  97,  240, 18,  81,  240, 33,  97,  240, 18,  81,  240, 33,  97,  240, 18,  81,  240, 33,  97,  0,   8,   32,  46,  17,  146, 242,
    214, 153, 115, 18,  34,  114, 34,  49,  98,  50,  162, 49,  178, 34,  178, 34,  182, 198, 198, 198, 178, 19,  178, 34,  177, 50,  162,
    50,  162, 34,  97,  66,  34,  99,  37,  136, 166, 210, 242, 0,   14,  16,  73,  21,  67,  161, 100, 145, 98,  34,  129, 82,  50,  113,
    98,  50,  97,  98,  66,  82,  98,  66,  81,  114, 50,  81,  130, 50,  65,  146, 34,  81,  165, 65,  179, 81,  240, 66,  67,  193, 68,
    177, 66,  34,  145, 66,  50,  145, 66,  50,  129, 67,  50,  113, 82,  66,  98,  82,  66,  97,  98,  50,  97,  114, 50,  81,  130, 34,
    97,  148, 97,  163, 0,   16,  80,  55,  22,  0,   6,   99,  240, 38,  240, 17,  50,  242, 50,  241, 66,  226, 66,  226, 50,  242, 34,
    240, 18,  18,  240, 36,  113, 162, 146, 131, 130, 118, 99,  98,  50,  98,  98,  67,  66,  98,  98,  50,  114, 99,  18,  130, 116, 147,
    85,  169, 23,  101, 86,  0,   22,  64,  11,  7,   243, 67,  67,  66,  81,  82,  0,   20,  96,  34,  13,  130, 162, 162, 178, 162, 162,
    178, 162, 178, 162, 178, 178, 162, 178, 178, 178, 178, 162, 178, 178, 178, 178, 178, 178, 178, 178, 193, 194, 178, 194, 178, 144, 34,
    13,  98,  193, 194, 178, 194, 178, 178, 178, 178, 178, 178, 178, 178, 178, 163, 162, 178, 178, 178, 162, 178, 178, 162, 178, 162, 178,
    162, 162, 178, 162, 162, 176, 27,  15,  113, 210, 210, 145, 50,  34,  67,  33,  35,  83,  21,  133, 164, 152, 84,  17,  20,  66,  34,
    50,  130, 210, 210, 0,   33,  43,  22,  0,   17,  113, 240, 97,  240, 82,  240, 81,  240, 97,  240, 97,  240, 97,  240, 81,  240, 97,
    207, 4,   193, 240, 97,  240, 81,  240, 97,  240, 97,  240, 97,  240, 82,  240, 81,  240, 97,  0,   18,  32,  13,  7,   0,   18,  67,
    67,  66,  82,  81,  82,  240, 240, 48,  9,   11,  0,   20,  88,  56,  0,   19,  80,  9,   5,   0,   13,  18,  50,  240, 240, 208, 66,
    20,  240, 17,  240, 50,  240, 49,  240, 50,  240, 49,  240, 49,  240, 65,  240, 49,  240, 65,  240, 49,  240, 65,  240, 49,  240, 65,
    240, 49,  240, 50,  240, 49,  240, 50,  240, 49,  240, 50,  240, 49,  240, 49,  240, 65,  240, 49,  240, 65,  240, 49,  240, 65,  240,
    49,  240, 65,  240, 49,  240, 50,  240, 49,  240, 64,  43,  16,  0,   6,   101, 167, 131, 51,  98,  98,  83,  98,  82,  114, 82,  114,
    66,  130, 66,  130, 66,  115, 66,  114, 66,  130, 66,  130, 66,  114, 82,  114, 82,  99,  82,  98,  114, 51,  135, 165, 0,   17,  16,
    28,  13,  0,   6,   1,   163, 117, 115, 18,  178, 178, 163, 162, 178, 178, 163, 163, 162, 178, 178, 163, 162, 178, 122, 58,  0,   13,
    48,  31,  17,  0,   7,   37,  183, 146, 67,  114, 98,  98,  114, 97,  130, 242, 241, 242, 226, 226, 226, 226, 226, 226, 225, 226, 226,
    236, 91,  0,   17,  96,  31,  16,  0,   6,   117, 152, 115, 66,  113, 98,  226, 226, 210, 211, 149, 181, 242, 242, 226, 226, 226, 210,
    82,  114, 83,  67,  120, 164, 0,   17,  16,  37,  16,  0,   7,   35,  196, 180, 193, 18,  178, 18,  162, 34,  147, 19,  131, 34,  146,
    50,  130, 66,  115, 51,  99,  67,  98,  82,  109, 61,  163, 211, 210, 226, 211, 0,   16,  112, 32,  17,  0,   7,   9,   121, 130, 242,
    242, 242, 227, 226, 20,  168, 147, 51,  115, 82,  242, 242, 242, 242, 226, 98,  99,  99,  67,  136, 165, 0,   18,  32,  39,  15,  0,
    6,   69,  135, 115, 179, 194, 194, 210, 36,  98,  22,  100, 51,  83,  82,  67,  98,  66,  114, 66,  114, 66,  114, 66,  98,  82,  98,
    82,  82,  114, 51,  119, 148, 0,   16,  16,  27,  16,  0,   6,   28,  76,  210, 210, 211, 195, 210, 210, 210, 211, 210, 211, 210, 211,
    210, 211, 210, 226, 211, 211, 0,   17,  80,  41,  17,  0,   7,   37,  168, 131, 66,  114, 99,  83,  114, 82,  114, 99,  98,  114, 67,
    151, 166, 147, 66,  115, 98,  98,  114, 82,  130, 82,  130, 82,  114, 98,  114, 99,  67,  136, 165, 0,   18,  32,  40,  15,  0,   6,
    52,  151, 115, 51,  98,  82,  82,  98,  82,  98,  66,  114, 66,  114, 66,  114, 66,  99,  66,  83,  83,  52,  102, 18,  100, 35,  194,
    194, 195, 97,  67,  119, 148, 0,   16,  32,  13,  8,   0,   10,  50,  83,  0,   9,   51,  82,  0,   8,   96,  17,  9,   0,   11,  83,
    99,  0,   10,  83,  98,  114, 114, 113, 113, 240, 240, 224, 26,  10,  0,   10,  67,  115, 240, 240, 114, 114, 130, 130, 130, 115, 114,
    130, 130, 115, 115, 114, 130, 130, 115, 115, 240, 192, 12,  23,  0,   34,  95,  4,   0,   14,  111, 4,   0,   35,  27,  12,  0,   12,
    114, 147, 240, 240, 242, 162, 146, 162, 162, 146, 146, 147, 131, 146, 146, 162, 162, 162, 82,  57,  70,  240, 224, 27,  13,  240, 229,
    104, 82,  67,  178, 178, 178, 162, 163, 146, 162, 162, 178, 162, 178, 178, 162, 0,   6,   19,  163, 0,   14,  32,  55,  19,  0,   5,
    117, 200, 148, 67,  115, 99,  99,  67,  18,  83,  56,  82,  51,  36,  66,  51,  67,  66,  50,  83,  65,  51,  83,  50,  50,  98,  66,
    50,  98,  66,  50,  83,  66,  50,  82,  82,  51,  50,  99,  54,  130, 68,  147, 240, 35,  98,  153, 182, 0,   20,  16,  47,  20,  0,
    6,   51,  240, 35,  240, 20,  240, 17,  19,  226, 19,  210, 35,  210, 50,  194, 66,  194, 66,  178, 82,  178, 83,  146, 99,  146, 99,
    140, 125, 114, 146, 99,  146, 98,  162, 82,  179, 66,  179, 50,  195, 0,   20,  48,  43,  19,  240, 240, 201, 171, 115, 100, 99,  130,
    99,  130, 98,  146, 98,  146, 83,  130, 99,  99,  122, 155, 130, 115, 99,  131, 83,  146, 82,  162, 82,  162, 82,  146, 83,  131, 82,
    116, 108, 122, 0,   20,  16,  43,  19,  0,   5,   103, 170, 131, 98,  115, 243, 243, 240, 18,  240, 18,  240, 34,  240, 34,  240, 18,
    240, 34,  240, 34,  240, 34,  240, 34,  240, 34,  240, 50,  240, 35,  129, 131, 83,  153, 182, 0,   20,  16,  45,  21,  0,   5,   106,
    188, 146, 116, 130, 131, 115, 147, 99,  162, 98,  178, 98,  178, 98,  178, 83,  178, 83,  178, 82,  194, 82,  178, 98,  178, 83,  162,
    99,  162, 98,  162, 114, 146, 115, 115, 140, 154, 0,   22,  48,  43,  20,  240, 240, 237, 124, 130, 240, 35,  240, 35,  240, 34,  240,
    50,  240, 35,  240, 35,  240, 44,  140, 130, 240, 35,  240, 35,  240, 35,  240, 34,  240, 50,  240, 35,  240, 35,  240, 45,  125, 0,
    20,  112, 44,  19,  240, 240, 204, 124, 114, 240, 19,  240, 19,  240, 18,  240, 34,  240, 19,  240, 19,  240, 19,  240, 27,  139, 115,
    240, 19,  240, 19,  240, 18,  240, 34,  240, 19,  240, 19,  240, 18,  240, 34,  0,   21,  16,  44,  19,  0,   5,   103, 170, 131, 98,
    115, 129, 99,  243, 240, 18,  240, 18,  240, 34,  240, 34,  240, 18,  240, 34,  240, 34,  102, 82,  102, 82,  162, 82,  147, 98,  130,
    115, 114, 131, 98,  154, 166, 0,   20,  16,  46,  22,  0,   6,   2,   163, 114, 162, 130, 162, 115, 147, 115, 147, 114, 162, 130, 162,
    115, 162, 115, 147, 127, 126, 130, 162, 115, 147, 115, 147, 115, 147, 114, 162, 130, 162, 115, 147, 115, 147, 114, 163, 114, 162, 0,
    23,  27,  10,  240, 147, 115, 114, 130, 130, 115, 115, 114, 130, 115, 115, 115, 114, 130, 115, 115, 114, 130, 130, 115, 115, 0,   10,
    112, 29,  17,  0,   5,   98,  242, 227, 227, 226, 242, 242, 227, 227, 226, 242, 227, 227, 226, 242, 242, 227, 226, 129, 83,  121, 165,
    0,   18,  32,  49,  22,  0,   6,   2,   163, 114, 147, 130, 131, 131, 114, 163, 83,  178, 83,  194, 67,  195, 51,  211, 35,  227, 21,
    210, 22,  213, 34,  196, 67,  179, 83,  179, 99,  162, 115, 162, 131, 131, 131, 131, 131, 130, 163, 114, 163, 0,   22,  112, 28,  14,
    240, 240, 34,  194, 194, 179, 179, 178, 194, 179, 179, 179, 178, 194, 179, 179, 179, 178, 194, 179, 179, 187, 59,  0,   14,  48,  78,
    26,  0,   7,   4,   195, 116, 180, 116, 165, 101, 165, 101, 146, 18,  114, 18,  146, 18,  114, 19,  114, 34,  114, 19,  114, 19,  99,
    34,  98,  35,  99,  34,  98,  34,  114, 50,  82,  50,  114, 50,  82,  50,  99,  50,  66,  51,  99,  50,  51,  50,  114, 67,  34,  66,
    114, 67,  18,  82,  114, 82,  18,  67,  99,  84,  83,  99,  84,  82,  114, 99,  98,  114, 99,  98,  0,   26,  112, 62,  22,  0,   6,
    4,   131, 116, 130, 132, 130, 118, 114, 114, 19,  99,  114, 34,  98,  130, 34,  98,  115, 35,  82,  115, 35,  82,  114, 66,  67,  114,
    66,  66,  130, 67,  50,  115, 67,  50,  115, 82,  35,  114, 98,  35,  114, 99,  18,  130, 99,  18,  115, 114, 18,  115, 117, 114, 133,
    114, 132, 0,   23,  45,  20,  0,   6,   5,   217, 163, 68,  130, 130, 114, 147, 82,  178, 82,  178, 66,  194, 66,  194, 66,  194, 50,
    210, 50,  194, 66,  194, 66,  194, 66,  178, 82,  163, 98,  146, 114, 115, 147, 67,  169, 213, 0,   21,  48,  44,  20,  240, 240, 249,
    187, 131, 99,  131, 130, 114, 146, 114, 146, 99,  146, 99,  130, 114, 131, 114, 115, 139, 138, 163, 240, 34,  240, 50,  240, 50,  240,
    35,  240, 35,  240, 34,  240, 50,  240, 35,  0,   22,  16,  56,  20,  0,   6,   5,   217, 163, 68,  130, 130, 114, 147, 83,  162, 82,
    178, 66,  194, 66,  194, 66,  194, 50,  210, 50,  195, 50,  194, 66,  194, 66,  178, 82,  82,  66,  98,  67,  34,  114, 82,  18,  147,
    52,  169, 216, 240, 35,  240, 50,  240, 51,  240, 35,  0,   10,  112, 45,  20,  240, 240, 234, 172, 131, 99,  130, 146, 114, 146, 99,
    146, 99,  146, 98,  146, 114, 115, 139, 138, 163, 67,  162, 98,  162, 98,  162, 99,  131, 99,  131, 114, 130, 131, 114, 131, 99,  146,
    99,  147, 0,   20,  80,  37,  18,  240, 240, 229, 185, 131, 81,  130, 242, 240, 18,  240, 18,  240, 19,  244, 246, 215, 244, 243, 240,
    18,  240, 18,  240, 18,  242, 98,  130, 100, 67,  137, 181, 0,   19,  32,  48,  20,  240, 240, 175, 2,   63,  2,   163, 240, 35,  240,
    34,  240, 50,  240, 35,  240, 35,  240, 34,  240, 50,  240, 50,  240, 35,  240, 35,  240, 34,  240, 50,  240, 50,  240, 35,  240, 35,
    240, 34,  240, 50,  240, 35,  0,   21,  96,  47,  20,  240, 240, 210, 147, 83,  146, 99,  146, 98,  162, 98,  147, 98,  146, 99,  146,
    98,  162, 98,  147, 98,  147, 98,  146, 99,  146, 98,  162, 98,  147, 98,  146, 114, 146, 114, 131, 115, 99,  147, 67,  184, 213, 0,
    21,  64,  48,  20,  240, 240, 163, 194, 51,  194, 51,  178, 67,  163, 82,  162, 98,  147, 98,  146, 115, 114, 131, 114, 131, 98,  147,
    83,  162, 82,  178, 67,  179, 50,  195, 34,  211, 34,  211, 18,  227, 18,  244, 240, 20,  240, 19,  0,   21,  96,  79,  28,  0,   7,
    2,   147, 146, 50,  147, 146, 51,  116, 130, 67,  116, 130, 67,  98,  18,  114, 83,  98,  18,  114, 83,  82,  34,  98,  99,  82,  35,
    82,  99,  82,  35,  66,  115, 66,  51,  66,  115, 66,  51,  51,  130, 50,  67,  50,  146, 50,  67,  35,  146, 34,  83,  34,  162, 34,
    83,  34,  162, 18,  114, 18,  178, 18,  114, 18,  180, 132, 196, 132, 195, 147, 211, 147, 0,   29,  64,  51,  23,  0,   6,   35,  163,
    131, 146, 147, 130, 179, 98,  195, 83,  211, 51,  242, 35,  240, 22,  240, 52,  240, 67,  240, 83,  240, 69,  240, 34,  19,  240, 19,
    35,  227, 51,  211, 83,  179, 99,  178, 131, 146, 147, 130, 179, 99,  179, 0,   23,  96,  48,  21,  240, 240, 195, 195, 51,  179, 83,
    147, 99,  131, 115, 130, 147, 98,  163, 83,  179, 51,  195, 35,  226, 19,  245, 240, 20,  240, 50,  240, 66,  240, 66,  240, 51,  240,
    51,  240, 50,  240, 66,  240, 51,  240, 51,  0,   22,  112, 46,  21,  0,   5,   110, 126, 240, 35,  240, 35,  240, 35,  240, 50,  240,
    50,  240, 51,  240, 35,  240, 35,  240, 35,  240, 50,  240, 51,  240, 35,  240, 35,  240, 35,  240, 35,  240, 50,  240, 51,  240, 46,
    126, 0,   21,  112, 34,  14,  101, 149, 146, 194, 194, 179, 178, 194, 194, 194, 179, 178, 194, 194, 194, 179, 178, 194, 194, 194, 179,
    178, 194, 194, 194, 178, 194, 194, 194, 196, 149, 144, 18,  13,  240, 210, 66,  81,  81,  82,  66,  66,  66,  83,  51,  67,  51,  0,
    37,  112, 34,  14,  101, 149, 179, 178, 194, 194, 194, 179, 178, 194, 194, 194, 179, 178, 194, 194, 194, 179, 178, 194, 194, 194, 179,
    178, 194, 194, 194, 179, 178, 149, 149, 144, 18,  13,  240, 240, 18,  161, 18,  130, 33,  114, 50,  82,  66,  66,  98,  0,   37,  96,
    9,   6,   240, 51,  51,  51,  0,   19,  16,  12,  7,   240, 18,  81,  82,  66,  83,  67,  0,   20,  80,  26,  14,  0,   18,  5,   136,
    82,  82,  194, 194, 134, 88,  83,  66,  66,  98,  66,  98,  67,  67,  74,  84,  34,  0,   14,  80,  39,  15,  240, 240, 66,  210, 195,
    194, 210, 210, 210, 195, 194, 52,  98,  22,  99,  67,  67,  98,  67,  98,  66,  114, 66,  114, 66,  114, 51,  98,  67,  83,  67,  67,
    89,  98,  20,  0,   16,  21,  15,  0,   19,  53,  137, 83,  81,  98,  194, 194, 210, 210, 210, 210, 226, 82,  105, 117, 0,   16,  40,
    17,  0,   5,   98,  242, 227, 226, 242, 242, 242, 227, 133, 18,  137, 115, 67,  99,  98,  98,  99,  82,  114, 98,  114, 98,  114, 98,
    99,  98,  99,  99,  67,  134, 18,  148, 34,  0,   17,  112, 23,  15,  0,   19,  53,  136, 99,  67,  66,  114, 75,  60,  50,  210, 210,
    211, 211, 81,  105, 133, 0,   15,  112, 28,  14,  240, 240, 84,  134, 115, 178, 179, 178, 194, 194, 152, 103, 146, 194, 194, 194, 179,
    178, 194, 194, 194, 178, 194, 0,   15,  64,  38,  19,  0,   24,  84,  35,  139, 115, 51,  147, 82,  146, 98,  146, 83,  147, 51,  168,
    162, 20,  193, 240, 50,  240, 41,  171, 114, 115, 98,  146, 98,  146, 99,  99,  138, 182, 0,   6,   41,  15,  240, 240, 82,  195, 194,
    210, 210, 210, 195, 194, 210, 36,  114, 22,  84,  66,  83,  82,  83,  82,  82,  98,  82,  82,  83,  82,  83,  82,  82,  98,  82,  98,
    82,  83,  67,  82,  0,   15,  80,  24,  10,  240, 240, 67,  115, 115, 0,   5,   98,  130, 115, 115, 114, 130, 115, 115, 114, 130, 130,
    115, 114, 0,   11,  31,  15,  0,   6,   99,  195, 195, 0,   8,   114, 210, 210, 210, 195, 194, 210, 210, 210, 195, 194, 210, 210, 210,
    195, 194, 195, 134, 164, 240, 240, 160, 39,  16,  240, 240, 114, 211, 210, 226, 226, 226, 211, 210, 226, 83,  98,  67,  99,  50,  130,
    35,  146, 19,  166, 166, 148, 19,  131, 50,  130, 67,  114, 82,  114, 83,  83,  83,  0,   16,  80,  26,  10,  240, 162, 115, 114, 130,
    130, 115, 115, 114, 130, 130, 115, 114, 130, 130, 115, 115, 114, 130, 130, 115, 114, 0,   11,  46,  22,  0,   27,  98,  37,  52,  98,
    22,  38,  83,  68,  51,  67,  83,  82,  67,  83,  82,  66,  98,  98,  66,  98,  82,  82,  83,  82,  67,  83,  82,  66,  98,  98,  66,
    98,  98,  66,  98,  83,  66,  83,  82,  0,   22,  80,  33,  15,  0,   19,  18,  36,  114, 22,  99,  66,  83,  82,  83,  82,  82,  98,
    82,  82,  83,  82,  83,  82,  82,  98,  82,  98,  82,  83,  67,  82,  0,   15,  80,  29,  16,  0,   20,  100, 168, 99,  82,  98,  114,
    66,  130, 65,  146, 50,  146, 50,  131, 50,  130, 66,  114, 98,  83,  104, 164, 0,   17,  16,  37,  17,  0,   21,  98,  52,  130, 22,
    131, 67,  114, 98,  99,  98,  98,  114, 98,  114, 98,  114, 83,  98,  99,  83,  99,  67,  121, 130, 36,  131, 226, 242, 242, 242, 227,
    0,   6,   38,  15,  0,   19,  52,  18,  105, 83,  67,  67,  83,  66,  99,  65,  114, 66,  114, 66,  114, 66,  99,  66,  99,  67,  67,
    102, 18,  116, 34,  195, 194, 210, 210, 210, 195, 240, 240, 96,  22,  13,  0,   16,  82,  35,  98,  20,  85,  132, 147, 162, 178, 163,
    162, 178, 178, 178, 163, 0,   14,  32,  22,  14,  0,   18,  21,  120, 98,  81,  82,  194, 197, 166, 180, 194, 194, 81,  82,  89,  117,
    0,   14,  112, 25,  11,  0,   8,   82,  131, 130, 146, 120, 56,  67,  130, 146, 146, 146, 130, 146, 146, 146, 49,  86,  84,  0,   11,
    112, 32,  15,  0,   19,  2,   83,  82,  83,  66,  98,  82,  98,  82,  98,  82,  83,  82,  82,  82,  98,  82,  98,  82,  83,  82,  68,
    89,  116, 34,  0,   15,  96,  30,  15,  0,   18,  99,  114, 51,  98,  67,  98,  82,  82,  98,  67,  98,  66,  114, 51,  115, 34,  131,
    18,  162, 18,  164, 180, 179, 0,   16,  32,  50,  21,  0,   26,  35,  82,  98,  51,  82,  98,  51,  68,  66,  67,  65,  18,  66,  82,
    50,  18,  50,  98,  49,  34,  50,  98,  34,  34,  34,  114, 33,  50,  34,  114, 18,  50,  18,  130, 17,  66,  18,  132, 68,  147, 84,
    147, 83,  0,   22,  16,  29,  18,  0,   22,  115, 99,  114, 83,  131, 51,  163, 19,  197, 212, 242, 244, 210, 18,  194, 35,  162, 66,
    146, 83,  99,  115, 0,   18,  80,  37,  18,  0,   22,  115, 114, 99,  98,  130, 98,  130, 82,  146, 67,  147, 50,  163, 34,  194, 34,
    194, 18,  210, 18,  212, 228, 242, 242, 240, 18,  242, 243, 197, 212, 0,   6,   32,  20,  16,  0,   20,  58,  106, 195, 195, 195, 195,
    195, 195, 195, 195, 195, 203, 90,  0,   16,  96,  9,   17,  0,   29,  110, 62,  0,   32,  32,  11,  32,  0,   56,  15,  14,  63,  14,
    0,   60,  48,  18,  13,  240, 226, 35,  82,  50,  98,  35,  82,  50,  98,  34,  98,  50,  0,   38,  16,  15,  13,  240, 240, 179, 50,
    69,  34,  65,  37,  66,  51,  0,   39,  80,
};

//*****************************************************************************
//
// The font definition for the 30 point Cmss italic font.
//
//*****************************************************************************
const tFont g_sFontCmss30i = {
    //
    // The format of the font.
    //
    FONT_FMT_PIXEL_RLE,

    //
    // The maximum width of the font.
    //
    28,

    //
    // The height of the font.
    //
    31,

    //
    // The baseline of the font.
    //
    23,

    //
    // The offset to each character in the font.
    //
    {
     0,    5,    31,   48,   131,  177,  250,  305,  316,  350,  384,  411,  454,  467,  476,  485,  551,  594,  622,
     653,  684,  721,  753,  792,  819,  860,  900,  913,  930,  956,  968,  995,  1022, 1077, 1124, 1167, 1210, 1255,
     1298, 1342, 1386, 1432, 1459, 1488, 1537, 1565, 1643, 1705, 1750, 1794, 1850, 1895, 1932, 1980, 2027, 2075, 2154,
     2205, 2253, 2299, 2333, 2351, 2385, 2403, 2412, 2424, 2450, 2489, 2510, 2550, 2573, 2601, 2639, 2680, 2704, 2735,
     2774, 2800, 2846, 2879, 2908, 2945, 2983, 3005, 3027, 3052, 3084, 3114, 3164, 3193, 3230, 3250, 3259, 3270, 3288,
     },

    //
    // A pointer to the actual font data
    //
    g_pui8Cmss30iData
};

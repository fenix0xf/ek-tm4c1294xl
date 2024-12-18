//*****************************************************************************
//
// fontcm36.c - Font definition for the 36pt Cm font.
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
//     Style: cm
//     Size: 36 point
//     Bold: no
//     Italic: no
//     Memory usage: 4328 bytes
//
//*****************************************************************************

//*****************************************************************************
//
// The compressed data for the 36 point Cm font.
// Contains characters 32 to 126 inclusive.
//
//*****************************************************************************
static const uint8_t g_pui8Cm36Data[4127] = {
    5,   14,  0,   61,  32,  28,  6,   99,  51,  51,  51,  51,  51,  51,  51,  51,  65,  81,  81,  81,  81,  81,  81,  81,  81,  81,  240,
    115, 51,  51,  0,   7,   16,  24,  14,  240, 226, 82,  68,  52,  67,  67,  97,  97,  97,  97,  97,  97,  81,  97,  97,  97,  81,  97,
    0,   42,  80,  95,  27,  0,   8,   18,  97,  240, 49,  113, 240, 49,  113, 240, 49,  98,  240, 34,  97,  240, 49,  113, 240, 49,  113,
    240, 49,  98,  240, 34,  97,  240, 49,  113, 240, 49,  113, 240, 49,  98,  159, 9,   177, 113, 240, 49,  98,  240, 49,  97,  240, 50,
    97,  240, 49,  113, 191, 9,   146, 97,  240, 49,  113, 240, 49,  113, 240, 49,  98,  240, 34,  97,  240, 49,  113, 240, 49,  113, 240,
    49,  98,  240, 34,  97,  240, 49,  113, 240, 49,  113, 240, 49,  98,  0,   8,   64,  67,  16,  97,  214, 130, 33,  34,  113, 49,  65,
    82,  49,  66,  50,  65,  81,  50,  65,  51,  50,  65,  51,  50,  65,  51,  51,  49,  162, 49,  164, 17,  182, 183, 197, 177, 35,  161,
    51,  145, 51,  51,  49,  66,  51,  49,  66,  51,  49,  66,  49,  81,  66,  65,  65,  50,  81,  65,  50,  98,  33,  34,  134, 209, 241,
    0,   15,  16,  88,  27,  51,  210, 130, 34,  163, 114, 67,  100, 129, 81,  38,  18,  130, 97,  130, 130, 97,  114, 146, 97,  98,  162,
    97,  98,  162, 97,  82,  178, 97,  82,  194, 65,  82,  210, 65,  66,  242, 33,  82,  240, 34,  82,  240, 161, 85,  242, 65,  81,  210,
    66,  81,  209, 81,  113, 178, 66,  113, 162, 82,  113, 162, 82,  113, 146, 98,  113, 145, 114, 113, 130, 114, 113, 114, 146, 81,  129,
    162, 81,  114, 178, 49,  129, 212, 0,   24,  48,  76,  26,  240, 240, 51,  240, 98,  49,  240, 82,  65,  240, 50,  81,  240, 50,  81,
    240, 50,  81,  240, 50,  65,  240, 66,  65,  240, 66,  49,  240, 98,  17,  240, 115, 150, 130, 179, 178, 177, 164, 161, 161, 50,  129,
    161, 67,  113, 161, 82,  97,  161, 114, 81,  146, 115, 49,  162, 131, 17,  178, 148, 113, 51,  146, 129, 66,  132, 98,  82,  82,  51,
    50,  118, 116, 0,   30,  14,  7,   242, 68,  67,  97,  97,  97,  81,  97,  81,  0,   21,  80,  38,  11,  113, 145, 145, 145, 161, 145,
    146, 146, 145, 146, 146, 146, 130, 146, 146, 146, 146, 146, 146, 146, 146, 146, 146, 162, 146, 146, 146, 162, 146, 161, 162, 162, 161,
    177, 177, 48,  38,  11,  1,   177, 177, 177, 162, 161, 162, 146, 162, 146, 146, 162, 146, 146, 146, 146, 146, 146, 146, 146, 146, 146,
    146, 145, 146, 146, 145, 161, 146, 145, 146, 145, 145, 145, 145, 160, 32,  15,  82,  210, 210, 209, 81,  50,  49,  66,  82,  17,  34,
    146, 17,  193, 210, 17,  146, 17,  34,  82,  49,  66,  49,  65,  226, 210, 210, 0,   38,  64,  49,  24,  0,   19,  33,  240, 129, 240,
    129, 240, 129, 240, 129, 240, 129, 240, 129, 240, 129, 240, 129, 240, 129, 240, 129, 223, 6,   209, 240, 129, 240, 129, 240, 129, 240,
    129, 240, 129, 240, 129, 240, 129, 240, 129, 240, 129, 0,   22,  80,  16,  7,   0,   20,  34,  68,  67,  97,  97,  97,  81,  97,  81,
    97,  240, 64,  9,   12,  0,   25,  73,  57,  0,   24,  48,  10,  6,   0,   17,  35,  51,  51,  0,   7,   16,  38,  16,  193, 226, 225,
    241, 226, 225, 241, 226, 225, 241, 226, 225, 241, 226, 225, 241, 225, 241, 241, 225, 241, 226, 225, 241, 226, 225, 241, 226, 225, 241,
    226, 225, 241, 226, 225, 240, 51,  17,  0,   7,   5,   162, 66,  130, 98,  98,  130, 82,  130, 81,  161, 66,  162, 50,  162, 50,  162,
    50,  162, 50,  162, 50,  162, 50,  162, 50,  162, 50,  162, 50,  162, 50,  162, 65,  161, 82,  130, 82,  130, 98,  98,  130, 66,  180,
    0,   20,  16,  30,  13,  240, 240, 225, 163, 115, 18,  178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178,
    178, 178, 178, 122, 0,   15,  40,  16,  0,   6,   69,  146, 67,  97,  130, 81,  130, 65,  162, 51,  130, 51,  130, 51,  130, 226, 210,
    226, 210, 225, 225, 225, 225, 225, 225, 225, 129, 81,  145, 65,  161, 75,  76,  0,   18,  64,  42,  17,  0,   6,   118, 161, 83,  97,
    130, 99,  99,  83,  99,  83,  99,  227, 226, 226, 226, 181, 240, 34,  240, 18,  243, 243, 227, 51,  131, 51,  131, 51,  131, 49,  162,
    81,  131, 98,  83,  150, 0,   20,  48,  18,  0,   8,   1,   240, 18,  240, 18,  243, 225, 18,  209, 34,  209, 34,  193, 50,  177, 66,
    177, 66,  161, 82,  161, 82,  145, 98,  129, 114, 129, 114, 113, 130, 127, 194, 240, 18,  240, 18,  240, 18,  240, 18,  216, 0,   20,
    96,  42,  16,  0,   6,   34,  98,  105, 119, 145, 241, 241, 241, 241, 241, 36,  145, 17,  66,  114, 97,  113, 114, 241, 242, 226, 226,
    66,  130, 51,  130, 51,  130, 49,  146, 81,  129, 114, 66,  165, 0,   18,  112, 49,  16,  0,   6,   101, 146, 81,  114, 97,  98,  98,
    97,  114, 82,  226, 225, 226, 52,  114, 33,  66,  83,  114, 67,  114, 66,  146, 50,  146, 50,  146, 50,  146, 50,  146, 65,  146, 66,
    130, 66,  114, 97,  113, 130, 65,  165, 0,   18,  112, 35,  17,  240, 240, 81,  240, 17,  254, 62,  49,  177, 65,  177, 241, 241, 241,
    240, 17,  241, 242, 241, 242, 242, 226, 242, 242, 242, 227, 227, 227, 227, 227, 0,   20,  48,  49,  17,  0,   7,   5,   162, 81,  130,
    113, 113, 145, 97,  145, 82,  145, 98,  129, 99,  97,  131, 65,  164, 17,  196, 209, 20,  146, 52,  113, 115, 82,  130, 66,  162, 50,
    162, 50,  177, 50,  177, 66,  145, 83,  114, 99,  82,  150, 0,   20,  50,  16,  0,   6,   69,  162, 65,  129, 113, 98,  114, 81,  145,
    66,  145, 66,  146, 50,  146, 50,  146, 50,  146, 50,  146, 66,  115, 81,  97,  18,  82,  66,  18,  116, 50,  226, 225, 226, 82,  113,
    98,  98,  97,  113, 113, 82,  149, 0,   19,  16,  15,  6,   0,   8,   35,  51,  51,  0,   7,   19,  51,  51,  0,   7,   16,  21,  6,
    0,   8,   35,  51,  51,  0,   7,   18,  67,  51,  81,  81,  81,  81,  65,  81,  65,  240, 32,  28,  6,   0,   6,   3,   51,  51,  240,
    113, 81,  81,  81,  81,  81,  81,  81,  81,  82,  51,  51,  51,  51,  51,  51,  51,  51,  51,  240, 13,  25,  0,   43,  111, 7,   0,
    16,  15,  7,   0,   44,  16,  36,  15,  0,   15,  67,  195, 195, 0,   7,   33,  225, 225, 225, 225, 225, 209, 225, 209, 225, 209, 209,
    210, 210, 115, 50,  115, 50,  115, 50,  129, 82,  97,  134, 240, 240, 96,  36,  14,  240, 37,  129, 82,  81,  113, 65,  130, 51,  98,
    51,  98,  51,  98,  194, 178, 178, 193, 194, 193, 194, 193, 209, 209, 209, 209, 0,   6,   114, 179, 179, 0,   16,  80,  87,  26,  240,
    240, 86,  240, 35,  83,  225, 177, 193, 209, 161, 241, 129, 100, 113, 113, 82,  50,  82,  81,  82,  97,  81,  81,  66,  115, 49,  65,
    82,  130, 65,  49,  66,  146, 65,  49,  66,  146, 65,  49,  66,  146, 65,  49,  66,  146, 65,  49,  66,  146, 65,  49,  66,  146, 65,
    50,  66,  130, 65,  65,  66,  115, 65,  65,  82,  99,  49,  97,  82,  50,  18,  49,  98,  84,  68,  130, 240, 162, 242, 147, 132, 217,
    0,   30,  48,  66,  26,  240, 240, 113, 240, 146, 240, 147, 240, 131, 240, 113, 18,  240, 113, 19,  240, 81,  35,  240, 81,  50,  240,
    81,  51,  240, 49,  67,  240, 49,  82,  240, 49,  83,  240, 17,  99,  240, 17,  114, 240, 17,  115, 225, 146, 236, 225, 147, 193, 178,
    193, 179, 161, 195, 161, 210, 161, 211, 130, 211, 102, 152, 0,   29,  80,  52,  23,  0,   5,   110, 194, 131, 162, 163, 130, 163, 130,
    179, 114, 179, 114, 179, 114, 179, 114, 163, 130, 147, 146, 130, 188, 178, 147, 146, 163, 130, 179, 114, 195, 98,  195, 98,  195, 98,
    195, 98,  195, 98,  179, 114, 163, 130, 147, 111, 0,   26,  112, 57,  23,  0,   6,   102, 81,  147, 82,  49,  130, 145, 18,  99,  179,
    98,  195, 82,  226, 67,  226, 67,  241, 66,  240, 17,  51,  240, 83,  240, 83,  240, 83,  240, 83,  240, 83,  240, 98,  240, 17,  67,
    241, 67,  241, 83,  209, 99,  209, 115, 177, 147, 145, 195, 82,  246, 0,   27,  53,  25,  0,   6,   46,  226, 132, 178, 163, 162, 179,
    146, 195, 130, 210, 130, 211, 114, 211, 114, 227, 98,  227, 98,  227, 98,  227, 98,  227, 98,  227, 98,  227, 98,  227, 98,  226, 114,
    211, 114, 210, 130, 195, 130, 179, 146, 163, 162, 132, 143, 0,   29,  48,  56,  23,  0,   5,   111, 3,   130, 163, 130, 193, 130, 194,
    114, 209, 114, 209, 114, 209, 114, 113, 81,  114, 113, 210, 113, 210, 98,  218, 210, 98,  210, 113, 210, 113, 210, 113, 97,  98,  225,
    98,  225, 98,  209, 114, 209, 114, 209, 114, 194, 114, 164, 79,  4,   0,   26,  48,  53,  22,  240, 240, 239, 3,   114, 163, 114, 178,
    114, 193, 114, 193, 114, 193, 114, 209, 98,  209, 98,  113, 194, 113, 194, 113, 194, 98,  202, 194, 98,  194, 113, 194, 113, 194, 113,
    194, 240, 82,  240, 82,  240, 82,  240, 82,  240, 82,  240, 41,  0,   26,  48,  60,  25,  0,   7,   53,  81,  179, 82,  49,  162, 145,
    33,  146, 179, 130, 210, 115, 210, 99,  241, 99,  241, 98,  240, 17,  83,  240, 17,  83,  240, 115, 240, 115, 240, 115, 240, 115, 240,
    115, 184, 67,  226, 99,  226, 115, 210, 115, 210, 131, 194, 147, 163, 179, 113, 33,  216, 49,  0,   28,  96,  54,  23,  0,   5,   104,
    72,  98,  162, 146, 162, 146, 162, 146, 162, 146, 162, 146, 162, 146, 162, 146, 162, 146, 162, 146, 162, 158, 146, 162, 146, 162, 146,
    162, 146, 162, 146, 162, 146, 162, 146, 162, 146, 162, 146, 162, 146, 162, 146, 162, 104, 72,  0,   26,  32,  30,  11,  240, 120, 98,
    146, 146, 146, 146, 146, 146, 146, 146, 146, 146, 146, 146, 146, 146, 146, 146, 146, 146, 146, 146, 146, 104, 0,   12,  96,  35,  15,
    240, 240, 87,  178, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 210, 83,  82,  83,  82,  83,  66,
    113, 66,  149, 0,   17,  112, 61,  25,  0,   6,   40,  134, 98,  195, 130, 193, 162, 177, 178, 161, 194, 145, 210, 129, 226, 113, 242,
    97,  240, 18,  81,  240, 34,  67,  240, 18,  49,  19,  242, 33,  50,  242, 17,  67,  227, 99,  210, 130, 210, 131, 194, 147, 178, 162,
    178, 163, 162, 178, 162, 179, 146, 195, 88,  119, 0,   28,  64,  53,  20,  240, 240, 169, 226, 240, 50,  240, 50,  240, 50,  240, 50,
    240, 50,  240, 50,  240, 50,  240, 50,  240, 50,  240, 50,  240, 50,  240, 50,  240, 50,  240, 50,  240, 50,  177, 98,  177, 98,  177,
    98,  177, 98,  162, 98,  147, 98,  131, 79,  1,   0,   23,  93,  29,  0,   7,   38,  245, 99,  227, 145, 18,  193, 18,  145, 18,  193,
    18,  145, 18,  193, 18,  145, 34,  161, 34,  145, 34,  161, 34,  145, 34,  161, 34,  145, 50,  129, 50,  145, 50,  129, 50,  145, 50,
    129, 50,  145, 66,  97,  66,  145, 66,  97,  66,  145, 67,  65,  82,  145, 82,  65,  82,  145, 82,  65,  82,  145, 98,  33,  98,  145,
    98,  33,  98,  145, 98,  33,  98,  145, 115, 114, 145, 115, 114, 145, 115, 114, 131, 113, 130, 103, 81,  88,  0,   33,  72,  25,  0,
    6,   38,  151, 100, 163, 129, 18,  177, 145, 19,  161, 145, 35,  145, 145, 35,  145, 145, 51,  129, 145, 66,  129, 145, 67,  113, 145,
    83,  97,  145, 98,  97,  145, 99,  81,  145, 115, 65,  145, 130, 65,  145, 131, 49,  145, 146, 49,  145, 147, 33,  145, 163, 17,  145,
    178, 17,  145, 180, 145, 195, 145, 210, 131, 194, 103, 177, 0,   28,  112, 63,  25,  0,   7,   38,  240, 35,  67,  211, 131, 163, 163,
    131, 195, 114, 226, 99,  227, 83,  227, 82,  240, 19,  51,  240, 19,  51,  240, 19,  51,  240, 19,  51,  240, 19,  51,  240, 19,  51,
    240, 19,  51,  240, 19,  67,  227, 83,  227, 99,  210, 115, 195, 131, 163, 163, 131, 211, 67,  240, 38,  0,   29,  64,  52,  22,  240,
    240, 238, 178, 131, 146, 162, 130, 163, 114, 179, 98,  179, 98,  179, 98,  179, 98,  179, 98,  163, 114, 162, 130, 131, 155, 178, 240,
    82,  240, 82,  240, 82,  240, 82,  240, 82,  240, 82,  240, 82,  240, 82,  240, 82,  240, 40,  0,   26,  64,  86,  25,  0,   7,   38,
    240, 35,  67,  211, 131, 163, 163, 146, 195, 114, 211, 99,  227, 83,  227, 82,  240, 18,  67,  240, 19,  51,  240, 19,  51,  240, 19,
    51,  240, 19,  51,  240, 19,  51,  240, 19,  51,  240, 19,  67,  242, 83,  227, 98,  226, 115, 68,  67,  131, 34,  49,  50,  163, 17,
    65,  33,  227, 82,  240, 39,  240, 145, 97,  240, 34,  81,  240, 49,  81,  240, 50,  50,  240, 54,  240, 70,  240, 84,  0,   6,   112,
    56,  25,  0,   6,   45,  242, 115, 210, 146, 194, 147, 178, 163, 162, 163, 162, 163, 162, 163, 162, 163, 162, 147, 178, 146, 194, 115,
    217, 240, 18,  114, 226, 130, 210, 146, 194, 146, 194, 146, 194, 147, 178, 147, 178, 147, 178, 147, 65,  98,  163, 34,  56,  133, 0,
    28,  80,  52,  18,  240, 240, 165, 65,  99,  66,  33,  82,  131, 82,  146, 66,  162, 66,  177, 66,  177, 67,  161, 67,  240, 20,  246,
    216, 215, 244, 240, 18,  240, 19,  49,  194, 49,  194, 49,  194, 50,  178, 50,  162, 67,  146, 65,  34,  83,  81,  70,  0,   21,  16,
    61,  25,  0,   6,   63,  5,   82,  114, 99,  81,  130, 129, 81,  130, 129, 65,  146, 129, 65,  146, 129, 65,  146, 145, 49,  146, 145,
    210, 240, 130, 240, 130, 240, 130, 240, 130, 240, 130, 240, 130, 240, 130, 240, 130, 240, 130, 240, 130, 240, 130, 240, 130, 240, 130,
    240, 130, 240, 74,  0,   29,  32,  55,  24,  0,   6,   8,   103, 98,  179, 130, 193, 146, 193, 146, 193, 146, 193, 146, 193, 146, 193,
    146, 193, 146, 193, 146, 193, 146, 193, 146, 193, 146, 193, 146, 193, 146, 193, 146, 193, 146, 193, 146, 193, 162, 161, 178, 146, 194,
    129, 226, 82,  240, 37,  0,   28,  48,  64,  27,  0,   6,   103, 182, 83,  242, 131, 225, 147, 225, 162, 209, 179, 193, 194, 177, 211,
    161, 211, 161, 226, 145, 243, 129, 240, 18,  113, 240, 34,  113, 240, 35,  97,  240, 50,  81,  240, 67,  65,  240, 82,  49,  240, 98,
    49,  240, 99,  33,  240, 114, 17,  240, 132, 240, 146, 240, 162, 240, 162, 0,   32,  16,  98,  36,  0,   9,   7,   103, 118, 83,  163,
    178, 130, 178, 177, 146, 178, 177, 147, 163, 161, 162, 145, 18,  145, 178, 145, 18,  145, 179, 129, 19,  129, 194, 113, 50,  113, 210,
    113, 50,  113, 211, 97,  51,  97,  226, 81,  82,  81,  242, 81,  82,  81,  243, 65,  83,  65,  240, 18,  49,  114, 49,  240, 34,  49,
    114, 49,  240, 35,  33,  115, 33,  240, 50,  17,  146, 17,  240, 66,  17,  146, 17,  240, 68,  148, 240, 82,  178, 240, 98,  178, 240,
    98,  178, 240, 240, 65,  0,   42,  16,  65,  27,  0,   6,   104, 135, 116, 163, 179, 162, 210, 161, 227, 129, 240, 19,  97,  240, 51,
    81,  240, 66,  65,  240, 83,  33,  240, 115, 17,  240, 131, 240, 147, 240, 148, 240, 129, 19,  240, 97,  50,  240, 81,  67,  240, 49,
    99,  240, 33,  115, 241, 131, 225, 163, 194, 179, 177, 210, 162, 211, 102, 168, 0,   30,  96,  61,  27,  0,   6,   104, 166, 99,  211,
    131, 225, 163, 193, 194, 177, 211, 161, 227, 129, 240, 18,  113, 240, 35,  97,  240, 50,  81,  240, 82,  49,  240, 99,  33,  240, 114,
    17,  240, 132, 240, 146, 240, 162, 240, 162, 240, 162, 240, 162, 240, 162, 240, 162, 240, 162, 240, 162, 240, 120, 0,   31,  96,  56,
    20,  240, 240, 175, 2,   52,  163, 51,  163, 66,  178, 81,  179, 81,  163, 97,  162, 113, 147, 240, 19,  240, 34,  240, 35,  240, 19,
    240, 34,  240, 35,  240, 34,  240, 34,  145, 115, 145, 114, 161, 98,  177, 83,  177, 82,  178, 66,  179, 51,  164, 63,  2,   0,   22,
    112, 38,  7,   4,   49,  97,  97,  97,  97,  97,  97,  97,  97,  97,  97,  97,  97,  97,  97,  97,  97,  97,  97,  97,  97,  97,  97,
    97,  97,  97,  97,  97,  97,  97,  97,  97,  97,  100, 48,  25,  14,  240, 240, 225, 97,  81,  97,  97,  97,  81,  97,  97,  97,  97,
    97,  100, 51,  68,  52,  66,  82,  0,   40,  96,  38,  7,   4,   97,  97,  97,  97,  97,  97,  97,  97,  97,  97,  97,  97,  97,  97,
    97,  97,  97,  97,  97,  97,  97,  97,  97,  97,  97,  97,  97,  97,  97,  97,  97,  97,  97,  52,  48,  15,  12,  240, 209, 161, 17,
    129, 49,  97,  81,  65,  113, 0,   42,  48,  9,   6,   240, 51,  51,  51,  0,   22,  16,  15,  7,   240, 129, 81,  97,  81,  97,  97,
    99,  68,  66,  0,   20,  80,  40,  18,  0,   25,  22,  177, 83,  130, 99,  115, 98,  114, 114, 240, 18,  198, 147, 66,  115, 98,  114,
    114, 98,  130, 33,  50,  130, 33,  50,  115, 33,  66,  81,  18,  33,  86,  51,  0,   20,  96,  57,  19,  240, 240, 132, 240, 34,  240,
    34,  240, 34,  240, 34,  240, 34,  240, 34,  240, 34,  240, 34,  240, 34,  53,  146, 18,  66,  131, 114, 114, 146, 98,  161, 98,  162,
    82,  162, 82,  162, 82,  162, 82,  162, 82,  161, 98,  146, 99,  114, 113, 33,  82,  129, 53,  0,   22,  48,  29,  16,  0,   22,  85,
    146, 82,  98,  129, 66,  115, 65,  131, 50,  226, 226, 226, 226, 242, 226, 145, 82,  113, 114, 81,  165, 0,   18,  96,  56,  19,  0,
    5,   117, 240, 34,  240, 34,  240, 34,  240, 34,  240, 34,  240, 34,  240, 34,  240, 34,  165, 34,  130, 81,  18,  114, 115, 98,  146,
    97,  162, 82,  162, 82,  162, 82,  162, 82,  162, 82,  162, 97,  162, 98,  146, 114, 115, 130, 66,  20,  117, 52,  0,   21,  96,  30,
    16,  0,   22,  69,  161, 82,  113, 114, 81,  145, 81,  146, 50,  146, 61,  50,  226, 226, 241, 242, 145, 82,  113, 114, 81,  165, 0,
    18,  96,  34,  13,  240, 67,  146, 33,  114, 34,  98,  50,  98,  178, 178, 178, 178, 178, 137, 114, 178, 178, 178, 178, 178, 178, 178,
    178, 178, 178, 178, 178, 151, 0,   15,  32,  49,  18,  0,   25,  36,  37,  82,  66,  50,  81,  97,  146, 98,  130, 98,  130, 98,  130,
    98,  145, 82,  162, 66,  145, 36,  177, 240, 33,  240, 34,  240, 41,  171, 82,  131, 66,  178, 50,  178, 50,  178, 66,  146, 98,  99,
    151, 240, 240, 208, 56,  18,  240, 240, 100, 240, 18,  240, 18,  240, 18,  240, 18,  240, 18,  240, 18,  240, 18,  240, 18,  240, 18,
    52,  146, 17,  66,  131, 98,  115, 98,  114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114,
    114, 86,  54,  0,   20,  80,  26,  9,   240, 211, 99,  99,  0,   6,   36,  114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114,
    114, 86,  0,   10,  64,  36,  11,  240, 240, 131, 131, 131, 0,   7,   100, 146, 146, 146, 146, 146, 146, 146, 146, 146, 146, 146, 146,
    146, 146, 146, 146, 146, 51,  50,  51,  49,  66,  50,  85,  240, 192, 55,  18,  240, 240, 100, 240, 18,  240, 18,  240, 18,  240, 18,
    240, 18,  240, 18,  240, 18,  240, 18,  240, 18,  86,  82,  98,  130, 97,  146, 81,  162, 65,  178, 49,  194, 19,  195, 34,  178, 66,
    162, 67,  146, 82,  146, 98,  130, 99,  114, 115, 70,  69,  0,   20,  80,  30,  9,   240, 52,  114, 114, 114, 114, 114, 114, 114, 114,
    114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 86,  0,   10,  64,  54,  27,  0,   37,  35,  37,  84,  116, 17,
    66,  33,  66,  131, 99,  98,  115, 99,  98,  114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114,
    114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 86,  54,  54,  0,   30,  96,  38,  18,  0,   24,  115, 37,  116, 17,  66,
    131, 98,  115, 98,  114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 86,  54,  0,
    20,  80,  35,  17,  0,   24,  4,   178, 66,  129, 129, 98,  130, 81,  161, 66,  162, 50,  162, 50,  162, 50,  162, 50,  162, 65,  161,
    82,  130, 97,  129, 130, 66,  165, 0,   20,  16,  51,  19,  0,   26,  20,  53,  116, 18,  66,  131, 114, 114, 146, 98,  146, 98,  162,
    82,  162, 82,  162, 82,  162, 82,  162, 82,  146, 98,  146, 99,  114, 114, 17,  82,  130, 37,  162, 240, 34,  240, 34,  240, 34,  240,
    34,  240, 34,  247, 0,   6,   32,  53,  19,  0,   26,  100, 65,  130, 66,  33,  114, 113, 17,  98,  131, 98,  146, 82,  162, 82,  162,
    82,  162, 82,  162, 82,  162, 98,  146, 98,  146, 114, 115, 130, 66,  18,  149, 50,  240, 34,  240, 34,  240, 34,  240, 34,  240, 34,
    240, 34,  231, 240, 240, 176, 26,  13,  0,   18,  3,   35,  68,  17,  34,  83,  50,  83,  162, 178, 178, 178, 178, 178, 178, 178, 178,
    178, 151, 0,   15,  48,  33,  14,  0,   19,  84,  33,  82,  67,  66,  98,  66,  113, 66,  113, 68,  183, 151, 180, 49,  115, 49,  130,
    50,  114, 50,  114, 51,  82,  65,  37,  0,   16,  64,  35,  14,  0,   7,   65,  209, 209, 209, 194, 194, 179, 154, 114, 194, 194, 194,
    194, 194, 194, 194, 81,  98,  81,  98,  81,  98,  81,  98,  81,  114, 49,  148, 0,   16,  48,  38,  18,  0,   24,  100, 84,  114, 114,
    114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 99,  114, 99,  130, 65,  20,  117, 36,
    0,   20,  80,  37,  19,  0,   26,  22,  85,  82,  130, 130, 113, 146, 113, 146, 113, 162, 81,  178, 81,  194, 49,  210, 49,  210, 49,
    226, 17,  242, 17,  240, 18,  240, 34,  240, 33,  0,   22,  96,  55,  25,  0,   34,  54,  38,  68,  82,  98,  114, 98,  113, 113, 114,
    114, 97,  130, 83,  81,  146, 81,  17,  81,  146, 65,  34,  65,  162, 49,  34,  49,  178, 33,  65,  49,  194, 17,  66,  33,  194, 17,
    66,  17,  211, 97,  17,  226, 98,  242, 98,  241, 129, 0,   29,  32,  38,  20,  0,   27,  70,  85,  114, 114, 147, 97,  178, 81,  210,
    49,  242, 17,  240, 34,  240, 51,  240, 35,  240, 17,  34,  225, 66,  193, 98,  177, 99,  131, 115, 85,  102, 0,   22,  112, 50,  19,
    0,   26,  22,  85,  82,  130, 129, 129, 146, 113, 146, 97,  178, 81,  178, 81,  193, 65,  210, 49,  210, 33,  242, 17,  242, 17,  240,
    18,  240, 34,  240, 33,  240, 49,  240, 49,  240, 33,  194, 65,  194, 49,  209, 50,  227, 0,   6,   80,  32,  15,  0,   20,  92,  50,
    114, 65,  130, 65,  114, 81,  98,  97,  82,  210, 194, 194, 194, 97,  97,  113, 82,  113, 66,  129, 65,  115, 60,  0,   17,  32,  9,
    20,  0,   40,  15,  2,   0,   45,  48,  10,  36,  0,   72,  15,  15,  3,   0,   81,  48,  18,  13,  240, 210, 66,  82,  66,  66,  66,
    81,  81,  82,  66,  81,  81,  0,   44,  80,  14,  14,  240, 240, 227, 81,  65,  35,  33,  65,  83,  0,   51,  48,
};

//*****************************************************************************
//
// The font definition for the 36 point Cm font.
//
//*****************************************************************************
const tFont g_sFontCm36 = {
    //
    // The format of the font.
    //
    FONT_FMT_PIXEL_RLE,

    //
    // The maximum width of the font.
    //
    32,

    //
    // The height of the font.
    //
    35,

    //
    // The baseline of the font.
    //
    26,

    //
    // The offset to each character in the font.
    //
    {
     0,    5,    33,   57,   152,  219,  307,  383,  397,  435,  473,  505,  554,  570,  579,  589,  627,  678,  708,
     748,  790,  838,  880,  929,  964,  1013, 1063, 1078, 1099, 1127, 1140, 1176, 1212, 1299, 1365, 1417, 1474, 1527,
     1583, 1636, 1696, 1750, 1780, 1815, 1876, 1929, 2022, 2094, 2157, 2209, 2295, 2351, 2403, 2464, 2519, 2583, 2681,
     2746, 2807, 2863, 2901, 2926, 2964, 2979, 2988, 3003, 3043, 3100, 3129, 3185, 3215, 3249, 3298, 3354, 3380, 3416,
     3471, 3501, 3555, 3593, 3628, 3679, 3732, 3758, 3791, 3826, 3864, 3901, 3956, 3994, 4044, 4076, 4085, 4095, 4113,
     },

    //
    // A pointer to the actual font data
    //
    g_pui8Cm36Data
};

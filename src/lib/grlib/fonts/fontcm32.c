//*****************************************************************************
//
// fontcm32.c - Font definition for the 32pt Cm font.
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
//     Size: 32 point
//     Bold: no
//     Italic: no
//     Memory usage: 3972 bytes
//
//*****************************************************************************

//*****************************************************************************
//
// The compressed data for the 32 point Cm font.
// Contains characters 32 to 126 inclusive.
//
//*****************************************************************************
static const uint8_t g_pui8Cm32Data[3769] = {
    5,   13,  0,   53,  80,  27,  6,   195, 51,  51,  51,  51,  51,  51,  51,  50,  81,  81,  81,  81,  81,  81,  81,  81,  81,  240, 19,
    51,  51,  0,   6,   48,  25,  13,  240, 240, 162, 66,  68,  51,  67,  51,  97,  81,  97,  81,  97,  81,  81,  81,  97,  81,  81,  81,
    0,   34,  96,  86,  25,  0,   10,  82,  82,  240, 17,  97,  240, 33,  97,  240, 33,  97,  240, 18,  82,  240, 17,  97,  240, 33,  97,
    240, 33,  97,  240, 18,  82,  240, 17,  97,  240, 33,  97,  159, 7,   161, 97,  240, 33,  97,  240, 33,  97,  240, 33,  97,  175, 7,
    145, 97,  240, 33,  97,  240, 18,  82,  240, 17,  97,  240, 33,  97,  240, 33,  97,  240, 18,  82,  240, 17,  97,  240, 33,  97,  240,
    33,  97,  240, 18,  82,  0,   7,   112, 62,  16,  97,  241, 214, 130, 33,  34,  98,  49,  65,  82,  49,  66,  50,  65,  81,  50,  65,
    51,  50,  65,  51,  50,  65,  147, 49,  163, 33,  182, 183, 197, 177, 35,  161, 51,  145, 66,  51,  49,  66,  51,  49,  66,  49,  81,
    66,  50,  65,  65,  81,  65,  50,  98,  33,  34,  134, 209, 241, 0,   13,  16,  85,  25,  51,  193, 130, 33,  177, 114, 66,  130, 113,
    83,  83,  114, 97,  21,  17,  130, 97,  113, 130, 97,  97,  146, 97,  97,  146, 97,  81,  162, 97,  65,  193, 81,  81,  194, 65,  65,
    226, 33,  66,  240, 18,  81,  240, 129, 84,  241, 66,  49,  209, 81,  65,  194, 66,  81,  177, 82,  81,  161, 98,  81,  146, 98,  81,
    145, 114, 81,  130, 114, 81,  114, 145, 81,  113, 162, 49,  114, 177, 34,  113, 211, 0,   19,  48,  72,  24,  0,   6,   99,  240, 82,
    18,  240, 65,  49,  240, 50,  49,  240, 50,  49,  240, 50,  49,  240, 50,  33,  240, 66,  33,  240, 81,  17,  240, 99,  118, 130, 147,
    162, 161, 161, 18,  129, 161, 49,  113, 161, 66,  97,  145, 97,  81,  161, 98,  49,  162, 114, 33,  162, 114, 17,  178, 130, 129, 66,
    115, 98,  82,  66,  35,  50,  117, 100, 0,   24,  96,  14,  7,   240, 114, 68,  67,  97,  97,  97,  81,  97,  81,  0,   19,  36,  10,
    97,  129, 145, 129, 129, 145, 130, 129, 130, 130, 130, 114, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 146, 130, 130, 130, 146,
    130, 146, 145, 146, 145, 161, 48,  36,  10,  1,   161, 146, 145, 161, 146, 130, 146, 130, 130, 131, 130, 130, 130, 130, 130, 130, 130,
    130, 130, 130, 130, 129, 130, 130, 129, 130, 129, 145, 129, 129, 145, 129, 144, 30,  14,  81,  209, 209, 209, 65,  50,  49,  50,  81,
    33,  33,  133, 177, 181, 129, 33,  33,  82,  49,  50,  49,  65,  209, 209, 209, 0,   32,  64,  47,  23,  0,   18,  50,  240, 98,  240,
    98,  240, 98,  240, 98,  240, 98,  240, 98,  240, 98,  240, 98,  240, 98,  240, 98,  207, 5,   194, 240, 98,  240, 98,  240, 98,  240,
    98,  240, 98,  240, 98,  240, 98,  240, 98,  0,   18,  96,  15,  6,   0,   16,  66,  67,  51,  81,  81,  81,  65,  81,  65,  240, 32,
    8,   11,  0,   24,  104, 0,   19,  80,  10,  6,   0,   16,  67,  51,  51,  0,   6,   48,  36,  15,  177, 210, 209, 225, 210, 209, 225,
    210, 209, 225, 210, 209, 225, 210, 209, 225, 210, 209, 225, 210, 209, 225, 210, 209, 225, 210, 209, 225, 210, 209, 225, 210, 209, 224,
    49,  15,  0,   6,   20,  146, 66,  113, 97,  98,  98,  81,  129, 66,  130, 50,  130, 50,  130, 50,  130, 50,  130, 50,  130, 50,  130,
    50,  130, 50,  130, 50,  130, 50,  130, 50,  130, 66,  113, 82,  98,  97,  97,  114, 66,  148, 0,   15,  112, 30,  13,  240, 240, 225,
    178, 163, 115, 18,  178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 122, 0,   13,  48,  39,  15,
    0,   6,   21,  130, 51,  97,  114, 81,  114, 65,  146, 51,  114, 51,  114, 51,  114, 210, 194, 210, 194, 209, 209, 209, 209, 209, 209,
    113, 81,  129, 65,  145, 74,  75,  0,   15,  64,  39,  15,  0,   6,   21,  130, 66,  97,  114, 83,  82,  83,  82,  83,  82,  210, 210,
    194, 209, 164, 242, 226, 210, 226, 210, 66,  114, 51,  114, 51,  114, 65,  114, 97,  82,  134, 0,   15,  96,  41,  16,  0,   7,   17,
    226, 226, 211, 193, 18,  193, 18,  177, 34,  161, 50,  161, 50,  145, 66,  145, 66,  129, 82,  113, 98,  113, 98,  97,  114, 97,  114,
    109, 178, 226, 226, 226, 184, 0,   16,  48,  40,  15,  0,   5,   113, 113, 99,  65,  119, 134, 145, 225, 225, 225, 225, 36,  129, 17,
    50,  114, 82,  210, 226, 210, 210, 210, 66,  114, 51,  114, 49,  145, 81,  114, 98,  66,  133, 0,   15,  112, 47,  15,  0,   6,   52,
    146, 65,  113, 97,  98,  82,  97,  98,  82,  209, 225, 210, 36,  114, 17,  66,  83,  98,  67,  113, 66,  130, 50,  130, 50,  130, 50,
    130, 65,  130, 65,  130, 66,  113, 97,  98,  98,  66,  148, 0,   15,  112, 32,  16,  0,   6,   17,  252, 75,  65,  161, 65,  145, 81,
    129, 241, 225, 225, 241, 225, 241, 241, 225, 241, 241, 226, 226, 226, 226, 226, 226, 0,   17,  32,  47,  17,  0,   7,   5,   162, 66,
    129, 114, 113, 130, 82,  130, 82,  130, 98,  114, 99,  82,  131, 50,  165, 212, 193, 36,  130, 83,  98,  115, 81,  147, 50,  162, 50,
    162, 50,  162, 51,  145, 82,  130, 99,  81,  166, 0,   17,  112, 47,  15,  0,   6,   20,  146, 65,  129, 97,  98,  98,  81,  129, 66,
    129, 66,  130, 50,  130, 50,  130, 50,  130, 50,  130, 66,  99,  66,  81,  18,  82,  65,  18,  116, 34,  209, 210, 210, 82,  97,  98,
    81,  113, 81,  149, 0,   16,  15,  6,   0,   8,   35,  51,  51,  0,   6,   51,  51,  51,  0,   6,   48,  20,  6,   0,   8,   35,  51,
    51,  0,   6,   50,  67,  51,  81,  81,  81,  65,  81,  65,  240, 32,  27,  6,   0,   6,   3,   51,  51,  240, 113, 81,  81,  81,  81,
    81,  81,  81,  81,  82,  51,  51,  51,  51,  51,  51,  51,  51,  144, 13,  23,  0,   40,  47,  5,   0,   11,  127, 5,   0,   37,  96,
    33,  14,  0,   14,  67,  179, 179, 0,   6,   97,  209, 209, 209, 209, 193, 209, 193, 209, 193, 193, 194, 194, 114, 50,  114, 50,  129,
    66,  82,  102, 240, 240, 64,  35,  14,  240, 240, 21,  129, 82,  81,  114, 49,  130, 50,  114, 50,  114, 194, 178, 193, 193, 194, 193,
    209, 193, 209, 209, 209, 209, 240, 240, 163, 179, 179, 0,   14,  112, 80,  24,  0,   7,   6,   243, 83,  194, 146, 161, 209, 129, 85,
    81,  113, 66,  50,  66,  81,  66,  97,  65,  81,  50,  130, 33,  65,  66,  130, 49,  49,  50,  146, 49,  49,  50,  146, 49,  49,  50,
    146, 49,  49,  50,  146, 49,  49,  50,  146, 49,  49,  66,  130, 49,  65,  50,  115, 49,  65,  66,  99,  49,  81,  66,  50,  18,  33,
    97,  84,  67,  129, 240, 146, 210, 131, 116, 200, 0,   25,  16,  57,  23,  0,   7,   1,   240, 98,  240, 98,  240, 84,  240, 65,  18,
    240, 49,  34,  240, 49,  50,  240, 33,  50,  240, 17,  66,  240, 17,  82,  241, 82,  225, 98,  225, 114, 209, 114, 219, 177, 146, 177,
    146, 161, 163, 145, 178, 145, 178, 129, 195, 114, 194, 85,  150, 0,   23,  48,  48,  21,  0,   7,   126, 162, 130, 146, 146, 130, 162,
    114, 162, 114, 162, 114, 162, 114, 162, 114, 146, 130, 114, 172, 146, 131, 130, 162, 114, 162, 114, 178, 98,  178, 98,  178, 98,  178,
    98,  162, 114, 162, 114, 131, 94,  0,   21,  112, 51,  21,  0,   8,   102, 65,  131, 81,  49,  114, 129, 18,  98,  163, 82,  194, 66,
    210, 66,  225, 65,  241, 50,  241, 50,  240, 66,  240, 66,  240, 66,  240, 66,  240, 81,  241, 66,  225, 66,  225, 82,  193, 114, 177,
    130, 145, 163, 82,  214, 0,   22,  49,  23,  0,   8,   94,  194, 130, 178, 162, 146, 178, 130, 178, 130, 194, 114, 194, 114, 210, 98,
    210, 98,  210, 98,  210, 98,  210, 98,  210, 98,  210, 98,  210, 98,  194, 114, 194, 114, 193, 130, 178, 130, 162, 146, 130, 141, 0,
    24,  32,  50,  21,  0,   7,   127, 2,   114, 147, 114, 162, 114, 177, 114, 177, 114, 177, 114, 97,  194, 97,  194, 97,  194, 82,  201,
    194, 82,  194, 97,  194, 97,  194, 97,  194, 193, 98,  193, 98,  193, 98,  178, 98,  177, 114, 147, 79,  2,   0,   21,  64,  48,  20,
    0,   7,   79,  1,   114, 147, 98,  162, 98,  177, 98,  177, 98,  177, 98,  97,  178, 97,  178, 97,  178, 82,  185, 178, 82,  178, 97,
    178, 97,  178, 97,  178, 240, 50,  240, 50,  240, 50,  240, 50,  240, 50,  248, 0,   21,  64,  53,  23,  0,   9,   70,  65,  163, 82,
    33,  146, 132, 130, 163, 114, 194, 98,  225, 98,  225, 97,  241, 82,  240, 98,  240, 98,  240, 98,  240, 98,  240, 98,  168, 66,  210,
    98,  210, 98,  210, 114, 194, 130, 178, 146, 147, 163, 97,  33,  199, 49,  0,   23,  80,  50,  23,  0,   8,   88,  72,  98,  162, 146,
    162, 146, 162, 146, 162, 146, 162, 146, 162, 146, 162, 146, 162, 146, 162, 158, 146, 162, 146, 162, 146, 162, 146, 162, 146, 162, 146,
    162, 146, 162, 146, 162, 146, 162, 146, 162, 104, 72,  0,   23,  48,  29,  11,  240, 240, 56,  98,  146, 146, 146, 146, 146, 146, 146,
    146, 146, 146, 146, 146, 146, 146, 146, 146, 146, 146, 146, 104, 0,   11,  48,  32,  14,  0,   5,   103, 162, 194, 194, 194, 194, 194,
    194, 194, 194, 194, 194, 194, 194, 194, 194, 194, 83,  66,  83,  66,  83,  65,  113, 66,  132, 0,   15,  54,  24,  0,   9,   8,   117,
    114, 178, 146, 177, 162, 161, 178, 145, 194, 129, 210, 113, 226, 97,  242, 81,  240, 18,  66,  240, 18,  37,  242, 17,  50,  243, 82,
    226, 99,  210, 114, 210, 130, 194, 131, 178, 146, 178, 162, 162, 163, 146, 179, 88,  103, 0,   24,  48,  49,  19,  0,   7,   24,  226,
    240, 34,  240, 34,  240, 34,  240, 34,  240, 34,  240, 34,  240, 34,  240, 34,  240, 34,  240, 34,  240, 34,  240, 34,  240, 34,  161,
    98,  161, 98,  161, 98,  161, 98,  146, 98,  146, 98,  115, 79,  0,   19,  64,  87,  28,  0,   10,  70,  229, 99,  211, 145, 18,  177,
    18,  145, 18,  177, 18,  145, 18,  177, 18,  145, 34,  145, 34,  145, 34,  145, 34,  145, 34,  145, 34,  145, 50,  113, 50,  145, 50,
    113, 50,  145, 50,  97,  66,  145, 66,  81,  66,  145, 66,  81,  66,  145, 82,  49,  82,  145, 82,  49,  82,  145, 82,  49,  82,  145,
    98,  17,  98,  145, 98,  17,  98,  145, 98,  17,  98,  145, 114, 114, 131, 98,  114, 103, 168, 0,   28,  48,  66,  23,  0,   8,   86,
    134, 99,  147, 129, 18,  145, 145, 19,  129, 145, 34,  129, 145, 35,  113, 145, 50,  113, 145, 66,  97,  145, 66,  97,  145, 82,  81,
    145, 83,  65,  145, 98,  65,  145, 114, 49,  145, 114, 49,  145, 130, 33,  145, 131, 17,  145, 146, 17,  145, 148, 145, 163, 145, 178,
    131, 162, 102, 161, 0,   23,  96,  49,  22,  0,   9,   21,  242, 82,  193, 146, 145, 177, 130, 178, 98,  210, 82,  210, 81,  242, 50,
    242, 50,  242, 50,  242, 50,  242, 50,  242, 50,  242, 51,  226, 66,  210, 82,  210, 98,  178, 130, 161, 147, 130, 178, 82,  245, 0,
    23,  32,  47,  20,  0,   7,   77,  162, 115, 130, 146, 114, 161, 114, 162, 98,  162, 98,  162, 98,  162, 98,  161, 114, 146, 114, 115,
    138, 162, 240, 50,  240, 50,  240, 50,  240, 50,  240, 50,  240, 50,  240, 50,  240, 50,  248, 0,   21,  64,  70,  22,  0,   9,   22,
    226, 82,  194, 130, 146, 162, 114, 178, 98,  210, 82,  210, 81,  242, 50,  242, 50,  242, 50,  242, 50,  242, 50,  242, 50,  242, 50,
    242, 66,  210, 82,  210, 98,  67,  81,  129, 49,  49,  49,  161, 33,  65,  17,  195, 66,  246, 240, 113, 65,  240, 17,  65,  240, 17,
    65,  240, 18,  34,  240, 36,  240, 51,  0,   6,   16,  51,  24,  0,   9,   13,  226, 115, 194, 146, 178, 161, 178, 162, 162, 162, 162,
    162, 162, 161, 178, 146, 178, 114, 217, 242, 99,  210, 115, 194, 130, 194, 131, 178, 131, 178, 131, 178, 131, 178, 131, 178, 146, 65,
    98,  147, 34,  56,  117, 0,   24,  64,  47,  17,  0,   6,   117, 49,  98,  81,  33,  82,  115, 81,  146, 66,  161, 66,  161, 66,  161,
    67,  145, 83,  230, 216, 198, 243, 243, 49,  178, 49,  178, 49,  178, 49,  178, 50,  161, 67,  130, 65,  34,  82,  81,  69,  0,   17,
    112, 55,  23,  0,   8,   111, 3,   82,  98,  98,  81,  114, 113, 65,  130, 113, 65,  130, 129, 49,  130, 129, 49,  130, 129, 194, 240,
    98,  240, 98,  240, 98,  240, 98,  240, 98,  240, 98,  240, 98,  240, 98,  240, 98,  240, 98,  240, 98,  240, 98,  240, 98,  240, 42,
    0,   24,  51,  23,  0,   8,   87,  103, 98,  163, 130, 177, 146, 177, 146, 177, 146, 177, 146, 177, 146, 177, 146, 177, 146, 177, 146,
    177, 146, 177, 146, 177, 146, 177, 146, 177, 146, 177, 146, 177, 161, 161, 178, 145, 194, 113, 226, 66,  240, 36,  0,   24,  48,  58,
    25,  0,   9,   55,  165, 83,  210, 130, 209, 147, 193, 162, 177, 178, 177, 179, 161, 194, 145, 211, 129, 226, 113, 242, 113, 243, 97,
    240, 18,  81,  240, 35,  65,  240, 50,  49,  240, 66,  49,  240, 67,  33,  240, 82,  17,  240, 98,  17,  240, 114, 240, 130, 240, 130,
    0,   26,  80,  87,  33,  0,   12,  55,  86,  117, 83,  147, 146, 115, 147, 161, 130, 162, 145, 146, 147, 145, 147, 131, 145, 162, 113,
    34,  113, 178, 113, 34,  113, 179, 97,  34,  113, 194, 81,  66,  81,  210, 81,  66,  81,  211, 65,  66,  81,  226, 49,  98,  49,  242,
    49,  98,  49,  243, 33,  98,  49,  240, 18,  17,  115, 17,  240, 34,  17,  130, 17,  240, 36,  130, 17,  240, 51,  131, 240, 66,  162,
    240, 66,  162, 240, 81,  161, 0,   34,  64,  58,  24,  0,   9,   7,   118, 115, 146, 163, 145, 195, 113, 226, 113, 242, 81,  240, 19,
    49,  240, 50,  49,  240, 66,  17,  240, 83,  240, 115, 240, 99,  240, 81,  34,  240, 65,  35,  240, 33,  66,  240, 17,  98,  225, 115,
    209, 130, 193, 162, 161, 179, 131, 179, 86,  135, 0,   24,  48,  55,  25,  0,   9,   55,  165, 83,  210, 131, 193, 162, 177, 179, 145,
    211, 129, 226, 113, 243, 97,  240, 18,  81,  240, 50,  49,  240, 67,  33,  240, 82,  17,  240, 114, 240, 130, 240, 130, 240, 130, 240,
    130, 240, 130, 240, 130, 240, 130, 240, 130, 240, 88,  0,   26,  32,  44,  18,  0,   6,   111, 52,  131, 50,  162, 65,  162, 81,  147,
    81,  146, 97,  130, 243, 242, 242, 240, 18,  242, 242, 240, 18,  242, 240, 18,  129, 98,  145, 82,  161, 82,  161, 66,  162, 50,  148,
    63,  0,   18,  48,  35,  8,   133, 50,  98,  98,  98,  98,  98,  98,  98,  98,  98,  98,  98,  98,  98,  98,  98,  98,  98,  98,  98,
    98,  98,  98,  98,  98,  98,  98,  98,  98,  98,  101, 48,  23,  13,  240, 240, 177, 81,  81,  81,  81,  97,  81,  81,  97,  81,  99,
    51,  67,  52,  66,  66,  0,   36,  32,  35,  8,   133, 98,  98,  98,  98,  98,  98,  98,  98,  98,  98,  98,  98,  98,  98,  98,  98,
    98,  98,  98,  98,  98,  98,  98,  98,  98,  98,  98,  98,  98,  98,  53,  48,  14,  11,  240, 240, 97,  145, 18,  97,  65,  65,  97,
    0,   36,  16,  9,   6,   240, 51,  51,  51,  0,   20,  80,  14,  7,   240, 129, 81,  97,  81,  97,  99,  68,  66,  0,   19,  96,  38,
    17,  0,   23,  101, 177, 67,  129, 99,  114, 98,  114, 98,  182, 146, 66,  115, 82,  114, 98,  98,  114, 33,  50,  114, 33,  50,  99,
    33,  66,  65,  18,  33,  85,  51,  0,   17,  64,  45,  17,  0,   6,   52,  242, 242, 242, 242, 242, 242, 242, 242, 36,  146, 17,  66,
    115, 98,  98,  114, 98,  130, 82,  130, 82,  130, 82,  130, 82,  130, 82,  130, 82,  114, 99,  98,  97,  33,  66,  113, 52,  0,   17,
    112, 28,  14,  0,   19,  101, 130, 65,  97,  113, 66,  98,  50,  114, 50,  194, 194, 194, 194, 210, 113, 82,  81,  99,  65,  133, 0,
    14,  80,  45,  17,  0,   7,   52,  242, 242, 242, 242, 242, 242, 242, 148, 34,  114, 65,  18,  113, 99,  98,  114, 82,  130, 82,  130,
    82,  130, 82,  130, 82,  130, 82,  130, 98,  114, 98,  99,  114, 65,  20,  116, 36,  0,   17,  48,  28,  15,  0,   21,  21,  130, 66,
    98,  98,  81,  130, 50,  130, 60,  50,  210, 210, 225, 226, 129, 82,  97,  114, 65,  149, 0,   15,  96,  32,  13,  240, 240, 35,  130,
    34,  114, 34,  98,  178, 178, 178, 178, 178, 137, 114, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 151, 0,   13,  80,  48,
    17,  0,   21,  99,  52,  82,  51,  34,  81,  66,  146, 82,  130, 82,  130, 82,  130, 82,  145, 81,  162, 50,  145, 35,  177, 240, 17,
    240, 17,  240, 18,  240, 25,  114, 115, 66,  162, 50,  162, 50,  147, 67,  98,  135, 240, 240, 176, 52,  18,  0,   6,   100, 240, 18,
    240, 18,  240, 18,  240, 18,  240, 18,  240, 18,  240, 18,  240, 18,  37,  146, 17,  66,  131, 98,  115, 98,  114, 114, 114, 114, 114,
    114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 86,  54,  0,   18,  48,  25,  9,   240, 211, 99,  99,  0,   6,   36,
    114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 86,  0,   9,   48,  33,  10,  240, 240, 67,  115, 115, 0,   7,   4,   130,
    130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 50,  49,  65,  50,  84,  240, 160, 43,  17,  0,   6,   52,
    242, 242, 242, 242, 242, 242, 242, 242, 85,  82,  82,  130, 81,  146, 65,  162, 49,  178, 34,  178, 19,  179, 34,  162, 66,  146, 66,
    146, 82,  130, 98,  114, 99,  70,  53,  0,   17,  48,  28,  9,   240, 196, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114,
    114, 114, 114, 114, 114, 114, 114, 114, 86,  0,   9,   48,  51,  26,  0,   35,  115, 37,  68,  116, 17,  66,  33,  50,  131, 99,  82,
    115, 98,  98,  114, 114, 98,  114, 114, 98,  114, 114, 98,  114, 114, 98,  114, 114, 98,  114, 114, 98,  114, 114, 98,  114, 114, 98,
    114, 114, 98,  86,  54,  38,  0,   26,  48,  36,  18,  0,   24,  115, 37,  116, 17,  66,  131, 98,  115, 98,  114, 114, 114, 114, 114,
    114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 86,  54,  0,   18,  48,  33,  16,  0,   22,  69,  161, 67,  113, 114,
    82,  114, 66,  146, 50,  146, 50,  146, 50,  146, 50,  146, 50,  146, 66,  114, 82,  114, 99,  66,  149, 0,   16,  112, 43,  17,  0,
    23,  67,  36,  116, 17,  66,  115, 98,  98,  114, 98,  130, 82,  130, 82,  130, 82,  130, 82,  130, 82,  130, 82,  114, 99,  98,  98,
    17,  51,  114, 36,  146, 242, 242, 242, 242, 214, 240, 240, 240, 44,  17,  0,   23,  116, 49,  115, 49,  33,  99,  81,  17,  98,  114,
    82,  130, 82,  130, 82,  130, 82,  130, 82,  130, 82,  130, 98,  114, 98,  99,  115, 49,  18,  148, 34,  242, 242, 242, 242, 242, 214,
    240, 240, 112, 25,  12,  0,   16,  83,  34,  68,  17,  18,  83,  34,  82,  162, 162, 162, 162, 162, 162, 162, 162, 162, 134, 0,   12,
    96,  32,  13,  0,   18,  21,  17,  82,  66,  66,  97,  66,  97,  67,  81,  68,  182, 164, 65,  99,  49,  114, 49,  114, 50,  98,  51,
    66,  65,  37,  0,   13,  80,  32,  13,  0,   8,   81,  193, 193, 193, 178, 163, 137, 114, 178, 178, 178, 178, 178, 178, 178, 65,  98,
    65,  98,  65,  98,  65,  114, 33,  147, 0,   13,  80,  36,  18,  0,   24,  100, 84,  114, 114, 114, 114, 114, 114, 114, 114, 114, 114,
    114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 99,  130, 65,  20,  117, 36,  0,   18,  48,  33,  18,  0,   24,  102, 84,  82,
    129, 114, 129, 130, 97,  146, 97,  162, 65,  178, 65,  193, 49,  210, 33,  210, 33,  227, 243, 240, 17,  240, 33,  0,   19,  32,  51,
    23,  0,   31,  85,  38,  52,  67,  82,  98,  98,  97,  97,  114, 98,  81,  129, 83,  65,  146, 49,  33,  65,  146, 49,  34,  49,  161,
    49,  34,  33,  178, 17,  65,  33,  178, 17,  66,  17,  193, 17,  67,  210, 98,  210, 98,  225, 97,  0,   24,  16,  34,  18,  0,   24,
    101, 85,  83,  82,  146, 81,  178, 49,  210, 33,  210, 17,  242, 240, 19,  225, 34,  209, 49,  193, 66,  161, 98,  130, 99,  85,  85,
    0,   18,  48,  44,  18,  0,   24,  101, 85,  82,  114, 114, 113, 146, 97,  146, 81,  177, 81,  178, 65,  193, 49,  210, 33,  210, 17,
    243, 242, 240, 33,  240, 33,  240, 17,  240, 33,  240, 17,  194, 49,  193, 49,  227, 0,   6,   32,  29,  14,  0,   19,  43,  50,  113,
    65,  114, 65,  98,  81,  82,  193, 194, 178, 178, 193, 97,  82,  97,  66,  113, 65,  114, 59,  0,   14,  48,  8,   18,  0,   36,  15,
    0,   36,  48,  9,   33,  0,   66,  15,  15,  0,   66,  48,  17,  12,  240, 240, 130, 50,  82,  50,  66,  50,  81,  65,  81,  65,  0,
    38,  32,  14,  13,  0,   6,   99,  65,  65,  34,  33,  65,  67,  0,   42,  112,
};

//*****************************************************************************
//
// The font definition for the 32 point Cm font.
//
//*****************************************************************************
const tFont g_sFontCm32 = {
    //
    // The format of the font.
    //
    FONT_FMT_PIXEL_RLE,

    //
    // The maximum width of the font.
    //
    29,

    //
    // The height of the font.
    //
    33,

    //
    // The baseline of the font.
    //
    25,

    //
    // The offset to each character in the font.
    //
    {
     0,    5,    32,   57,   143,  205,  290,  362,  376,  412,  448,  478,  525,  540,  548,  558,  594,  643,  673,
     712,  751,  792,  832,  879,  911,  958,  1005, 1020, 1040, 1067, 1080, 1113, 1148, 1228, 1285, 1333, 1384, 1433,
     1483, 1531, 1584, 1634, 1663, 1695, 1749, 1798, 1885, 1951, 2000, 2047, 2117, 2168, 2215, 2270, 2321, 2379, 2466,
     2524, 2579, 2623, 2658, 2681, 2716, 2730, 2739, 2753, 2791, 2836, 2864, 2909, 2937, 2969, 3017, 3069, 3094, 3127,
     3170, 3198, 3249, 3285, 3318, 3361, 3405, 3430, 3462, 3494, 3530, 3563, 3614, 3648, 3692, 3721, 3729, 3738, 3755,
     },

    //
    // A pointer to the actual font data
    //
    g_pui8Cm32Data
};

//*****************************************************************************
//
// fontcm22b.c - Font definition for the 22pt Cm bold font.
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
//     Size: 22 point
//     Bold: yes
//     Italic: no
//     Memory usage: 2804 bytes
//
//*****************************************************************************

//*****************************************************************************
//
// The compressed data for the 22 point Cm bold font.
// Contains characters 32 to 126 inclusive.
//
//*****************************************************************************
static const uint8_t g_pui8Cm22bData[2601] = {
    4,   9,   0,   27,  21,  5,   83,  35,  35,  35,  35,  35,  35,  49,  65,  65,  65,  65,  145, 51,  35,  49,  240, 240, 48,  21,  11,
    240, 240, 66,  50,  52,  20,  36,  20,  51,  35,  81,  65,  65,  65,  65,  65,  0,   19,  96,  45,  18,  0,   7,   82,  50,  177, 65,
    193, 65,  178, 50,  178, 49,  193, 65,  111, 1,   114, 50,  177, 65,  193, 65,  193, 65,  178, 50,  127, 1,   97,  65,  193, 50,  178,
    50,  177, 65,  193, 65,  178, 50,  240, 240, 240, 42,  11,  65,  161, 133, 87,  66,  17,  34,  34,  33,  19,  34,  33,  19,  35,  17,
    19,  37,  118, 102, 117, 35,  17,  34,  35,  17,  34,  35,  17,  34,  34,  33,  33,  66,  17,  18,  85,  129, 0,   7,   80,  57,  18,
    240, 83,  129, 81,  35,  67,  66,  49,  22,  82,  49,  82,  82,  49,  66,  98,  49,  50,  114, 49,  49,  145, 49,  34,  145, 33,  34,
    178, 49,  240, 18,  52,  130, 50,  49,  113, 66,  49,  98,  66,  49,  82,  82,  49,  81,  98,  49,  66,  113, 33,  81,  147, 0,   11,
    80,  42,  17,  240, 240, 131, 210, 33,  178, 49,  178, 49,  178, 49,  178, 33,  196, 69,  67,  113, 115, 81,  116, 81,  98,  19,  49,
    99,  35,  18,  99,  37,  115, 52,  65,  35,  53,  34,  68,  53,  0,   13,  16,  12,  6,   240, 66,  52,  36,  51,  81,  65,  65,  0,
    11,  26,  7,   65,  81,  82,  81,  82,  82,  81,  82,  82,  82,  82,  82,  82,  82,  82,  82,  97,  98,  82,  97,  98,  97,  113, 144,
    26,  7,   1,   113, 98,  97,  98,  82,  97,  98,  82,  82,  82,  82,  82,  82,  82,  82,  81,  82,  82,  81,  82,  81,  81,  208, 20,
    10,  50,  130, 130, 81,  34,  33,  40,  54,  84,  72,  34,  18,  18,  82,  130, 0,   16,  112, 36,  17,  0,   9,   49,  240, 17,  240,
    17,  240, 17,  240, 17,  240, 17,  240, 17,  240, 17,  159, 145, 240, 17,  240, 17,  240, 17,  240, 17,  240, 17,  240, 17,  0,   9,
    80,  14,  6,   0,   10,  82,  52,  36,  51,  81,  65,  81,  65,  240, 16,  9,   8,   0,   12,  6,   38,  0,   10,  32,  11,  5,   0,
    8,   113, 51,  35,  49,  240, 240, 48,  27,  11,  129, 146, 145, 161, 146, 145, 146, 146, 145, 146, 146, 145, 146, 146, 145, 146, 146,
    145, 146, 145, 161, 146, 145, 240, 96,  34,  10,  240, 240, 36,  82,  34,  65,  65,  50,  66,  34,  66,  34,  66,  34,  66,  34,  66,
    34,  66,  34,  66,  34,  66,  34,  66,  49,  65,  66,  34,  84,  0,   8,   22,  10,  240, 240, 65,  130, 85,  130, 130, 130, 130, 130,
    130, 130, 130, 130, 130, 130, 103, 0,   7,   96,  28,  11,  240, 240, 85,  81,  51,  51,  51,  35,  51,  35,  51,  131, 130, 130, 130,
    145, 145, 65,  65,  81,  56,  41,  40,  0,   8,   80,  29,  11,  240, 240, 85,  81,  51,  66,  50,  66,  50,  66,  50,  146, 130, 100,
    163, 147, 131, 35,  51,  35,  51,  34,  66,  85,  0,   8,   96,  28,  11,  240, 240, 145, 146, 146, 131, 113, 18,  113, 18,  97,  34,
    81,  50,  81,  50,  65,  66,  73,  114, 146, 146, 118, 0,   8,   64,  29,  11,  240, 240, 65,  81,  71,  70,  84,  113, 161, 161, 20,
    82,  50,  147, 131, 35,  51,  35,  51,  35,  51,  49,  51,  84,  0,   8,   112, 35,  11,  240, 240, 115, 98,  49,  67,  34,  66,  50,
    51,  50,  51,  19,  68,  34,  51,  51,  35,  51,  35,  51,  35,  51,  35,  51,  50,  51,  51,  34,  100, 0,   8,   96,  23,  10,  240,
    248, 40,  39,  49,  65,  65,  65,  129, 145, 129, 145, 145, 130, 130, 130, 130, 130, 0,   8,   32,  33,  11,  240, 240, 85,  82,  50,
    65,  81,  65,  81,  67,  49,  68,  18,  70,  102, 66,  21,  34,  52,  34,  82,  34,  82,  34,  82,  50,  50,  85,  0,   8,   96,  34,
    10,  240, 240, 36,  82,  34,  50,  65,  50,  66,  34,  66,  34,  66,  34,  66,  34,  66,  49,  51,  67,  18,  130, 49,  65,  50,  65,
    65,  49,  84,  0,   8,   16,  15,  5,   240, 240, 177, 51,  35,  49,  225, 51,  35,  49,  240, 240, 48,  19,  6,   0,   6,   18,  52,
    36,  50,  240, 18,  52,  36,  51,  81,  65,  81,  65,  240, 16,  20,  5,   240, 240, 17,  51,  35,  49,  145, 65,  65,  65,  65,  51,
    35,  35,  35,  35,  35,  192, 11,  17,  0,   19,  31,  0,   10,  127, 0,   17,  32,  25,  9,   0,   7,   3,   84,  84,  99,  240, 17,
    129, 129, 129, 113, 114, 98,  114, 50,  34,  50,  34,  65,  53,  240, 96,  26,  9,   240, 69,  65,  50,  34,  50,  34,  50,  34,  50,
    98,  113, 114, 113, 129, 129, 240, 19,  84,  84,  99,  0,   7,   32,  55,  17,  240, 240, 134, 162, 82,  113, 145, 81,  52,  65,  65,
    34,  34,  49,  49,  34,  66,  49,  33,  34,  66,  49,  33,  34,  66,  49,  33,  34,  66,  49,  33,  34,  66,  49,  33,  34,  66,  49,
    49,  34,  35,  33,  65,  52,  19,  97,  240, 34,  99,  120, 0,   13,  48,  30,  17,  0,   7,   33,  242, 243, 212, 213, 193, 19,  178,
    19,  177, 36,  161, 51,  145, 67,  153, 129, 83,  113, 99,  113, 115, 69,  55,  0,   13,  34,  16,  0,   6,   11,  114, 83,  98,  99,
    82,  99,  82,  99,  82,  83,  104, 130, 83,  98,  99,  82,  99,  82,  100, 66,  100, 66,  99,  82,  84,  59,  0,   12,  80,  32,  15,
    0,   6,   22,  33,  83,  67,  66,  114, 51,  114, 50,  145, 35,  145, 35,  195, 195, 195, 195, 145, 51,  129, 66,  113, 99,  65,  134,
    0,   11,  112, 35,  16,  0,   6,   10,  130, 83,  98,  99,  82,  114, 82,  115, 66,  115, 66,  115, 66,  115, 66,  115, 66,  115, 66,
    115, 66,  114, 82,  99,  82,  83,  74,  0,   12,  96,  37,  15,  240, 240, 252, 83,  82,  83,  97,  83,  97,  83,  49,  34,  67,  49,
    49,  67,  34,  135, 131, 49,  131, 49,  49,  67,  113, 67,  113, 67,  98,  67,  82,  60,  0,   11,  80,  32,  13,  240, 240, 155, 67,
    66,  67,  81,  67,  81,  67,  33,  33,  67,  33,  115, 33,  118, 115, 33,  115, 33,  115, 33,  115, 163, 163, 135, 0,   10,  64,  33,
    18,  0,   7,   54,  33,  115, 68,  98,  130, 83,  130, 82,  161, 67,  161, 67,  243, 243, 243, 88,  50,  131, 83,  115, 98,  115, 115,
    68,  150, 33,  0,   14,  35,  17,  0,   6,   55,  23,  67,  83,  99,  83,  99,  83,  99,  83,  99,  83,  107, 99,  83,  99,  83,  99,
    83,  99,  83,  99,  83,  99,  83,  99,  83,  71,  23,  0,   13,  20,  9,   240, 199, 67,  99,  99,  99,  99,  99,  99,  99,  99,  99,
    99,  99,  99,  71,  0,   7,   25,  12,  240, 240, 151, 130, 162, 162, 162, 162, 162, 162, 162, 162, 162, 67,  50,  67,  50,  66,  50,
    101, 0,   9,   96,  35,  17,  0,   6,   55,  53,  67,  98,  99,  82,  115, 66,  131, 50,  147, 34,  163, 19,  168, 148, 19,  147, 51,
    131, 52,  115, 67,  115, 83,  99,  83,  71,  38,  0,   13,  27,  13,  240, 240, 152, 115, 163, 163, 163, 163, 163, 163, 163, 81,  67,
    81,  67,  81,  67,  81,  67,  66,  67,  51,  43,  0,   10,  58,  20,  0,   7,   69,  133, 68,  115, 100, 97,  18,  97,  18,  97,  18,
    97,  19,  81,  18,  97,  34,  65,  34,  97,  34,  65,  34,  97,  35,  49,  34,  97,  50,  33,  50,  97,  51,  17,  50,  97,  51,  17,
    50,  97,  67,  66,  97,  67,  66,  97,  66,  82,  69,  49,  54,  0,   15,  32,  43,  17,  0,   6,   53,  85,  68,  97,  101, 81,  97,
    19,  81,  97,  35,  65,  97,  36,  49,  97,  51,  49,  97,  67,  33,  97,  83,  17,  97,  85,  97,  100, 97,  115, 97,  115, 97,  130,
    69,  113, 0,   13,  32,  35,  16,  0,   6,   70,  146, 66,  114, 98,  82,  130, 51,  131, 35,  131, 35,  131, 35,  131, 35,  131, 35,
    131, 35,  131, 51,  99,  67,  98,  99,  67,  134, 0,   12,  96,  28,  14,  240, 240, 202, 99,  51,  83,  67,  67,  67,  67,  67,  67,
    67,  67,  51,  88,  99,  179, 179, 179, 179, 179, 151, 0,   11,  48,  44,  16,  0,   6,   70,  146, 67,  98,  99,  67,  114, 51,  131,
    35,  131, 35,  131, 35,  131, 35,  131, 35,  131, 50,  130, 67,  35,  19,  82,  17,  33,  18,  115, 50,  151, 33,  178, 33,  181, 196,
    195, 240, 240, 80,  36,  18,  0,   6,   106, 162, 83,  130, 99,  114, 99,  114, 99,  114, 99,  114, 83,  136, 162, 67,  146, 68,  130,
    68,  130, 68,  130, 68,  130, 84,  18,  39,  53,  0,   13,  112, 32,  12,  240, 240, 133, 17,  66,  51,  50,  97,  50,  97,  50,  97,
    52,  151, 88,  118, 147, 33,  114, 33,  114, 34,  98,  35,  66,  49,  37,  0,   9,   64,  32,  15,  240, 240, 253, 34,  51,  50,  33,
    67,  65,  33,  67,  65,  33,  67,  65,  33,  67,  65,  115, 195, 195, 195, 195, 195, 195, 195, 153, 0,   11,  96,  36,  17,  0,   6,
    55,  53,  67,  113, 99,  113, 99,  113, 99,  113, 99,  113, 99,  113, 99,  113, 99,  113, 99,  113, 99,  113, 99,  113, 114, 97,  146,
    66,  165, 0,   13,  80,  33,  18,  0,   6,   103, 69,  68,  113, 115, 113, 115, 97,  147, 81,  147, 66,  148, 49,  179, 49,  179, 33,
    211, 17,  213, 212, 243, 242, 240, 18,  0,   14,  80,  50,  24,  0,   9,   7,   23,  37,  67,  83,  97,  115, 68,  81,  115, 83,  81,
    115, 83,  65,  147, 53,  49,  147, 49,  19,  49,  148, 18,  19,  33,  179, 17,  36,  17,  179, 17,  51,  17,  181, 52,  211, 68,  211,
    83,  211, 82,  241, 113, 0,   19,  32,  17,  0,   6,   55,  22,  83,  81,  147, 50,  148, 33,  179, 17,  212, 212, 227, 228, 193, 19,
    178, 35,  161, 52,  129, 83,  114, 84,  69,  55,  0,   13,  29,  16,  0,   6,   6,   68,  67,  97,  100, 66,  115, 65,  131, 50,  147,
    33,  178, 17,  196, 210, 226, 226, 226, 226, 226, 198, 0,   12,  96,  30,  13,  240, 240, 155, 35,  68,  34,  83,  49,  83,  65,  68,
    147, 148, 147, 147, 163, 65,  67,  81,  67,  81,  51,  82,  36,  67,  43,  0,   10,  26,  5,   83,  33,  65,  65,  65,  65,  65,  65,
    65,  65,  65,  65,  65,  65,  65,  65,  65,  65,  65,  65,  65,  65,  67,  32,  21,  11,  240, 240, 81,  65,  65,  65,  65,  65,  83,
    35,  52,  20,  36,  20,  50,  50,  0,   19,  80,  26,  5,   83,  65,  65,  65,  65,  65,  65,  65,  65,  65,  65,  65,  65,  65,  65,
    65,  65,  65,  65,  65,  65,  65,  35,  32,  10,  8,   240, 178, 84,  50,  34,  0,   18,  32,  9,   5,   240, 17,  51,  35,  49,  0,
    11,  13,  6,   240, 81,  65,  65,  83,  52,  36,  50,  0,   10,  112, 24,  11,  0,   11,  21,  97,  50,  82,  50,  146, 101, 67,  34,
    50,  66,  50,  66,  50,  51,  68,  19,  0,   8,   64,  32,  13,  240, 240, 148, 178, 178, 178, 178, 178, 20,  99,  50,  82,  82,  66,
    82,  66,  82,  66,  82,  66,  82,  66,  82,  67,  50,  81,  36,  0,   10,  32,  21,  9,   0,   9,   36,  66,  34,  34,  50,  34,  114,
    114, 114, 114, 65,  50,  49,  68,  0,   7,   16,  31,  13,  240, 240, 228, 178, 178, 178, 178, 100, 18,  82,  51,  81,  82,  66,  82,
    66,  82,  66,  82,  66,  82,  66,  82,  82,  51,  100, 20,  0,   10,  22,  11,  0,   11,  37,  82,  50,  50,  82,  34,  82,  41,  34,
    146, 161, 97,  50,  65,  100, 0,   8,   96,  23,  10,  240, 147, 98,  18,  66,  34,  66,  130, 130, 117, 98,  130, 130, 130, 130, 130,
    130, 130, 102, 0,   8,   31,  11,  0,   11,  35,  19,  49,  49,  18,  34,  50,  66,  50,  66,  50,  81,  49,  81,  19,  97,  167, 87,
    49,  83,  33,  98,  34,  66,  85,  240, 176, 31,  14,  240, 240, 196, 194, 194, 194, 194, 194, 35,  116, 34,  99,  50,  98,  66,  98,
    66,  98,  66,  98,  66,  98,  66,  98,  66,  76,  0,   10,  96,  20,  7,   240, 130, 67,  67,  82,  179, 82,  82,  82,  82,  82,  82,
    82,  82,  53,  240, 240, 224, 25,  8,   240, 195, 83,  83,  83,  196, 98,  98,  98,  98,  98,  98,  98,  98,  98,  98,  34,  34,  34,
    18,  67,  240, 80,  30,  13,  240, 240, 148, 178, 178, 178, 178, 178, 36,  82,  50,  98,  34,  114, 17,  149, 130, 18,  130, 34,  114,
    35,  98,  50,  69,  21,  0,   10,  21,  8,   240, 148, 98,  98,  98,  98,  98,  98,  98,  98,  98,  98,  98,  98,  98,  70,  0,   6,
    32,  36,  20,  0,   20,  4,   35,  36,  116, 36,  34,  99,  51,  50,  98,  66,  66,  98,  66,  66,  98,  66,  66,  98,  66,  66,  98,
    66,  66,  98,  66,  66,  79,  3,   0,   15,  32,  26,  14,  0,   14,  4,   35,  116, 34,  99,  50,  98,  66,  98,  66,  98,  66,  98,
    66,  98,  66,  98,  66,  76,  0,   10,  96,  25,  11,  0,   11,  37,  82,  50,  65,  81,  50,  82,  34,  82,  34,  82,  34,  82,  34,
    82,  50,  50,  85,  0,   8,   96,  31,  13,  0,   13,  4,   20,  99,  50,  82,  82,  66,  82,  66,  82,  66,  82,  66,  82,  66,  66,
    83,  50,  82,  20,  98,  178, 178, 150, 240, 240, 48,  30,  13,  0,   13,  36,  33,  82,  51,  66,  82,  66,  82,  66,  82,  66,  82,
    66,  82,  66,  82,  82,  51,  100, 18,  178, 178, 178, 150, 240, 208, 19,  10,  0,   10,  4,   19,  67,  18,  66,  34,  66,  130, 130,
    130, 130, 130, 102, 0,   8,   23,  9,   0,   9,   21,  50,  49,  50,  49,  51,  117, 85,  33,  66,  33,  66,  34,  50,  33,  20,  0,
    7,   16,  25,  8,   240, 177, 113, 113, 113, 98,  86,  50,  98,  98,  98,  98,  33,  50,  33,  50,  33,  50,  33,  67,  0,   6,   48,
    27,  14,  0,   14,  4,   36,  98,  66,  98,  66,  98,  66,  98,  66,  98,  66,  98,  66,  98,  66,  98,  51,  116, 20,  0,   10,  96,
    24,  13,  0,   13,  6,   20,  67,  50,  83,  49,  114, 49,  115, 17,  146, 17,  146, 17,  147, 178, 178, 0,   10,  64,  32,  17,  0,
    17,  5,   20,  35,  66,  50,  65,  83,  34,  65,  98,  35,  33,  114, 35,  33,  116, 21,  131, 35,  147, 35,  146, 51,  161, 65,  0,
    13,  64,  23,  13,  0,   13,  5,   36,  67,  34,  114, 33,  147, 163, 178, 161, 18,  130, 19,  113, 50,  69,  21,  0,   10,  29,  12,
    0,   12,  5,   20,  51,  50,  82,  49,  98,  49,  99,  17,  130, 17,  132, 146, 162, 162, 161, 114, 33,  114, 17,  146, 240, 240, 48,
    24,  10,  0,   10,  8,   34,  51,  33,  51,  49,  50,  115, 99,  33,  66,  49,  51,  49,  35,  50,  40,  0,   7,   96,  8,   13,  0,
    17,  123, 0,   19,  96,  9,   24,  0,   33,  15,  7,   0,   36,  32,  13,  8,   146, 18,  38,  38,  34,  18,  49,  33,  0,   18,  64,
    9,   9,   240, 214, 33,  35,  0,   21,  96,
};

//*****************************************************************************
//
// The font definition for the 22 point Cm bold font.
//
//*****************************************************************************
const tFont g_sFontCm22b = {
    //
    // The format of the font.
    //
    FONT_FMT_PIXEL_RLE,

    //
    // The maximum width of the font.
    //
    21,

    //
    // The height of the font.
    //
    24,

    //
    // The baseline of the font.
    //
    18,

    //
    // The offset to each character in the font.
    //
    {
     0,    4,    25,   46,   91,   133,  190,  232,  244,  270,  296,  316,  352,  366,  375,  386,  413,  447,  469,
     497,  526,  554,  583,  618,  641,  674,  708,  723,  742,  762,  773,  798,  824,  879,  909,  943,  975,  1010,
     1047, 1079, 1112, 1147, 1167, 1192, 1227, 1254, 1312, 1355, 1390, 1418, 1462, 1498, 1530, 1562, 1598, 1631, 1681,
     1713, 1742, 1772, 1798, 1819, 1845, 1855, 1864, 1877, 1901, 1933, 1954, 1985, 2007, 2030, 2061, 2092, 2112, 2137,
     2167, 2188, 2224, 2250, 2275, 2306, 2336, 2355, 2378, 2403, 2430, 2454, 2486, 2509, 2538, 2562, 2570, 2579, 2592,
     },

    //
    // A pointer to the actual font data
    //
    g_pui8Cm22bData
};

//*****************************************************************************
//
// fontcm48i.c - Font definition for the 48pt Cm italic font.
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
//     Size: 48 point
//     Bold: no
//     Italic: yes
//     Memory usage: 7144 bytes
//
//*****************************************************************************

//*****************************************************************************
//
// The compressed data for the 48 point Cm italic font.
// Contains characters 32 to 126 inclusive.
//
//*****************************************************************************
static const uint8_t g_pui8Cm48iData[6944] = {
    5,   19,  0,   116, 48,  40,  16,  240, 240, 179, 196, 196, 181, 181, 180, 196, 196, 195, 196, 196, 195, 211, 211, 210, 211, 211, 211,
    210, 226, 211, 210, 226, 226, 225, 241, 0,   9,   67,  197, 181, 181, 195, 0,   25,  64,  35,  20,  0,   7,   115, 99,  117, 69,  101,
    69,  101, 69,  116, 84,  161, 129, 145, 129, 161, 129, 145, 129, 161, 129, 145, 129, 145, 129, 145, 129, 145, 129, 0,   81,  32,  134,
    37,  0,   16,  65,  145, 240, 162, 130, 240, 162, 130, 240, 146, 130, 240, 162, 130, 240, 161, 130, 240, 162, 130, 240, 162, 114, 240,
    162, 130, 240, 162, 129, 240, 162, 130, 240, 162, 130, 240, 146, 130, 240, 162, 130, 240, 146, 130, 240, 162, 130, 240, 161, 130, 239,
    15,  1,   240, 18,  130, 240, 162, 114, 240, 162, 130, 240, 162, 130, 240, 146, 130, 240, 162, 130, 240, 162, 114, 240, 162, 130, 240,
    31,  15,  1,   226, 130, 240, 146, 130, 240, 162, 130, 240, 146, 130, 240, 162, 130, 240, 146, 130, 240, 162, 130, 240, 146, 130, 240,
    162, 130, 240, 146, 130, 240, 162, 130, 240, 146, 130, 240, 162, 130, 240, 161, 130, 240, 162, 130, 240, 161, 145, 0,   17,  89,  33,
    0,   15,  5,   240, 194, 66,  240, 131, 97,  240, 115, 129, 240, 83,  145, 240, 82,  161, 240, 67,  131, 240, 67,  131, 240, 51,  132,
    240, 51,  146, 240, 67,  240, 243, 240, 227, 240, 243, 240, 243, 240, 243, 240, 227, 240, 188, 240, 163, 240, 243, 240, 227, 240, 243,
    240, 243, 240, 243, 240, 227, 240, 243, 240, 243, 240, 242, 240, 168, 209, 146, 68,  194, 130, 85,  177, 130, 83,  20,  129, 146, 66,
    83,  82,  181, 150, 0,   51,  145, 37,  163, 240, 50,  194, 49,  240, 34,  178, 66,  242, 178, 98,  195, 194, 99,  163, 194, 113, 19,
    98,  17,  210, 113, 55,  34,  195, 113, 178, 210, 129, 162, 226, 129, 146, 227, 129, 145, 243, 113, 146, 242, 129, 130, 240, 18,  129,
    114, 240, 34,  113, 114, 240, 50,  113, 98,  240, 66,  97,  113, 240, 82,  97,  98,  240, 97,  81,  98,  240, 129, 34,  98,  240, 162,
    114, 240, 240, 66,  118, 240, 114, 97,  81,  240, 98,  98,  97,  240, 66,  98,  113, 240, 50,  98,  129, 240, 34,  114, 129, 240, 18,
    115, 129, 240, 18,  114, 145, 242, 130, 145, 226, 131, 129, 226, 147, 129, 210, 162, 145, 195, 162, 129, 210, 178, 129, 194, 194, 113,
    194, 210, 98,  178, 241, 82,  178, 240, 18,  50,  194, 240, 36,  0,   43,  48,  123, 35,  0,   10,  22,  240, 210, 66,  178, 195, 98,
    147, 179, 129, 147, 178, 146, 146, 163, 116, 145, 163, 116, 146, 163, 116, 145, 163, 131, 146, 163, 240, 66,  179, 240, 50,  195, 240,
    34,  211, 36,  163, 210, 19,  49,  115, 18,  196, 81,  99,  49,  195, 97,  82,  81,  195, 97,  66,  98,  164, 81,  82,  113, 162, 18,
    50,  81,  129, 147, 36,  98,  129, 147, 194, 18,  81,  131, 228, 81,  131, 228, 81,  116, 240, 129, 115, 240, 129, 131, 240, 129, 131,
    240, 129, 131, 240, 113, 147, 240, 98,  162, 240, 97,  179, 240, 65,  210, 240, 49,  227, 240, 17,  240, 19,  210, 240, 67,  131, 240,
    152, 0,   50,  64,  21,  11,  240, 240, 99,  117, 101, 101, 116, 161, 145, 161, 145, 161, 145, 145, 145, 145, 0,   45,  32,  102, 21,
    240, 17,  240, 65,  240, 65,  240, 50,  240, 65,  240, 65,  240, 66,  240, 50,  240, 50,  240, 66,  240, 50,  240, 51,  240, 50,  240,
    50,  240, 66,  240, 51,  240, 50,  240, 66,  240, 50,  240, 66,  240, 51,  240, 50,  240, 66,  240, 66,  240, 51,  240, 50,  240, 66,
    240, 66,  240, 66,  240, 51,  240, 51,  240, 50,  240, 66,  240, 66,  240, 66,  240, 66,  240, 66,  240, 66,  240, 66,  240, 66,  240,
    81,  240, 82,  240, 66,  240, 66,  240, 81,  240, 82,  240, 81,  240, 82,  240, 81,  240, 16,  101, 21,  193, 240, 97,  240, 82,  240,
    81,  240, 81,  240, 82,  240, 81,  240, 81,  240, 82,  240, 66,  240, 66,  240, 66,  240, 66,  240, 66,  240, 66,  240, 66,  240, 66,
    240, 66,  240, 66,  240, 51,  240, 51,  240, 50,  240, 66,  240, 66,  240, 51,  240, 51,  240, 50,  240, 66,  240, 51,  240, 50,  240,
    66,  240, 51,  240, 50,  240, 66,  240, 50,  240, 66,  240, 50,  240, 66,  240, 50,  240, 66,  240, 50,  240, 50,  240, 65,  240, 66,
    240, 50,  240, 50,  240, 50,  240, 50,  240, 50,  240, 64,  52,  22,  177, 240, 82,  240, 82,  240, 82,  240, 81,  211, 66,  82,  100,
    50,  52,  131, 33,  51,  179, 17,  19,  245, 240, 50,  240, 53,  243, 17,  19,  179, 49,  35,  132, 50,  52,  98,  82,  67,  209, 240,
    82,  240, 82,  240, 82,  240, 82,  0,   78,  96,  89,  33,  0,   43,  50,  240, 240, 18,  240, 240, 17,  240, 240, 18,  240, 240, 18,
    240, 240, 18,  240, 240, 18,  240, 242, 240, 240, 18,  240, 240, 18,  240, 240, 18,  240, 240, 17,  240, 240, 18,  240, 240, 18,  240,
    240, 18,  240, 47,  14,  240, 34,  240, 240, 18,  240, 240, 18,  240, 242, 240, 240, 18,  240, 240, 18,  240, 240, 17,  240, 240, 18,
    240, 240, 18,  240, 240, 18,  240, 240, 17,  240, 240, 18,  240, 240, 18,  0,   43,  112, 21,  11,  0,   44,  51,  117, 101, 101, 116,
    161, 145, 161, 145, 161, 145, 145, 145, 145, 240, 240, 208, 10,  16,  0,   50,  12,  76,  76,  0,   42,  64,  12,  9,   0,   36,  34,
    100, 69,  69,  83,  0,   14,  16,  102, 32,  240, 178, 240, 242, 240, 226, 240, 242, 240, 226, 240, 242, 240, 226, 240, 226, 240, 242,
    240, 226, 240, 242, 240, 226, 240, 242, 240, 226, 240, 242, 240, 226, 240, 226, 240, 242, 240, 226, 240, 242, 240, 226, 240, 242, 240,
    226, 240, 242, 240, 226, 240, 226, 240, 242, 240, 226, 240, 242, 240, 226, 240, 242, 240, 226, 240, 242, 240, 226, 240, 226, 240, 242,
    240, 226, 240, 242, 240, 226, 240, 242, 240, 226, 240, 242, 240, 226, 240, 226, 240, 242, 240, 226, 240, 242, 240, 226, 240, 242, 240,
    240, 73,  24,  0,   16,  54,  240, 19,  51,  226, 99,  194, 130, 179, 131, 162, 147, 147, 147, 146, 163, 131, 163, 131, 163, 115, 164,
    115, 164, 100, 164, 100, 163, 115, 179, 115, 164, 100, 164, 100, 164, 99,  179, 115, 164, 115, 164, 100, 163, 116, 163, 115, 164, 115,
    163, 131, 163, 131, 147, 147, 147, 147, 131, 178, 130, 195, 98,  227, 51,  240, 37,  0,   34,  112, 68,  20,  0,   14,  49,  240, 50,
    240, 34,  240, 35,  240, 20,  215, 164, 35,  240, 35,  240, 35,  240, 20,  240, 19,  240, 35,  240, 35,  240, 20,  240, 19,  240, 35,
    240, 35,  240, 20,  240, 19,  240, 35,  240, 35,  240, 35,  240, 19,  240, 35,  240, 35,  240, 35,  240, 19,  240, 35,  240, 35,  240,
    35,  240, 20,  190, 0,   30,  96,  85,  26,  0,   17,  101, 240, 66,  82,  240, 18,  114, 226, 131, 194, 162, 193, 179, 161, 65,  115,
    161, 65,  115, 145, 81,  115, 145, 81,  115, 129, 97,  115, 129, 81,  115, 145, 81,  115, 145, 65,  115, 161, 49,  131, 179, 131, 240,
    115, 240, 114, 240, 130, 240, 114, 240, 130, 240, 114, 240, 129, 240, 145, 240, 145, 209, 161, 210, 145, 225, 146, 210, 149, 147, 130,
    52,  83,  145, 105, 146, 119, 161, 164, 0,   37,  16,  78,  26,  0,   17,  102, 240, 50,  83,  226, 131, 194, 162, 193, 179, 161, 195,
    161, 49,  131, 145, 65,  131, 145, 65,  131, 145, 65,  115, 161, 49,  131, 179, 131, 240, 130, 240, 130, 240, 114, 240, 54,  240, 147,
    240, 147, 240, 146, 240, 147, 240, 131, 240, 131, 240, 131, 162, 179, 148, 148, 148, 147, 163, 163, 161, 179, 177, 179, 193, 147, 209,
    131, 242, 67,  240, 54,  0,   37,  112, 90,  24,  0,   17,  34,  240, 99,  240, 99,  240, 99,  240, 98,  240, 99,  240, 99,  240, 98,
    240, 99,  240, 99,  240, 98,  240, 99,  240, 98,  240, 114, 240, 98,  240, 114, 240, 98,  240, 114, 240, 98,  240, 114, 240, 98,  240,
    98,  67,  241, 82,  242, 67,  226, 83,  210, 99,  209, 99,  209, 115, 193, 131, 183, 51,  146, 103, 129, 164, 50,  240, 23,  240, 35,
    240, 83,  240, 99,  240, 99,  240, 99,  240, 83,  240, 99,  240, 99,  0,   10,  48,  73,  25,  0,   16,  82,  161, 196, 99,  203, 219,
    232, 240, 33,  240, 145, 240, 130, 240, 130, 240, 129, 240, 145, 240, 130, 240, 130, 37,  240, 17,  18,  82,  227, 99,  209, 146, 240,
    131, 240, 115, 240, 115, 240, 115, 240, 115, 240, 100, 131, 164, 116, 163, 132, 163, 131, 163, 145, 195, 145, 179, 162, 162, 193, 146,
    210, 114, 242, 67,  240, 38,  0,   36,  48,  76,  25,  0,   17,  53,  240, 35,  81,  242, 99,  210, 100, 194, 116, 178, 131, 179, 240,
    99,  240, 115, 240, 99,  240, 100, 240, 99,  53,  227, 33,  67,  180, 17,  98,  179, 17,  115, 164, 146, 149, 147, 132, 163, 132, 148,
    131, 164, 116, 164, 116, 164, 116, 163, 131, 164, 131, 164, 131, 163, 147, 163, 147, 147, 178, 146, 194, 130, 211, 98,  243, 51,  240,
    53,  0,   36,  48,  78,  26,  0,   16,  113, 52,  129, 130, 22,  113, 145, 23,  98,  133, 66,  66,  147, 113, 51,  131, 134, 146, 194,
    146, 210, 146, 194, 161, 210, 145, 210, 240, 146, 240, 131, 240, 130, 240, 131, 240, 130, 240, 131, 240, 130, 240, 131, 240, 131, 240,
    115, 240, 131, 240, 116, 240, 115, 240, 131, 240, 116, 240, 116, 240, 115, 240, 116, 240, 116, 240, 115, 240, 131, 240, 131, 0,   37,
    112, 73,  25,  0,   17,  22,  240, 35,  66,  242, 114, 210, 146, 178, 162, 162, 178, 162, 178, 147, 178, 147, 162, 163, 162, 164, 130,
    181, 98,  214, 50,  231, 18,  240, 39,  240, 70,  240, 56,  242, 54,  210, 86,  178, 118, 146, 149, 130, 180, 114, 211, 114, 211, 98,
    227, 98,  226, 114, 226, 114, 210, 130, 194, 162, 163, 162, 146, 211, 83,  240, 22,  0,   36,  32,  76,  25,  0,   17,  22,  240, 35,
    66,  242, 99,  210, 130, 194, 147, 163, 147, 147, 163, 147, 163, 132, 163, 131, 179, 116, 164, 116, 164, 116, 164, 115, 164, 131, 164,
    131, 149, 146, 149, 146, 129, 20,  147, 98,  19,  179, 65,  36,  213, 51,  240, 115, 240, 100, 240, 99,  240, 99,  240, 115, 162, 147,
    164, 130, 180, 114, 195, 114, 210, 114, 242, 67,  240, 38,  0,   36,  64,  19,  13,  0,   26,  98,  164, 133, 133, 147, 0,   18,  83,
    164, 133, 132, 162, 0,   20,  96,  28,  15,  0,   31,  2,   196, 165, 165, 179, 0,   21,  83,  181, 165, 165, 179, 225, 225, 209, 225,
    209, 225, 209, 209, 209, 0,   7,   48,  40,  16,  0,   25,  3,   197, 181, 181, 195, 0,   9,   65,  241, 226, 226, 226, 211, 210, 226,
    211, 211, 211, 210, 211, 211, 211, 196, 196, 195, 196, 196, 196, 181, 181, 180, 196, 195, 240, 240, 240, 13,  35,  0,   87,  111, 14,
    0,   35,  79,  14,  0,   83,  112, 70,  21,  0,   33,  19,  240, 36,  240, 21,  240, 21,  240, 35,  0,   12,  68,  240, 17,  50,  225,
    66,  210, 66,  209, 82,  240, 51,  240, 35,  240, 35,  240, 20,  240, 20,  240, 20,  240, 20,  240, 20,  99,  115, 116, 99,  132, 83,
    163, 82,  194, 67,  193, 82,  194, 82,  193, 98,  177, 114, 162, 114, 161, 146, 114, 178, 82,  214, 0,   6,   96,  70,  21,  0,   6,
    38,  211, 66,  178, 114, 146, 146, 114, 162, 113, 178, 97,  194, 82,  194, 81,  195, 66,  194, 83,  163, 84,  131, 100, 115, 115, 100,
    240, 20,  240, 20,  240, 20,  240, 20,  240, 19,  240, 35,  240, 35,  240, 50,  81,  210, 66,  210, 65,  226, 49,  240, 20,  0,   12,
    67,  240, 37,  240, 21,  240, 20,  240, 35,  0,   33,  80,  126, 34,  0,   14,  103, 240, 147, 99,  240, 82,  178, 240, 49,  241, 242,
    240, 33,  210, 240, 50,  178, 117, 129, 177, 99,  50,  113, 161, 98,  113, 113, 129, 83,  130, 97,  114, 82,  163, 65,  113, 83,  163,
    65,  97,  83,  179, 65,  97,  83,  179, 65,  82,  67,  179, 81,  81,  83,  179, 81,  81,  83,  179, 66,  81,  67,  195, 65,  81,  83,
    194, 81,  81,  83,  179, 81,  81,  83,  179, 66,  81,  83,  179, 65,  97,  83,  164, 65,  97,  98,  163, 66,  97,  99,  132, 65,  113,
    114, 113, 19,  50,  129, 114, 66,  35,  34,  145, 133, 100, 177, 240, 240, 49,  240, 240, 65,  240, 82,  194, 243, 243, 148, 240, 105,
    0,   53,  16,  97,  33,  0,   11,  2,   240, 243, 240, 243, 240, 228, 240, 228, 240, 213, 240, 213, 240, 194, 19,  240, 193, 35,  240,
    178, 35,  240, 162, 51,  240, 162, 51,  240, 146, 68,  240, 129, 84,  240, 114, 84,  240, 113, 100, 240, 98,  100, 240, 97,  116, 240,
    82,  116, 240, 66,  132, 240, 66,  132, 240, 50,  148, 240, 50,  163, 240, 47,  1,   240, 33,  195, 240, 18,  195, 240, 17,  211, 242,
    212, 210, 228, 209, 244, 194, 244, 193, 240, 20,  178, 240, 20,  149, 244, 121, 155, 0,   50,  84,  35,  0,   18,  63,  4,   240, 84,
    163, 240, 51,  195, 240, 35,  196, 240, 19,  212, 228, 212, 227, 228, 227, 228, 227, 212, 228, 212, 227, 212, 243, 211, 240, 19,  195,
    240, 20,  179, 240, 35,  163, 240, 78,  240, 99,  164, 240, 36,  195, 240, 19,  212, 243, 227, 243, 228, 212, 228, 211, 244, 211, 244,
    211, 244, 196, 228, 212, 228, 211, 228, 227, 227, 243, 212, 228, 195, 240, 19,  180, 223, 4,   0,   54,  64,  105, 35,  0,   15,  23,
    113, 240, 51,  98,  66,  240, 19,  161, 35,  227, 194, 19,  211, 228, 211, 244, 195, 240, 35,  179, 240, 51,  164, 240, 50,  164, 240,
    66,  163, 240, 82,  148, 240, 82,  148, 240, 81,  148, 240, 97,  148, 240, 244, 240, 240, 20,  240, 240, 20,  240, 245, 240, 245, 240,
    244, 240, 240, 20,  240, 240, 20,  240, 97,  148, 240, 82,  148, 240, 81,  164, 240, 81,  179, 240, 65,  195, 240, 50,  196, 240, 33,
    227, 240, 17,  244, 225, 240, 35,  209, 240, 68,  146, 240, 116, 82,  240, 183, 0,   50,  80,  106, 37,  0,   19,  79,  4,   240, 116,
    148, 240, 83,  195, 240, 67,  211, 240, 36,  226, 240, 36,  227, 240, 19,  240, 18,  240, 19,  240, 19,  228, 240, 19,  228, 240, 19,
    227, 240, 35,  227, 240, 35,  227, 240, 35,  212, 240, 35,  211, 240, 36,  211, 240, 36,  211, 240, 35,  212, 240, 35,  212, 240, 35,
    211, 240, 36,  211, 240, 35,  212, 240, 35,  212, 240, 19,  227, 240, 35,  227, 240, 19,  228, 240, 18,  244, 242, 240, 19,  243, 240,
    19,  227, 240, 20,  210, 240, 52,  179, 240, 68,  147, 240, 31,  4,   0,   57,  96,  98,  36,  0,   19,  15,  9,   207, 9,   240, 20,
    181, 240, 19,  227, 244, 242, 244, 241, 240, 19,  240, 17,  240, 19,  240, 17,  244, 240, 17,  244, 240, 17,  243, 145, 113, 243, 145,
    240, 116, 130, 240, 116, 130, 240, 115, 130, 240, 141, 240, 116, 115, 240, 116, 130, 240, 115, 145, 240, 131, 145, 240, 116, 130, 113,
    228, 130, 113, 227, 240, 34,  227, 240, 33,  228, 240, 33,  228, 240, 18,  227, 240, 33,  243, 240, 18,  228, 242, 244, 227, 244, 212,
    228, 197, 191, 10,  0,   55,  48,  93,  35,  0,   18,  79,  8,   207, 8,   240, 20,  180, 240, 19,  211, 244, 226, 244, 226, 243, 242,
    243, 242, 228, 241, 244, 241, 243, 240, 17,  243, 145, 240, 100, 130, 240, 100, 129, 240, 115, 130, 240, 115, 115, 240, 110, 240, 100,
    99,  240, 115, 130, 240, 115, 130, 240, 100, 130, 240, 100, 129, 240, 115, 145, 240, 115, 240, 240, 20,  240, 240, 20,  240, 240, 19,
    240, 240, 35,  240, 240, 20,  240, 240, 20,  240, 240, 20,  240, 245, 240, 189, 0,   55,  32,  104, 35,  0,   15,  23,  113, 240, 51,
    98,  66,  240, 19,  146, 35,  227, 194, 19,  211, 228, 211, 244, 195, 240, 35,  179, 240, 51,  163, 240, 66,  164, 240, 66,  163, 240,
    82,  148, 240, 82,  132, 240, 97,  148, 240, 97,  133, 240, 244, 240, 240, 20,  240, 240, 20,  240, 245, 240, 244, 240, 240, 20,  240,
    240, 20,  220, 100, 240, 52,  148, 240, 52,  148, 240, 51,  164, 240, 51,  179, 240, 36,  180, 240, 20,  180, 240, 19,  211, 244, 212,
    228, 228, 197, 244, 161, 34,  240, 52,  83,  65,  240, 87,  0,   50,  80,  104, 41,  0,   21,  76,  92,  240, 20,  197, 240, 83,  227,
    240, 84,  212, 240, 84,  212, 240, 83,  227, 240, 99,  227, 240, 84,  212, 240, 84,  212, 240, 84,  211, 240, 99,  227, 240, 84,  212,
    240, 84,  212, 240, 84,  211, 240, 99,  227, 240, 95,  6,   240, 84,  212, 240, 83,  227, 240, 99,  227, 240, 84,  212, 240, 84,  212,
    240, 84,  212, 240, 83,  227, 240, 99,  212, 240, 84,  212, 240, 84,  212, 240, 83,  227, 240, 99,  212, 240, 84,  212, 240, 84,  212,
    240, 83,  227, 240, 84,  212, 240, 28,  92,  0,   63,  71,  24,  0,   13,  12,  240, 20,  240, 83,  240, 84,  240, 84,  240, 83,  240,
    99,  240, 84,  240, 84,  240, 83,  240, 99,  240, 84,  240, 84,  240, 83,  240, 99,  240, 84,  240, 84,  240, 84,  240, 83,  240, 99,
    240, 84,  240, 84,  240, 83,  240, 99,  240, 84,  240, 84,  240, 83,  240, 99,  240, 84,  240, 84,  240, 83,  240, 85,  252, 0,   37,
    64,  75,  28,  0,   15,  76,  240, 100, 240, 147, 240, 148, 240, 148, 240, 147, 240, 163, 240, 148, 240, 148, 240, 147, 240, 163, 240,
    163, 240, 148, 240, 147, 240, 163, 240, 163, 240, 148, 240, 147, 240, 163, 240, 163, 240, 148, 240, 148, 240, 147, 240, 163, 240, 148,
    240, 148, 227, 115, 228, 100, 228, 99,  243, 100, 241, 131, 240, 18,  99,  240, 50,  67,  240, 101, 0,   41,  108, 41,  0,   21,  76,
    137, 240, 20,  229, 240, 51,  243, 240, 68,  227, 240, 84,  210, 240, 116, 194, 240, 131, 194, 240, 147, 178, 240, 148, 162, 240, 164,
    130, 240, 195, 130, 240, 211, 114, 240, 212, 98,  240, 228, 83,  240, 227, 84,  240, 227, 65,  20,  240, 196, 34,  36,  240, 196, 18,
    52,  240, 195, 18,  84,  240, 181, 100, 240, 165, 116, 240, 164, 148, 240, 147, 164, 240, 147, 179, 240, 132, 180, 240, 116, 180, 240,
    116, 195, 240, 115, 212, 240, 84,  212, 240, 84,  227, 240, 84,  228, 240, 53,  214, 220, 138, 0,   62,  112, 72,  30,  0,   16,  13,
    240, 100, 240, 179, 240, 180, 240, 180, 240, 180, 240, 179, 240, 195, 240, 180, 240, 180, 240, 179, 240, 195, 240, 180, 240, 180, 240,
    179, 240, 195, 240, 180, 240, 180, 240, 179, 240, 195, 240, 180, 240, 180, 225, 179, 241, 179, 226, 164, 225, 180, 210, 179, 225, 195,
    210, 180, 210, 180, 194, 196, 164, 180, 150, 127, 7,   0,   46,  168, 48,  0,   25,  9,   240, 72,  240, 21,  240, 53,  240, 81,  19,
    240, 33,  19,  240, 97,  19,  240, 33,  19,  240, 82,  19,  240, 17,  20,  240, 82,  19,  240, 17,  19,  240, 97,  35,  241, 35,  240,
    97,  35,  241, 35,  240, 82,  35,  225, 36,  240, 82,  35,  209, 51,  240, 97,  51,  209, 51,  240, 97,  52,  177, 67,  240, 97,  67,
    177, 52,  240, 82,  67,  161, 67,  240, 97,  83,  145, 83,  240, 97,  83,  145, 83,  240, 97,  83,  129, 84,  240, 82,  83,  129, 83,
    240, 98,  83,  113, 99,  240, 97,  99,  113, 99,  240, 97,  99,  97,  115, 240, 82,  100, 65,  115, 240, 98,  100, 65,  115, 240, 97,
    131, 49,  131, 240, 97,  131, 49,  131, 240, 82,  131, 33,  132, 240, 82,  131, 17,  147, 240, 97,  147, 17,  147, 240, 97,  148, 163,
    240, 82,  148, 148, 240, 82,  147, 163, 240, 84,  131, 163, 240, 26,  98,  108, 0,   73,  64,  129, 41,  0,   21,  72,  186, 240, 20,
    228, 240, 69,  210, 240, 86,  210, 240, 82,  19,  210, 240, 81,  36,  193, 240, 97,  36,  193, 240, 97,  51,  178, 240, 82,  52,  162,
    240, 81,  83,  161, 240, 97,  83,  161, 240, 97,  84,  130, 240, 82,  99,  130, 240, 82,  99,  129, 240, 97,  116, 113, 240, 97,  131,
    113, 240, 82,  131, 98,  240, 82,  132, 81,  240, 97,  163, 81,  240, 97,  163, 81,  240, 82,  164, 50,  240, 82,  179, 49,  240, 97,
    195, 49,  240, 97,  196, 33,  240, 82,  211, 18,  240, 82,  211, 17,  240, 97,  229, 240, 97,  244, 240, 82,  244, 240, 82,  243, 240,
    98,  240, 18,  240, 83,  240, 18,  240, 26,  210, 0,   63,  64,  104, 34,  0,   14,  103, 240, 147, 84,  240, 83,  147, 240, 51,  179,
    240, 19,  211, 227, 227, 211, 244, 179, 240, 35,  163, 240, 52,  132, 240, 52,  131, 240, 68,  116, 240, 68,  115, 240, 84,  100, 240,
    84,  100, 240, 84,  84,  240, 100, 84,  240, 85,  84,  240, 84,  85,  240, 84,  85,  240, 84,  84,  240, 84,  100, 240, 84,  100, 240,
    69,  100, 240, 68,  116, 240, 52,  132, 240, 52,  132, 240, 36,  163, 240, 35,  180, 243, 211, 227, 227, 211, 240, 19,  179, 240, 51,
    147, 240, 84,  83,  240, 151, 0,   49,  32,  92,  35,  0,   18,  79,  3,   240, 84,  148, 240, 52,  179, 240, 35,  211, 240, 19,  212,
    243, 212, 228, 212, 227, 228, 227, 228, 227, 212, 228, 212, 228, 211, 243, 212, 243, 196, 244, 179, 240, 36,  148, 240, 62,  240, 99,
    240, 240, 20,  240, 240, 20,  240, 240, 19,  240, 240, 35,  240, 240, 20,  240, 240, 20,  240, 240, 19,  240, 240, 35,  240, 240, 20,
    240, 240, 20,  240, 240, 19,  240, 240, 35,  240, 240, 35,  240, 240, 20,  240, 204, 0,   55,  48,  135, 34,  0,   14,  103, 240, 147,
    84,  240, 83,  147, 240, 51,  179, 240, 19,  211, 227, 227, 211, 244, 179, 240, 35,  164, 240, 36,  132, 240, 52,  131, 240, 68,  116,
    240, 68,  116, 240, 68,  100, 240, 84,  100, 240, 84,  85,  240, 84,  84,  240, 85,  84,  240, 84,  85,  240, 84,  85,  240, 84,  84,
    240, 84,  100, 240, 84,  100, 240, 84,  100, 240, 68,  116, 240, 67,  132, 240, 52,  132, 240, 51,  163, 115, 115, 180, 81,  49,  84,
    195, 65,  81,  52,  211, 49,  97,  50,  240, 19,  33,  97,  19,  240, 51,  17,  100, 240, 84,  83,  240, 151, 17,  129, 240, 130, 129,
    240, 130, 113, 240, 147, 82,  240, 147, 67,  240, 153, 240, 168, 240, 198, 240, 228, 0,   14,  64,  95,  34,  0,   18,  15,  2,   240,
    84,  132, 240, 52,  163, 240, 35,  195, 240, 19,  196, 243, 196, 228, 196, 227, 212, 227, 212, 227, 197, 212, 196, 228, 195, 243, 196,
    243, 179, 240, 20,  163, 240, 36,  131, 240, 77,  240, 99,  131, 240, 68,  147, 240, 52,  162, 240, 51,  179, 240, 35,  179, 240, 20,
    179, 240, 20,  179, 240, 19,  195, 240, 19,  180, 244, 180, 244, 180, 243, 196, 81,  147, 196, 66,  132, 196, 65,  148, 196, 50,  92,
    147, 49,  240, 213, 0,   47,  80,  81,  30,  0,   13,  5,   82,  240, 18,  82,  49,  242, 130, 18,  226, 164, 211, 164, 210, 194, 211,
    194, 210, 210, 195, 210, 195, 209, 211, 209, 211, 209, 212, 240, 181, 240, 182, 240, 153, 240, 122, 240, 106, 240, 136, 240, 166, 240,
    180, 240, 180, 240, 195, 193, 227, 178, 227, 178, 227, 178, 226, 194, 226, 179, 211, 179, 210, 195, 194, 212, 162, 211, 18,  130, 226,
    51,  82,  241, 102, 0,   43,  48,  83,  34,  0,   17,  79,  11,  127, 12,  116, 131, 132, 114, 148, 147, 98,  164, 161, 114, 163, 177,
    113, 179, 177, 98,  164, 177, 98,  164, 162, 97,  180, 162, 82,  179, 177, 240, 52,  240, 244, 240, 244, 240, 243, 240, 244, 240, 244,
    240, 244, 240, 243, 240, 244, 240, 244, 240, 244, 240, 243, 240, 244, 240, 244, 240, 244, 240, 243, 240, 244, 240, 244, 240, 244, 240,
    243, 240, 244, 240, 159, 1,   0,   53,  16,  91,  34,  0,   17,  28,  122, 148, 228, 195, 240, 18,  211, 240, 17,  212, 242, 212, 241,
    227, 240, 17,  227, 240, 17,  212, 242, 212, 241, 227, 240, 17,  227, 240, 17,  227, 242, 212, 242, 212, 241, 227, 240, 17,  227, 240,
    17,  212, 242, 212, 241, 227, 240, 17,  227, 240, 17,  212, 242, 212, 241, 227, 240, 17,  227, 242, 227, 241, 243, 226, 243, 225, 240,
    19,  209, 240, 50,  194, 240, 51,  162, 240, 83,  129, 240, 131, 82,  240, 182, 0,   49,  80,  103, 35,  0,   17,  75,  185, 117, 240,
    21,  148, 240, 50,  195, 240, 34,  211, 240, 33,  227, 240, 18,  227, 240, 17,  244, 226, 244, 210, 240, 20,  209, 240, 36,  194, 240,
    36,  193, 240, 52,  178, 240, 52,  162, 240, 83,  161, 240, 99,  146, 240, 99,  145, 240, 116, 114, 240, 116, 113, 240, 132, 97,  240,
    148, 82,  240, 148, 81,  240, 164, 66,  240, 164, 65,  240, 195, 49,  240, 211, 34,  240, 211, 33,  240, 230, 240, 229, 240, 244, 240,
    240, 20,  240, 240, 19,  240, 240, 35,  240, 240, 34,  0,   51,  64,  142, 47,  0,   23,  75,  91,  121, 116, 197, 197, 148, 196, 226,
    180, 196, 225, 196, 196, 210, 196, 196, 209, 212, 196, 194, 212, 181, 193, 228, 177, 19,  178, 228, 162, 19,  177, 244, 161, 35,  162,
    244, 146, 35,  146, 240, 20,  145, 51,  145, 240, 36,  130, 51,  130, 240, 51,  129, 67,  129, 240, 67,  114, 67,  114, 240, 67,  113,
    83,  113, 240, 83,  97,  100, 82,  240, 83,  97,  100, 81,  240, 99,  81,  116, 66,  240, 99,  66,  116, 65,  240, 115, 65,  132, 50,
    240, 115, 50,  132, 49,  240, 132, 33,  148, 34,  240, 132, 18,  148, 33,  240, 148, 17,  164, 18,  240, 150, 164, 17,  240, 165, 181,
    240, 181, 181, 240, 180, 196, 240, 196, 196, 240, 195, 211, 240, 210, 242, 240, 210, 241, 0,   67,  96,  111, 41,  0,   21,  91,  122,
    240, 21,  196, 240, 100, 194, 240, 132, 193, 240, 164, 161, 240, 180, 146, 240, 180, 130, 240, 212, 98,  240, 228, 97,  240, 244, 81,
    240, 240, 36,  49,  240, 240, 52,  34,  240, 240, 52,  18,  240, 240, 85,  240, 240, 100, 240, 240, 131, 240, 240, 132, 240, 240, 101,
    240, 240, 82,  20,  240, 240, 50,  36,  240, 240, 49,  52,  240, 240, 33,  84,  240, 241, 100, 240, 226, 100, 240, 210, 132, 240, 178,
    148, 240, 177, 164, 240, 161, 196, 240, 129, 212, 240, 114, 213, 240, 82,  244, 240, 52,  229, 234, 171, 0,   62,  96,  100, 35,  0,
    17,  75,  200, 117, 240, 21,  164, 240, 19,  196, 240, 18,  212, 242, 244, 210, 240, 20,  209, 240, 36,  193, 240, 52,  178, 240, 68,
    146, 240, 84,  130, 240, 100, 129, 240, 132, 97,  240, 148, 82,  240, 148, 66,  240, 180, 34,  240, 196, 33,  240, 212, 17,  240, 245,
    240, 244, 240, 240, 19,  240, 240, 35,  240, 240, 20,  240, 240, 20,  240, 240, 19,  240, 240, 35,  240, 240, 20,  240, 240, 20,  240,
    240, 19,  240, 240, 35,  240, 240, 20,  240, 240, 20,  240, 204, 0,   55,  16,  79,  33,  0,   17,  95,  5,   198, 180, 196, 196, 211,
    196, 226, 196, 226, 196, 242, 180, 240, 17,  196, 242, 180, 240, 17,  180, 240, 212, 240, 212, 240, 227, 240, 228, 240, 212, 240, 212,
    240, 212, 240, 212, 240, 227, 240, 228, 240, 212, 161, 240, 36,  177, 240, 20,  178, 240, 19,  193, 240, 19,  209, 244, 194, 228, 210,
    212, 210, 212, 211, 211, 212, 195, 182, 207, 6,   207, 6,   0,   51,  101, 22,  240, 240, 70,  240, 17,  240, 97,  240, 82,  240, 82,
    240, 82,  240, 81,  240, 82,  240, 82,  240, 82,  240, 81,  240, 82,  240, 82,  240, 82,  240, 81,  240, 82,  240, 82,  240, 82,  240,
    81,  240, 82,  240, 82,  240, 82,  240, 81,  240, 82,  240, 82,  240, 82,  240, 81,  240, 82,  240, 82,  240, 82,  240, 81,  240, 82,
    240, 82,  240, 82,  240, 82,  240, 66,  240, 82,  240, 82,  240, 82,  240, 66,  240, 82,  240, 82,  240, 82,  240, 66,  240, 82,  240,
    82,  240, 82,  240, 70,  240, 16,  35,  20,  0,   8,   33,  129, 145, 129, 145, 129, 145, 129, 145, 129, 161, 129, 145, 129, 161, 129,
    145, 129, 164, 84,  117, 69,  101, 69,  101, 69,  115, 99,  0,   80,  112, 101, 22,  240, 240, 70,  240, 82,  240, 66,  240, 82,  240,
    82,  240, 82,  240, 81,  240, 82,  240, 82,  240, 82,  240, 81,  240, 82,  240, 82,  240, 82,  240, 81,  240, 82,  240, 82,  240, 82,
    240, 81,  240, 82,  240, 82,  240, 82,  240, 81,  240, 82,  240, 82,  240, 82,  240, 81,  240, 82,  240, 82,  240, 82,  240, 81,  240,
    82,  240, 82,  240, 82,  240, 81,  240, 97,  240, 82,  240, 82,  240, 81,  240, 97,  240, 82,  240, 82,  240, 81,  240, 97,  240, 82,
    240, 82,  240, 81,  240, 22,  240, 16,  19,  16,  0,   8,   113, 227, 179, 18,  146, 50,  130, 82,  98,  114, 65,  161, 0,   76,  64,
    12,  9,   0,   5,   99,  85,  69,  69,  83,  0,   44,  64,  21,  11,  240, 240, 145, 145, 145, 145, 145, 161, 145, 161, 145, 164, 117,
    101, 101, 115, 0,   44,  112, 62,  24,  0,   46,  5,   240, 50,  50,  19,  179, 81,  19,  163, 100, 178, 131, 163, 131, 147, 147, 147,
    131, 148, 131, 147, 147, 147, 147, 132, 146, 148, 131, 147, 147, 147, 147, 65,  67,  146, 66,  67,  131, 65,  83,  131, 65,  98,  116,
    50,  99,  81,  19,  49,  130, 50,  50,  34,  149, 84,  0,   36,  112, 73,  21,  0,   10,  104, 240, 35,  240, 51,  240, 51,  240, 36,
    240, 35,  240, 51,  240, 51,  240, 35,  240, 51,  240, 51,  240, 36,  37,  163, 33,  66,  149, 83,  132, 114, 116, 131, 100, 131, 99,
    147, 99,  147, 84,  147, 83,  148, 83,  148, 68,  147, 84,  147, 83,  148, 83,  147, 99,  147, 99,  131, 115, 130, 146, 115, 147, 83,
    179, 50,  244, 0,   33,  16,  49,  21,  0,   40,  69,  227, 66,  178, 114, 146, 115, 130, 116, 115, 116, 99,  131, 115, 240, 36,  240,
    35,  240, 51,  240, 36,  240, 35,  240, 51,  240, 51,  240, 51,  240, 51,  194, 82,  178, 98,  162, 130, 130, 147, 82,  214, 0,   32,
    112, 83,  25,  0,   14,  39,  240, 100, 240, 115, 240, 99,  240, 115, 240, 115, 240, 114, 240, 115, 240, 115, 240, 115, 240, 114, 245,
    35,  226, 50,  19,  195, 81,  19,  179, 100, 194, 131, 179, 131, 163, 147, 163, 131, 164, 131, 163, 147, 163, 147, 148, 146, 164, 131,
    163, 147, 163, 147, 65,  83,  146, 66,  83,  131, 65,  99,  131, 65,  114, 116, 50,  115, 81,  19,  49,  146, 50,  50,  34,  165, 84,
    0,   38,  64,  48,  21,  0,   40,  69,  227, 66,  163, 114, 131, 130, 115, 146, 115, 146, 99,  162, 84,  146, 100, 130, 115, 100, 123,
    164, 240, 35,  240, 51,  240, 51,  240, 51,  240, 51,  209, 82,  194, 82,  178, 114, 130, 147, 83,  198, 0,   32,  112, 103, 27,  0,
    12,  36,  240, 114, 50,  240, 66,  51,  240, 51,  36,  240, 50,  51,  240, 51,  240, 147, 240, 147, 240, 147, 240, 146, 240, 147, 240,
    147, 240, 147, 240, 91,  240, 67,  240, 147, 240, 147, 240, 147, 240, 147, 240, 146, 240, 147, 240, 147, 240, 147, 240, 147, 240, 146,
    240, 147, 240, 147, 240, 147, 240, 147, 240, 147, 240, 146, 240, 147, 240, 147, 240, 147, 240, 147, 240, 146, 240, 147, 240, 147, 240,
    51,  50,  240, 52,  50,  240, 52,  34,  240, 67,  50,  240, 81,  50,  240, 116, 0,   9,   48,  74,  25,  0,   48,  37,  240, 66,  50,
    18,  211, 81,  19,  179, 100, 179, 131, 179, 131, 163, 147, 163, 131, 164, 131, 163, 147, 163, 147, 148, 131, 164, 131, 163, 147, 163,
    147, 163, 146, 179, 131, 179, 131, 194, 116, 195, 84,  226, 50,  19,  245, 35,  240, 115, 240, 115, 240, 99,  240, 115, 179, 131, 179,
    115, 180, 114, 195, 114, 226, 83,  240, 23,  0,   8,   32,  82,  25,  0,   13,  7,   240, 99,  240, 115, 240, 115, 240, 115, 240, 99,
    240, 115, 240, 115, 240, 115, 240, 99,  240, 115, 240, 115, 53,  227, 18,  51,  195, 18,  83,  181, 99,  180, 115, 179, 131, 164, 131,
    163, 147, 163, 132, 163, 131, 163, 147, 163, 147, 163, 132, 163, 131, 163, 147, 65,  83,  147, 65,  83,  132, 50,  83,  131, 65,  83,
    147, 50,  83,  147, 49,  99,  162, 33,  114, 180, 0,   38,  64,  48,  16,  0,   11,  19,  196, 196, 195, 0,   13,  20,  178, 34,  145,
    67,  114, 67,  113, 83,  113, 68,  98,  67,  113, 83,  196, 195, 196, 196, 195, 196, 195, 81,  115, 66,  100, 66,  99,  81,  115, 66,
    115, 65,  146, 49,  180, 0,   25,  81,  23,  0,   16,  50,  240, 84,  240, 68,  240, 67,  0,   19,  36,  240, 34,  50,  240, 17,  67,
    225, 83,  210, 83,  209, 99,  194, 84,  193, 100, 240, 67,  240, 83,  240, 83,  240, 68,  240, 67,  240, 83,  240, 83,  240, 68,  240,
    67,  240, 83,  240, 83,  240, 68,  240, 67,  240, 83,  240, 83,  240, 83,  240, 68,  240, 67,  195, 83,  180, 67,  196, 67,  195, 67,
    210, 66,  240, 37,  0,   7,   96,  87,  24,  0,   12,  70,  240, 99,  240, 99,  240, 99,  240, 99,  240, 98,  240, 99,  240, 99,  240,
    99,  240, 98,  240, 99,  240, 99,  116, 163, 82,  50,  146, 82,  51,  131, 66,  52,  131, 65,  68,  131, 49,  83,  147, 33,  240, 35,
    33,  240, 51,  18,  240, 53,  240, 70,  240, 35,  51,  243, 67,  227, 83,  210, 99,  195, 99,  66,  99,  99,  66,  99,  98,  81,  114,
    114, 66,  99,  114, 65,  115, 130, 34,  114, 163, 0,   37,  16,  46,  14,  0,   7,   55,  179, 179, 163, 179, 179, 179, 163, 179, 179,
    179, 163, 179, 179, 179, 163, 179, 179, 179, 163, 179, 179, 164, 163, 179, 179, 65,  84,  50,  83,  66,  83,  65,  99,  65,  99,  49,
    130, 34,  148, 0,   22,  91,  40,  0,   75,  52,  101, 118, 178, 34,  50,  66,  66,  67,  161, 50,  34,  83,  34,  99,  129, 69,  114,
    18,  115, 129, 68,  132, 131, 114, 67,  147, 147, 114, 52,  132, 147, 113, 67,  147, 163, 195, 147, 147, 211, 147, 147, 195, 147, 163,
    195, 147, 148, 195, 147, 147, 211, 147, 147, 195, 147, 148, 65,  115, 147, 147, 81,  115, 147, 132, 66,  115, 147, 131, 81,  115, 147,
    147, 66,  115, 147, 147, 65,  131, 147, 162, 49,  146, 162, 196, 0,   61,  66,  28,  0,   52,  116, 102, 178, 34,  50,  67,  161, 50,
    34,  99,  129, 69,  115, 129, 68,  131, 114, 67,  147, 114, 52,  147, 113, 67,  163, 195, 147, 211, 147, 195, 163, 195, 148, 195, 147,
    211, 147, 195, 148, 65,  115, 147, 81,  115, 132, 66,  115, 131, 81,  115, 147, 66,  115, 147, 65,  131, 162, 49,  146, 196, 0,   43,
    49,  23,  0,   44,  53,  243, 67,  195, 98,  178, 146, 147, 146, 131, 163, 99,  179, 99,  179, 84,  179, 83,  195, 83,  180, 68,  180,
    67,  195, 83,  180, 83,  179, 99,  179, 99,  163, 130, 147, 146, 146, 178, 114, 210, 67,  246, 0,   36,  16,  81,  27,  0,   51,  52,
    85,  194, 34,  50,  50,  177, 51,  17,  83,  146, 52,  114, 145, 67,  131, 129, 67,  131, 114, 66,  147, 113, 67,  147, 195, 147, 195,
    132, 194, 148, 179, 147, 195, 147, 195, 132, 194, 147, 195, 147, 195, 131, 211, 130, 227, 115, 211, 17,  83,  227, 18,  50,  240, 19,
    37,  240, 35,  240, 131, 240, 147, 240, 147, 240, 147, 240, 131, 240, 147, 240, 147, 240, 105, 0,   12,  48,  72,  22,  0,   42,  37,
    65,  178, 50,  34,  147, 81,  19,  131, 100, 146, 131, 131, 131, 115, 147, 115, 131, 116, 131, 115, 147, 115, 147, 100, 146, 116, 131,
    115, 147, 115, 147, 115, 146, 131, 131, 131, 131, 146, 116, 147, 81,  19,  162, 50,  19,  197, 35,  240, 67,  240, 67,  240, 51,  240,
    67,  240, 67,  240, 67,  240, 51,  240, 67,  251, 0,   9,   16,  59,  22,  0,   41,  83,  100, 129, 34,  50,  66,  82,  50,  18,  82,
    81,  66,  17,  83,  66,  67,  99,  66,  52,  98,  81,  67,  225, 67,  240, 66,  240, 67,  240, 67,  240, 67,  240, 66,  240, 67,  240,
    67,  240, 67,  240, 66,  240, 67,  240, 67,  240, 67,  240, 66,  240, 82,  0,   35,  32,  44,  19,  0,   36,  85,  210, 50,  177, 98,
    146, 113, 145, 99,  130, 99,  130, 99,  131, 240, 20,  247, 216, 199, 245, 240, 19,  240, 34,  99,  130, 84,  130, 84,  129, 99,  130,
    98,  130, 130, 98,  182, 0,   29,  96,  44,  17,  0,   15,  114, 227, 227, 227, 227, 211, 227, 227, 226, 157, 147, 227, 211, 227, 227,
    227, 211, 227, 227, 212, 211, 227, 227, 97,  100, 97,  99,  98,  99,  97,  115, 82,  115, 66,  146, 50,  180, 0,   26,  96,  66,  27,
    0,   51,  20,  240, 113, 50,  147, 129, 67,  131, 114, 67,  130, 129, 83,  115, 114, 68,  115, 113, 83,  131, 113, 68,  115, 211, 131,
    211, 131, 196, 131, 195, 131, 211, 131, 196, 131, 195, 147, 65,  115, 131, 66,  115, 131, 65,  131, 131, 65,  131, 116, 50,  147, 100,
    49,  163, 66,  34,  34,  197, 84,  0,   41,  48,  58,  23,  0,   43,  84,  130, 129, 50,  100, 97,  67,  84,  82,  67,  99,  81,  83,
    99,  66,  68,  114, 65,  83,  130, 65,  68,  129, 163, 145, 163, 145, 148, 130, 147, 146, 147, 145, 148, 145, 147, 146, 147, 145, 163,
    130, 163, 129, 179, 114, 195, 97,  227, 50,  240, 22,  0,   35,  112, 82,  33,  0,   62,  52,  240, 50,  129, 50,  146, 84,  97,  67,
    115, 84,  81,  83,  115, 99,  81,  83,  115, 99,  66,  68,  99,  130, 65,  83,  115, 130, 65,  68,  115, 129, 163, 131, 129, 163, 115,
    145, 148, 115, 130, 147, 131, 129, 163, 131, 129, 148, 115, 145, 147, 131, 130, 147, 131, 129, 163, 131, 129, 163, 131, 113, 179, 116,
    113, 195, 97,  19,  81,  227, 50,  35,  65,  240, 37,  85,  0,   50,  112, 64,  26,  0,   49,  84,  100, 177, 51,  34,  50,  145, 82,
    33,  66,  129, 100, 67,  114, 100, 67,  113, 116, 66,  114, 115, 225, 131, 225, 131, 240, 115, 240, 131, 240, 131, 240, 131, 240, 115,
    240, 131, 240, 131, 114, 227, 113, 115, 68,  98,  100, 68,  97,  116, 53,  81,  130, 66,  34,  65,  181, 69,  0,   40,  32,  78,  25,
    0,   47,  52,  240, 81,  50,  147, 97,  67,  131, 82,  67,  115, 97,  83,  115, 82,  68,  115, 81,  83,  131, 81,  68,  115, 179, 131,
    179, 131, 164, 131, 163, 131, 179, 131, 164, 131, 163, 147, 163, 131, 179, 131, 179, 131, 179, 116, 195, 84,  211, 69,  245, 35,  240,
    115, 240, 99,  179, 131, 179, 130, 180, 115, 179, 115, 209, 130, 225, 114, 242, 67,  240, 53,  0,   8,   48,  55,  23,  0,   44,  19,
    113, 166, 81,  167, 66,  162, 66,  49,  162, 100, 177, 146, 240, 82,  240, 82,  240, 97,  240, 97,  240, 97,  240, 97,  240, 97,  240,
    97,  240, 97,  240, 97,  161, 161, 162, 146, 162, 148, 114, 146, 35,  66,  146, 72,  130, 102, 145, 131, 0,   33,  9,   26,  0,   78,
    15,  7,   0,   78,  64,  14,  47,  0,   127, 0,   14,  15,  15,  13,  0,   127, 0,   14,  64,  25,  18,  0,   7,   50,  82,  131, 67,
    115, 67,  131, 67,  115, 67,  130, 82,  130, 82,  130, 82,  145, 97,  0,   84,  64,  15,  19,  0,   12,  51,  113, 117, 81,  98,  51,
    34,  97,  115, 0,   96,
};

//*****************************************************************************
//
// The font definition for the 48 point Cm italic font.
//
//*****************************************************************************
const tFont g_sFontCm48i = {
    //
    // The format of the font.
    //
    FONT_FMT_PIXEL_RLE,

    //
    // The maximum width of the font.
    //
    43,

    //
    // The height of the font.
    //
    49,

    //
    // The baseline of the font.
    //
    37,

    //
    // The offset to each character in the font.
    //
    {
     0,    5,    45,   80,   214,  303,  448,  571,  592,  694,  795,  847,  936,  957,  967,  979,  1081, 1154, 1222,
     1307, 1385, 1475, 1548, 1624, 1702, 1775, 1851, 1870, 1898, 1938, 1951, 2021, 2091, 2217, 2314, 2398, 2503, 2609,
     2707, 2800, 2904, 3008, 3079, 3154, 3262, 3334, 3502, 3631, 3735, 3827, 3962, 4057, 4138, 4221, 4312, 4415, 4557,
     4668, 4768, 4847, 4948, 4983, 5084, 5103, 5115, 5136, 5198, 5271, 5320, 5403, 5451, 5554, 5628, 5710, 5758, 5839,
     5926, 5972, 6063, 6129, 6178, 6259, 6331, 6390, 6434, 6478, 6544, 6602, 6684, 6748, 6826, 6881, 6890, 6904, 6929,
     },

    //
    // A pointer to the actual font data
    //
    g_pui8Cm48iData
};

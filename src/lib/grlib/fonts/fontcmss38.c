//*****************************************************************************
//
// fontcmss38.c - Font definition for the 38pt Cmss font.
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
//     Size: 38 point
//     Bold: no
//     Italic: no
//     Memory usage: 4132 bytes
//
//*****************************************************************************

//*****************************************************************************
//
// The compressed data for the 38 point Cmss font.
// Contains characters 32 to 126 inclusive.
//
//*****************************************************************************
static const uint8_t g_pui8Cmss38Data[3930] = {
    5,   15,  0,   69,  48,  29,  6,   195, 51,  51,  51,  51,  51,  51,  51,  51,  51,  51,  51,  51,  51,  51,  51,  51,  51,  51,  51,
    240, 99,  51,  51,  0,   7,   16,  22,  13,  240, 179, 67,  51,  67,  51,  67,  66,  82,  66,  82,  50,  82,  66,  82,  66,  82,  0,
    44,  48,  101, 28,  0,   8,   65,  113, 240, 65,  113, 240, 50,  98,  240, 49,  113, 240, 65,  113, 240, 65,  113, 240, 50,  98,  240,
    49,  113, 240, 65,  113, 240, 65,  113, 240, 50,  98,  240, 50,  98,  240, 49,  113, 175, 10,  178, 98,  240, 49,  113, 240, 65,  113,
    240, 65,  113, 240, 65,  113, 240, 50,  98,  191, 10,  161, 113, 240, 50,  98,  240, 50,  98,  240, 49,  113, 240, 65,  113, 240, 50,
    98,  240, 49,  113, 240, 65,  113, 240, 65,  113, 240, 50,  98,  240, 49,  113, 240, 65,  113, 0,   8,   112, 54,  17,  98,  242, 229,
    169, 123, 84,  18,  50,  83,  34,  65,  67,  50,  147, 50,  147, 50,  147, 50,  148, 34,  164, 18,  183, 184, 183, 183, 162, 36,  146,
    36,  146, 51,  146, 51,  146, 51,  146, 51,  49,  82,  35,  67,  50,  20,  91,  121, 165, 226, 242, 0,   16,  89,  28,  52,  194, 150,
    177, 147, 35,  146, 146, 51,  145, 147, 67,  114, 147, 67,  113, 163, 67,  98,  163, 67,  97,  179, 67,  82,  179, 67,  81,  210, 51,
    82,  211, 35,  81,  246, 81,  240, 37,  81,  240, 177, 240, 193, 84,  240, 33,  86,  242, 67,  35,  225, 83,  35,  210, 67,  67,  193,
    83,  67,  178, 83,  67,  177, 99,  67,  162, 99,  67,  161, 115, 67,  146, 115, 67,  145, 147, 35,  146, 147, 35,  145, 182, 146, 196,
    0,   25,  32,  73,  27,  0,   7,   100, 240, 119, 240, 67,  35,  240, 66,  67,  240, 35,  67,  240, 35,  67,  240, 35,  67,  240, 35,
    51,  240, 51,  51,  240, 51,  35,  240, 86,  240, 101, 240, 116, 163, 164, 163, 149, 162, 132, 19,  131, 116, 35,  130, 115, 83,  99,
    99,  100, 67,  115, 116, 51,  115, 116, 35,  131, 135, 163, 133, 180, 88,  188, 25,  119, 103, 0,   30,  96,  13,  6,   195, 51,  51,
    66,  66,  50,  66,  66,  0,   20,  96,  40,  12,  99,  131, 146, 146, 147, 146, 147, 147, 146, 147, 147, 147, 131, 147, 147, 147, 147,
    147, 147, 147, 147, 147, 147, 147, 147, 163, 147, 147, 147, 163, 147, 162, 163, 162, 178, 163, 163, 48,  40,  12,  3,   163, 163, 162,
    163, 162, 163, 147, 163, 147, 147, 147, 163, 147, 147, 147, 147, 147, 147, 147, 147, 147, 147, 147, 147, 131, 147, 147, 147, 131, 147,
    146, 147, 146, 146, 147, 131, 144, 28,  16,  83,  211, 211, 211, 130, 51,  50,  52,  19,  20,  75,  119, 165, 153, 84,  19,  20,  51,
    35,  35,  131, 211, 211, 211, 0,   43,  51,  26,  0,   24,  17,  240, 161, 240, 161, 240, 161, 240, 161, 240, 161, 240, 161, 240, 161,
    240, 161, 240, 161, 240, 161, 239, 8,   225, 240, 161, 240, 161, 240, 161, 240, 161, 240, 161, 240, 161, 240, 161, 240, 161, 240, 161,
    240, 161, 0,   24,  64,  14,  6,   0,   18,  99,  51,  51,  66,  66,  50,  66,  66,  240, 208, 9,   12,  0,   28,  73,  57,  0,   24,
    48,  10,  6,   0,   18,  99,  51,  51,  0,   7,   16,  49,  17,  209, 242, 241, 240, 17,  242, 241, 240, 17,  242, 241, 242, 242, 241,
    242, 241, 240, 17,  242, 241, 240, 17,  242, 241, 240, 17,  242, 241, 240, 17,  242, 241, 242, 242, 241, 242, 241, 240, 17,  242, 241,
    240, 17,  242, 241, 240, 16,  51,  18,  0,   9,   85,  185, 132, 52,  115, 83,  99,  115, 83,  115, 82,  147, 51,  147, 51,  147, 51,
    147, 51,  147, 51,  147, 51,  147, 51,  147, 51,  147, 51,  147, 51,  147, 51,  147, 67,  115, 83,  115, 99,  84,  100, 52,  137, 181,
    0,   21,  32,  32,  15,  0,   8,   49,  195, 120, 116, 19,  195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195,
    195, 195, 195, 139, 75,  0,   17,  32,  35,  17,  0,   9,   5,   169, 115, 68,  83,  115, 66,  132, 50,  147, 227, 227, 227, 227, 211,
    211, 227, 211, 210, 226, 226, 226, 226, 226, 226, 238, 62,  62,  0,   19,  64,  38,  17,  0,   9,   6,   153, 115, 83,  83,  115, 81,
    131, 227, 227, 227, 211, 211, 166, 182, 240, 19,  243, 227, 243, 227, 227, 227, 49,  163, 50,  131, 68,  83,  121, 165, 0,   20,  16,
    42,  18,  0,   10,  4,   228, 213, 213, 194, 19,  194, 19,  179, 19,  178, 35,  163, 35,  147, 51,  147, 51,  131, 67,  131, 67,  115,
    83,  115, 83,  99,  99,  111, 63,  195, 243, 243, 243, 243, 243, 0,   21,  38,  17,  0,   8,   92,  92,  83,  227, 227, 227, 227, 227,
    227, 227, 21,  139, 101, 51,  99,  99,  83,  115, 227, 227, 227, 227, 227, 49,  147, 66,  131, 68,  83,  106, 165, 0,   20,  16,  46,
    18,  0,   9,   118, 168, 147, 226, 243, 227, 243, 242, 53,  115, 25,  86,  52,  84,  115, 68,  115, 67,  147, 51,  147, 51,  147, 51,
    147, 51,  147, 66,  147, 67,  131, 67,  115, 99,  99,  100, 52,  137, 181, 0,   21,  32,  31,  18,  0,   9,   15,  63,  63,  242, 242,
    243, 242, 243, 227, 242, 243, 243, 227, 243, 242, 243, 243, 243, 242, 243, 243, 243, 243, 243, 0,   21,  80,  49,  18,  0,   9,   85,
    185, 131, 83,  99,  115, 82,  146, 82,  147, 66,  146, 82,  146, 83,  115, 99,  83,  151, 183, 147, 83,  99,  115, 83,  115, 67,  147,
    51,  147, 51,  147, 51,  147, 67,  131, 67,  115, 99,  83,  137, 181, 0,   21,  32,  46,  18,  0,   9,   85,  185, 132, 67,  99,  114,
    99,  115, 67,  146, 67,  147, 51,  147, 51,  147, 51,  147, 51,  147, 67,  116, 67,  116, 83,  85,  89,  19,  117, 51,  242, 243, 243,
    227, 242, 130, 67,  137, 182, 0,   21,  48,  15,  6,   0,   9,   3,   51,  51,  0,   7,   115, 51,  51,  0,   7,   16,  19,  6,   0,
    9,   3,   51,  51,  0,   7,   115, 51,  51,  66,  66,  50,  66,  66,  240, 208, 28,  6,   0,   6,   99,  51,  51,  240, 195, 51,  51,
    51,  51,  51,  51,  51,  51,  51,  51,  51,  51,  51,  51,  51,  51,  51,  51,  240, 13,  26,  0,   48,  111, 8,   0,   19,  127, 8,
    0,   45,  112, 33,  15,  0,   17,  51,  195, 195, 0,   9,   3,   195, 195, 195, 195, 195, 179, 195, 179, 180, 179, 179, 195, 195, 195,
    195, 129, 67,  83,  75,  102, 240, 240, 96,  34,  16,  240, 240, 71,  123, 83,  84,  65,  132, 211, 211, 211, 211, 195, 196, 180, 180,
    180, 195, 211, 195, 211, 211, 211, 211, 0,   7,   83,  211, 211, 0,   19,  16,  67,  22,  0,   6,   70,  234, 180, 68,  147, 115, 131,
    147, 99,  88,  99,  74,  67,  67,  53,  67,  51,  84,  51,  67,  84,  51,  51,  115, 51,  51,  115, 51,  51,  115, 51,  51,  115, 51,
    51,  115, 51,  51,  115, 52,  51,  83,  83,  51,  83,  83,  67,  51,  115, 71,  131, 85,  163, 240, 83,  240, 84,  84,  171, 214, 0,
    25,  96,  61,  24,  0,   7,   19,  240, 85,  240, 69,  240, 66,  18,  240, 51,  19,  240, 35,  19,  240, 34,  35,  240, 19,  51,  243,
    51,  242, 68,  211, 83,  211, 83,  210, 100, 179, 115, 179, 115, 178, 132, 159, 159, 146, 179, 115, 179, 115, 179, 114, 211, 83,  211,
    83,  211, 67,  243, 51,  243, 0,   27,  48,  53,  21,  240, 240, 204, 158, 115, 117, 99,  148, 83,  164, 67,  179, 67,  179, 67,  179,
    67,  179, 67,  163, 83,  147, 99,  116, 124, 157, 131, 132, 99,  163, 83,  179, 67,  195, 51,  195, 51,  195, 51,  195, 51,  179, 67,
    164, 67,  133, 95,  108, 0,   24,  96,  55,  21,  0,   6,   40,  188, 132, 99,  115, 240, 35,  240, 35,  240, 51,  240, 35,  240, 51,
    240, 35,  240, 51,  240, 51,  240, 51,  240, 51,  240, 51,  240, 51,  240, 52,  240, 51,  240, 51,  240, 67,  240, 51,  240, 67,  240,
    67,  161, 132, 99,  156, 183, 0,   24,  48,  55,  23,  0,   5,   108, 190, 147, 133, 115, 164, 99,  179, 99,  195, 83,  196, 67,  211,
    67,  211, 67,  227, 51,  227, 51,  227, 51,  227, 51,  227, 51,  227, 51,  227, 51,  227, 51,  211, 67,  211, 67,  211, 67,  195, 83,
    179, 99,  164, 99,  133, 126, 156, 0,   27,  32,  57,  19,  240, 240, 143, 1,   63,  1,   63,  1,   51,  240, 19,  240, 19,  240, 19,
    240, 19,  240, 19,  240, 19,  240, 19,  240, 19,  240, 31,  79,  67,  240, 19,  240, 19,  240, 19,  240, 19,  240, 19,  240, 19,  240,
    19,  240, 19,  240, 31,  1,   63,  1,   63,  1,   0,   21,  96,  33,  18,  240, 240, 111, 63,  63,  51,  243, 243, 243, 243, 243, 243,
    243, 243, 254, 78,  67,  243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 0,   22,  16,  55,  22,  0,   6,   72,  205, 132, 100,
    115, 162, 99,  240, 51,  240, 67,  240, 51,  240, 67,  240, 51,  240, 67,  240, 67,  240, 67,  240, 67,  240, 67,  240, 67,  136, 52,
    120, 67,  195, 67,  195, 83,  179, 83,  179, 99,  163, 115, 147, 132, 100, 157, 184, 0,   25,  64,  58,  21,  240, 240, 195, 195, 51,
    195, 51,  195, 51,  195, 51,  195, 51,  195, 51,  195, 51,  195, 51,  195, 51,  195, 51,  195, 51,  195, 63,  3,   63,  3,   51,  195,
    51,  195, 51,  195, 51,  195, 51,  195, 51,  195, 51,  195, 51,  195, 51,  195, 51,  195, 51,  195, 51,  195, 0,   24,  31,  6,   195,
    51,  51,  51,  51,  51,  51,  51,  51,  51,  51,  51,  51,  51,  51,  51,  51,  51,  51,  51,  51,  51,  51,  51,  51,  51,  0,   7,
    16,  35,  15,  240, 240, 147, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195,
    49,  116, 51,  68,  74,  119, 0,   17,  80,  59,  22,  240, 240, 227, 195, 67,  179, 83,  164, 83,  148, 99,  132, 115, 116, 131, 100,
    147, 99,  163, 83,  179, 67,  195, 52,  195, 37,  195, 23,  183, 20,  166, 51,  165, 68,  148, 99,  147, 131, 131, 132, 115, 147, 115,
    148, 99,  164, 83,  179, 83,  180, 67,  195, 67,  211, 0,   25,  16,  33,  17,  240, 240, 67,  227, 227, 227, 227, 227, 227, 227, 227,
    227, 227, 227, 227, 227, 227, 227, 227, 227, 227, 227, 227, 227, 227, 227, 238, 62,  0,   19,  64,  96,  27,  0,   6,   101, 229, 53,
    229, 53,  229, 54,  198, 54,  198, 51,  18,  194, 19,  51,  19,  163, 19,  51,  19,  163, 19,  51,  34,  162, 35,  51,  35,  131, 35,
    51,  35,  131, 35,  51,  51,  114, 51,  51,  51,  99,  51,  51,  51,  99,  51,  51,  67,  82,  67,  51,  67,  67,  67,  51,  67,  66,
    83,  51,  83,  50,  83,  51,  83,  35,  83,  51,  83,  34,  99,  51,  99,  18,  99,  51,  102, 99,  51,  116, 115, 51,  116, 115, 51,
    116, 115, 51,  240, 51,  0,   30,  96,  76,  21,  240, 240, 197, 163, 53,  163, 54,  147, 54,  147, 51,  19,  131, 51,  19,  131, 51,
    35,  115, 51,  35,  115, 51,  36,  99,  51,  51,  99,  51,  51,  99,  51,  67,  83,  51,  67,  83,  51,  83,  67,  51,  83,  67,  51,
    99,  51,  51,  99,  51,  51,  100, 35,  51,  115, 35,  51,  115, 35,  51,  131, 19,  51,  131, 19,  51,  150, 51,  150, 51,  165, 51,
    165, 0,   24,  64,  25,  0,   7,   38,  240, 42,  227, 85,  179, 132, 147, 163, 131, 195, 114, 227, 83,  227, 83,  227, 67,  240, 19,
    51,  240, 19,  51,  240, 19,  51,  240, 19,  51,  240, 19,  51,  240, 19,  51,  240, 19,  52,  243, 67,  227, 83,  227, 84,  196, 99,
    195, 131, 163, 148, 132, 165, 68,  234, 240, 38,  0,   29,  64,  54,  20,  240, 240, 172, 142, 99,  132, 83,  148, 67,  163, 67,  179,
    51,  179, 51,  179, 51,  179, 51,  179, 51,  163, 67,  148, 67,  132, 94,  108, 131, 240, 35,  240, 35,  240, 35,  240, 35,  240, 35,
    240, 35,  240, 35,  240, 35,  240, 35,  240, 35,  0,   24,  80,  77,  25,  0,   7,   38,  240, 42,  228, 69,  179, 132, 147, 163, 131,
    195, 115, 211, 83,  227, 83,  227, 67,  240, 19,  51,  240, 19,  51,  240, 19,  51,  240, 19,  51,  240, 19,  51,  240, 19,  51,  240,
    19,  51,  240, 19,  67,  227, 83,  227, 84,  83,  83,  99,  99,  51,  131, 84,  19,  148, 87,  165, 69,  219, 240, 26,  240, 115, 240,
    116, 240, 115, 240, 131, 240, 116, 0,   13,  55,  22,  240, 240, 236, 175, 115, 133, 99,  164, 83,  179, 83,  195, 67,  195, 67,  195,
    67,  195, 67,  179, 83,  164, 83,  148, 111, 125, 147, 100, 147, 115, 147, 116, 131, 131, 131, 132, 115, 147, 115, 163, 99,  163, 99,
    179, 83,  180, 67,  195, 67,  196, 0,   25,  16,  48,  19,  240, 240, 215, 172, 100, 84,  83,  145, 83,  240, 19,  240, 19,  240, 19,
    240, 20,  240, 20,  247, 217, 201, 215, 245, 240, 19,  240, 20,  240, 19,  240, 19,  240, 19,  240, 19,  50,  163, 68,  101, 93,  123,
    182, 0,   22,  48,  58,  24,  0,   6,   15,  6,   63,  6,   63,  6,   195, 240, 99,  240, 99,  240, 99,  240, 99,  240, 99,  240, 99,
    240, 99,  240, 99,  240, 99,  240, 99,  240, 99,  240, 99,  240, 99,  240, 99,  240, 99,  240, 99,  240, 99,  240, 99,  240, 99,  240,
    99,  240, 99,  240, 99,  0,   28,  64,  57,  21,  240, 240, 195, 195, 51,  195, 51,  195, 51,  195, 51,  195, 51,  195, 51,  195, 51,
    195, 51,  195, 51,  195, 51,  195, 51,  195, 51,  195, 51,  195, 51,  195, 51,  195, 51,  195, 51,  195, 51,  195, 51,  195, 67,  163,
    83,  163, 99,  131, 132, 68,  170, 214, 0,   24,  96,  64,  25,  0,   6,   35,  240, 19,  51,  243, 68,  227, 83,  226, 99,  211, 100,
    195, 115, 194, 131, 179, 147, 163, 147, 147, 164, 131, 179, 131, 179, 115, 196, 99,  211, 98,  227, 83,  243, 67,  243, 66,  240, 19,
    51,  240, 35,  35,  240, 35,  34,  240, 51,  19,  240, 70,  240, 69,  240, 85,  240, 99,  0,   29,  96,  98,  34,  0,   8,   67,  179,
    179, 51,  180, 163, 51,  165, 163, 52,  149, 163, 67,  146, 18,  147, 83,  146, 19,  131, 83,  131, 19,  131, 99,  115, 19,  130, 115,
    114, 50,  115, 115, 99,  51,  99,  116, 83,  51,  99,  131, 82,  67,  98,  147, 82,  83,  67,  147, 67,  83,  67,  148, 51,  83,  67,
    163, 51,  83,  66,  179, 50,  115, 35,  179, 50,  115, 35,  195, 19,  115, 34,  211, 18,  131, 34,  211, 18,  146, 19,  211, 18,  150,
    229, 149, 244, 165, 244, 180, 244, 180, 0,   39,  48,  62,  24,  0,   6,   4,   211, 84,  179, 115, 164, 116, 147, 148, 115, 179, 100,
    195, 83,  212, 51,  244, 19,  240, 35,  19,  240, 53,  240, 68,  240, 99,  240, 85,  240, 55,  240, 35,  19,  240, 19,  51,  227, 68,
    211, 83,  195, 115, 163, 132, 147, 148, 115, 179, 100, 180, 83,  212, 51,  243, 0,   27,  48,  61,  26,  0,   6,   68,  244, 68,  227,
    99,  211, 116, 195, 132, 163, 163, 147, 180, 131, 195, 115, 212, 84,  228, 67,  240, 19,  51,  240, 36,  35,  240, 55,  240, 85,  240,
    101, 240, 115, 240, 131, 240, 131, 240, 131, 240, 131, 240, 131, 240, 131, 240, 131, 240, 131, 240, 131, 240, 131, 0,   30,  112, 59,
    21,  240, 240, 207, 2,   79,  2,   240, 36,  240, 35,  240, 36,  240, 20,  240, 35,  240, 36,  240, 35,  240, 36,  240, 20,  240, 35,
    240, 36,  240, 35,  240, 36,  240, 20,  240, 35,  240, 36,  240, 35,  240, 36,  240, 20,  240, 35,  240, 36,  240, 35,  240, 47,  3,
    63,  3,   0,   24,  40,  9,   6,   54,  51,  99,  99,  99,  99,  99,  99,  99,  99,  99,  99,  99,  99,  99,  99,  99,  99,  99,  99,
    99,  99,  99,  99,  99,  99,  99,  99,  99,  99,  99,  99,  99,  99,  102, 54,  48,  22,  13,  240, 194, 82,  66,  82,  66,  82,  50,
    82,  66,  82,  67,  67,  51,  67,  51,  67,  0,   44,  32,  40,  9,   6,   54,  99,  99,  99,  99,  99,  99,  99,  99,  99,  99,  99,
    99,  99,  99,  99,  99,  99,  99,  99,  99,  99,  99,  99,  99,  99,  99,  99,  99,  99,  99,  99,  99,  99,  54,  54,  48,  18,  15,
    240, 240, 83,  180, 166, 131, 35,  114, 66,  98,  98,  67,  99,  0,   52,  112, 9,   6,   240, 147, 51,  51,  0,   22,  112, 13,  6,
    210, 66,  66,  50,  66,  67,  51,  51,  0,   20,  80,  30,  16,  0,   24,  70,  122, 99,  83,  227, 211, 211, 211, 136, 91,  68,  83,
    51,  115, 51,  115, 51,  115, 52,  84,  76,  86,  35,  0,   18,  48,  46,  17,  240, 240, 67,  227, 227, 227, 227, 227, 227, 227, 227,
    227, 227, 37,  124, 85,  53,  67,  115, 67,  116, 51,  131, 51,  131, 51,  131, 51,  131, 51,  131, 51,  131, 51,  115, 67,  115, 68,
    68,  91,  99,  37,  0,   20,  25,  16,  0,   24,  86,  138, 84,  82,  67,  211, 195, 211, 211, 211, 211, 211, 227, 212, 212, 82,  106,
    134, 0,   18,  80,  48,  17,  240, 240, 243, 227, 227, 227, 227, 227, 227, 227, 227, 227, 117, 35,  107, 84,  68,  67,  115, 67,  115,
    51,  131, 51,  131, 51,  131, 51,  131, 51,  131, 51,  131, 67,  115, 67,  100, 84,  53,  88,  19,  117, 35,  0,   19,  64,  28,  17,
    0,   26,  21,  169, 116, 67,  84,  98,  83,  115, 51,  146, 62,  62,  51,  227, 227, 243, 228, 228, 83,  107, 134, 0,   19,  112, 32,
    15,  240, 240, 117, 135, 115, 194, 195, 195, 195, 195, 195, 195, 154, 90,  131, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195,
    195, 195, 0,   18,  46,  19,  0,   29,  20,  52,  109, 83,  67,  131, 99,  115, 99,  115, 99,  115, 99,  116, 83,  131, 67,  153, 146,
    36,  178, 240, 35,  240, 27,  156, 110, 68,  132, 51,  163, 51,  163, 51,  163, 68,  100, 108, 151, 0,   5,   96,  48,  15,  240, 243,
    195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 37,  83,  23,  69,  52,  52,  83,  51,  99,  51,  99,  51,  99,  51,  99,  51,  99,
    51,  99,  51,  99,  51,  99,  51,  99,  51,  99,  51,  99,  51,  99,  0,   17,  32,  27,  6,   240, 147, 51,  51,  240, 240, 51,  51,
    51,  51,  51,  51,  51,  51,  51,  51,  51,  51,  51,  51,  51,  51,  0,   7,   16,  35,  11,  0,   6,   19,  131, 131, 0,   7,   115,
    131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 49,  52,  55,  85,  240, 192, 47,  17,
    240, 240, 67,  227, 227, 227, 227, 227, 227, 227, 227, 227, 227, 100, 67,  84,  83,  68,  99,  52,  115, 36,  131, 20,  152, 152, 149,
    19,  132, 36,  115, 67,  115, 83,  99,  84,  83,  99,  83,  115, 67,  116, 0,   19,  64,  31,  6,   195, 51,  51,  51,  51,  51,  51,
    51,  51,  51,  51,  51,  51,  51,  51,  51,  51,  51,  51,  51,  51,  51,  51,  51,  51,  51,  0,   7,   16,  55,  25,  0,   37,  67,
    37,  70,  83,  23,  40,  69,  54,  68,  52,  84,  99,  51,  99,  115, 51,  99,  115, 51,  99,  115, 51,  99,  115, 51,  99,  115, 51,
    99,  115, 51,  99,  115, 51,  99,  115, 51,  99,  115, 51,  99,  115, 51,  99,  115, 51,  99,  115, 0,   28,  64,  39,  15,  0,   22,
    67,  37,  83,  23,  69,  52,  52,  83,  51,  99,  51,  99,  51,  99,  51,  99,  51,  99,  51,  99,  51,  99,  51,  99,  51,  99,  51,
    99,  51,  99,  51,  99,  0,   17,  32,  35,  19,  0,   29,  22,  186, 132, 68,  99,  131, 83,  131, 67,  163, 51,  163, 51,  163, 51,
    163, 51,  163, 51,  163, 67,  131, 84,  100, 100, 68,  138, 182, 0,   22,  48,  43,  17,  0,   25,  67,  52,  124, 85,  53,  67,  100,
    67,  116, 51,  131, 51,  131, 51,  131, 51,  131, 51,  131, 51,  131, 51,  115, 67,  100, 68,  68,  91,  99,  37,  115, 227, 227, 227,
    227, 227, 227, 0,   6,   45,  17,  0,   26,  5,   35,  107, 84,  53,  68,  84,  67,  115, 51,  131, 51,  131, 51,  131, 51,  131, 51,
    131, 51,  131, 67,  115, 68,  84,  84,  53,  88,  19,  117, 35,  227, 227, 227, 227, 227, 227, 227, 240, 240, 112, 25,  12,  0,   18,
    3,   51,  51,  21,  56,  69,  116, 132, 131, 147, 147, 147, 147, 147, 147, 147, 147, 147, 0,   14,  80,  26,  15,  0,   22,  119, 106,
    68,  82,  67,  195, 196, 198, 153, 136, 181, 195, 195, 49,  131, 51,  84,  59,  103, 0,   17,  80,  29,  14,  0,   12,  83,  179, 179,
    179, 179, 139, 59,  99,  179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 180, 49,  119, 117, 0,   16,  48,  39,  15,  0,   22,  67,
    99,  51,  99,  51,  99,  51,  99,  51,  99,  51,  99,  51,  99,  51,  99,  51,  99,  51,  99,  51,  99,  51,  99,  51,  84,  52,  53,
    71,  19,  69,  51,  0,   17,  32,  35,  17,  0,   25,  67,  131, 51,  131, 51,  131, 67,  99,  83,  99,  83,  99,  99,  67,  115, 67,
    131, 50,  147, 35,  147, 35,  162, 34,  182, 182, 196, 212, 0,   20,  16,  57,  25,  0,   37,  67,  99,  115, 51,  100, 99,  51,  100,
    99,  66,  100, 83,  83,  66,  18,  83,  83,  66,  19,  67,  83,  66,  34,  66,  115, 35,  34,  51,  115, 34,  51,  35,  115, 34,  51,
    34,  146, 34,  66,  34,  150, 66,  19,  149, 86,  164, 100, 180, 100, 179, 116, 0,   29,  35,  19,  0,   28,  83,  131, 84,  99,  115,
    83,  147, 67,  163, 35,  198, 228, 243, 240, 20,  230, 195, 35,  178, 51,  163, 67,  131, 99,  99,  131, 68,  132, 0,   21,  96,  43,
    17,  0,   25,  67,  146, 51,  131, 67,  115, 67,  99,  83,  99,  99,  82,  115, 67,  131, 51,  131, 50,  147, 35,  163, 19,  163, 18,
    194, 18,  196, 227, 227, 226, 227, 226, 242, 227, 166, 181, 0,   5,   96,  23,  16,  0,   24,  13,  61,  195, 195, 196, 195, 195, 196,
    180, 195, 195, 196, 195, 195, 205, 61,  0,   18,  48,  11,  20,  0,   42,  79,  2,   63,  2,   0,   45,  48,  13,  38,  0,   80,  111,
    15,  5,   63,  15,  5,   0,   85,  112, 20,  14,  240, 243, 51,  82,  66,  83,  51,  83,  51,  82,  66,  83,  51,  82,  66,  0,   49,
    96,  14,  15,  0,   7,   99,  67,  70,  34,  67,  38,  66,  68,  0,   55,
};

//*****************************************************************************
//
// The font definition for the 38 point Cmss font.
//
//*****************************************************************************
const tFont g_sFontCmss38 = {
    //
    // The format of the font.
    //
    FONT_FMT_PIXEL_RLE,

    //
    // The maximum width of the font.
    //
    34,

    //
    // The height of the font.
    //
    37,

    //
    // The baseline of the font.
    //
    28,

    //
    // The offset to each character in the font.
    //
    {
     0,    5,    34,   56,   157,  211,  300,  373,  386,  426,  466,  494,  545,  559,  568,  578,  627,  678,  710,
     745,  783,  825,  863,  909,  940,  989,  1035, 1050, 1069, 1097, 1110, 1143, 1177, 1244, 1305, 1358, 1413, 1468,
     1525, 1558, 1613, 1671, 1702, 1737, 1796, 1829, 1925, 2001, 2065, 2119, 2196, 2251, 2299, 2357, 2414, 2478, 2576,
     2638, 2699, 2758, 2798, 2820, 2860, 2878, 2887, 2900, 2930, 2976, 3001, 3049, 3077, 3109, 3155, 3203, 3230, 3265,
     3312, 3343, 3398, 3437, 3472, 3515, 3560, 3585, 3611, 3640, 3679, 3714, 3771, 3806, 3849, 3872, 3883, 3896, 3916,
     },

    //
    // A pointer to the actual font data
    //
    g_pui8Cmss38Data
};

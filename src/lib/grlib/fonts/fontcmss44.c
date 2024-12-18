//*****************************************************************************
//
// fontcmss44.c - Font definition for the 44pt Cmss font.
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
//     Size: 44 point
//     Bold: no
//     Italic: no
//     Memory usage: 5216 bytes
//
//*****************************************************************************

//*****************************************************************************
//
// The compressed data for the 44 point Cmss font.
// Contains characters 32 to 126 inclusive.
//
//*****************************************************************************
static const uint8_t g_pui8Cmss44Data[5013] = {
    4,   18,  0,   99,  34,  7,   227, 67,  67,  67,  67,  67,  67,  67,  67,  67,  67,  67,  67,  67,  67,  67,  67,  67,  67,  67,  67,
    67,  67,  67,  240, 163, 67,  67,  67,  0,   10,  16,  24,  15,  240, 243, 83,  67,  83,  67,  83,  67,  83,  82,  98,  82,  98,  66,
    98,  82,  98,  82,  98,  0,   62,  64,  120, 34,  0,   10,  34,  129, 240, 130, 129, 240, 129, 130, 240, 129, 130, 240, 114, 129, 240,
    130, 129, 240, 129, 130, 240, 129, 130, 240, 114, 129, 240, 130, 129, 240, 129, 130, 240, 114, 130, 240, 114, 129, 240, 130, 129, 240,
    129, 130, 207, 15,  79,  15,  226, 129, 240, 129, 130, 240, 129, 130, 240, 114, 129, 240, 130, 129, 240, 129, 130, 239, 15,  79,  15,
    194, 129, 240, 129, 130, 240, 129, 130, 240, 114, 130, 240, 114, 129, 240, 129, 130, 240, 129, 130, 240, 114, 129, 240, 130, 129, 240,
    129, 130, 240, 129, 130, 240, 114, 129, 240, 130, 129, 240, 129, 130, 240, 129, 130, 0,   10,  96,  69,  20,  115, 240, 35,  240, 22,
    202, 141, 116, 19,  35,  99,  51,  65,  84,  51,  163, 67,  163, 67,  163, 67,  163, 67,  164, 51,  180, 35,  185, 201, 202, 186, 215,
    211, 20,  195, 35,  195, 36,  179, 51,  179, 51,  179, 51,  179, 51,  179, 51,  65,  99,  35,  82,  83,  35,  84,  51,  20,  109, 139,
    198, 240, 19,  240, 35,  0,   23,  96,  115, 34,  68,  240, 17,  198, 226, 184, 210, 164, 36,  178, 179, 67,  177, 179, 84,  146, 179,
    99,  130, 195, 99,  130, 195, 99,  114, 211, 99,  114, 211, 99,  98,  227, 99,  98,  242, 83,  98,  240, 19,  67,  98,  240, 20,  36,
    82,  240, 56,  97,  240, 86,  98,  240, 240, 18,  240, 240, 34,  101, 240, 82,  103, 240, 66,  83,  36,  240, 34,  99,  51,  240, 34,
    98,  67,  240, 18,  99,  83,  242, 99,  83,  226, 115, 83,  226, 115, 83,  210, 131, 83,  209, 147, 83,  194, 147, 83,  178, 163, 83,
    178, 179, 51,  178, 195, 36,  178, 215, 178, 245, 194, 240, 19,  0,   35,  86,  31,  0,   8,   116, 240, 167, 240, 152, 240, 115, 51,
    240, 115, 67,  240, 83,  83,  240, 83,  83,  240, 83,  83,  240, 83,  83,  240, 83,  67,  240, 99,  67,  240, 100, 35,  240, 116, 19,
    240, 150, 240, 165, 179, 196, 195, 181, 195, 167, 163, 164, 19,  163, 148, 36,  131, 147, 84,  115, 147, 99,  99,  147, 116, 68,  147,
    132, 36,  163, 152, 180, 150, 211, 149, 229, 89,  97,  109, 27,  123, 58,  150, 135, 0,   43,  32,  14,  7,   227, 67,  67,  67,  82,
    82,  66,  82,  82,  0,   29,  64,  47,  14,  115, 163, 163, 178, 179, 178, 179, 178, 179, 179, 178, 179, 179, 179, 179, 163, 179, 179,
    179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 195, 179, 179, 179, 179, 195, 179, 195, 179, 194, 195, 195, 179, 195, 195, 64,
    47,  14,  3,   195, 195, 194, 195, 195, 179, 195, 179, 179, 195, 179, 179, 179, 179, 195, 179, 179, 179, 179, 179, 179, 179, 179, 179,
    179, 179, 179, 179, 178, 179, 179, 179, 179, 163, 179, 178, 179, 179, 163, 178, 179, 163, 163, 176, 42,  19,  99,  240, 19,  240, 19,
    240, 19,  162, 67,  66,  67,  51,  51,  69,  19,  21,  107, 167, 213, 215, 171, 101, 19,  21,  68,  35,  36,  66,  67,  66,  163, 240,
    19,  240, 19,  240, 19,  0,   60,  80,  63,  32,  0,   33,  82,  240, 242, 240, 242, 240, 242, 240, 242, 240, 242, 240, 242, 240, 242,
    240, 242, 240, 242, 240, 242, 240, 242, 240, 242, 240, 47,  13,  79,  13,  240, 34,  240, 242, 240, 242, 240, 242, 240, 242, 240, 242,
    240, 242, 240, 242, 240, 242, 240, 242, 240, 242, 240, 242, 240, 242, 0,   34,  16,  17,  7,   0,   25,  51,  67,  67,  67,  82,  82,
    81,  82,  82,  82,  240, 240, 160, 10,  15,  0,   41,  43,  75,  75,  0,   36,  16,  11,  7,   0,   25,  51,  67,  67,  67,  0,   10,
    16,  91,  20,  241, 240, 50,  240, 49,  240, 50,  240, 50,  240, 49,  240, 50,  240, 50,  240, 49,  240, 50,  240, 50,  240, 49,  240,
    50,  240, 50,  240, 49,  240, 50,  240, 50,  240, 49,  240, 50,  240, 50,  240, 49,  240, 50,  240, 50,  240, 49,  240, 50,  240, 50,
    240, 49,  240, 50,  240, 50,  240, 49,  240, 50,  240, 50,  240, 49,  240, 50,  240, 50,  240, 49,  240, 50,  240, 50,  240, 49,  240,
    50,  240, 50,  240, 49,  240, 50,  240, 49,  240, 64,  59,  21,  0,   11,  37,  233, 187, 148, 84,  131, 115, 115, 147, 99,  147, 99,
    147, 83,  179, 67,  179, 67,  179, 67,  179, 67,  179, 67,  179, 67,  179, 67,  179, 67,  179, 67,  179, 67,  179, 67,  179, 67,  179,
    83,  148, 83,  147, 99,  147, 115, 116, 116, 84,  155, 185, 229, 0,   30,  16,  37,  17,  0,   9,   49,  212, 152, 152, 147, 35,  227,
    227, 227, 227, 227, 227, 227, 227, 227, 227, 227, 227, 227, 227, 227, 227, 227, 227, 227, 227, 227, 157, 77,  77,  0,   23,  112, 62,
    20,  0,   10,  86,  202, 156, 116, 84,  115, 116, 83,  147, 82,  164, 66,  179, 81,  179, 240, 35,  240, 35,  240, 35,  240, 19,  240,
    35,  240, 19,  240, 19,  240, 34,  240, 34,  240, 34,  240, 34,  240, 34,  240, 34,  240, 34,  240, 34,  240, 34,  240, 35,  240, 31,
    1,   79,  1,   79,  1,   0,   28,  55,  20,  0,   10,  86,  202, 156, 116, 84,  100, 116, 83,  147, 97,  163, 240, 35,  240, 35,  240,
    20,  240, 19,  244, 200, 198, 232, 240, 36,  240, 51,  240, 35,  240, 51,  240, 35,  240, 35,  240, 35,  240, 35,  65,  179, 83,  147,
    85,  84,  125, 154, 198, 0,   28,  80,  64,  22,  0,   12,  36,  240, 52,  240, 37,  240, 37,  240, 22,  240, 18,  19,  243, 19,  227,
    35,  227, 35,  211, 51,  211, 51,  195, 67,  195, 67,  179, 83,  179, 83,  163, 99,  148, 99,  147, 115, 132, 115, 143, 3,   79,  3,
    79,  3,   243, 240, 67,  240, 67,  240, 67,  240, 67,  240, 67,  240, 67,  0,   31,  32,  57,  21,  0,   10,  110, 126, 126, 115, 240,
    51,  240, 51,  240, 51,  240, 51,  240, 51,  240, 51,  240, 51,  37,  188, 157, 133, 68,  132, 115, 115, 131, 240, 67,  240, 51,  240,
    51,  240, 51,  240, 51,  240, 51,  81,  195, 82,  163, 84,  132, 101, 84,  140, 170, 214, 0,   30,  16,  58,  20,  0,   11,  5,   216,
    185, 164, 243, 240, 19,  240, 35,  240, 19,  240, 35,  240, 34,  69,  131, 40,  115, 26,  102, 69,  85,  100, 84,  131, 83,  163, 67,
    163, 67,  163, 67,  163, 67,  163, 67,  163, 82,  163, 83,  147, 83,  131, 115, 100, 116, 68,  154, 184, 213, 0,   28,  96,  65,  21,
    0,   10,  79,  2,   79,  2,   79,  2,   240, 51,  240, 35,  240, 50,  240, 51,  240, 35,  240, 50,  240, 51,  240, 50,  240, 51,  240,
    50,  240, 51,  240, 51,  240, 35,  240, 51,  240, 51,  240, 35,  240, 51,  240, 51,  240, 51,  240, 51,  240, 35,  240, 51,  240, 51,
    240, 51,  240, 51,  240, 51,  0,   30,  64,  56,  20,  0,   10,  86,  217, 156, 132, 68,  115, 131, 98,  162, 98,  162, 83,  163, 82,
    162, 98,  162, 99,  131, 116, 83,  154, 198, 202, 148, 68,  115, 131, 99,  131, 83,  163, 67,  163, 67,  163, 67,  163, 67,  163, 83,
    131, 99,  131, 116, 68,  140, 154, 198, 0,   28,  80,  59,  20,  0,   10,  101, 216, 186, 148, 68,  116, 99,  115, 131, 83,  147, 83,
    162, 83,  163, 67,  163, 67,  163, 67,  163, 67,  163, 67,  163, 83,  132, 84,  101, 85,  70,  106, 19,  120, 35,  133, 66,  240, 35,
    240, 35,  240, 34,  240, 35,  240, 19,  146, 84,  139, 169, 213, 0,   28,  112, 17,  7,   0,   12,  35,  67,  67,  67,  0,   10,  19,
    67,  67,  67,  0,   10,  16,  23,  7,   0,   12,  35,  67,  67,  67,  0,   10,  19,  67,  67,  67,  82,  82,  81,  82,  82,  82,  240,
    240, 160, 36,  7,   0,   8,   99,  67,  67,  67,  240, 240, 35,  67,  67,  67,  67,  67,  67,  67,  67,  67,  67,  67,  67,  67,  67,
    67,  67,  67,  67,  67,  67,  67,  67,  67,  240, 48,  17,  32,  0,   68,  15,  13,  79,  13,  0,   24,  79,  13,  79,  13,  0,   68,
    64,  52,  19,  0,   24,  67,  240, 19,  240, 19,  240, 19,  0,   11,  67,  240, 19,  240, 19,  240, 19,  240, 19,  240, 19,  243, 240,
    19,  244, 243, 244, 228, 228, 243, 244, 243, 240, 19,  240, 19,  240, 19,  240, 20,  146, 84,  100, 94,  107, 167, 0,   5,   96,  38,
    18,  240, 240, 166, 155, 109, 84,  84,  97,  132, 243, 243, 243, 243, 228, 227, 228, 212, 212, 227, 228, 227, 243, 227, 243, 243, 243,
    243, 243, 0,   8,   83,  243, 243, 243, 0,   26,  81,  27,  0,   8,   7,   240, 59,  238, 198, 85,  165, 147, 148, 101, 19,  131, 106,
    116, 91,  115, 84,  54,  83,  84,  85,  83,  83,  116, 83,  83,  116, 67,  83,  147, 67,  83,  147, 67,  83,  147, 67,  83,  147, 67,
    83,  147, 67,  83,  147, 67,  83,  147, 68,  83,  115, 99,  83,  115, 99,  84,  84,  115, 84,  52,  132, 89,  163, 103, 181, 85,  213,
    240, 134, 132, 175, 236, 240, 39,  0,   38,  48,  83,  29,  0,   8,   84,  240, 149, 240, 150, 240, 130, 19,  240, 115, 19,  240, 115,
    20,  240, 99,  20,  240, 83,  51,  240, 83,  52,  240, 67,  52,  240, 51,  83,  240, 51,  84,  240, 35,  84,  240, 19,  115, 240, 19,
    116, 228, 116, 227, 147, 227, 148, 196, 148, 207, 2,   207, 3,   175, 4,   163, 211, 163, 212, 132, 212, 131, 243, 131, 244, 100, 244,
    99,  240, 35,  99,  240, 36,  68,  240, 36,  0,   40,  48,  65,  25,  0,   6,   45,  207, 1,   147, 150, 115, 181, 99,  211, 99,  212,
    83,  227, 83,  227, 83,  227, 83,  212, 83,  196, 99,  180, 115, 149, 143, 174, 191, 1,   147, 150, 115, 196, 99,  212, 83,  227, 83,
    228, 67,  243, 67,  243, 67,  243, 67,  243, 67,  227, 83,  212, 83,  196, 99,  165, 127, 2,   142, 0,   35,  96,  63,  25,  0,   7,
    71,  253, 190, 165, 100, 148, 177, 132, 240, 84,  240, 99,  240, 100, 240, 99,  240, 115, 240, 100, 240, 99,  240, 115, 240, 115, 240,
    115, 240, 115, 240, 115, 240, 115, 240, 116, 240, 115, 240, 115, 240, 116, 240, 115, 240, 116, 240, 116, 240, 116, 178, 149, 116, 175,
    188, 248, 0,   35,  48,  82,  27,  0,   6,   110, 223, 1,   179, 149, 163, 195, 147, 211, 131, 227, 115, 228, 99,  243, 99,  240, 19,
    83,  240, 19,  83,  240, 19,  83,  240, 35,  67,  240, 35,  67,  240, 35,  67,  240, 35,  67,  240, 35,  67,  240, 35,  67,  240, 35,
    67,  240, 35,  67,  240, 35,  67,  240, 19,  83,  240, 19,  83,  240, 19,  83,  243, 99,  243, 99,  227, 115, 211, 131, 196, 131, 164,
    175, 1,   190, 0,   38,  96,  69,  22,  240, 240, 239, 3,   79,  3,   79,  3,   67,  240, 67,  240, 67,  240, 67,  240, 67,  240, 67,
    240, 67,  240, 67,  240, 67,  240, 67,  240, 67,  240, 79,  2,   95,  2,   95,  2,   83,  240, 67,  240, 67,  240, 67,  240, 67,  240,
    67,  240, 67,  240, 67,  240, 67,  240, 67,  240, 67,  240, 79,  3,   79,  3,   79,  3,   0,   30,  96,  68,  21,  240, 240, 207, 2,
    79,  2,   79,  2,   67,  240, 51,  240, 51,  240, 51,  240, 51,  240, 51,  240, 51,  240, 51,  240, 51,  240, 51,  240, 51,  240, 63,
    1,   95,  1,   95,  1,   83,  240, 51,  240, 51,  240, 51,  240, 51,  240, 51,  240, 51,  240, 51,  240, 51,  240, 51,  240, 51,  240,
    51,  240, 51,  240, 51,  0,   31,  16,  63,  25,  0,   7,   71,  253, 191, 149, 101, 132, 163, 116, 240, 84,  240, 99,  240, 100, 240,
    99,  240, 115, 240, 115, 240, 99,  240, 115, 240, 115, 240, 115, 240, 115, 240, 115, 240, 115, 168, 68,  152, 83,  152, 83,  227, 84,
    211, 99,  211, 100, 195, 116, 179, 132, 163, 149, 116, 175, 188, 247, 0,   35,  64,  69,  25,  0,   6,   35,  243, 67,  243, 67,  243,
    67,  243, 67,  243, 67,  243, 67,  243, 67,  243, 67,  243, 67,  243, 67,  243, 67,  243, 67,  243, 79,  6,   79,  6,   79,  6,   67,
    243, 67,  243, 67,  243, 67,  243, 67,  243, 67,  243, 67,  243, 67,  243, 67,  243, 67,  243, 67,  243, 67,  243, 67,  243, 67,  243,
    67,  243, 0,   34,  112, 36,  7,   227, 67,  67,  67,  67,  67,  67,  67,  67,  67,  67,  67,  67,  67,  67,  67,  67,  67,  67,  67,
    67,  67,  67,  67,  67,  67,  67,  67,  67,  67,  67,  0,   10,  16,  40,  18,  0,   5,   115, 243, 243, 243, 243, 243, 243, 243, 243,
    243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 81,  132, 83,  84,  93,  107, 166, 0,   25,  96,
    70,  26,  0,   6,   67,  228, 83,  212, 99,  197, 99,  181, 115, 165, 131, 164, 147, 148, 163, 132, 179, 116, 195, 100, 211, 84,  227,
    68,  243, 53,  243, 39,  227, 39,  227, 20,  20,  215, 36,  214, 68,  197, 85,  180, 116, 179, 148, 163, 148, 163, 164, 147, 180, 131,
    180, 131, 196, 115, 197, 99,  212, 99,  228, 83,  228, 83,  244, 0,   36,  32,  68,  20,  240, 240, 163, 240, 35,  240, 35,  240, 35,
    240, 35,  240, 35,  240, 35,  240, 35,  240, 35,  240, 35,  240, 35,  240, 35,  240, 35,  240, 35,  240, 35,  240, 35,  240, 35,  240,
    35,  240, 35,  240, 35,  240, 35,  240, 35,  240, 35,  240, 35,  240, 35,  240, 35,  240, 35,  240, 35,  240, 47,  1,   79,  1,   79,
    1,   0,   28,  120, 32,  0,   8,   5,   240, 53,  69,  240, 53,  70,  240, 22,  70,  240, 22,  70,  240, 22,  67,  19,  227, 19,  67,
    19,  227, 19,  67,  19,  227, 19,  67,  35,  195, 35,  67,  35,  195, 35,  67,  36,  164, 35,  67,  51,  163, 51,  67,  51,  163, 51,
    67,  52,  132, 51,  67,  67,  131, 67,  67,  67,  131, 67,  67,  68,  100, 67,  67,  83,  99,  83,  67,  83,  99,  83,  67,  84,  68,
    83,  67,  99,  67,  99,  67,  100, 51,  99,  67,  100, 35,  115, 67,  115, 35,  115, 67,  115, 35,  115, 67,  134, 131, 67,  134, 131,
    67,  134, 131, 67,  148, 147, 67,  148, 147, 67,  240, 115, 0,   44,  64,  91,  25,  0,   6,   37,  211, 70,  195, 70,  195, 71,  179,
    67,  19,  179, 67,  20,  163, 67,  20,  163, 67,  36,  147, 67,  36,  147, 67,  52,  131, 67,  52,  131, 67,  67,  131, 67,  68,  115,
    67,  83,  115, 67,  84,  99,  67,  99,  99,  67,  100, 83,  67,  115, 83,  67,  116, 67,  67,  131, 67,  67,  132, 51,  67,  132, 51,
    67,  148, 35,  67,  148, 35,  67,  164, 19,  67,  164, 19,  67,  183, 67,  183, 67,  198, 67,  198, 67,  213, 0,   34,  112, 81,  29,
    0,   8,   70,  240, 91,  240, 45,  245, 85,  212, 148, 180, 180, 148, 212, 131, 243, 115, 240, 35,  99,  240, 35,  99,  240, 35,  83,
    240, 67,  67,  240, 67,  67,  240, 67,  67,  240, 67,  67,  240, 67,  67,  240, 67,  67,  240, 67,  67,  240, 67,  68,  240, 36,  83,
    240, 35,  99,  240, 35,  100, 244, 115, 243, 132, 212, 148, 180, 180, 148, 213, 85,  253, 240, 43,  240, 87,  0,   41,  64,  66,  24,
    0,   6,   14,  175, 1,   131, 149, 115, 180, 99,  211, 83,  211, 83,  227, 67,  227, 67,  227, 67,  227, 67,  227, 67,  212, 67,  211,
    83,  196, 83,  150, 111, 2,   127, 1,   141, 179, 240, 99,  240, 99,  240, 99,  240, 99,  240, 99,  240, 99,  240, 99,  240, 99,  240,
    99,  240, 99,  240, 99,  240, 99,  0,   35,  80,  99,  30,  0,   8,   102, 240, 123, 240, 46,  245, 101, 212, 164, 180, 196, 148, 228,
    131, 240, 19,  116, 240, 20,  99,  240, 51,  99,  240, 51,  84,  240, 67,  67,  240, 83,  67,  240, 83,  67,  240, 83,  67,  240, 83,
    67,  240, 83,  67,  240, 83,  67,  240, 83,  68,  240, 67,  83,  240, 51,  99,  240, 51,  100, 101, 84,  115, 116, 83,  132, 116, 52,
    148, 116, 20,  180, 104, 213, 86,  254, 240, 46,  240, 70,  20,  240, 196, 240, 181, 240, 180, 240, 196, 240, 180, 240, 196, 0,   19,
    48,  66,  25,  0,   6,   45,  207, 1,   147, 149, 131, 195, 115, 211, 99,  212, 83,  227, 83,  227, 83,  227, 83,  227, 83,  212, 83,
    211, 99,  196, 99,  165, 127, 1,   159, 173, 195, 116, 179, 131, 179, 132, 163, 147, 163, 148, 147, 163, 147, 164, 131, 180, 115, 195,
    115, 196, 99,  211, 99,  212, 83,  227, 83,  243, 0,   34,  112, 59,  22,  0,   6,   39,  220, 158, 116, 101, 100, 161, 115, 240, 51,
    240, 67,  240, 67,  240, 67,  240, 68,  240, 68,  240, 54,  240, 40,  250, 234, 248, 240, 38,  240, 52,  240, 68,  240, 67,  240, 67,
    240, 67,  240, 67,  240, 67,  65,  211, 83,  164, 85,  116, 126, 156, 215, 0,   31,  64,  68,  29,  0,   7,   47,  10,  79,  10,  79,
    10,  243, 240, 179, 240, 179, 240, 179, 240, 179, 240, 179, 240, 179, 240, 179, 240, 179, 240, 179, 240, 179, 240, 179, 240, 179, 240,
    179, 240, 179, 240, 179, 240, 179, 240, 179, 240, 179, 240, 179, 240, 179, 240, 179, 240, 179, 240, 179, 240, 179, 240, 179, 240, 179,
    240, 179, 0,   41,  96,  68,  24,  0,   6,   3,   227, 67,  227, 67,  227, 67,  227, 67,  227, 67,  227, 67,  227, 67,  227, 67,  227,
    67,  227, 67,  227, 67,  227, 67,  227, 67,  227, 67,  227, 67,  227, 67,  227, 67,  227, 67,  227, 67,  227, 67,  227, 67,  227, 67,
    227, 67,  227, 83,  195, 99,  195, 115, 163, 147, 131, 180, 83,  218, 240, 22,  0,   34,  48,  85,  30,  0,   7,   68,  240, 52,  68,
    240, 51,  84,  240, 51,  100, 240, 20,  100, 240, 19,  131, 240, 19,  132, 228, 132, 227, 164, 196, 164, 195, 180, 195, 196, 164, 196,
    163, 212, 163, 228, 132, 228, 131, 240, 19,  131, 240, 20,  100, 240, 20,  99,  240, 51,  99,  240, 52,  67,  240, 68,  67,  240, 83,
    67,  240, 84,  35,  240, 100, 35,  240, 115, 35,  240, 119, 240, 150, 240, 150, 240, 149, 240, 180, 0,   43,  16,  124, 41,  0,   10,
    36,  212, 211, 68,  197, 211, 68,  197, 196, 83,  197, 195, 100, 178, 19,  179, 100, 163, 19,  179, 100, 163, 19,  164, 115, 163, 19,
    163, 132, 131, 36,  147, 132, 131, 51,  132, 132, 131, 51,  132, 147, 131, 52,  115, 164, 99,  68,  115, 164, 99,  83,  100, 164, 99,
    83,  99,  195, 99,  84,  83,  196, 67,  100, 83,  196, 67,  115, 68,  211, 67,  115, 67,  227, 67,  116, 51,  228, 35,  132, 51,  228,
    35,  147, 51,  243, 35,  147, 35,  240, 19,  35,  148, 19,  240, 20,  18,  164, 19,  240, 23,  179, 19,  240, 38,  182, 240, 54,  182,
    240, 53,  213, 240, 68,  212, 240, 84,  212, 0,   57,  112, 79,  30,  0,   7,   69,  244, 117, 212, 148, 196, 180, 180, 181, 148, 212,
    132, 244, 116, 245, 84,  240, 36,  68,  240, 68,  52,  240, 84,  20,  240, 104, 240, 135, 240, 149, 240, 164, 240, 181, 240, 151, 240,
    135, 240, 116, 20,  240, 84,  52,  240, 67,  68,  240, 52,  84,  240, 20,  116, 243, 133, 212, 148, 196, 180, 180, 196, 148, 212, 132,
    244, 116, 240, 20,  84,  240, 37,  0,   41,  96,  75,  29,  0,   7,   36,  240, 51,  68,  240, 36,  84,  244, 101, 228, 116, 212, 148,
    195, 164, 180, 180, 148, 212, 131, 228, 116, 244, 99,  240, 21,  68,  240, 36,  52,  240, 68,  35,  240, 84,  20,  240, 103, 240, 133,
    240, 149, 240, 163, 240, 179, 240, 179, 240, 179, 240, 179, 240, 179, 240, 179, 240, 179, 240, 179, 240, 179, 240, 179, 240, 179, 240,
    179, 0,   41,  96,  70,  25,  0,   6,   63,  5,   95,  5,   95,  5,   240, 84,  240, 84,  240, 100, 240, 84,  240, 100, 240, 84,  240,
    84,  240, 100, 240, 84,  240, 84,  240, 100, 240, 84,  240, 100, 240, 84,  240, 84,  240, 100, 240, 84,  240, 100, 240, 84,  240, 84,
    240, 100, 240, 84,  240, 84,  240, 100, 240, 84,  240, 111, 5,   79,  6,   79,  6,   0,   34,  112, 47,  11,  7,   71,  71,  67,  131,
    131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131,
    131, 131, 131, 131, 131, 131, 131, 131, 131, 135, 71,  71,  64,  25,  15,  240, 240, 18,  98,  82,  98,  82,  98,  66,  98,  82,  98,
    83,  83,  67,  83,  67,  83,  67,  83,  0,   62,  48,  47,  11,  7,   71,  71,  131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131,
    131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131,
    71,  71,  71,  64,  19,  18,  240, 240, 180, 229, 198, 179, 35,  162, 67,  131, 82,  115, 99,  83,  131, 0,   77,  9,   7,   240, 211,
    67,  67,  67,  0,   32,  14,  7,   242, 82,  82,  66,  82,  83,  67,  67,  67,  0,   29,  48,  35,  18,  0,   32,  6,   170, 124, 99,
    100, 243, 243, 243, 168, 123, 108, 85,  83,  68,  115, 67,  131, 67,  131, 67,  131, 69,  69,  93,  89,  19,  117, 51,  0,   25,  32,
    67,  20,  240, 240, 163, 240, 35,  240, 35,  240, 35,  240, 35,  240, 35,  240, 35,  240, 35,  240, 35,  240, 35,  240, 35,  240, 35,
    240, 35,  69,  131, 40,  126, 101, 85,  84,  116, 83,  147, 83,  148, 67,  163, 67,  163, 67,  163, 67,  163, 67,  163, 67,  148, 67,
    147, 84,  116, 85,  69,  110, 99,  25,  115, 53,  0,   28,  80,  37,  19,  0,   34,  6,   187, 124, 100, 99,  84,  145, 83,  240, 19,
    243, 240, 19,  240, 19,  240, 19,  240, 19,  240, 20,  240, 19,  240, 20,  145, 100, 99,  124, 138, 182, 0,   27,  66,  21,  0,   7,
    3,   240, 51,  240, 51,  240, 51,  240, 51,  240, 51,  240, 51,  240, 51,  240, 51,  240, 51,  240, 51,  240, 51,  150, 51,  122, 19,
    111, 101, 85,  84,  147, 83,  163, 68,  163, 67,  179, 67,  179, 67,  179, 67,  179, 67,  179, 68,  163, 83,  163, 84,  132, 101, 85,
    111, 121, 35,  149, 67,  0,   29,  48,  39,  20,  0,   35,  101, 217, 171, 132, 84,  99,  146, 98,  163, 79,  1,   79,  1,   79,  1,
    67,  240, 35,  240, 35,  240, 51,  240, 35,  240, 36,  161, 101, 99,  125, 139, 182, 0,   28,  64,  38,  17,  240, 240, 182, 167, 152,
    132, 211, 211, 227, 227, 227, 227, 227, 227, 186, 122, 122, 163, 227, 227, 227, 227, 227, 227, 227, 227, 227, 227, 227, 227, 227, 227,
    227, 0,   24,  96,  55,  22,  0,   39,  21,  67,  151, 21,  143, 100, 52,  164, 84,  147, 115, 147, 115, 147, 115, 147, 115, 163, 84,
    164, 52,  186, 186, 194, 37,  210, 240, 83,  240, 76,  189, 143, 100, 133, 83,  164, 83,  179, 83,  179, 83,  179, 84,  147, 117, 85,
    155, 215, 0,   6,   96,  69,  19,  240, 240, 131, 240, 19,  240, 19,  240, 19,  240, 19,  240, 19,  240, 19,  240, 19,  240, 19,  240,
    19,  240, 19,  240, 19,  240, 19,  69,  115, 41,  83,  26,  86,  69,  68,  116, 68,  131, 67,  147, 67,  147, 67,  147, 67,  147, 67,
    147, 67,  147, 67,  147, 67,  147, 67,  147, 67,  147, 67,  147, 67,  147, 67,  147, 0,   26,  80,  31,  7,   240, 211, 67,  67,  67,
    0,   5,   99,  67,  67,  67,  67,  67,  67,  67,  67,  67,  67,  67,  67,  67,  67,  67,  67,  67,  67,  0,   10,  16,  42,  13,  0,
    7,   35,  163, 163, 163, 0,   11,  3,   163, 163, 163, 163, 163, 163, 163, 163, 163, 163, 163, 163, 163, 163, 163, 163, 163, 163, 163,
    163, 163, 163, 163, 65,  68,  72,  87,  132, 240, 240, 48,  66,  20,  240, 240, 163, 240, 35,  240, 35,  240, 35,  240, 35,  240, 35,
    240, 35,  240, 35,  240, 35,  240, 35,  240, 35,  240, 35,  240, 35,  117, 83,  101, 99,  85,  115, 69,  131, 68,  147, 52,  163, 36,
    179, 20,  201, 186, 165, 20,  164, 52,  147, 84,  131, 84,  131, 100, 115, 116, 99,  116, 99,  132, 83,  148, 0,   28,  36,  7,   227,
    67,  67,  67,  67,  67,  67,  67,  67,  67,  67,  67,  67,  67,  67,  67,  67,  67,  67,  67,  67,  67,  67,  67,  67,  67,  67,  67,
    67,  67,  67,  0,   10,  16,  64,  30,  0,   52,  67,  69,  101, 115, 41,  56,  83,  26,  41,  85,  87,  69,  68,  117, 100, 68,  132,
    115, 67,  147, 131, 67,  147, 131, 67,  147, 131, 67,  147, 131, 67,  147, 131, 67,  147, 131, 67,  147, 131, 67,  147, 131, 67,  147,
    131, 67,  147, 131, 67,  147, 131, 67,  147, 131, 67,  147, 131, 0,   41,  96,  45,  19,  0,   33,  35,  69,  115, 41,  83,  26,  86,
    69,  68,  116, 68,  131, 67,  147, 67,  147, 67,  147, 67,  147, 67,  147, 67,  147, 67,  147, 67,  147, 67,  147, 67,  147, 67,  147,
    67,  147, 67,  147, 0,   26,  80,  39,  22,  0,   39,  38,  234, 188, 149, 69,  116, 132, 99,  163, 99,  164, 67,  195, 67,  195, 67,
    195, 67,  195, 67,  195, 68,  164, 83,  163, 100, 132, 117, 69,  156, 186, 230, 0,   31,  64,  60,  20,  0,   35,  3,   69,  131, 40,
    126, 101, 70,  83,  132, 83,  148, 67,  148, 67,  163, 67,  163, 67,  163, 67,  163, 67,  163, 67,  148, 67,  147, 84,  116, 85,  69,
    110, 99,  25,  115, 53,  147, 240, 35,  240, 35,  240, 35,  240, 35,  240, 35,  240, 35,  240, 35,  240, 35,  0,   7,   16,  61,  21,
    0,   37,  54,  51,  137, 19,  126, 101, 85,  84,  132, 83,  163, 68,  163, 67,  179, 67,  179, 67,  179, 67,  179, 67,  179, 68,  163,
    83,  163, 84,  132, 101, 85,  111, 121, 35,  149, 67,  240, 51,  240, 51,  240, 51,  240, 51,  240, 51,  240, 51,  240, 51,  240, 51,
    240, 51,  0,   5,   96,  29,  14,  0,   24,  67,  67,  67,  37,  67,  22,  71,  117, 148, 164, 163, 179, 179, 179, 179, 179, 179, 179,
    179, 179, 179, 179, 0,   20,  80,  29,  18,  0,   32,  7,   155, 108, 84,  99,  83,  243, 244, 230, 217, 185, 184, 229, 243, 243, 65,
    163, 68,  100, 77,  107, 151, 0,   25,  96,  32,  16,  0,   18,  51,  211, 211, 211, 211, 172, 76,  76,  115, 211, 211, 211, 211, 211,
    211, 211, 211, 211, 211, 211, 212, 50,  121, 136, 148, 0,   22,  112, 45,  19,  0,   33,  35,  147, 67,  147, 67,  147, 67,  147, 67,
    147, 67,  147, 67,  147, 67,  147, 67,  147, 67,  147, 67,  147, 67,  147, 67,  147, 67,  147, 67,  132, 68,  86,  75,  19,  89,  35,
    101, 83,  0,   26,  80,  44,  21,  0,   36,  99,  179, 68,  148, 68,  147, 99,  147, 100, 116, 115, 115, 131, 115, 132, 84,  147, 83,
    163, 83,  164, 52,  179, 51,  196, 35,  211, 19,  227, 19,  227, 19,  245, 240, 21,  240, 21,  0,   30,  16,  69,  30,  0,   52,  67,
    132, 131, 67,  132, 131, 68,  116, 131, 83,  102, 100, 83,  102, 99,  100, 82,  19,  99,  115, 82,  34,  84,  115, 67,  35,  67,  132,
    51,  35,  67,  132, 50,  51,  67,  147, 50,  67,  35,  163, 35,  67,  35,  164, 19,  67,  35,  179, 18,  83,  20,  179, 18,  102, 198,
    102, 212, 118, 212, 132, 228, 132, 0,   42,  48,  46,  23,  0,   40,  52,  148, 100, 132, 132, 115, 164, 83,  196, 52,  211, 36,  243,
    19,  240, 22,  240, 52,  240, 83,  240, 69,  240, 35,  19,  243, 36,  212, 51,  211, 83,  179, 115, 148, 116, 116, 148, 84,  180, 0,
    32,  16,  57,  21,  0,   36,  99,  179, 68,  148, 83,  147, 100, 131, 100, 116, 115, 115, 132, 99,  147, 84,  148, 67,  164, 67,  179,
    51,  196, 35,  211, 35,  211, 19,  246, 246, 245, 240, 36,  240, 36,  240, 35,  240, 51,  240, 35,  240, 51,  240, 51,  240, 35,  231,
    230, 245, 0,   7,   16,  26,  19,  0,   33,  62,  94,  94,  228, 228, 243, 244, 228, 228, 243, 244, 228, 228, 243, 244, 228, 239, 79,
    79,  0,   26,  80,  13,  25,  0,   62,  79,  6,   79,  6,   79,  6,   0,   66,  16,  16,  45,  0,   112, 79,  15,  11,  79,  15,  11,
    79,  15,  11,  0,   118, 80,  23,  17,  240, 240, 100, 52,  99,  67,  115, 67,  100, 52,  99,  67,  115, 67,  99,  67,  115, 67,  0,
    73,  16,  16,  18,  0,   9,   51,  98,  102, 51,  93,  82,  70,  83,  84,  0,   79,  64,
};

//*****************************************************************************
//
// The font definition for the 44 point Cmss font.
//
//*****************************************************************************
const tFont g_sFontCmss44 = {
    //
    // The format of the font.
    //
    FONT_FMT_PIXEL_RLE,

    //
    // The maximum width of the font.
    //
    40,

    //
    // The height of the font.
    //
    44,

    //
    // The baseline of the font.
    //
    33,

    //
    // The offset to each character in the font.
    //
    {
     0,    4,    38,   62,   182,  251,  366,  452,  466,  513,  560,  602,  665,  682,  692,  703,  794,  853,  890,
     952,  1007, 1071, 1128, 1186, 1251, 1307, 1366, 1383, 1406, 1442, 1459, 1511, 1549, 1630, 1713, 1778, 1841, 1923,
     1992, 2060, 2123, 2192, 2228, 2268, 2338, 2406, 2526, 2617, 2698, 2764, 2863, 2929, 2988, 3056, 3124, 3209, 3333,
     3412, 3487, 3557, 3604, 3629, 3676, 3695, 3704, 3718, 3753, 3820, 3857, 3923, 3962, 4000, 4055, 4124, 4155, 4197,
     4263, 4299, 4363, 4408, 4447, 4507, 4568, 4597, 4626, 4658, 4703, 4747, 4816, 4862, 4919, 4945, 4958, 4974, 4997,
     },

    //
    // A pointer to the actual font data
    //
    g_pui8Cmss44Data
};

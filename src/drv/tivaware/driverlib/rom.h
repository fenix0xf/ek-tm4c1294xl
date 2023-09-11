//*****************************************************************************
//
// rom.h - Macros to facilitate calling functions in the ROM.
//
// Copyright (c) 2007-2020 Texas Instruments Incorporated.  All rights reserved.
// Software License Agreement
//
//   Redistribution and use in source and binary forms, with or without
//   modification, are permitted provided that the following conditions
//   are met:
//
//   Redistributions of source code must retain the above copyright
//   notice, this list of conditions and the following disclaimer.
//
//   Redistributions in binary form must reproduce the above copyright
//   notice, this list of conditions and the following disclaimer in the
//   documentation and/or other materials provided with the
//   distribution.
//
//   Neither the name of Texas Instruments Incorporated nor the names of
//   its contributors may be used to endorse or promote products derived
//   from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// This is part of revision 2.2.0.295 of the Tiva Peripheral Driver Library.
//
//*****************************************************************************

#ifndef __DRIVERLIB_ROM_H__
#define __DRIVERLIB_ROM_H__

#ifndef DEPRECATED
//*****************************************************************************
//
// ROM selection labels changed between TivaWare 2.0.1 and 2.1.  The following
// labels are intended to ensure backwards compatibility for applications
// which have not yet been updated to use the replacement labels.
//
//*****************************************************************************
#ifdef TARGET_IS_SNOWFLAKE_RA0
#define TARGET_IS_TM4C129_RA0
#endif
#ifdef TARGET_IS_SNOWFLAKE_RA1
#define TARGET_IS_TM4C129_RA1
#endif
#ifdef TARGET_IS_SNOWFLAKE_RA2
#define TARGET_IS_TM4C129_RA2
#endif
#ifdef TARGET_IS_BLIZZARD_RA1
#define TARGET_IS_TM4C123_RA1
#endif
#ifdef TARGET_IS_BLIZZARD_RA2
#define TARGET_IS_TM4C123_RA2
#endif
#ifdef TARGET_IS_BLIZZARD_RA3
#define TARGET_IS_TM4C123_RA3
#endif
#ifdef TARGET_IS_BLIZZARD_RB0
#define TARGET_IS_TM4C123_RB0
#endif
#ifdef TARGET_IS_BLIZZARD_RB1
#define TARGET_IS_TM4C123_RB1
#endif
#endif

//*****************************************************************************
//
// Pointers to the main API tables.
//
//*****************************************************************************
#define ROM_APITABLE        ((uint32_t*)0x01000010)
#define ROM_VERSION         (ROM_APITABLE[0])
#define ROM_UARTTABLE       ((uint32_t*)(ROM_APITABLE[1]))
#define ROM_SSITABLE        ((uint32_t*)(ROM_APITABLE[2]))
#define ROM_I2CTABLE        ((uint32_t*)(ROM_APITABLE[3]))
#define ROM_GPIOTABLE       ((uint32_t*)(ROM_APITABLE[4]))
#define ROM_ADCTABLE        ((uint32_t*)(ROM_APITABLE[5]))
#define ROM_COMPARATORTABLE ((uint32_t*)(ROM_APITABLE[6]))
#define ROM_FLASHTABLE      ((uint32_t*)(ROM_APITABLE[7]))
#define ROM_PWMTABLE        ((uint32_t*)(ROM_APITABLE[8]))
#define ROM_QEITABLE        ((uint32_t*)(ROM_APITABLE[9]))
#define ROM_SYSTICKTABLE    ((uint32_t*)(ROM_APITABLE[10]))
#define ROM_TIMERTABLE      ((uint32_t*)(ROM_APITABLE[11]))
#define ROM_WATCHDOGTABLE   ((uint32_t*)(ROM_APITABLE[12]))
#define ROM_SYSCTLTABLE     ((uint32_t*)(ROM_APITABLE[13]))
#define ROM_INTERRUPTTABLE  ((uint32_t*)(ROM_APITABLE[14]))
#define ROM_USBTABLE        ((uint32_t*)(ROM_APITABLE[16]))
#define ROM_UDMATABLE       ((uint32_t*)(ROM_APITABLE[17]))
#define ROM_CANTABLE        ((uint32_t*)(ROM_APITABLE[18]))
#define ROM_HIBERNATETABLE  ((uint32_t*)(ROM_APITABLE[19]))
#define ROM_MPUTABLE        ((uint32_t*)(ROM_APITABLE[20]))
#define ROM_SOFTWARETABLE   ((uint32_t*)(ROM_APITABLE[21]))
#define ROM_EPITABLE        ((uint32_t*)(ROM_APITABLE[23]))
#define ROM_EEPROMTABLE     ((uint32_t*)(ROM_APITABLE[24]))
#define ROM_FPUTABLE        ((uint32_t*)(ROM_APITABLE[26]))
#define ROM_SMBUSTABLE      ((uint32_t*)(ROM_APITABLE[29]))
#define ROM_SYSEXCTABLE     ((uint32_t*)(ROM_APITABLE[30]))
#define ROM_ONEWIRETABLE    ((uint32_t*)(ROM_APITABLE[34]))
#define ROM_SPIFLASHTABLE   ((uint32_t*)(ROM_APITABLE[38]))
#define ROM_LCDTABLE        ((uint32_t*)(ROM_APITABLE[41]))
#define ROM_EMACTABLE       ((uint32_t*)(ROM_APITABLE[42]))
#define ROM_AESTABLE        ((uint32_t*)(ROM_APITABLE[43]))
#define ROM_CRCTABLE        ((uint32_t*)(ROM_APITABLE[44]))
#define ROM_DESTABLE        ((uint32_t*)(ROM_APITABLE[45]))
#define ROM_SHAMD5TABLE     ((uint32_t*)(ROM_APITABLE[46]))

//*****************************************************************************
//
// Macros for calling ROM functions in the ADC API.
//
//*****************************************************************************
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define ADCSequenceDataGet \
    ((int32_t(*)(uint32_t ui32Base, uint32_t ui32SequenceNum, uint32_t * pui32Buffer)) ROM_ADCTABLE[0])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define ADCIntDisable ((void (*)(uint32_t ui32Base, uint32_t ui32SequenceNum))ROM_ADCTABLE[1])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define ADCIntEnable ((void (*)(uint32_t ui32Base, uint32_t ui32SequenceNum))ROM_ADCTABLE[2])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define ADCIntStatus ((uint32_t(*)(uint32_t ui32Base, uint32_t ui32SequenceNum, bool bMasked))ROM_ADCTABLE[3])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define ADCIntClear ((void (*)(uint32_t ui32Base, uint32_t ui32SequenceNum))ROM_ADCTABLE[4])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define ADCSequenceEnable ((void (*)(uint32_t ui32Base, uint32_t ui32SequenceNum))ROM_ADCTABLE[5])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define ADCSequenceDisable ((void (*)(uint32_t ui32Base, uint32_t ui32SequenceNum))ROM_ADCTABLE[6])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define ADCSequenceConfigure                                                                              \
    ((void (*)(uint32_t ui32Base, uint32_t ui32SequenceNum, uint32_t ui32Trigger, uint32_t ui32Priority)) \
         ROM_ADCTABLE[7])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define ADCSequenceStepConfigure \
    ((void (*)(uint32_t ui32Base, uint32_t ui32SequenceNum, uint32_t ui32Step, uint32_t ui32Config))ROM_ADCTABLE[8])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define ADCSequenceOverflow ((int32_t(*)(uint32_t ui32Base, uint32_t ui32SequenceNum))ROM_ADCTABLE[9])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define ADCSequenceOverflowClear ((void (*)(uint32_t ui32Base, uint32_t ui32SequenceNum))ROM_ADCTABLE[10])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define ADCSequenceUnderflow ((int32_t(*)(uint32_t ui32Base, uint32_t ui32SequenceNum))ROM_ADCTABLE[11])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define ADCSequenceUnderflowClear ((void (*)(uint32_t ui32Base, uint32_t ui32SequenceNum))ROM_ADCTABLE[12])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define ADCProcessorTrigger ((void (*)(uint32_t ui32Base, uint32_t ui32SequenceNum))ROM_ADCTABLE[13])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define ADCHardwareOversampleConfigure ((void (*)(uint32_t ui32Base, uint32_t ui32Factor))ROM_ADCTABLE[14])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define ADCComparatorConfigure ((void (*)(uint32_t ui32Base, uint32_t ui32Comp, uint32_t ui32Config))ROM_ADCTABLE[15])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define ADCComparatorRegionSet \
    ((void (*)(uint32_t ui32Base, uint32_t ui32Comp, uint32_t ui32LowRef, uint32_t ui32HighRef))ROM_ADCTABLE[16])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define ADCComparatorReset \
    ((void (*)(uint32_t ui32Base, uint32_t ui32Comp, bool bTrigger, bool bInterrupt))ROM_ADCTABLE[17])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define ADCComparatorIntDisable ((void (*)(uint32_t ui32Base, uint32_t ui32SequenceNum))ROM_ADCTABLE[18])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define ADCComparatorIntEnable ((void (*)(uint32_t ui32Base, uint32_t ui32SequenceNum))ROM_ADCTABLE[19])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define ADCComparatorIntStatus ((uint32_t(*)(uint32_t ui32Base))ROM_ADCTABLE[20])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define ADCComparatorIntClear ((void (*)(uint32_t ui32Base, uint32_t ui32Status))ROM_ADCTABLE[21])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define ADCReferenceSet ((void (*)(uint32_t ui32Base, uint32_t ui32Ref))ROM_ADCTABLE[22])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define ADCReferenceGet ((uint32_t(*)(uint32_t ui32Base))ROM_ADCTABLE[23])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define ADCPhaseDelaySet ((void (*)(uint32_t ui32Base, uint32_t ui32Phase))ROM_ADCTABLE[24])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define ADCPhaseDelayGet ((uint32_t(*)(uint32_t ui32Base))ROM_ADCTABLE[25])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define ADCIntDisableEx ((void (*)(uint32_t ui32Base, uint32_t ui32IntFlags))ROM_ADCTABLE[29])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define ADCIntEnableEx ((void (*)(uint32_t ui32Base, uint32_t ui32IntFlags))ROM_ADCTABLE[30])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define ADCIntStatusEx ((uint32_t(*)(uint32_t ui32Base, bool bMasked))ROM_ADCTABLE[31])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define ADCSequenceDMAEnable ((void (*)(uint32_t ui32Base, uint32_t ui32SequenceNum))ROM_ADCTABLE[32])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define ADCSequenceDMADisable ((void (*)(uint32_t ui32Base, uint32_t ui32SequenceNum))ROM_ADCTABLE[33])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define ADCBusy ((bool (*)(uint32_t ui32Base))ROM_ADCTABLE[34])
#endif

//*****************************************************************************
//
// Macros for calling ROM functions in the AES API.
//
//*****************************************************************************
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define AESIntStatus ((uint32_t(*)(uint32_t ui32Base, bool bMasked))ROM_AESTABLE[0])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define AESAuthLengthSet ((void (*)(uint32_t ui32Base, uint32_t ui32Length))ROM_AESTABLE[1])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define AESConfigSet ((void (*)(uint32_t ui32Base, uint32_t ui32Config))ROM_AESTABLE[2])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define AESDataAuth \
    ((bool (*)(uint32_t ui32Base, uint32_t * pui32Src, uint32_t ui32Length, uint32_t * pui32Tag)) ROM_AESTABLE[3])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define AESDataProcess \
    ((bool (*)(uint32_t ui32Base, uint32_t * pui32Src, uint32_t * pui32Dest, uint32_t ui32Length)) ROM_AESTABLE[4])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define AESDataProcessAuth              \
    ((bool (*)(uint32_t ui32Base,       \
               uint32_t * pui32Src,     \
               uint32_t * pui32Dest,    \
               uint32_t ui32Length,     \
               uint32_t * pui32AuthSrc, \
               uint32_t ui32AuthLength, \
               uint32_t * pui32Tag)) ROM_AESTABLE[5])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define AESDataRead ((void (*)(uint32_t ui32Base, uint32_t * pui32Dest)) ROM_AESTABLE[6])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define AESDataReadNonBlocking ((bool (*)(uint32_t ui32Base, uint32_t * pui32Dest)) ROM_AESTABLE[7])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define AESDataWrite ((void (*)(uint32_t ui32Base, uint32_t * pui32Src)) ROM_AESTABLE[8])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define AESDataWriteNonBlocking ((bool (*)(uint32_t ui32Base, uint32_t * pui32Src)) ROM_AESTABLE[9])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define AESDMADisable ((void (*)(uint32_t ui32Base, uint32_t ui32Flags))ROM_AESTABLE[10])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define AESDMAEnable ((void (*)(uint32_t ui32Base, uint32_t ui32Flags))ROM_AESTABLE[11])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define AESIntClear ((void (*)(uint32_t ui32Base, uint32_t ui32IntFlags))ROM_AESTABLE[12])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define AESIntDisable ((void (*)(uint32_t ui32Base, uint32_t ui32IntFlags))ROM_AESTABLE[13])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define AESIntEnable ((void (*)(uint32_t ui32Base, uint32_t ui32IntFlags))ROM_AESTABLE[14])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define AESIVSet ((void (*)(uint32_t ui32Base, uint32_t * pui32IVdata)) ROM_AESTABLE[15])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define AESKey1Set ((void (*)(uint32_t ui32Base, uint32_t * pui32Key, uint32_t ui32Keysize)) ROM_AESTABLE[16])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define AESKey2Set ((void (*)(uint32_t ui32Base, uint32_t * pui32Key, uint32_t ui32Keysize)) ROM_AESTABLE[17])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define AESKey3Set ((void (*)(uint32_t ui32Base, uint32_t * pui32Key)) ROM_AESTABLE[18])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define AESLengthSet ((void (*)(uint32_t ui32Base, uint64_t ui64Length))ROM_AESTABLE[19])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define AESReset ((void (*)(uint32_t ui32Base))ROM_AESTABLE[20])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define AESTagRead ((void (*)(uint32_t ui32Base, uint32_t * pui32TagData)) ROM_AESTABLE[21])
#endif
#if defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define AESIVRead ((void (*)(uint32_t ui32Base, uint32_t * pui32IVdata)) ROM_AESTABLE[22])
#endif

//*****************************************************************************
//
// Macros for calling ROM functions in the CAN API.
//
//*****************************************************************************
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define CANIntClear ((void (*)(uint32_t ui32Base, uint32_t ui32IntClr))ROM_CANTABLE[0])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define CANInit ((void (*)(uint32_t ui32Base))ROM_CANTABLE[1])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define CANEnable ((void (*)(uint32_t ui32Base))ROM_CANTABLE[2])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define CANDisable ((void (*)(uint32_t ui32Base))ROM_CANTABLE[3])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define CANBitTimingSet ((void (*)(uint32_t ui32Base, tCANBitClkParms * psClkParms)) ROM_CANTABLE[4])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define CANBitTimingGet ((void (*)(uint32_t ui32Base, tCANBitClkParms * psClkParms)) ROM_CANTABLE[5])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define CANMessageSet                                                                                     \
    ((void (*)(uint32_t ui32Base, uint32_t ui32ObjID, tCANMsgObject * psMsgObject, tMsgObjType eMsgType)) \
         ROM_CANTABLE[6])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define CANMessageGet                                                                                    \
    ((void (*)(uint32_t ui32Base, uint32_t ui32ObjID, tCANMsgObject * psMsgObject, bool bClrPendingInt)) \
         ROM_CANTABLE[7])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define CANStatusGet ((uint32_t(*)(uint32_t ui32Base, tCANStsReg eStatusReg))ROM_CANTABLE[8])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define CANMessageClear ((void (*)(uint32_t ui32Base, uint32_t ui32ObjID))ROM_CANTABLE[9])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define CANIntEnable ((void (*)(uint32_t ui32Base, uint32_t ui32IntFlags))ROM_CANTABLE[10])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define CANIntDisable ((void (*)(uint32_t ui32Base, uint32_t ui32IntFlags))ROM_CANTABLE[11])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define CANIntStatus ((uint32_t(*)(uint32_t ui32Base, tCANIntStsReg eIntStsReg))ROM_CANTABLE[12])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define CANRetryGet ((bool (*)(uint32_t ui32Base))ROM_CANTABLE[13])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define CANRetrySet ((void (*)(uint32_t ui32Base, bool bAutoRetry))ROM_CANTABLE[14])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define CANErrCntrGet ((bool (*)(uint32_t ui32Base, uint32_t * pui32RxCount, uint32_t * pui32TxCount)) ROM_CANTABLE[15])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define CANBitRateSet ((uint32_t(*)(uint32_t ui32Base, uint32_t ui32SourceClock, uint32_t ui32BitRate))ROM_CANTABLE[16])
#endif

//*****************************************************************************
//
// Macros for calling ROM functions in the Comparator API.
//
//*****************************************************************************
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define ComparatorIntClear ((void (*)(uint32_t ui32Base, uint32_t ui32Comp))ROM_COMPARATORTABLE[0])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define ComparatorConfigure \
    ((void (*)(uint32_t ui32Base, uint32_t ui32Comp, uint32_t ui32Config))ROM_COMPARATORTABLE[1])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define ComparatorRefSet ((void (*)(uint32_t ui32Base, uint32_t ui32Ref))ROM_COMPARATORTABLE[2])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define ComparatorValueGet ((bool (*)(uint32_t ui32Base, uint32_t ui32Comp))ROM_COMPARATORTABLE[3])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define ComparatorIntEnable ((void (*)(uint32_t ui32Base, uint32_t ui32Comp))ROM_COMPARATORTABLE[4])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define ComparatorIntDisable ((void (*)(uint32_t ui32Base, uint32_t ui32Comp))ROM_COMPARATORTABLE[5])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define ComparatorIntStatus ((bool (*)(uint32_t ui32Base, uint32_t ui32Comp, bool bMasked))ROM_COMPARATORTABLE[6])
#endif

//*****************************************************************************
//
// Macros for calling ROM functions in the CRC API.
//
//*****************************************************************************
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define CRCConfigSet ((void (*)(uint32_t ui32Base, uint32_t ui32CRCConfig))ROM_CRCTABLE[0])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define CRCDataProcess \
    ((uint32_t(*)(uint32_t ui32Base, uint32_t * pui32DataIn, uint32_t ui32DataLength, bool bPPResult)) ROM_CRCTABLE[1])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define CRCDataWrite ((void (*)(uint32_t ui32Base, uint32_t ui32Data))ROM_CRCTABLE[2])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define CRCResultRead ((uint32_t(*)(uint32_t ui32Base, bool bPPResult))ROM_CRCTABLE[3])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define CRCSeedSet ((void (*)(uint32_t ui32Base, uint32_t ui32Seed))ROM_CRCTABLE[4])
#endif

//*****************************************************************************
//
// Macros for calling ROM functions in the DES API.
//
//*****************************************************************************
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define DESIntStatus ((uint32_t(*)(uint32_t ui32Base, bool bMasked))ROM_DESTABLE[0])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define DESConfigSet ((void (*)(uint32_t ui32Base, uint32_t ui32Config))ROM_DESTABLE[1])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define DESDataRead ((void (*)(uint32_t ui32Base, uint32_t * pui32Dest)) ROM_DESTABLE[2])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define DESDataReadNonBlocking ((bool (*)(uint32_t ui32Base, uint32_t * pui32Dest)) ROM_DESTABLE[3])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define DESDataProcess \
    ((bool (*)(uint32_t ui32Base, uint32_t * pui32Src, uint32_t * pui32Dest, uint32_t ui32Length)) ROM_DESTABLE[4])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define DESDataWrite ((void (*)(uint32_t ui32Base, uint32_t * pui32Src)) ROM_DESTABLE[5])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define DESDataWriteNonBlocking ((bool (*)(uint32_t ui32Base, uint32_t * pui32Src)) ROM_DESTABLE[6])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define DESDMADisable ((void (*)(uint32_t ui32Base, uint32_t ui32Flags))ROM_DESTABLE[7])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define DESDMAEnable ((void (*)(uint32_t ui32Base, uint32_t ui32Flags))ROM_DESTABLE[8])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define DESIntClear ((void (*)(uint32_t ui32Base, uint32_t ui32IntFlags))ROM_DESTABLE[9])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define DESIntDisable ((void (*)(uint32_t ui32Base, uint32_t ui32IntFlags))ROM_DESTABLE[10])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define DESIntEnable ((void (*)(uint32_t ui32Base, uint32_t ui32IntFlags))ROM_DESTABLE[11])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define DESIVSet ((bool (*)(uint32_t ui32Base, uint32_t * pui32IVdata)) ROM_DESTABLE[12])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define DESKeySet ((void (*)(uint32_t ui32Base, uint32_t * pui32Key)) ROM_DESTABLE[13])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define DESLengthSet ((void (*)(uint32_t ui32Base, uint32_t ui32Length))ROM_DESTABLE[14])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define DESReset ((void (*)(uint32_t ui32Base))ROM_DESTABLE[15])
#endif

//*****************************************************************************
//
// Macros for calling ROM functions in the EEPROM API.
//
//*****************************************************************************
#if defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || defined(TARGET_IS_TM4C123_RB2) || \
    defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define EEPROMRead ((void (*)(uint32_t * pui32Data, uint32_t ui32Address, uint32_t ui32Count)) ROM_EEPROMTABLE[0])
#endif
#if defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || defined(TARGET_IS_TM4C123_RB2) || \
    defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define EEPROMBlockCountGet ((uint32_t(*)(void))ROM_EEPROMTABLE[1])
#endif
#if defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || defined(TARGET_IS_TM4C123_RB2) || \
    defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define EEPROMBlockHide ((void (*)(uint32_t ui32Block))ROM_EEPROMTABLE[2])
#endif
#if defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || defined(TARGET_IS_TM4C123_RB2) || \
    defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define EEPROMBlockLock ((uint32_t(*)(uint32_t ui32Block))ROM_EEPROMTABLE[3])
#endif
#if defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || defined(TARGET_IS_TM4C123_RB2) || \
    defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define EEPROMBlockPasswordSet \
    ((uint32_t(*)(uint32_t ui32Block, uint32_t * pui32Password, uint32_t ui32Count)) ROM_EEPROMTABLE[4])
#endif
#if defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || defined(TARGET_IS_TM4C123_RB2) || \
    defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define EEPROMBlockProtectGet ((uint32_t(*)(uint32_t ui32Block))ROM_EEPROMTABLE[5])
#endif
#if defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || defined(TARGET_IS_TM4C123_RB2) || \
    defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define EEPROMBlockProtectSet ((uint32_t(*)(uint32_t ui32Block, uint32_t ui32Protect))ROM_EEPROMTABLE[6])
#endif
#if defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || defined(TARGET_IS_TM4C123_RB2) || \
    defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define EEPROMBlockUnlock \
    ((uint32_t(*)(uint32_t ui32Block, uint32_t * pui32Password, uint32_t ui32Count)) ROM_EEPROMTABLE[7])
#endif
#if defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || defined(TARGET_IS_TM4C123_RB2) || \
    defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define EEPROMIntClear ((void (*)(uint32_t ui32IntFlags))ROM_EEPROMTABLE[8])
#endif
#if defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || defined(TARGET_IS_TM4C123_RB2) || \
    defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define EEPROMIntDisable ((void (*)(uint32_t ui32IntFlags))ROM_EEPROMTABLE[9])
#endif
#if defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || defined(TARGET_IS_TM4C123_RB2) || \
    defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define EEPROMIntEnable ((void (*)(uint32_t ui32IntFlags))ROM_EEPROMTABLE[10])
#endif
#if defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || defined(TARGET_IS_TM4C123_RB2) || \
    defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define EEPROMIntStatus ((uint32_t(*)(bool bMasked))ROM_EEPROMTABLE[11])
#endif
#if defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1)
#define EEPROMMassErase ((uint32_t(*)(void))ROM_EEPROMTABLE[12])
#endif
#if defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || defined(TARGET_IS_TM4C123_RB2) || \
    defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define EEPROMProgram \
    ((uint32_t(*)(uint32_t * pui32Data, uint32_t ui32Address, uint32_t ui32Count)) ROM_EEPROMTABLE[13])
#endif
#if defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || defined(TARGET_IS_TM4C123_RB2) || \
    defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define EEPROMProgramNonBlocking ((uint32_t(*)(uint32_t ui32Data, uint32_t ui32Address))ROM_EEPROMTABLE[14])
#endif
#if defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || defined(TARGET_IS_TM4C123_RB2) || \
    defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define EEPROMSizeGet ((uint32_t(*)(void))ROM_EEPROMTABLE[15])
#endif
#if defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || defined(TARGET_IS_TM4C123_RB2) || \
    defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define EEPROMStatusGet ((uint32_t(*)(void))ROM_EEPROMTABLE[16])
#endif

/**
 * Errata MEM#11
 *
 * Description: The ROM_EEPROMInit API in TivaWare does not correctly initialize the EEPROM module
 * as described in the data sheet. It should not be used to initialize the EEPROM.
 *
 * Workaround: Use the Flash version of the EEPROMInit API in TivaWare version 2.1 or later.
 */

//*****************************************************************************
//
// Macros for calling ROM functions in the EPI API.
//
//*****************************************************************************
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define EPIIntStatus ((uint32_t(*)(uint32_t ui32Base, bool bMasked))ROM_EPITABLE[0])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define EPIModeSet ((void (*)(uint32_t ui32Base, uint32_t ui32Mode))ROM_EPITABLE[1])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define EPIDividerSet ((void (*)(uint32_t ui32Base, uint32_t ui32Divider))ROM_EPITABLE[2])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define EPIConfigSDRAMSet ((void (*)(uint32_t ui32Base, uint32_t ui32Config, uint32_t ui32Refresh))ROM_EPITABLE[3])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define EPIConfigGPModeSet \
    ((void (*)(uint32_t ui32Base, uint32_t ui32Config, uint32_t ui32FrameCount, uint32_t ui32MaxWait))ROM_EPITABLE[4])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define EPIConfigHB8Set ((void (*)(uint32_t ui32Base, uint32_t ui32Config, uint32_t ui32MaxWait))ROM_EPITABLE[5])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define EPIConfigHB16Set ((void (*)(uint32_t ui32Base, uint32_t ui32Config, uint32_t ui32MaxWait))ROM_EPITABLE[6])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define EPIAddressMapSet ((void (*)(uint32_t ui32Base, uint32_t ui32Map))ROM_EPITABLE[7])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define EPINonBlockingReadConfigure \
    ((void (*)(uint32_t ui32Base, uint32_t ui32Channel, uint32_t ui32DataSize, uint32_t ui32Address))ROM_EPITABLE[8])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define EPINonBlockingReadStart ((void (*)(uint32_t ui32Base, uint32_t ui32Channel, uint32_t ui32Count))ROM_EPITABLE[9])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define EPINonBlockingReadStop ((void (*)(uint32_t ui32Base, uint32_t ui32Channel))ROM_EPITABLE[10])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define EPINonBlockingReadCount ((uint32_t(*)(uint32_t ui32Base, uint32_t ui32Channel))ROM_EPITABLE[11])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define EPINonBlockingReadAvail ((uint32_t(*)(uint32_t ui32Base))ROM_EPITABLE[12])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define EPINonBlockingReadGet32 \
    ((uint32_t(*)(uint32_t ui32Base, uint32_t ui32Count, uint32_t * pui32Buf)) ROM_EPITABLE[13])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define EPINonBlockingReadGet16 \
    ((uint32_t(*)(uint32_t ui32Base, uint32_t ui32Count, uint16_t * pui16Buf)) ROM_EPITABLE[14])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define EPINonBlockingReadGet8 \
    ((uint32_t(*)(uint32_t ui32Base, uint32_t ui32Count, uint8_t * pui8Buf)) ROM_EPITABLE[15])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define EPIFIFOConfig ((void (*)(uint32_t ui32Base, uint32_t ui32Config))ROM_EPITABLE[16])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define EPIWriteFIFOCountGet ((uint32_t(*)(uint32_t ui32Base))ROM_EPITABLE[17])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define EPIIntEnable ((void (*)(uint32_t ui32Base, uint32_t ui32IntFlags))ROM_EPITABLE[18])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define EPIIntDisable ((void (*)(uint32_t ui32Base, uint32_t ui32IntFlags))ROM_EPITABLE[19])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define EPIIntErrorStatus ((uint32_t(*)(uint32_t ui32Base))ROM_EPITABLE[20])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define EPIIntErrorClear ((void (*)(uint32_t ui32Base, uint32_t ui32ErrFlags))ROM_EPITABLE[21])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define EPIDividerCSSet ((void (*)(uint32_t ui32Base, uint32_t ui32CS, uint32_t ui32Divider))ROM_EPITABLE[22])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define EPIDMATxCount ((void (*)(uint32_t ui32Base, uint32_t ui32Count))ROM_EPITABLE[23])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define EPIConfigHB8CSSet ((void (*)(uint32_t ui32Base, uint32_t ui32CS, uint32_t ui32Config))ROM_EPITABLE[24])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define EPIConfigHB16CSSet ((void (*)(uint32_t ui32Base, uint32_t ui32CS, uint32_t ui32Config))ROM_EPITABLE[25])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define EPIConfigHB8TimingSet ((void (*)(uint32_t ui32Base, uint32_t ui32CS, uint32_t ui32Config))ROM_EPITABLE[26])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define EPIConfigHB16TimingSet ((void (*)(uint32_t ui32Base, uint32_t ui32CS, uint32_t ui32Config))ROM_EPITABLE[27])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define EPIPSRAMConfigRegSet ((void (*)(uint32_t ui32Base, uint32_t ui32CS, uint32_t ui32CR))ROM_EPITABLE[28])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define EPIPSRAMConfigRegRead ((void (*)(uint32_t ui32Base, uint32_t ui32CS))ROM_EPITABLE[29])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define EPIPSRAMConfigRegGetNonBlocking \
    ((bool (*)(uint32_t ui32Base, uint32_t ui32CS, uint32_t * pui32CR)) ROM_EPITABLE[30])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define EPIPSRAMConfigRegGet ((uint32_t(*)(uint32_t ui32Base, uint32_t ui32CS))ROM_EPITABLE[31])
#endif

//*****************************************************************************
//
// Macros for calling ROM functions in the EMAC API.
//
//*****************************************************************************
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define EMACIntStatus ((uint32_t(*)(uint32_t ui32Base, bool bMasked))ROM_EMACTABLE[0])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define EMACAddrGet ((void (*)(uint32_t ui32Base, uint32_t ui32Index, uint8_t * pui8MACAddr)) ROM_EMACTABLE[1])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define EMACAddrSet ((void (*)(uint32_t ui32Base, uint32_t ui32Index, const uint8_t* pui8MACAddr))ROM_EMACTABLE[2])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define EMACConfigGet                                                                                            \
    ((void (*)(uint32_t ui32Base, uint32_t * pui32Config, uint32_t * pui32Mode, uint32_t * pui32RxMaxFrameSize)) \
         ROM_EMACTABLE[3])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define EMACConfigSet                                                                                        \
    ((void (*)(uint32_t ui32Base, uint32_t ui32Config, uint32_t ui32ModeFlags, uint32_t ui32RxMaxFrameSize)) \
         ROM_EMACTABLE[4])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define EMACDMAStateGet ((uint32_t(*)(uint32_t ui32Base))ROM_EMACTABLE[5])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define EMACFrameFilterGet ((uint32_t(*)(uint32_t ui32Base))ROM_EMACTABLE[6])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define EMACFrameFilterSet ((void (*)(uint32_t ui32Base, uint32_t ui32FilterOpts))ROM_EMACTABLE[7])
#endif
#if defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define EMACInit                       \
    ((void (*)(uint32_t ui32Base,      \
               uint32_t ui32SysClk,    \
               uint32_t ui32BusConfig, \
               uint32_t ui32RxBurst,   \
               uint32_t ui32TxBurst,   \
               uint32_t ui32DescSkipSize))ROM_EMACTABLE[8])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define EMACIntClear ((void (*)(uint32_t ui32Base, uint32_t ui32IntFlags))ROM_EMACTABLE[9])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define EMACIntDisable ((void (*)(uint32_t ui32Base, uint32_t ui32IntFlags))ROM_EMACTABLE[10])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define EMACIntEnable ((void (*)(uint32_t ui32Base, uint32_t ui32IntFlags))ROM_EMACTABLE[11])
#endif
#if defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define EMACPHYConfigSet ((void (*)(uint32_t ui32Base, uint32_t ui32Config))ROM_EMACTABLE[12])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define EMACPHYPowerOff ((void (*)(uint32_t ui32Base, uint8_t ui8PhyAddr))ROM_EMACTABLE[13])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define EMACPHYPowerOn ((void (*)(uint32_t ui32Base, uint8_t ui8PhyAddr))ROM_EMACTABLE[14])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define EMACPHYRead ((uint16_t(*)(uint32_t ui32Base, uint8_t ui8PhyAddr, uint8_t ui8RegAddr))ROM_EMACTABLE[15])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define EMACPHYWrite \
    ((void (*)(uint32_t ui32Base, uint8_t ui8PhyAddr, uint8_t ui8RegAddr, uint16_t ui16Data))ROM_EMACTABLE[16])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define EMACReset ((void (*)(uint32_t ui32Base))ROM_EMACTABLE[17])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define EMACRxDisable ((void (*)(uint32_t ui32Base))ROM_EMACTABLE[18])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define EMACRxDMACurrentBufferGet ((uint8_t * (*)(uint32_t ui32Base)) ROM_EMACTABLE[19])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define EMACRxDMACurrentDescriptorGet ((tEMACDMADescriptor * (*)(uint32_t ui32Base)) ROM_EMACTABLE[20])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define EMACRxDMADescriptorListGet ((tEMACDMADescriptor * (*)(uint32_t ui32Base)) ROM_EMACTABLE[21])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define EMACRxDMADescriptorListSet ((void (*)(uint32_t ui32Base, tEMACDMADescriptor * pDescriptor)) ROM_EMACTABLE[22])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define EMACRxDMAPollDemand ((void (*)(uint32_t ui32Base))ROM_EMACTABLE[23])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define EMACRxEnable ((void (*)(uint32_t ui32Base))ROM_EMACTABLE[24])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define EMACRxWatchdogTimerSet ((void (*)(uint32_t ui32Base, uint8_t ui8Timeout))ROM_EMACTABLE[25])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define EMACStatusGet ((uint32_t(*)(uint32_t ui32Base))ROM_EMACTABLE[26])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define EMACTxDisable ((void (*)(uint32_t ui32Base))ROM_EMACTABLE[27])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define EMACTxDMACurrentBufferGet ((uint8_t * (*)(uint32_t ui32Base)) ROM_EMACTABLE[28])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define EMACTxDMACurrentDescriptorGet ((tEMACDMADescriptor * (*)(uint32_t ui32Base)) ROM_EMACTABLE[29])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define EMACTxDMADescriptorListGet ((tEMACDMADescriptor * (*)(uint32_t ui32Base)) ROM_EMACTABLE[30])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define EMACTxDMADescriptorListSet ((void (*)(uint32_t ui32Base, tEMACDMADescriptor * pDescriptor)) ROM_EMACTABLE[31])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define EMACTxDMAPollDemand ((void (*)(uint32_t ui32Base))ROM_EMACTABLE[32])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define EMACTxEnable ((void (*)(uint32_t ui32Base))ROM_EMACTABLE[33])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define EMACTxFlush ((void (*)(uint32_t ui32Base))ROM_EMACTABLE[34])
#endif
#if defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define EMACAddrFilterGet ((uint32_t(*)(uint32_t ui32Base, uint32_t ui32Index))ROM_EMACTABLE[35])
#endif
#if defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define EMACAddrFilterSet ((void (*)(uint32_t ui32Base, uint32_t ui32Index, uint32_t ui32Config))ROM_EMACTABLE[36])
#endif
#if defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define EMACHashFilterBitCalculate ((uint32_t(*)(uint8_t * pui8MACAddr)) ROM_EMACTABLE[37])
#endif
#if defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define EMACHashFilterGet \
    ((void (*)(uint32_t ui32Base, uint32_t * pui32HashHi, uint32_t * pui32HashLo)) ROM_EMACTABLE[38])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define EMACHashFilterSet ((void (*)(uint32_t ui32Base, uint32_t ui32HashHi, uint32_t ui32HashLo))ROM_EMACTABLE[39])
#endif
#if defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define EMACNumAddrGet ((uint32_t(*)(uint32_t ui32Base))ROM_EMACTABLE[40])
#endif
#if defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define EMACPHYExtendedRead \
    ((uint16_t(*)(uint32_t ui32Base, uint8_t ui8PhyAddr, uint16_t ui16RegAddr))ROM_EMACTABLE[41])
#endif
#if defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define EMACPHYExtendedWrite \
    ((void (*)(uint32_t ui32Base, uint8_t ui8PhyAddr, uint16_t ui16RegAddr, uint16_t ui16Data))ROM_EMACTABLE[42])
#endif
#if defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define EMACPowerManagementControlGet ((uint32_t(*)(uint32_t ui32Base))ROM_EMACTABLE[43])
#endif
#if defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define EMACPowerManagementControlSet ((void (*)(uint32_t ui32Base, uint32_t ui32Flags))ROM_EMACTABLE[44])
#endif
#if defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define EMACPowerManagementStatusGet ((uint32_t(*)(uint32_t ui32Base))ROM_EMACTABLE[45])
#endif
#if defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define EMACRemoteWakeUpFrameFilterGet \
    ((void (*)(uint32_t ui32Base, tEMACWakeUpFrameFilter * pFilter)) ROM_EMACTABLE[46])
#endif
#if defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define EMACRemoteWakeUpFrameFilterSet \
    ((void (*)(uint32_t ui32Base, const tEMACWakeUpFrameFilter* pFilter))ROM_EMACTABLE[47])
#endif
#if defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define EMACTimestampAddendSet ((void (*)(uint32_t ui32Base, uint32_t ui32Seconds))ROM_EMACTABLE[48])
#endif
#if defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define EMACTimestampConfigGet ((uint32_t(*)(uint32_t ui32Base, uint32_t * pui32SubSecondInc)) ROM_EMACTABLE[49])
#endif
#if defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define EMACTimestampConfigSet \
    ((void (*)(uint32_t ui32Base, uint32_t ui32Config, uint32_t ui32SubSecondInc))ROM_EMACTABLE[50])
#endif
#if defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define EMACTimestampDisable ((void (*)(uint32_t ui32Base))ROM_EMACTABLE[51])
#endif
#if defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define EMACTimestampEnable ((void (*)(uint32_t ui32Base))ROM_EMACTABLE[52])
#endif
#if defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define EMACTimestampIntStatus ((uint32_t(*)(uint32_t ui32Base))ROM_EMACTABLE[53])
#endif
#if defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define EMACTimestampPPSCommand ((void (*)(uint32_t ui32Base, uint8_t ui8Cmd))ROM_EMACTABLE[54])
#endif
#if defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define EMACTimestampPPSCommandModeSet ((void (*)(uint32_t ui32Base, uint32_t ui32Config))ROM_EMACTABLE[55])
#endif
#if defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define EMACTimestampPPSPeriodSet \
    ((void (*)(uint32_t ui32Base, uint32_t ui32Period, uint32_t ui32Width))ROM_EMACTABLE[56])
#endif
#if defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define EMACTimestampPPSSimpleModeSet ((void (*)(uint32_t ui32Base, uint32_t ui32FreqConfig))ROM_EMACTABLE[57])
#endif
#if defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define EMACTimestampSysTimeGet \
    ((void (*)(uint32_t ui32Base, uint32_t * pui32Seconds, uint32_t * pui32SubSeconds)) ROM_EMACTABLE[58])
#endif
#if defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define EMACTimestampSysTimeSet \
    ((void (*)(uint32_t ui32Base, uint32_t ui32Seconds, uint32_t ui32SubSeconds))ROM_EMACTABLE[59])
#endif
#if defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define EMACTimestampSysTimeUpdate \
    ((void (*)(uint32_t ui32Base, uint32_t ui32Seconds, uint32_t ui32SubSeconds, bool bInc))ROM_EMACTABLE[60])
#endif
#if defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define EMACTimestampTargetIntDisable ((void (*)(uint32_t ui32Base))ROM_EMACTABLE[61])
#endif
#if defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define EMACTimestampTargetIntEnable ((void (*)(uint32_t ui32Base))ROM_EMACTABLE[62])
#endif
#if defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define EMACTimestampTargetSet \
    ((void (*)(uint32_t ui32Base, uint32_t ui32Seconds, uint32_t ui32Nanoseconds))ROM_EMACTABLE[63])
#endif
#if defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define EMACVLANHashFilterBitCalculate ((uint32_t(*)(uint16_t ui16Tag))ROM_EMACTABLE[64])
#endif
#if defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define EMACVLANHashFilterGet ((uint32_t(*)(uint32_t ui32Base))ROM_EMACTABLE[65])
#endif
#if defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define EMACVLANHashFilterSet ((void (*)(uint32_t ui32Base, uint32_t ui32Hash))ROM_EMACTABLE[66])
#endif
#if defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define EMACVLANRxConfigGet ((uint32_t(*)(uint32_t ui32Base, uint16_t * pui16Tag)) ROM_EMACTABLE[67])
#endif
#if defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define EMACVLANRxConfigSet ((void (*)(uint32_t ui32Base, uint16_t ui16Tag, uint32_t ui32Config))ROM_EMACTABLE[68])
#endif
#if defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define EMACVLANTxConfigGet ((uint32_t(*)(uint32_t ui32Base, uint16_t * pui16Tag)) ROM_EMACTABLE[69])
#endif
#if defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define EMACVLANTxConfigSet ((void (*)(uint32_t ui32Base, uint16_t ui16Tag, uint32_t ui32Config))ROM_EMACTABLE[70])
#endif
#if defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define UpdateEMAC ((void (*)(uint32_t ui32Clock))ROM_EMACTABLE[71])
#endif

//*****************************************************************************
//
// Macros for calling ROM functions in the Flash API.
//
//*****************************************************************************
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define FlashProgram ((int32_t(*)(uint32_t * pui32Data, uint32_t ui32Address, uint32_t ui32Count)) ROM_FLASHTABLE[0])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define FlashErase ((int32_t(*)(uint32_t ui32Address))ROM_FLASHTABLE[3])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define FlashProtectGet ((tFlashProtection(*)(uint32_t ui32Address))ROM_FLASHTABLE[4])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define FlashProtectSet ((int32_t(*)(uint32_t ui32Address, tFlashProtection eProtect))ROM_FLASHTABLE[5])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define FlashProtectSave ((int32_t(*)(void))ROM_FLASHTABLE[6])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define FlashUserGet ((int32_t(*)(uint32_t * pui32User0, uint32_t * pui32User1)) ROM_FLASHTABLE[7])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define FlashUserSet ((int32_t(*)(uint32_t ui32User0, uint32_t ui32User1))ROM_FLASHTABLE[8])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define FlashUserSave ((int32_t(*)(void))ROM_FLASHTABLE[9])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define FlashIntEnable ((void (*)(uint32_t ui32IntFlags))ROM_FLASHTABLE[10])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define FlashIntDisable ((void (*)(uint32_t ui32IntFlags))ROM_FLASHTABLE[11])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define FlashIntStatus ((uint32_t(*)(bool bMasked))ROM_FLASHTABLE[12])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define FlashIntClear ((void (*)(uint32_t ui32IntFlags))ROM_FLASHTABLE[13])
#endif

//*****************************************************************************
//
// Macros for calling ROM functions in the FPU API.
//
//*****************************************************************************
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define FPUEnable ((void (*)(void))ROM_FPUTABLE[0])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define FPUDisable ((void (*)(void))ROM_FPUTABLE[1])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define FPUFlushToZeroModeSet ((void (*)(uint32_t ui32Mode))ROM_FPUTABLE[2])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define FPUHalfPrecisionModeSet ((void (*)(uint32_t ui32Mode))ROM_FPUTABLE[3])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define FPULazyStackingEnable ((void (*)(void))ROM_FPUTABLE[4])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define FPUNaNModeSet ((void (*)(uint32_t ui32Mode))ROM_FPUTABLE[5])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define FPURoundingModeSet ((void (*)(uint32_t ui32Mode))ROM_FPUTABLE[6])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define FPUStackingDisable ((void (*)(void))ROM_FPUTABLE[7])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define FPUStackingEnable ((void (*)(void))ROM_FPUTABLE[8])
#endif

//*****************************************************************************
//
// Macros for calling ROM functions in the GPIO API.
//
//*****************************************************************************
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define GPIOPinWrite ((void (*)(uint32_t ui32Port, uint8_t ui8Pins, uint8_t ui8Val))ROM_GPIOTABLE[0])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define GPIODirModeSet ((void (*)(uint32_t ui32Port, uint8_t ui8Pins, uint32_t ui32PinIO))ROM_GPIOTABLE[1])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define GPIODirModeGet ((uint32_t(*)(uint32_t ui32Port, uint8_t ui8Pin))ROM_GPIOTABLE[2])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define GPIOIntTypeSet ((void (*)(uint32_t ui32Port, uint8_t ui8Pins, uint32_t ui32IntType))ROM_GPIOTABLE[3])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define GPIOIntTypeGet ((uint32_t(*)(uint32_t ui32Port, uint8_t ui8Pin))ROM_GPIOTABLE[4])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2)
#define GPIOPadConfigSet \
    ((void (*)(uint32_t ui32Port, uint8_t ui8Pins, uint32_t ui32Strength, uint32_t ui32PadType))ROM_GPIOTABLE[5])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define GPIOPadConfigGet \
    ((void (*)(uint32_t ui32Port, uint8_t ui8Pin, uint32_t * pui32Strength, uint32_t * pui32PadType)) ROM_GPIOTABLE[6])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define GPIOPinRead ((int32_t(*)(uint32_t ui32Port, uint8_t ui8Pins))ROM_GPIOTABLE[11])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2)
#define GPIOPinTypeCAN ((void (*)(uint32_t ui32Port, uint8_t ui8Pins))ROM_GPIOTABLE[12])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define GPIOPinTypeComparator ((void (*)(uint32_t ui32Port, uint8_t ui8Pins))ROM_GPIOTABLE[13])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define GPIOPinTypeGPIOInput ((void (*)(uint32_t ui32Port, uint8_t ui8Pins))ROM_GPIOTABLE[14])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define GPIOPinTypeGPIOOutput ((void (*)(uint32_t ui32Port, uint8_t ui8Pins))ROM_GPIOTABLE[15])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define GPIOPinTypeI2C ((void (*)(uint32_t ui32Port, uint8_t ui8Pins))ROM_GPIOTABLE[16])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define GPIOPinTypePWM ((void (*)(uint32_t ui32Port, uint8_t ui8Pins))ROM_GPIOTABLE[17])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define GPIOPinTypeQEI ((void (*)(uint32_t ui32Port, uint8_t ui8Pins))ROM_GPIOTABLE[18])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define GPIOPinTypeSSI ((void (*)(uint32_t ui32Port, uint8_t ui8Pins))ROM_GPIOTABLE[19])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define GPIOPinTypeTimer ((void (*)(uint32_t ui32Port, uint8_t ui8Pins))ROM_GPIOTABLE[20])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define GPIOPinTypeUART ((void (*)(uint32_t ui32Port, uint8_t ui8Pins))ROM_GPIOTABLE[21])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define GPIOPinTypeGPIOOutputOD ((void (*)(uint32_t ui32Port, uint8_t ui8Pins))ROM_GPIOTABLE[22])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define GPIOPinTypeADC ((void (*)(uint32_t ui32Port, uint8_t ui8Pins))ROM_GPIOTABLE[23])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define GPIOPinTypeUSBDigital ((void (*)(uint32_t ui32Port, uint8_t ui8Pins))ROM_GPIOTABLE[24])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define GPIOPinConfigure ((void (*)(uint32_t ui32PinConfig))ROM_GPIOTABLE[26])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define GPIOPinTypeUSBAnalog ((void (*)(uint32_t ui32Port, uint8_t ui8Pins))ROM_GPIOTABLE[28])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define GPIODMATriggerEnable ((void (*)(uint32_t ui32Port, uint8_t ui8Pins))ROM_GPIOTABLE[31])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define GPIODMATriggerDisable ((void (*)(uint32_t ui32Port, uint8_t ui8Pins))ROM_GPIOTABLE[32])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define GPIOADCTriggerEnable ((void (*)(uint32_t ui32Port, uint8_t ui8Pins))ROM_GPIOTABLE[33])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define GPIOADCTriggerDisable ((void (*)(uint32_t ui32Port, uint8_t ui8Pins))ROM_GPIOTABLE[34])
#endif
#if defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || defined(TARGET_IS_TM4C123_RB2) || \
    defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define GPIOPinTypeI2CSCL ((void (*)(uint32_t ui32Port, uint8_t ui8Pins))ROM_GPIOTABLE[39])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define GPIOPinTypeOneWire ((void (*)(uint32_t ui32Port, uint8_t ui8Pins))ROM_GPIOTABLE[44])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define GPIOPinTypeWakeHigh ((void (*)(uint32_t ui32Port, uint8_t ui8Pins))ROM_GPIOTABLE[48])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define GPIOPinTypeWakeLow ((void (*)(uint32_t ui32Port, uint8_t ui8Pins))ROM_GPIOTABLE[49])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define GPIOIntClear ((void (*)(uint32_t ui32Port, uint32_t ui32IntFlags))ROM_GPIOTABLE[51])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define GPIOIntDisable ((void (*)(uint32_t ui32Port, uint32_t ui32IntFlags))ROM_GPIOTABLE[52])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define GPIOIntEnable ((void (*)(uint32_t ui32Port, uint32_t ui32IntFlags))ROM_GPIOTABLE[53])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define GPIOIntStatus ((uint32_t(*)(uint32_t ui32Port, bool bMasked))ROM_GPIOTABLE[54])
#endif

//*****************************************************************************
//
// Macros for calling ROM functions in the Hibernate API.
//
//*****************************************************************************
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define HibernateIntClear ((void (*)(uint32_t ui32IntFlags))ROM_HIBERNATETABLE[0])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define HibernateEnableExpClk ((void (*)(uint32_t ui32HibClk))ROM_HIBERNATETABLE[1])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define HibernateDisable ((void (*)(void))ROM_HIBERNATETABLE[2])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define HibernateRTCEnable ((void (*)(void))ROM_HIBERNATETABLE[4])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define HibernateRTCDisable ((void (*)(void))ROM_HIBERNATETABLE[5])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define HibernateWakeSet ((void (*)(uint32_t ui32WakeFlags))ROM_HIBERNATETABLE[6])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define HibernateWakeGet ((uint32_t(*)(void))ROM_HIBERNATETABLE[7])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define HibernateLowBatSet ((void (*)(uint32_t ui32LowBatFlags))ROM_HIBERNATETABLE[8])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define HibernateLowBatGet ((uint32_t(*)(void))ROM_HIBERNATETABLE[9])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define HibernateRTCSet ((void (*)(uint32_t ui32RTCValue))ROM_HIBERNATETABLE[10])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define HibernateRTCGet ((uint32_t(*)(void))ROM_HIBERNATETABLE[11])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define HibernateRTCTrimSet ((void (*)(uint32_t ui32Trim))ROM_HIBERNATETABLE[16])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define HibernateRTCTrimGet ((uint32_t(*)(void))ROM_HIBERNATETABLE[17])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define HibernateDataSet ((void (*)(uint32_t * pui32Data, uint32_t ui32Count)) ROM_HIBERNATETABLE[18])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define HibernateDataGet ((void (*)(uint32_t * pui32Data, uint32_t ui32Count)) ROM_HIBERNATETABLE[19])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define HibernateRequest ((void (*)(void))ROM_HIBERNATETABLE[20])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define HibernateIntEnable ((void (*)(uint32_t ui32IntFlags))ROM_HIBERNATETABLE[21])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define HibernateIntDisable ((void (*)(uint32_t ui32IntFlags))ROM_HIBERNATETABLE[22])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define HibernateIntStatus ((uint32_t(*)(bool bMasked))ROM_HIBERNATETABLE[23])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define HibernateIsActive ((uint32_t(*)(void))ROM_HIBERNATETABLE[24])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define HibernateRTCSSGet ((uint32_t(*)(void))ROM_HIBERNATETABLE[27])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define HibernateClockConfig ((void (*)(uint32_t ui32Config))ROM_HIBERNATETABLE[28])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define HibernateBatCheckStart ((void (*)(void))ROM_HIBERNATETABLE[29])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define HibernateBatCheckDone ((uint32_t(*)(void))ROM_HIBERNATETABLE[30])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define HibernateGPIORetentionEnable ((void (*)(void))ROM_HIBERNATETABLE[31])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define HibernateGPIORetentionDisable ((void (*)(void))ROM_HIBERNATETABLE[32])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define HibernateGPIORetentionGet ((bool (*)(void))ROM_HIBERNATETABLE[33])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define HibernateCounterMode ((void (*)(uint32_t ui32Config))ROM_HIBERNATETABLE[34])
#endif
#if defined(TARGET_IS_TM4C123_RB1) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define HibernateCalendarSet ((void (*)(struct tm * psTime)) ROM_HIBERNATETABLE[35])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define HibernateCalendarGet ((int (*)(struct tm * psTime)) ROM_HIBERNATETABLE[36])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define HibernateCalendarMatchSet ((void (*)(uint32_t ui32Index, struct tm * psTime)) ROM_HIBERNATETABLE[37])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define HibernateCalendarMatchGet ((void (*)(uint32_t ui32Index, struct tm * psTime)) ROM_HIBERNATETABLE[38])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define HibernateTamperDisable ((void (*)(void))ROM_HIBERNATETABLE[39])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define HibernateTamperEnable ((void (*)(void))ROM_HIBERNATETABLE[40])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define HibernateTamperEventsClear ((void (*)(void))ROM_HIBERNATETABLE[41])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define HibernateTamperEventsConfig ((void (*)(uint32_t ui32Config))ROM_HIBERNATETABLE[42])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define HibernateTamperEventsGet \
    ((bool (*)(uint32_t ui32Index, uint32_t * pui32RTC, uint32_t * pui32Event)) ROM_HIBERNATETABLE[43])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define HibernateTamperExtOscValid ((bool (*)(void))ROM_HIBERNATETABLE[44])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define HibernateTamperExtOscRecover ((void (*)(void))ROM_HIBERNATETABLE[45])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define HibernateTamperIODisable ((void (*)(uint32_t ui32Input))ROM_HIBERNATETABLE[46])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define HibernateTamperIOEnable ((void (*)(uint32_t ui32Input, uint32_t ui32Config))ROM_HIBERNATETABLE[47])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define HibernateTamperStatusGet ((uint32_t(*)(void))ROM_HIBERNATETABLE[48])
#endif
#if defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define HibernateRTCMatchGet ((uint32_t(*)(uint32_t ui32Match))ROM_HIBERNATETABLE[49])
#endif
#if defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define HibernateRTCMatchSet ((void (*)(uint32_t ui32Match, uint32_t ui32Value))ROM_HIBERNATETABLE[50])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define HibernateRTCSSMatchGet ((uint32_t(*)(uint32_t ui32Match))ROM_HIBERNATETABLE[51])
#endif
#if defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define HibernateRTCSSMatchSet ((void (*)(uint32_t ui32Match, uint32_t ui32Value))ROM_HIBERNATETABLE[52])
#endif

//*****************************************************************************
//
// Macros for calling ROM functions in the I2C API.
//
//*****************************************************************************
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define I2CMasterDataPut ((void (*)(uint32_t ui32Base, uint8_t ui8Data))ROM_I2CTABLE[0])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define I2CMasterInitExpClk ((void (*)(uint32_t ui32Base, uint32_t ui32I2CClk, bool bFast))ROM_I2CTABLE[1])
#endif
#if defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define I2CSlaveInit ((void (*)(uint32_t ui32Base, uint8_t ui8SlaveAddr))ROM_I2CTABLE[2])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define I2CMasterEnable ((void (*)(uint32_t ui32Base))ROM_I2CTABLE[3])
#endif
#if defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define I2CSlaveEnable ((void (*)(uint32_t ui32Base))ROM_I2CTABLE[4])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define I2CMasterDisable ((void (*)(uint32_t ui32Base))ROM_I2CTABLE[5])
#endif
#if defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define I2CSlaveDisable ((void (*)(uint32_t ui32Base))ROM_I2CTABLE[6])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define I2CMasterIntEnable ((void (*)(uint32_t ui32Base))ROM_I2CTABLE[7])
#endif
#if defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define I2CSlaveIntEnable ((void (*)(uint32_t ui32Base))ROM_I2CTABLE[8])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define I2CMasterIntDisable ((void (*)(uint32_t ui32Base))ROM_I2CTABLE[9])
#endif
#if defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define I2CSlaveIntDisable ((void (*)(uint32_t ui32Base))ROM_I2CTABLE[10])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define I2CMasterIntStatus ((bool (*)(uint32_t ui32Base, bool bMasked))ROM_I2CTABLE[11])
#endif
#if defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define I2CSlaveIntStatus ((bool (*)(uint32_t ui32Base, bool bMasked))ROM_I2CTABLE[12])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define I2CMasterIntClear ((void (*)(uint32_t ui32Base))ROM_I2CTABLE[13])
#endif
#if defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define I2CSlaveIntClear ((void (*)(uint32_t ui32Base))ROM_I2CTABLE[14])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define I2CMasterSlaveAddrSet ((void (*)(uint32_t ui32Base, uint8_t ui8SlaveAddr, bool bReceive))ROM_I2CTABLE[15])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define I2CMasterBusy ((bool (*)(uint32_t ui32Base))ROM_I2CTABLE[16])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define I2CMasterBusBusy ((bool (*)(uint32_t ui32Base))ROM_I2CTABLE[17])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define I2CMasterControl ((void (*)(uint32_t ui32Base, uint32_t ui32Cmd))ROM_I2CTABLE[18])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define I2CMasterErr ((uint32_t(*)(uint32_t ui32Base))ROM_I2CTABLE[19])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define I2CMasterDataGet ((uint32_t(*)(uint32_t ui32Base))ROM_I2CTABLE[20])
#endif
#if defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define I2CSlaveStatus ((uint32_t(*)(uint32_t ui32Base))ROM_I2CTABLE[21])
#endif
#if defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define I2CSlaveDataPut ((void (*)(uint32_t ui32Base, uint8_t ui8Data))ROM_I2CTABLE[22])
#endif
#if defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define I2CSlaveDataGet ((uint32_t(*)(uint32_t ui32Base))ROM_I2CTABLE[23])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define UpdateI2C ((void (*)(void))ROM_I2CTABLE[24])
#endif
#if defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define I2CSlaveIntEnableEx ((void (*)(uint32_t ui32Base, uint32_t ui32IntFlags))ROM_I2CTABLE[25])
#endif
#if defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define I2CSlaveIntDisableEx ((void (*)(uint32_t ui32Base, uint32_t ui32IntFlags))ROM_I2CTABLE[26])
#endif
#if defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define I2CSlaveIntStatusEx ((uint32_t(*)(uint32_t ui32Base, bool bMasked))ROM_I2CTABLE[27])
#endif
#if defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define I2CSlaveIntClearEx ((void (*)(uint32_t ui32Base, uint32_t ui32IntFlags))ROM_I2CTABLE[28])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define I2CMasterIntEnableEx ((void (*)(uint32_t ui32Base, uint32_t ui32IntFlags))ROM_I2CTABLE[29])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define I2CMasterIntDisableEx ((void (*)(uint32_t ui32Base, uint32_t ui32IntFlags))ROM_I2CTABLE[30])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define I2CMasterIntStatusEx ((uint32_t(*)(uint32_t ui32Base, bool bMasked))ROM_I2CTABLE[31])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define I2CMasterIntClearEx ((void (*)(uint32_t ui32Base, uint32_t ui32IntFlags))ROM_I2CTABLE[32])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define I2CMasterTimeoutSet ((void (*)(uint32_t ui32Base, uint32_t ui32Value))ROM_I2CTABLE[33])
#endif
#if defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define I2CSlaveACKOverride ((void (*)(uint32_t ui32Base, bool bEnable))ROM_I2CTABLE[34])
#endif
#if defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define I2CSlaveACKValueSet ((void (*)(uint32_t ui32Base, bool bACK))ROM_I2CTABLE[35])
#endif
#if defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define I2CSlaveAddressSet ((void (*)(uint32_t ui32Base, uint8_t ui8AddrNum, uint8_t ui8SlaveAddr))ROM_I2CTABLE[37])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define I2CMasterLineStateGet ((uint32_t(*)(uint32_t ui32Base))ROM_I2CTABLE[38])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define I2CTxFIFOConfigSet ((void (*)(uint32_t ui32Base, uint32_t ui32Config))ROM_I2CTABLE[39])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define I2CTxFIFOFlush ((void (*)(uint32_t ui32Base))ROM_I2CTABLE[40])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define I2CRxFIFOConfigSet ((void (*)(uint32_t ui32Base, uint32_t ui32Config))ROM_I2CTABLE[41])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define I2CRxFIFOFlush ((void (*)(uint32_t ui32Base))ROM_I2CTABLE[42])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define I2CFIFOStatus ((uint32_t(*)(uint32_t ui32Base))ROM_I2CTABLE[43])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define I2CFIFODataPut ((void (*)(uint32_t ui32Base, uint8_t ui8Data))ROM_I2CTABLE[44])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define I2CFIFODataPutNonBlocking ((uint32_t(*)(uint32_t ui32Base, uint8_t ui8Data))ROM_I2CTABLE[45])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define I2CFIFODataGet ((uint32_t(*)(uint32_t ui32Base))ROM_I2CTABLE[46])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define I2CFIFODataGetNonBlocking ((uint32_t(*)(uint32_t ui32Base, uint8_t * pui8Data)) ROM_I2CTABLE[47])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define I2CMasterBurstLengthSet ((void (*)(uint32_t ui32Base, uint8_t ui8Length))ROM_I2CTABLE[48])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define I2CMasterBurstCountGet ((uint32_t(*)(uint32_t ui32Base))ROM_I2CTABLE[49])
#endif
#if defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define I2CSlaveFIFODisable ((void (*)(uint32_t ui32Base))ROM_I2CTABLE[50])
#endif
#if defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define I2CSlaveFIFOEnable ((void (*)(uint32_t ui32Base, uint32_t ui32Config))ROM_I2CTABLE[51])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define I2CMasterGlitchFilterConfigSet ((void (*)(uint32_t ui32Base, uint32_t ui32Config))ROM_I2CTABLE[54])
#endif

//*****************************************************************************
//
// Macros for calling ROM functions in the Interrupt API.
//
//*****************************************************************************
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define IntEnable ((void (*)(uint32_t ui32Interrupt))ROM_INTERRUPTTABLE[0])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define IntMasterEnable ((bool (*)(void))ROM_INTERRUPTTABLE[1])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define IntMasterDisable ((bool (*)(void))ROM_INTERRUPTTABLE[2])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define IntDisable ((void (*)(uint32_t ui32Interrupt))ROM_INTERRUPTTABLE[3])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define IntPriorityGroupingSet ((void (*)(uint32_t ui32Bits))ROM_INTERRUPTTABLE[4])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define IntPriorityGroupingGet ((uint32_t(*)(void))ROM_INTERRUPTTABLE[5])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define IntPrioritySet ((void (*)(uint32_t ui32Interrupt, uint8_t ui8Priority))ROM_INTERRUPTTABLE[6])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define IntPriorityGet ((int32_t(*)(uint32_t ui32Interrupt))ROM_INTERRUPTTABLE[7])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define IntPendSet ((void (*)(uint32_t ui32Interrupt))ROM_INTERRUPTTABLE[8])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define IntPendClear ((void (*)(uint32_t ui32Interrupt))ROM_INTERRUPTTABLE[9])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define IntPriorityMaskSet ((void (*)(uint32_t ui32PriorityMask))ROM_INTERRUPTTABLE[10])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define IntPriorityMaskGet ((uint32_t(*)(void))ROM_INTERRUPTTABLE[11])
#endif
#if defined(TARGET_IS_TM4C123_RB1) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define IntIsEnabled ((uint32_t(*)(uint32_t ui32Interrupt))ROM_INTERRUPTTABLE[12])
#endif
#if defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define IntTrigger ((void (*)(uint32_t ui32Interrupt))ROM_INTERRUPTTABLE[13])
#endif

//*****************************************************************************
//
// Macros for calling ROM functions in the LCD API.
//
//*****************************************************************************
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define LCDIntStatus ((uint32_t(*)(uint32_t ui32Base, bool bMasked))ROM_LCDTABLE[0])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define LCDClockReset ((void (*)(uint32_t ui32Base, uint32_t ui32Clocks))ROM_LCDTABLE[1])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define LCDDMAConfigSet ((void (*)(uint32_t ui32Base, uint32_t ui32Config))ROM_LCDTABLE[2])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define LCDIDDCommandWrite ((void (*)(uint32_t ui32Base, uint32_t ui32CS, uint16_t ui16Cmd))ROM_LCDTABLE[3])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define LCDIDDConfigSet ((void (*)(uint32_t ui32Base, uint32_t ui32Config))ROM_LCDTABLE[4])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define LCDIDDDataRead ((uint16_t(*)(uint32_t ui32Base, uint32_t ui32CS))ROM_LCDTABLE[5])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define LCDIDDDataWrite ((void (*)(uint32_t ui32Base, uint32_t ui32CS, uint16_t ui16Data))ROM_LCDTABLE[6])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define LCDIDDDMADisable ((void (*)(uint32_t ui32Base))ROM_LCDTABLE[7])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define LCDIDDDMAWrite \
    ((void (*)(uint32_t ui32Base, uint32_t ui32CS, const uint32_t* pui32Data, uint32_t ui32Count))ROM_LCDTABLE[8])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define LCDIDDIndexedRead ((uint16_t(*)(uint32_t ui32Base, uint32_t ui32CS, uint16_t ui16Addr))ROM_LCDTABLE[9])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define LCDIDDIndexedWrite \
    ((void (*)(uint32_t ui32Base, uint32_t ui32CS, uint16_t ui16Addr, uint16_t ui16Data))ROM_LCDTABLE[10])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define LCDIDDStatusRead ((uint16_t(*)(uint32_t ui32Base, uint32_t ui32CS))ROM_LCDTABLE[11])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define LCDIDDTimingSet ((void (*)(uint32_t ui32Base, uint32_t ui32CS, const tLCDIDDTiming* pTiming))ROM_LCDTABLE[12])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define LCDIntClear ((void (*)(uint32_t ui32Base, uint32_t ui32IntFlags))ROM_LCDTABLE[13])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define LCDIntDisable ((void (*)(uint32_t ui32Base, uint32_t ui32IntFlags))ROM_LCDTABLE[14])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define LCDIntEnable ((void (*)(uint32_t ui32Base, uint32_t ui32IntFlags))ROM_LCDTABLE[15])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define LCDModeSet \
    ((uint32_t(*)(uint32_t ui32Base, uint8_t ui8Mode, uint32_t ui32PixClk, uint32_t ui32SysClk))ROM_LCDTABLE[16])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define LCDRasterACBiasIntCountSet ((void (*)(uint32_t ui32Base, uint8_t ui8Count))ROM_LCDTABLE[17])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define LCDRasterConfigSet ((void (*)(uint32_t ui32Base, uint32_t ui32Config, uint8_t ui8PalLoadDelay))ROM_LCDTABLE[18])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define LCDRasterDisable ((void (*)(uint32_t ui32Base))ROM_LCDTABLE[19])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define LCDRasterEnable ((void (*)(uint32_t ui32Base))ROM_LCDTABLE[20])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define LCDRasterFrameBufferSet \
    ((void (*)(uint32_t ui32Base, uint8_t ui8Buffer, uint32_t * pui32Addr, uint32_t ui32NumBytes)) ROM_LCDTABLE[21])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define LCDRasterPaletteSet                    \
    ((void (*)(uint32_t ui32Base,              \
               uint32_t ui32Type,              \
               uint32_t * pui32PalAddr,        \
               const uint32_t* pui32SrcColors, \
               uint32_t        ui32Start,      \
               uint32_t        ui32Count)) ROM_LCDTABLE[22])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define LCDRasterSubPanelConfigSet                                                                          \
    ((void (*)(uint32_t ui32Base, uint32_t ui32Flags, uint32_t ui32BottomLines, uint32_t ui32DefaultPixel)) \
         ROM_LCDTABLE[23])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define LCDRasterSubPanelDisable ((void (*)(uint32_t ui32Base))ROM_LCDTABLE[24])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define LCDRasterSubPanelEnable ((void (*)(uint32_t ui32Base))ROM_LCDTABLE[25])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define LCDRasterTimingSet ((void (*)(uint32_t ui32Base, const tLCDRasterTiming* pTiming))ROM_LCDTABLE[26])
#endif
#if defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define LCDRasterEnabled ((bool (*)(uint32_t ui32Base))ROM_LCDTABLE[27])
#endif

//*****************************************************************************
//
// Macros for calling ROM functions in the MPU API.
//
//*****************************************************************************
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define MPUEnable ((void (*)(uint32_t ui32MPUConfig))ROM_MPUTABLE[0])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define MPUDisable ((void (*)(void))ROM_MPUTABLE[1])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define MPURegionCountGet ((uint32_t(*)(void))ROM_MPUTABLE[2])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define MPURegionEnable ((void (*)(uint32_t ui32Region))ROM_MPUTABLE[3])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define MPURegionDisable ((void (*)(uint32_t ui32Region))ROM_MPUTABLE[4])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define MPURegionSet ((void (*)(uint32_t ui32Region, uint32_t ui32Addr, uint32_t ui32Flags))ROM_MPUTABLE[5])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define MPURegionGet ((void (*)(uint32_t ui32Region, uint32_t * pui32Addr, uint32_t * pui32Flags)) ROM_MPUTABLE[6])
#endif

//*****************************************************************************
//
// Macros for calling ROM functions in the OneWire API.
//
//*****************************************************************************
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define OneWireIntStatus ((uint32_t(*)(uint32_t ui32Base, bool bMasked))ROM_ONEWIRETABLE[0])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define OneWireBusReset ((void (*)(uint32_t ui32Base))ROM_ONEWIRETABLE[1])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define OneWireBusStatus ((uint32_t(*)(uint32_t ui32Base))ROM_ONEWIRETABLE[2])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define OneWireDataGet ((void (*)(uint32_t u3i2Base, uint32_t * pui32Data)) ROM_ONEWIRETABLE[3])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define OneWireDataGetNonBlocking ((bool (*)(uint32_t ui32Base, uint32_t * pui32Data)) ROM_ONEWIRETABLE[4])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define OneWireInit ((void (*)(uint32_t ui32Base, uint32_t ui32InitFlags))ROM_ONEWIRETABLE[5])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define OneWireIntClear ((void (*)(uint32_t ui32Base, uint32_t ui32IntFlags))ROM_ONEWIRETABLE[6])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define OneWireIntDisable ((void (*)(uint32_t ui32Base, uint32_t ui32IntFlags))ROM_ONEWIRETABLE[7])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define OneWireIntEnable ((void (*)(uint32_t ui32Base, uint32_t ui32IntFlags))ROM_ONEWIRETABLE[8])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define OneWireTransaction \
    ((void (*)(uint32_t ui32Base, uint32_t ui32OpFlags, uint32_t ui32Data, uint32_t ui32BitCnt))ROM_ONEWIRETABLE[9])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define OneWireDMADisable ((void (*)(uint32_t ui32Base, uint32_t ui32DMAFlags))ROM_ONEWIRETABLE[10])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define OneWireDMAEnable ((void (*)(uint32_t ui32Base, uint32_t ui32DMAFlags))ROM_ONEWIRETABLE[11])
#endif

//*****************************************************************************
//
// Macros for calling ROM functions in the PWM API.
//
//*****************************************************************************
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define PWMPulseWidthSet ((void (*)(uint32_t ui32Base, uint32_t ui32PWMOut, uint32_t ui32Width))ROM_PWMTABLE[0])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define PWMGenConfigure ((void (*)(uint32_t ui32Base, uint32_t ui32Gen, uint32_t ui32Config))ROM_PWMTABLE[1])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define PWMGenPeriodSet ((void (*)(uint32_t ui32Base, uint32_t ui32Gen, uint32_t ui32Period))ROM_PWMTABLE[2])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define PWMGenPeriodGet ((uint32_t(*)(uint32_t ui32Base, uint32_t ui32Gen))ROM_PWMTABLE[3])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define PWMGenEnable ((void (*)(uint32_t ui32Base, uint32_t ui32Gen))ROM_PWMTABLE[4])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define PWMGenDisable ((void (*)(uint32_t ui32Base, uint32_t ui32Gen))ROM_PWMTABLE[5])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define PWMPulseWidthGet ((uint32_t(*)(uint32_t ui32Base, uint32_t ui32PWMOut))ROM_PWMTABLE[6])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define PWMDeadBandEnable \
    ((void (*)(uint32_t ui32Base, uint32_t ui32Gen, uint16_t ui16Rise, uint16_t ui16Fall))ROM_PWMTABLE[7])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define PWMDeadBandDisable ((void (*)(uint32_t ui32Base, uint32_t ui32Gen))ROM_PWMTABLE[8])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define PWMSyncUpdate ((void (*)(uint32_t ui32Base, uint32_t ui32GenBits))ROM_PWMTABLE[9])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define PWMSyncTimeBase ((void (*)(uint32_t ui32Base, uint32_t ui32GenBits))ROM_PWMTABLE[10])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define PWMOutputState ((void (*)(uint32_t ui32Base, uint32_t ui32PWMOutBits, bool bEnable))ROM_PWMTABLE[11])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define PWMOutputInvert ((void (*)(uint32_t ui32Base, uint32_t ui32PWMOutBits, bool bInvert))ROM_PWMTABLE[12])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define PWMOutputFault ((void (*)(uint32_t ui32Base, uint32_t ui32PWMOutBits, bool bFaultSuppress))ROM_PWMTABLE[13])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define PWMGenIntTrigEnable ((void (*)(uint32_t ui32Base, uint32_t ui32Gen, uint32_t ui32IntTrig))ROM_PWMTABLE[14])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define PWMGenIntTrigDisable ((void (*)(uint32_t ui32Base, uint32_t ui32Gen, uint32_t ui32IntTrig))ROM_PWMTABLE[15])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define PWMGenIntStatus ((uint32_t(*)(uint32_t ui32Base, uint32_t ui32Gen, bool bMasked))ROM_PWMTABLE[16])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define PWMGenIntClear ((void (*)(uint32_t ui32Base, uint32_t ui32Gen, uint32_t ui32Ints))ROM_PWMTABLE[17])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define PWMIntEnable ((void (*)(uint32_t ui32Base, uint32_t ui32GenFault))ROM_PWMTABLE[18])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define PWMIntDisable ((void (*)(uint32_t ui32Base, uint32_t ui32GenFault))ROM_PWMTABLE[19])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define PWMFaultIntClear ((void (*)(uint32_t ui32Base))ROM_PWMTABLE[20])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define PWMIntStatus ((uint32_t(*)(uint32_t ui32Base, bool bMasked))ROM_PWMTABLE[21])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define PWMOutputFaultLevel ((void (*)(uint32_t ui32Base, uint32_t ui32PWMOutBits, bool bDriveHigh))ROM_PWMTABLE[22])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define PWMFaultIntClearExt ((void (*)(uint32_t ui32Base, uint32_t ui32FaultInts))ROM_PWMTABLE[23])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define PWMGenFaultConfigure                                                                                \
    ((void (*)(uint32_t ui32Base, uint32_t ui32Gen, uint32_t ui32MinFaultPeriod, uint32_t ui32FaultSenses)) \
         ROM_PWMTABLE[24])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define PWMGenFaultTriggerSet \
    ((void (*)(uint32_t ui32Base, uint32_t ui32Gen, uint32_t ui32Group, uint32_t ui32FaultTriggers))ROM_PWMTABLE[25])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define PWMGenFaultTriggerGet ((uint32_t(*)(uint32_t ui32Base, uint32_t ui32Gen, uint32_t ui32Group))ROM_PWMTABLE[26])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define PWMGenFaultStatus ((uint32_t(*)(uint32_t ui32Base, uint32_t ui32Gen, uint32_t ui32Group))ROM_PWMTABLE[27])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define PWMGenFaultClear \
    ((void (*)(uint32_t ui32Base, uint32_t ui32Gen, uint32_t ui32Group, uint32_t ui32FaultTriggers))ROM_PWMTABLE[28])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define PWMClockSet ((void (*)(uint32_t ui32Base, uint32_t ui32Config))ROM_PWMTABLE[29])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define PWMClockGet ((uint32_t(*)(uint32_t ui32Base))ROM_PWMTABLE[30])
#endif
#if defined(TARGET_IS_TM4C123_RB1) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define PWMOutputUpdateMode ((void (*)(uint32_t ui32Base, uint32_t ui32PWMOutBits, uint32_t ui32Mode))ROM_PWMTABLE[31])
#endif

//*****************************************************************************
//
// Macros for calling ROM functions in the QEI API.
//
//*****************************************************************************
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define QEIPositionGet ((uint32_t(*)(uint32_t ui32Base))ROM_QEITABLE[0])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define QEIEnable ((void (*)(uint32_t ui32Base))ROM_QEITABLE[1])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define QEIDisable ((void (*)(uint32_t ui32Base))ROM_QEITABLE[2])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define QEIConfigure ((void (*)(uint32_t ui32Base, uint32_t ui32Config, uint32_t ui32MaxPosition))ROM_QEITABLE[3])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define QEIPositionSet ((void (*)(uint32_t ui32Base, uint32_t ui32Position))ROM_QEITABLE[4])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define QEIDirectionGet ((int32_t(*)(uint32_t ui32Base))ROM_QEITABLE[5])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define QEIErrorGet ((bool (*)(uint32_t ui32Base))ROM_QEITABLE[6])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define QEIVelocityEnable ((void (*)(uint32_t ui32Base))ROM_QEITABLE[7])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define QEIVelocityDisable ((void (*)(uint32_t ui32Base))ROM_QEITABLE[8])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define QEIVelocityConfigure ((void (*)(uint32_t ui32Base, uint32_t ui32PreDiv, uint32_t ui32Period))ROM_QEITABLE[9])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define QEIVelocityGet ((uint32_t(*)(uint32_t ui32Base))ROM_QEITABLE[10])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define QEIIntEnable ((void (*)(uint32_t ui32Base, uint32_t ui32IntFlags))ROM_QEITABLE[11])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define QEIIntDisable ((void (*)(uint32_t ui32Base, uint32_t ui32IntFlags))ROM_QEITABLE[12])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define QEIIntStatus ((uint32_t(*)(uint32_t ui32Base, bool bMasked))ROM_QEITABLE[13])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define QEIIntClear ((void (*)(uint32_t ui32Base, uint32_t ui32IntFlags))ROM_QEITABLE[14])
#endif

//*****************************************************************************
//
// Macros for calling ROM functions in the SHAMD5 API.
//
//*****************************************************************************
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define SHAMD5IntStatus ((uint32_t(*)(uint32_t ui32Base, bool bMasked))ROM_SHAMD5TABLE[0])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define SHAMD5ConfigSet ((void (*)(uint32_t ui32Base, uint32_t ui32Mode))ROM_SHAMD5TABLE[1])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define SHAMD5DataProcess                                                                                        \
    ((void (*)(uint32_t ui32Base, uint32_t * pui32DataSrc, uint32_t ui32DataLength, uint32_t * pui32HashResult)) \
         ROM_SHAMD5TABLE[2])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define SHAMD5DataWrite ((void (*)(uint32_t ui32Base, uint32_t * pui32Src)) ROM_SHAMD5TABLE[3])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define SHAMD5DataWriteNonBlocking ((bool (*)(uint32_t ui32Base, uint32_t * pui32Src)) ROM_SHAMD5TABLE[4])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define SHAMD5DMADisable ((void (*)(uint32_t ui32Base))ROM_SHAMD5TABLE[5])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define SHAMD5DMAEnable ((void (*)(uint32_t ui32Base))ROM_SHAMD5TABLE[6])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define SHAMD5HashLengthSet ((void (*)(uint32_t ui32Base, uint32_t ui32Length))ROM_SHAMD5TABLE[7])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define SHAMD5HMACKeySet ((void (*)(uint32_t ui32Base, uint32_t * pui32Src)) ROM_SHAMD5TABLE[8])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define SHAMD5HMACPPKeyGenerate \
    ((void (*)(uint32_t ui32Base, uint32_t * pui32Key, uint32_t * pui32PPKey)) ROM_SHAMD5TABLE[9])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define SHAMD5HMACPPKeySet ((void (*)(uint32_t ui32Base, uint32_t * pui32Src)) ROM_SHAMD5TABLE[10])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define SHAMD5HMACProcess                                                                                        \
    ((void (*)(uint32_t ui32Base, uint32_t * pui32DataSrc, uint32_t ui32DataLength, uint32_t * pui32HashResult)) \
         ROM_SHAMD5TABLE[11])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define SHAMD5IntClear ((void (*)(uint32_t ui32Base, uint32_t ui32IntFlags))ROM_SHAMD5TABLE[12])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define SHAMD5IntDisable ((void (*)(uint32_t ui32Base, uint32_t ui32IntFlags))ROM_SHAMD5TABLE[13])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define SHAMD5IntEnable ((void (*)(uint32_t ui32Base, uint32_t ui32IntFlags))ROM_SHAMD5TABLE[14])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define SHAMD5Reset ((void (*)(uint32_t ui32Base))ROM_SHAMD5TABLE[15])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define SHAMD5ResultRead ((void (*)(uint32_t ui32Base, uint32_t * pui32Dest)) ROM_SHAMD5TABLE[16])
#endif

//*****************************************************************************
//
// Macros for calling ROM functions in the SMBus API.
//
//*****************************************************************************
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define SMBusMasterIntProcess ((tSMBusStatus(*)(tSMBus * psSMBus)) ROM_SMBUSTABLE[0])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define SMBusARPDisable ((void (*)(tSMBus * psSMBus)) ROM_SMBUSTABLE[1])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define SMBusARPEnable ((void (*)(tSMBus * psSMBus)) ROM_SMBUSTABLE[2])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define SMBusARPUDIDPacketDecode \
    ((void (*)(tSMBusUDID * pUDID, uint8_t * pui8Address, uint8_t * pui8Data)) ROM_SMBUSTABLE[3])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define SMBusARPUDIDPacketEncode \
    ((void (*)(tSMBusUDID * pUDID, uint8_t ui8Address, uint8_t * pui8Data)) ROM_SMBUSTABLE[4])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define SMBusMasterARPAssignAddress ((tSMBusStatus(*)(tSMBus * psSMBus, uint8_t * pui8Data)) ROM_SMBUSTABLE[5])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define SMBusMasterARPGetUDIDDir \
    ((tSMBusStatus(*)(tSMBus * psSMBus, uint8_t ui8TargetAddress, uint8_t * pui8Data)) ROM_SMBUSTABLE[6])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define SMBusMasterARPGetUDIDGen ((tSMBusStatus(*)(tSMBus * psSMBus, uint8_t * pui8Data)) ROM_SMBUSTABLE[7])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define SMBusMasterARPNotifyMaster ((tSMBusStatus(*)(tSMBus * psSMBus, uint8_t * pui8Data)) ROM_SMBUSTABLE[8])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define SMBusMasterARPPrepareToARP ((tSMBusStatus(*)(tSMBus * psSMBus)) ROM_SMBUSTABLE[9])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define SMBusMasterARPResetDeviceDir ((tSMBusStatus(*)(tSMBus * psSMBus, uint8_t ui8TargetAddress)) ROM_SMBUSTABLE[10])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define SMBusMasterARPResetDeviceGen ((tSMBusStatus(*)(tSMBus * psSMBus)) ROM_SMBUSTABLE[11])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define SMBusMasterBlockProcessCall             \
    ((tSMBusStatus(*)(tSMBus * psSMBus,         \
                      uint8_t ui8TargetAddress, \
                      uint8_t ui8Command,       \
                      uint8_t * pui8TxData,     \
                      uint8_t ui8TxSize,        \
                      uint8_t * pui8RxData)) ROM_SMBUSTABLE[12])
#endif
#if defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || defined(TARGET_IS_TM4C123_RB2) || \
    defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define SMBusMasterBlockRead                                                                               \
    ((tSMBusStatus(*)(tSMBus * psSMBus, uint8_t ui8TargetAddress, uint8_t ui8Command, uint8_t * pui8Data)) \
         ROM_SMBUSTABLE[13])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define SMBusMasterBlockWrite                   \
    ((tSMBusStatus(*)(tSMBus * psSMBus,         \
                      uint8_t ui8TargetAddress, \
                      uint8_t ui8Command,       \
                      uint8_t * pui8Data,       \
                      uint8_t ui8Size)) ROM_SMBUSTABLE[14])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define SMBusMasterByteReceive \
    ((tSMBusStatus(*)(tSMBus * psSMBus, uint8_t ui8TargetAddress, uint8_t * pui8Data)) ROM_SMBUSTABLE[15])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define SMBusMasterByteSend \
    ((tSMBusStatus(*)(tSMBus * psSMBus, uint8_t ui8TargetAddress, uint8_t ui8Data)) ROM_SMBUSTABLE[16])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define SMBusMasterByteWordRead                 \
    ((tSMBusStatus(*)(tSMBus * psSMBus,         \
                      uint8_t ui8TargetAddress, \
                      uint8_t ui8Command,       \
                      uint8_t * pui8Data,       \
                      uint8_t ui8Size)) ROM_SMBUSTABLE[17])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define SMBusMasterByteWordWrite                \
    ((tSMBusStatus(*)(tSMBus * psSMBus,         \
                      uint8_t ui8TargetAddress, \
                      uint8_t ui8Command,       \
                      uint8_t * pui8Data,       \
                      uint8_t ui8Size)) ROM_SMBUSTABLE[18])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define SMBusMasterHostNotify \
    ((tSMBusStatus(*)(tSMBus * psSMBus, uint8_t ui8OwnSlaveAddress, uint8_t * pui8Data)) ROM_SMBUSTABLE[19])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define SMBusMasterI2CRead                                                                              \
    ((tSMBusStatus(*)(tSMBus * psSMBus, uint8_t ui8TargetAddress, uint8_t * pui8Data, uint8_t ui8Size)) \
         ROM_SMBUSTABLE[20])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define SMBusMasterI2CWrite                                                                             \
    ((tSMBusStatus(*)(tSMBus * psSMBus, uint8_t ui8TargetAddress, uint8_t * pui8Data, uint8_t ui8Size)) \
         ROM_SMBUSTABLE[21])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define SMBusMasterI2CWriteRead                 \
    ((tSMBusStatus(*)(tSMBus * psSMBus,         \
                      uint8_t ui8TargetAddress, \
                      uint8_t * pui8TxData,     \
                      uint8_t ui8TxSize,        \
                      uint8_t * pui8RxData,     \
                      uint8_t ui8RxSize)) ROM_SMBUSTABLE[22])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define SMBusMasterInit ((void (*)(tSMBus * psSMBus, uint32_t ui32I2CBase, uint32_t ui32SMBusClock)) ROM_SMBUSTABLE[23])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define SMBusMasterIntEnable ((void (*)(tSMBus * psSMBus)) ROM_SMBUSTABLE[24])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define SMBusMasterProcessCall                  \
    ((tSMBusStatus(*)(tSMBus * psSMBus,         \
                      uint8_t ui8TargetAddress, \
                      uint8_t ui8Command,       \
                      uint8_t * pui8TxData,     \
                      uint8_t * pui8RxData)) ROM_SMBUSTABLE[25])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define SMBusMasterQuickCommand \
    ((tSMBusStatus(*)(tSMBus * psSMBus, uint8_t ui8TargetAddress, bool bData)) ROM_SMBUSTABLE[26])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define SMBusPECDisable ((void (*)(tSMBus * psSMBus)) ROM_SMBUSTABLE[27])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define SMBusPECEnable ((void (*)(tSMBus * psSMBus)) ROM_SMBUSTABLE[28])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define SMBusRxPacketSizeGet ((uint8_t(*)(tSMBus * psSMBus)) ROM_SMBUSTABLE[29])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define SMBusSlaveACKSend ((void (*)(tSMBus * psSMBus, bool bACK)) ROM_SMBUSTABLE[30])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define SMBusSlaveAddressSet \
    ((void (*)(tSMBus * psSMBus, uint8_t ui8AddressNum, uint8_t ui8SlaveAddress)) ROM_SMBUSTABLE[31])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define SMBusSlaveARPFlagARGet ((bool (*)(tSMBus * psSMBus)) ROM_SMBUSTABLE[32])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define SMBusSlaveARPFlagARSet ((void (*)(tSMBus * psSMBus, bool bValue)) ROM_SMBUSTABLE[33])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define SMBusSlaveARPFlagAVGet ((bool (*)(tSMBus * psSMBus)) ROM_SMBUSTABLE[34])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define SMBusSlaveARPFlagAVSet ((void (*)(tSMBus * psSMBus, bool bValue)) ROM_SMBUSTABLE[35])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define SMBusSlaveBlockTransferDisable ((void (*)(tSMBus * psSMBus)) ROM_SMBUSTABLE[36])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define SMBusSlaveBlockTransferEnable ((void (*)(tSMBus * psSMBus)) ROM_SMBUSTABLE[37])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define SMBusSlaveCommandGet ((uint8_t(*)(tSMBus * psSMBus)) ROM_SMBUSTABLE[38])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define SMBusSlaveI2CDisable ((void (*)(tSMBus * psSMBus)) ROM_SMBUSTABLE[39])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define SMBusSlaveI2CEnable ((void (*)(tSMBus * psSMBus)) ROM_SMBUSTABLE[40])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define SMBusSlaveInit ((void (*)(tSMBus * psSMBus, uint32_t ui32I2CBase)) ROM_SMBUSTABLE[41])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define SMBusSlaveIntAddressGet ((tSMBusStatus(*)(tSMBus * psSMBus)) ROM_SMBUSTABLE[42])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define SMBusSlaveIntEnable ((void (*)(tSMBus * psSMBus)) ROM_SMBUSTABLE[43])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define SMBusSlaveIntProcess ((tSMBusStatus(*)(tSMBus * psSMBus)) ROM_SMBUSTABLE[44])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define SMBusSlaveManualACKDisable ((void (*)(tSMBus * psSMBus)) ROM_SMBUSTABLE[45])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define SMBusSlaveManualACKEnable ((void (*)(tSMBus * psSMBus)) ROM_SMBUSTABLE[46])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define SMBusSlaveManualACKStatusGet ((bool (*)(tSMBus * psSMBus)) ROM_SMBUSTABLE[47])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define SMBusSlaveProcessCallDisable ((void (*)(tSMBus * psSMBus)) ROM_SMBUSTABLE[48])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define SMBusSlaveProcessCallEnable ((void (*)(tSMBus * psSMBus)) ROM_SMBUSTABLE[49])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define SMBusSlaveRxBufferSet ((void (*)(tSMBus * psSMBus, uint8_t * pui8Data, uint8_t ui8Size)) ROM_SMBUSTABLE[50])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define SMBusSlaveTransferInit ((void (*)(tSMBus * psSMBus)) ROM_SMBUSTABLE[51])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define SMBusSlaveTxBufferSet ((void (*)(tSMBus * psSMBus, uint8_t * pui8Data, uint8_t ui8Size)) ROM_SMBUSTABLE[52])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define SMBusSlaveUDIDSet ((void (*)(tSMBus * psSMBus, tSMBusUDID * pUDID)) ROM_SMBUSTABLE[53])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define SMBusStatusGet ((tSMBusStatus(*)(tSMBus * psSMBus)) ROM_SMBUSTABLE[54])
#endif
#if defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || defined(TARGET_IS_TM4C123_RB2) || \
    defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define SMBusSlaveDataSend ((tSMBusStatus(*)(tSMBus * psSMBus)) ROM_SMBUSTABLE[55])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define SMBusFIFOEnable ((void (*)(tSMBus * psSMBus)) ROM_SMBUSTABLE[56])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define SMBusFIFODisable ((void (*)(tSMBus * psSMBus)) ROM_SMBUSTABLE[57])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define SMBusDMAEnable ((void (*)(tSMBus * psSMBus, uint8_t ui8TxChannel, uint8_t ui8RxChannel)) ROM_SMBUSTABLE[58])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define SMBusDMADisable ((void (*)(tSMBus * psSMBus)) ROM_SMBUSTABLE[59])
#endif

//*****************************************************************************
//
// Macros for calling ROM functions in the SPIFlash API.
//
//*****************************************************************************
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define SPIFlashIntHandler ((uint32_t(*)(tSPIFlashState * pState)) ROM_SPIFLASHTABLE[0])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define SPIFlashInit ((void (*)(uint32_t ui32Base, uint32_t ui32Clock, uint32_t ui32BitRate))ROM_SPIFLASHTABLE[1])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define SPIFlashWriteStatus ((void (*)(uint32_t ui32Base, uint8_t ui8Status))ROM_SPIFLASHTABLE[2])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define SPIFlashPageProgram \
    ((void (*)(uint32_t ui32Base, uint32_t ui32Addr, const uint8_t* pui8Data, uint32_t ui32Count))ROM_SPIFLASHTABLE[3])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define SPIFlashPageProgramNonBlocking   \
    ((void (*)(tSPIFlashState * pState,  \
               uint32_t       ui32Base,  \
               uint32_t       ui32Addr,  \
               const uint8_t* pui8Data,  \
               uint32_t       ui32Count, \
               bool           bUseDMA,   \
               uint32_t       ui32TxChannel)) ROM_SPIFLASHTABLE[4])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define SPIFlashRead \
    ((void (*)(uint32_t ui32Base, uint32_t ui32Addr, uint8_t * pui8Data, uint32_t ui32Count)) ROM_SPIFLASHTABLE[5])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define SPIFlashReadNonBlocking         \
    ((void (*)(tSPIFlashState * pState, \
               uint32_t ui32Base,       \
               uint32_t ui32Addr,       \
               uint8_t * pui8Data,      \
               uint32_t ui32Count,      \
               bool     bUseDMA,        \
               uint32_t ui32TxChannel,  \
               uint32_t ui32RxChannel)) ROM_SPIFLASHTABLE[6])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define SPIFlashWriteDisable ((void (*)(uint32_t ui32Base))ROM_SPIFLASHTABLE[7])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define SPIFlashReadStatus ((uint8_t(*)(uint32_t ui32Base))ROM_SPIFLASHTABLE[8])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define SPIFlashWriteEnable ((void (*)(uint32_t ui32Base))ROM_SPIFLASHTABLE[9])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define SPIFlashFastRead \
    ((void (*)(uint32_t ui32Base, uint32_t ui32Addr, uint8_t * pui8Data, uint32_t ui32Count)) ROM_SPIFLASHTABLE[10])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define SPIFlashFastReadNonBlocking     \
    ((void (*)(tSPIFlashState * pState, \
               uint32_t ui32Base,       \
               uint32_t ui32Addr,       \
               uint8_t * pui8Data,      \
               uint32_t ui32Count,      \
               bool     bUseDMA,        \
               uint32_t ui32TxChannel,  \
               uint32_t ui32RxChannel)) ROM_SPIFLASHTABLE[11])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define SPIFlashSectorErase ((void (*)(uint32_t ui32Base, uint32_t ui32Addr))ROM_SPIFLASHTABLE[12])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define SPIFlashDualRead \
    ((void (*)(uint32_t ui32Base, uint32_t ui32Addr, uint8_t * pui8Data, uint32_t ui32Count)) ROM_SPIFLASHTABLE[13])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define SPIFlashDualReadNonBlocking     \
    ((void (*)(tSPIFlashState * pState, \
               uint32_t ui32Base,       \
               uint32_t ui32Addr,       \
               uint8_t * pui8Data,      \
               uint32_t ui32Count,      \
               bool     bUseDMA,        \
               uint32_t ui32TxChannel,  \
               uint32_t ui32RxChannel)) ROM_SPIFLASHTABLE[14])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define SPIFlashBlockErase32 ((void (*)(uint32_t ui32Base, uint32_t ui32Addr))ROM_SPIFLASHTABLE[15])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define SPIFlashQuadRead \
    ((void (*)(uint32_t ui32Base, uint32_t ui32Addr, uint8_t * pui8Data, uint32_t ui32Count)) ROM_SPIFLASHTABLE[16])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define SPIFlashQuadReadNonBlocking     \
    ((void (*)(tSPIFlashState * pState, \
               uint32_t ui32Base,       \
               uint32_t ui32Addr,       \
               uint8_t * pui8Data,      \
               uint32_t ui32Count,      \
               bool     bUseDMA,        \
               uint32_t ui32TxChannel,  \
               uint32_t ui32RxChannel)) ROM_SPIFLASHTABLE[17])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define SPIFlashReadID \
    ((void (*)(uint32_t ui32Base, uint8_t * pui8ManufacturerID, uint16_t * pui16DeviceID)) ROM_SPIFLASHTABLE[18])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define SPIFlashChipErase ((void (*)(uint32_t ui32Base))ROM_SPIFLASHTABLE[19])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define SPIFlashBlockErase64 ((void (*)(uint32_t ui32Base, uint32_t ui32Addr))ROM_SPIFLASHTABLE[20])
#endif

//*****************************************************************************
//
// Macros for calling ROM functions in the SSI API.
//
//*****************************************************************************
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define SSIDataPut ((void (*)(uint32_t ui32Base, uint32_t ui32Data))ROM_SSITABLE[0])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define SSIConfigSetExpClk            \
    ((void (*)(uint32_t ui32Base,     \
               uint32_t ui32SSIClk,   \
               uint32_t ui32Protocol, \
               uint32_t ui32Mode,     \
               uint32_t ui32BitRate,  \
               uint32_t ui32DataWidth))ROM_SSITABLE[1])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define SSIEnable ((void (*)(uint32_t ui32Base))ROM_SSITABLE[2])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define SSIDisable ((void (*)(uint32_t ui32Base))ROM_SSITABLE[3])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define SSIIntEnable ((void (*)(uint32_t ui32Base, uint32_t ui32IntFlags))ROM_SSITABLE[4])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define SSIIntDisable ((void (*)(uint32_t ui32Base, uint32_t ui32IntFlags))ROM_SSITABLE[5])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define SSIIntStatus ((uint32_t(*)(uint32_t ui32Base, bool bMasked))ROM_SSITABLE[6])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define SSIIntClear ((void (*)(uint32_t ui32Base, uint32_t ui32IntFlags))ROM_SSITABLE[7])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define SSIDataPutNonBlocking ((int32_t(*)(uint32_t ui32Base, uint32_t ui32Data))ROM_SSITABLE[8])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define SSIDataGet ((void (*)(uint32_t ui32Base, uint32_t * pui32Data)) ROM_SSITABLE[9])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define SSIDataGetNonBlocking ((int32_t(*)(uint32_t ui32Base, uint32_t * pui32Data)) ROM_SSITABLE[10])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define UpdateSSI ((void (*)(void))ROM_SSITABLE[11])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define SSIDMAEnable ((void (*)(uint32_t ui32Base, uint32_t ui32DMAFlags))ROM_SSITABLE[12])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define SSIDMADisable ((void (*)(uint32_t ui32Base, uint32_t ui32DMAFlags))ROM_SSITABLE[13])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define SSIBusy ((bool (*)(uint32_t ui32Base))ROM_SSITABLE[14])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define SSIClockSourceGet ((uint32_t(*)(uint32_t ui32Base))ROM_SSITABLE[15])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define SSIClockSourceSet ((void (*)(uint32_t ui32Base, uint32_t ui32Source))ROM_SSITABLE[16])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define SSIAdvModeSet ((void (*)(uint32_t ui32Base, uint32_t ui32Mode))ROM_SSITABLE[17])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define SSIAdvDataPutFrameEnd ((void (*)(uint32_t ui32Base, uint32_t ui32Data))ROM_SSITABLE[18])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define SSIAdvDataPutFrameEndNonBlocking ((int32_t(*)(uint32_t ui32Base, uint32_t ui32Data))ROM_SSITABLE[19])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define SSIAdvFrameHoldEnable ((void (*)(uint32_t ui32Base))ROM_SSITABLE[20])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define SSIAdvFrameHoldDisable ((void (*)(uint32_t ui32Base))ROM_SSITABLE[21])
#endif

//*****************************************************************************
//
// Macros for calling ROM functions in the SysCtl API.
//
//*****************************************************************************
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define SysCtlSleep ((void (*)(void))ROM_SYSCTLTABLE[0])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define SysCtlSRAMSizeGet ((uint32_t(*)(void))ROM_SYSCTLTABLE[1])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define SysCtlFlashSizeGet ((uint32_t(*)(void))ROM_SYSCTLTABLE[2])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define SysCtlPeripheralPresent ((bool (*)(uint32_t ui32Peripheral))ROM_SYSCTLTABLE[4])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define SysCtlPeripheralReset ((void (*)(uint32_t ui32Peripheral))ROM_SYSCTLTABLE[5])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define SysCtlPeripheralEnable ((void (*)(uint32_t ui32Peripheral))ROM_SYSCTLTABLE[6])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define SysCtlPeripheralDisable ((void (*)(uint32_t ui32Peripheral))ROM_SYSCTLTABLE[7])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define SysCtlPeripheralSleepEnable ((void (*)(uint32_t ui32Peripheral))ROM_SYSCTLTABLE[8])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define SysCtlPeripheralSleepDisable ((void (*)(uint32_t ui32Peripheral))ROM_SYSCTLTABLE[9])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define SysCtlPeripheralDeepSleepEnable ((void (*)(uint32_t ui32Peripheral))ROM_SYSCTLTABLE[10])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define SysCtlPeripheralDeepSleepDisable ((void (*)(uint32_t ui32Peripheral))ROM_SYSCTLTABLE[11])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define SysCtlPeripheralClockGating ((void (*)(bool bEnable))ROM_SYSCTLTABLE[12])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define SysCtlIntEnable ((void (*)(uint32_t ui32Ints))ROM_SYSCTLTABLE[13])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define SysCtlIntDisable ((void (*)(uint32_t ui32Ints))ROM_SYSCTLTABLE[14])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define SysCtlIntClear ((void (*)(uint32_t ui32Ints))ROM_SYSCTLTABLE[15])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define SysCtlIntStatus ((uint32_t(*)(bool bMasked))ROM_SYSCTLTABLE[16])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define SysCtlReset ((void (*)(void))ROM_SYSCTLTABLE[19])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define SysCtlDeepSleep ((void (*)(void))ROM_SYSCTLTABLE[20])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define SysCtlResetCauseGet ((uint32_t(*)(void))ROM_SYSCTLTABLE[21])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define SysCtlResetCauseClear ((void (*)(uint32_t ui32Causes))ROM_SYSCTLTABLE[22])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2)
#define SysCtlClockSet ((void (*)(uint32_t ui32Config))ROM_SYSCTLTABLE[23])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2)
#define SysCtlClockGet ((uint32_t(*)(void))ROM_SYSCTLTABLE[24])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2)
#define SysCtlPWMClockSet ((void (*)(uint32_t ui32Config))ROM_SYSCTLTABLE[25])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2)
#define SysCtlPWMClockGet ((uint32_t(*)(void))ROM_SYSCTLTABLE[26])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2)
#define SysCtlUSBPLLEnable ((void (*)(void))ROM_SYSCTLTABLE[31])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2)
#define SysCtlUSBPLLDisable ((void (*)(void))ROM_SYSCTLTABLE[32])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define SysCtlDelay ((void (*)(uint32_t ui32Count))ROM_SYSCTLTABLE[34])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define SysCtlPeripheralReady ((bool (*)(uint32_t ui32Peripheral))ROM_SYSCTLTABLE[35])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define SysCtlPeripheralPowerOn ((void (*)(uint32_t ui32Peripheral))ROM_SYSCTLTABLE[36])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define SysCtlPeripheralPowerOff ((void (*)(uint32_t ui32Peripheral))ROM_SYSCTLTABLE[37])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define SysCtlMOSCConfigSet ((void (*)(uint32_t ui32Config))ROM_SYSCTLTABLE[44])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define SysCtlPIOSCCalibrate ((uint32_t(*)(uint32_t ui32Type))ROM_SYSCTLTABLE[45])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2)
#define SysCtlDeepSleepClockSet ((void (*)(uint32_t ui32Config))ROM_SYSCTLTABLE[46])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define SysCtlDeepSleepClockConfigSet ((void (*)(uint32_t ui32Div, uint32_t ui32Config))ROM_SYSCTLTABLE[47])
#endif

/**
 * Errata MEM#09
 *
 * Description: The ROM_SysCtlClockFreqSet() function does not properly configure the MOSC.
 * Due to this erratum, any ROM functions that rely on the proper operation of the MOSC,
 * such as the Ethernet boot loader, will not function correctly.
 *
 * Workaround(s): Use the TivaWare function of SysCtlClockFreqSet() in Flash memory.
 */

#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define SysCtlResetBehaviorSet ((void (*)(uint32_t ui32Behavior))ROM_SYSCTLTABLE[51])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define SysCtlResetBehaviorGet ((uint32_t(*)(void))ROM_SYSCTLTABLE[52])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define SysCtlFlashSectorSizeGet ((uint32_t(*)(void))ROM_SYSCTLTABLE[54])
#endif
#if defined(TARGET_IS_TM4C123_RB1) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define SysCtlVoltageEventConfig ((void (*)(uint32_t ui32Config))ROM_SYSCTLTABLE[55])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define SysCtlVoltageEventStatus ((uint32_t(*)(void))ROM_SYSCTLTABLE[56])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define SysCtlVoltageEventClear ((void (*)(uint32_t ui32Status))ROM_SYSCTLTABLE[57])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define SysCtlNMIStatus ((uint32_t(*)(void))ROM_SYSCTLTABLE[58])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define SysCtlNMIClear ((void (*)(uint32_t ui32Status))ROM_SYSCTLTABLE[59])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define SysCtlClockOutConfig ((void (*)(uint32_t ui32Config, uint32_t ui32Div))ROM_SYSCTLTABLE[60])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define SysCtlAltClkConfig ((void (*)(uint32_t ui32Config))ROM_SYSCTLTABLE[61])
#endif

//*****************************************************************************
//
// Macros for calling ROM functions in the SysExc API.
//
//*****************************************************************************
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define SysExcIntStatus ((uint32_t(*)(bool bMasked))ROM_SYSEXCTABLE[0])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define SysExcIntClear ((void (*)(uint32_t ui32IntFlags))ROM_SYSEXCTABLE[1])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define SysExcIntDisable ((void (*)(uint32_t ui32IntFlags))ROM_SYSEXCTABLE[2])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define SysExcIntEnable ((void (*)(uint32_t ui32IntFlags))ROM_SYSEXCTABLE[3])
#endif

//*****************************************************************************
//
// Macros for calling ROM functions in the SysTick API.
//
//*****************************************************************************
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define SysTickValueGet ((uint32_t(*)(void))ROM_SYSTICKTABLE[0])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define SysTickEnable ((void (*)(void))ROM_SYSTICKTABLE[1])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define SysTickDisable ((void (*)(void))ROM_SYSTICKTABLE[2])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define SysTickIntEnable ((void (*)(void))ROM_SYSTICKTABLE[3])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define SysTickIntDisable ((void (*)(void))ROM_SYSTICKTABLE[4])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define SysTickPeriodSet ((void (*)(uint32_t ui32Period))ROM_SYSTICKTABLE[5])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define SysTickPeriodGet ((uint32_t(*)(void))ROM_SYSTICKTABLE[6])
#endif

//*****************************************************************************
//
// Macros for calling ROM functions in the Timer API.
//
//*****************************************************************************
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define TimerIntClear ((void (*)(uint32_t ui32Base, uint32_t ui32IntFlags))ROM_TIMERTABLE[0])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define TimerEnable ((void (*)(uint32_t ui32Base, uint32_t ui32Timer))ROM_TIMERTABLE[1])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define TimerDisable ((void (*)(uint32_t ui32Base, uint32_t ui32Timer))ROM_TIMERTABLE[2])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define TimerConfigure ((void (*)(uint32_t ui32Base, uint32_t ui32Config))ROM_TIMERTABLE[3])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define TimerControlLevel ((void (*)(uint32_t ui32Base, uint32_t ui32Timer, bool bInvert))ROM_TIMERTABLE[4])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA1)
#define TimerControlTrigger ((void (*)(uint32_t ui32Base, uint32_t ui32Timer, bool bEnable))ROM_TIMERTABLE[5])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define TimerControlEvent ((void (*)(uint32_t ui32Base, uint32_t ui32Timer, uint32_t ui32Event))ROM_TIMERTABLE[6])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define TimerControlStall ((void (*)(uint32_t ui32Base, uint32_t ui32Timer, bool bStall))ROM_TIMERTABLE[7])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define TimerRTCEnable ((void (*)(uint32_t ui32Base))ROM_TIMERTABLE[8])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define TimerRTCDisable ((void (*)(uint32_t ui32Base))ROM_TIMERTABLE[9])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define TimerPrescaleSet ((void (*)(uint32_t ui32Base, uint32_t ui32Timer, uint32_t ui32Value))ROM_TIMERTABLE[10])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define TimerPrescaleGet ((uint32_t(*)(uint32_t ui32Base, uint32_t ui32Timer))ROM_TIMERTABLE[11])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define TimerPrescaleMatchSet ((void (*)(uint32_t ui32Base, uint32_t ui32Timer, uint32_t ui32Value))ROM_TIMERTABLE[12])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define TimerPrescaleMatchGet ((uint32_t(*)(uint32_t ui32Base, uint32_t ui32Timer))ROM_TIMERTABLE[13])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define TimerLoadSet ((void (*)(uint32_t ui32Base, uint32_t ui32Timer, uint32_t ui32Value))ROM_TIMERTABLE[14])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define TimerLoadGet ((uint32_t(*)(uint32_t ui32Base, uint32_t ui32Timer))ROM_TIMERTABLE[15])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define TimerValueGet ((uint32_t(*)(uint32_t ui32Base, uint32_t ui32Timer))ROM_TIMERTABLE[16])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define TimerMatchSet ((void (*)(uint32_t ui32Base, uint32_t ui32Timer, uint32_t ui32Value))ROM_TIMERTABLE[17])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define TimerMatchGet ((uint32_t(*)(uint32_t ui32Base, uint32_t ui32Timer))ROM_TIMERTABLE[18])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define TimerIntEnable ((void (*)(uint32_t ui32Base, uint32_t ui32IntFlags))ROM_TIMERTABLE[19])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define TimerIntDisable ((void (*)(uint32_t ui32Base, uint32_t ui32IntFlags))ROM_TIMERTABLE[20])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define TimerIntStatus ((uint32_t(*)(uint32_t ui32Base, bool bMasked))ROM_TIMERTABLE[21])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define TimerControlWaitOnTrigger ((void (*)(uint32_t ui32Base, uint32_t ui32Timer, bool bWait))ROM_TIMERTABLE[22])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2)
#define TimerLoadSet64 ((void (*)(uint32_t ui32Base, uint64_t ui64Value))ROM_TIMERTABLE[23])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2)
#define TimerLoadGet64 ((uint64_t(*)(uint32_t ui32Base))ROM_TIMERTABLE[24])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2)
#define TimerValueGet64 ((uint64_t(*)(uint32_t ui32Base))ROM_TIMERTABLE[25])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2)
#define TimerMatchSet64 ((void (*)(uint32_t ui32Base, uint64_t ui64Value))ROM_TIMERTABLE[26])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2)
#define TimerMatchGet64 ((uint64_t(*)(uint32_t ui32Base))ROM_TIMERTABLE[27])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define TimerClockSourceGet ((uint32_t(*)(uint32_t ui32Base))ROM_TIMERTABLE[28])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define TimerClockSourceSet ((void (*)(uint32_t ui32Base, uint32_t ui32Source))ROM_TIMERTABLE[29])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define TimerADCEventGet ((uint32_t(*)(uint32_t ui32Base))ROM_TIMERTABLE[30])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define TimerADCEventSet ((void (*)(uint32_t ui32Base, uint32_t ui32ADCEvent))ROM_TIMERTABLE[31])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define TimerDMAEventGet ((uint32_t(*)(uint32_t ui32Base))ROM_TIMERTABLE[32])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define TimerDMAEventSet ((void (*)(uint32_t ui32Base, uint32_t ui32DMAEvent))ROM_TIMERTABLE[33])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define TimerSynchronize ((void (*)(uint32_t ui32Base, uint32_t ui32Timers))ROM_TIMERTABLE[34])
#endif

//*****************************************************************************
//
// Macros for calling ROM functions in the UART API.
//
//*****************************************************************************
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define UARTCharPut ((void (*)(uint32_t ui32Base, unsigned char ucData))ROM_UARTTABLE[0])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define UARTParityModeSet ((void (*)(uint32_t ui32Base, uint32_t ui32Parity))ROM_UARTTABLE[1])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define UARTParityModeGet ((uint32_t(*)(uint32_t ui32Base))ROM_UARTTABLE[2])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define UARTFIFOLevelSet ((void (*)(uint32_t ui32Base, uint32_t ui32TxLevel, uint32_t ui32RxLevel))ROM_UARTTABLE[3])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define UARTFIFOLevelGet \
    ((void (*)(uint32_t ui32Base, uint32_t * pui32TxLevel, uint32_t * pui32RxLevel)) ROM_UARTTABLE[4])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define UARTConfigSetExpClk \
    ((void (*)(uint32_t ui32Base, uint32_t ui32UARTClk, uint32_t ui32Baud, uint32_t ui32Config))ROM_UARTTABLE[5])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define UARTConfigGetExpClk \
    ((void (*)(uint32_t ui32Base, uint32_t ui32UARTClk, uint32_t * pui32Baud, uint32_t * pui32Config)) ROM_UARTTABLE[6])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define UARTEnable ((void (*)(uint32_t ui32Base))ROM_UARTTABLE[7])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define UARTDisable ((void (*)(uint32_t ui32Base))ROM_UARTTABLE[8])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define UARTEnableSIR ((void (*)(uint32_t ui32Base, bool bLowPower))ROM_UARTTABLE[9])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define UARTDisableSIR ((void (*)(uint32_t ui32Base))ROM_UARTTABLE[10])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define UARTCharsAvail ((bool (*)(uint32_t ui32Base))ROM_UARTTABLE[11])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define UARTSpaceAvail ((bool (*)(uint32_t ui32Base))ROM_UARTTABLE[12])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define UARTCharGetNonBlocking ((int32_t(*)(uint32_t ui32Base))ROM_UARTTABLE[13])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define UARTCharGet ((int32_t(*)(uint32_t ui32Base))ROM_UARTTABLE[14])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define UARTCharPutNonBlocking ((bool (*)(uint32_t ui32Base, unsigned char ucData))ROM_UARTTABLE[15])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define UARTBreakCtl ((void (*)(uint32_t ui32Base, bool bBreakState))ROM_UARTTABLE[16])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define UARTIntEnable ((void (*)(uint32_t ui32Base, uint32_t ui32IntFlags))ROM_UARTTABLE[17])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define UARTIntDisable ((void (*)(uint32_t ui32Base, uint32_t ui32IntFlags))ROM_UARTTABLE[18])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define UARTIntStatus ((uint32_t(*)(uint32_t ui32Base, bool bMasked))ROM_UARTTABLE[19])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define UARTIntClear ((void (*)(uint32_t ui32Base, uint32_t ui32IntFlags))ROM_UARTTABLE[20])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define UpdateUART ((void (*)(void))ROM_UARTTABLE[21])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define UARTDMAEnable ((void (*)(uint32_t ui32Base, uint32_t ui32DMAFlags))ROM_UARTTABLE[22])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define UARTDMADisable ((void (*)(uint32_t ui32Base, uint32_t ui32DMAFlags))ROM_UARTTABLE[23])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define UARTFIFOEnable ((void (*)(uint32_t ui32Base))ROM_UARTTABLE[24])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define UARTFIFODisable ((void (*)(uint32_t ui32Base))ROM_UARTTABLE[25])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define UARTBusy ((bool (*)(uint32_t ui32Base))ROM_UARTTABLE[26])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define UARTTxIntModeSet ((void (*)(uint32_t ui32Base, uint32_t ui32Mode))ROM_UARTTABLE[27])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define UARTTxIntModeGet ((uint32_t(*)(uint32_t ui32Base))ROM_UARTTABLE[28])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define UARTRxErrorGet ((uint32_t(*)(uint32_t ui32Base))ROM_UARTTABLE[29])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define UARTRxErrorClear ((void (*)(uint32_t ui32Base))ROM_UARTTABLE[30])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define UARTClockSourceSet ((void (*)(uint32_t ui32Base, uint32_t ui32Source))ROM_UARTTABLE[31])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define UARTClockSourceGet ((uint32_t(*)(uint32_t ui32Base))ROM_UARTTABLE[32])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define UART9BitEnable ((void (*)(uint32_t ui32Base))ROM_UARTTABLE[33])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define UART9BitDisable ((void (*)(uint32_t ui32Base))ROM_UARTTABLE[34])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define UART9BitAddrSet ((void (*)(uint32_t ui32Base, uint8_t ui8Addr, uint8_t ui8Mask))ROM_UARTTABLE[35])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define UART9BitAddrSend ((void (*)(uint32_t ui32Base, uint8_t ui8Addr))ROM_UARTTABLE[36])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define UARTSmartCardDisable ((void (*)(uint32_t ui32Base))ROM_UARTTABLE[37])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define UARTSmartCardEnable ((void (*)(uint32_t ui32Base))ROM_UARTTABLE[38])
#endif
#if defined(TARGET_IS_TM4C123_RB1) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define UARTModemControlClear ((void (*)(uint32_t ui32Base, uint32_t ui32Control))ROM_UARTTABLE[39])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define UARTModemControlGet ((uint32_t(*)(uint32_t ui32Base))ROM_UARTTABLE[40])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define UARTModemControlSet ((void (*)(uint32_t ui32Base, uint32_t ui32Control))ROM_UARTTABLE[41])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define UARTModemStatusGet ((uint32_t(*)(uint32_t ui32Base))ROM_UARTTABLE[42])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define UARTFlowControlGet ((uint32_t(*)(uint32_t ui32Base))ROM_UARTTABLE[43])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define UARTFlowControlSet ((void (*)(uint32_t ui32Base, uint32_t ui32Mode))ROM_UARTTABLE[44])
#endif

//*****************************************************************************
//
// Macros for calling ROM functions in the uDMA API.
//
//*****************************************************************************
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define uDMAChannelTransferSet                  \
    ((void (*)(uint32_t ui32ChannelStructIndex, \
               uint32_t ui32Mode,               \
               void*    pvSrcAddr,              \
               void*    pvDstAddr,              \
               uint32_t ui32TransferSize))ROM_UDMATABLE[0])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define uDMAEnable ((void (*)(void))ROM_UDMATABLE[1])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define uDMADisable ((void (*)(void))ROM_UDMATABLE[2])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define uDMAErrorStatusGet ((uint32_t(*)(void))ROM_UDMATABLE[3])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define uDMAErrorStatusClear ((void (*)(void))ROM_UDMATABLE[4])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define uDMAChannelEnable ((void (*)(uint32_t ui32ChannelNum))ROM_UDMATABLE[5])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define uDMAChannelDisable ((void (*)(uint32_t ui32ChannelNum))ROM_UDMATABLE[6])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define uDMAChannelIsEnabled ((bool (*)(uint32_t ui32ChannelNum))ROM_UDMATABLE[7])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define uDMAControlBaseSet ((void (*)(void* pControlTable))ROM_UDMATABLE[8])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define uDMAControlBaseGet ((void* (*)(void))ROM_UDMATABLE[9])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define uDMAChannelRequest ((void (*)(uint32_t ui32ChannelNum))ROM_UDMATABLE[10])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define uDMAChannelAttributeEnable ((void (*)(uint32_t ui32ChannelNum, uint32_t ui32Attr))ROM_UDMATABLE[11])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define uDMAChannelAttributeDisable ((void (*)(uint32_t ui32ChannelNum, uint32_t ui32Attr))ROM_UDMATABLE[12])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define uDMAChannelAttributeGet ((uint32_t(*)(uint32_t ui32ChannelNum))ROM_UDMATABLE[13])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define uDMAChannelControlSet ((void (*)(uint32_t ui32ChannelStructIndex, uint32_t ui32Control))ROM_UDMATABLE[14])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define uDMAChannelSizeGet ((uint32_t(*)(uint32_t ui32ChannelStructIndex))ROM_UDMATABLE[15])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define uDMAChannelModeGet ((uint32_t(*)(uint32_t ui32ChannelStructIndex))ROM_UDMATABLE[16])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define uDMAChannelSelectSecondary ((void (*)(uint32_t ui32SecPeriphs))ROM_UDMATABLE[17])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define uDMAChannelSelectDefault ((void (*)(uint32_t ui32DefPeriphs))ROM_UDMATABLE[18])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define uDMAIntStatus ((uint32_t(*)(void))ROM_UDMATABLE[19])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define uDMAIntClear ((void (*)(uint32_t ui32ChanMask))ROM_UDMATABLE[20])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define uDMAControlAlternateBaseGet ((void* (*)(void))ROM_UDMATABLE[21])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define uDMAChannelScatterGatherSet                                                                         \
    ((void (*)(uint32_t ui32ChannelNum, uint32_t ui32TaskCount, void* pvTaskList, uint32_t ui32IsPeriphSG)) \
         ROM_UDMATABLE[22])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define uDMAChannelAssign ((void (*)(uint32_t ui32Mapping))ROM_UDMATABLE[23])
#endif

//*****************************************************************************
//
// Macros for calling ROM functions in the USB API.
//
//*****************************************************************************
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define USBDevAddrGet ((uint32_t(*)(uint32_t ui32Base))ROM_USBTABLE[1])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define USBDevAddrSet ((void (*)(uint32_t ui32Base, uint32_t ui32Address))ROM_USBTABLE[2])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define USBDevConnect ((void (*)(uint32_t ui32Base))ROM_USBTABLE[3])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define USBDevDisconnect ((void (*)(uint32_t ui32Base))ROM_USBTABLE[4])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define USBDevEndpointConfigSet                                                                           \
    ((void (*)(uint32_t ui32Base, uint32_t ui32Endpoint, uint32_t ui32MaxPacketSize, uint32_t ui32Flags)) \
         ROM_USBTABLE[5])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define USBDevEndpointDataAck ((void (*)(uint32_t ui32Base, uint32_t ui32Endpoint, bool bIsLastPacket))ROM_USBTABLE[6])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define USBDevEndpointStall ((void (*)(uint32_t ui32Base, uint32_t ui32Endpoint, uint32_t ui32Flags))ROM_USBTABLE[7])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define USBDevEndpointStallClear \
    ((void (*)(uint32_t ui32Base, uint32_t ui32Endpoint, uint32_t ui32Flags))ROM_USBTABLE[8])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define USBDevEndpointStatusClear \
    ((void (*)(uint32_t ui32Base, uint32_t ui32Endpoint, uint32_t ui32Flags))ROM_USBTABLE[9])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define USBEndpointDataGet \
    ((int32_t(*)(uint32_t ui32Base, uint32_t ui32Endpoint, uint8_t * pui8Data, uint32_t * pui32Size)) ROM_USBTABLE[10])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define USBEndpointDataPut \
    ((int32_t(*)(uint32_t ui32Base, uint32_t ui32Endpoint, uint8_t * pui8Data, uint32_t ui32Size)) ROM_USBTABLE[11])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define USBEndpointDataSend \
    ((int32_t(*)(uint32_t ui32Base, uint32_t ui32Endpoint, uint32_t ui32TransType))ROM_USBTABLE[12])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define USBEndpointDataToggleClear \
    ((void (*)(uint32_t ui32Base, uint32_t ui32Endpoint, uint32_t ui32Flags))ROM_USBTABLE[13])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define USBEndpointStatus ((uint32_t(*)(uint32_t ui32Base, uint32_t ui32Endpoint))ROM_USBTABLE[14])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define USBFIFOAddrGet ((uint32_t(*)(uint32_t ui32Base, uint32_t ui32Endpoint))ROM_USBTABLE[15])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define USBFIFOConfigGet                    \
    ((void (*)(uint32_t ui32Base,           \
               uint32_t ui32Endpoint,       \
               uint32_t * pui32FIFOAddress, \
               uint32_t * pui32FIFOSize,    \
               uint32_t ui32Flags)) ROM_USBTABLE[16])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define USBFIFOConfigSet                 \
    ((void (*)(uint32_t ui32Base,        \
               uint32_t ui32Endpoint,    \
               uint32_t ui32FIFOAddress, \
               uint32_t ui32FIFOSize,    \
               uint32_t ui32Flags))ROM_USBTABLE[17])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define USBFIFOFlush ((void (*)(uint32_t ui32Base, uint32_t ui32Endpoint, uint32_t ui32Flags))ROM_USBTABLE[18])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define USBFrameNumberGet ((uint32_t(*)(uint32_t ui32Base))ROM_USBTABLE[19])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define USBHostAddrGet ((uint32_t(*)(uint32_t ui32Base, uint32_t ui32Endpoint, uint32_t ui32Flags))ROM_USBTABLE[20])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define USBHostAddrSet \
    ((void (*)(uint32_t ui32Base, uint32_t ui32Endpoint, uint32_t ui32Addr, uint32_t ui32Flags))ROM_USBTABLE[21])
#endif
#if defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || defined(TARGET_IS_TM4C123_RB2) || \
    defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define USBHostEndpointConfig                \
    ((void (*)(uint32_t ui32Base,            \
               uint32_t ui32Endpoint,        \
               uint32_t ui32MaxPacketSize,   \
               uint32_t ui32NAKPollInterval, \
               uint32_t ui32TargetEndpoint,  \
               uint32_t ui32Flags))ROM_USBTABLE[22])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define USBHostEndpointDataAck ((void (*)(uint32_t ui32Base, uint32_t ui32Endpoint))ROM_USBTABLE[23])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define USBHostEndpointDataToggle \
    ((void (*)(uint32_t ui32Base, uint32_t ui32Endpoint, bool bDataToggle, uint32_t ui32Flags))ROM_USBTABLE[24])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define USBHostEndpointStatusClear \
    ((void (*)(uint32_t ui32Base, uint32_t ui32Endpoint, uint32_t ui32Flags))ROM_USBTABLE[25])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define USBHostHubAddrGet ((uint32_t(*)(uint32_t ui32Base, uint32_t ui32Endpoint, uint32_t ui32Flags))ROM_USBTABLE[26])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define USBHostHubAddrSet \
    ((void (*)(uint32_t ui32Base, uint32_t ui32Endpoint, uint32_t ui32Addr, uint32_t ui32Flags))ROM_USBTABLE[27])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define USBHostPwrDisable ((void (*)(uint32_t ui32Base))ROM_USBTABLE[28])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define USBHostPwrEnable ((void (*)(uint32_t ui32Base))ROM_USBTABLE[29])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define USBHostPwrConfig ((void (*)(uint32_t ui32Base, uint32_t ui32Flags))ROM_USBTABLE[30])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define USBHostPwrFaultDisable ((void (*)(uint32_t ui32Base))ROM_USBTABLE[31])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define USBHostPwrFaultEnable ((void (*)(uint32_t ui32Base))ROM_USBTABLE[32])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define USBHostRequestIN ((void (*)(uint32_t ui32Base, uint32_t ui32Endpoint))ROM_USBTABLE[33])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define USBHostRequestStatus ((void (*)(uint32_t ui32Base))ROM_USBTABLE[34])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define USBHostReset ((void (*)(uint32_t ui32Base, bool bStart))ROM_USBTABLE[35])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define USBHostResume ((void (*)(uint32_t ui32Base, bool bStart))ROM_USBTABLE[36])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define USBHostSpeedGet ((uint32_t(*)(uint32_t ui32Base))ROM_USBTABLE[37])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define USBHostSuspend ((void (*)(uint32_t ui32Base))ROM_USBTABLE[38])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define USBDevEndpointConfigGet                                                                                 \
    ((void (*)(uint32_t ui32Base, uint32_t ui32Endpoint, uint32_t * pui32MaxPacketSize, uint32_t * pui32Flags)) \
         ROM_USBTABLE[41])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define USBEndpointDMAEnable ((void (*)(uint32_t ui32Base, uint32_t ui32Endpoint, uint32_t ui32Flags))ROM_USBTABLE[42])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define USBEndpointDMADisable ((void (*)(uint32_t ui32Base, uint32_t ui32Endpoint, uint32_t ui32Flags))ROM_USBTABLE[43])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define USBEndpointDataAvail ((uint32_t(*)(uint32_t ui32Base, uint32_t ui32Endpoint))ROM_USBTABLE[44])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define USBModeGet ((uint32_t(*)(uint32_t ui32Base))ROM_USBTABLE[46])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define USBEndpointDMAChannel \
    ((void (*)(uint32_t ui32Base, uint32_t ui32Endpoint, uint32_t ui32Channel))ROM_USBTABLE[47])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define USBIntDisableControl ((void (*)(uint32_t ui32Base, uint32_t ui32IntFlags))ROM_USBTABLE[48])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define USBIntEnableControl ((void (*)(uint32_t ui32Base, uint32_t ui32IntFlags))ROM_USBTABLE[49])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define USBIntStatusControl ((uint32_t(*)(uint32_t ui32Base))ROM_USBTABLE[50])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define USBIntDisableEndpoint ((void (*)(uint32_t ui32Base, uint32_t ui32IntFlags))ROM_USBTABLE[51])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define USBIntEnableEndpoint ((void (*)(uint32_t ui32Base, uint32_t ui32IntFlags))ROM_USBTABLE[52])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define USBIntStatusEndpoint ((uint32_t(*)(uint32_t ui32Base))ROM_USBTABLE[53])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define USBHostMode ((void (*)(uint32_t ui32Base))ROM_USBTABLE[54])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define USBDevMode ((void (*)(uint32_t ui32Base))ROM_USBTABLE[55])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define USBPHYPowerOff ((void (*)(uint32_t ui32Base))ROM_USBTABLE[56])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define USBPHYPowerOn ((void (*)(uint32_t ui32Base))ROM_USBTABLE[57])
#endif
#if defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || defined(TARGET_IS_TM4C123_RB2) || \
    defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define UpdateUSB ((void (*)(uint8_t * pui8DescriptorInfo)) ROM_USBTABLE[58])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define USBOTGMode ((void (*)(uint32_t ui32Base))ROM_USBTABLE[59])
#endif
#if defined(TARGET_IS_TM4C123_RB1) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define USBHostRequestINClear ((void (*)(uint32_t ui32Base, uint32_t ui32Endpoint))ROM_USBTABLE[60])
#endif
#if defined(TARGET_IS_TM4C123_RB1) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define USBNumEndpointsGet ((uint32_t(*)(uint32_t ui32Base))ROM_USBTABLE[61])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define USBClockDisable ((void (*)(uint32_t ui32Base))ROM_USBTABLE[62])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define USBClockEnable ((void (*)(uint32_t ui32Base, uint32_t ui32Div, uint32_t ui32Flags))ROM_USBTABLE[63])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define USBControllerVersion ((uint32_t(*)(uint32_t ui32Base))ROM_USBTABLE[64])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define USBDevLPMConfig ((void (*)(uint32_t ui32Base, uint32_t ui32Config))ROM_USBTABLE[65])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define USBDevLPMDisable ((void (*)(uint32_t ui32Base))ROM_USBTABLE[66])
#endif
#if defined(TARGET_IS_TM4C123_RB1) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define USBDevLPMEnable ((void (*)(uint32_t ui32Base))ROM_USBTABLE[67])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define USBDevLPMRemoteWake ((void (*)(uint32_t ui32Base))ROM_USBTABLE[68])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define USBDevSpeedGet ((uint32_t(*)(uint32_t ui32Base))ROM_USBTABLE[69])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define USBDMAChannelAddressGet ((void* (*)(uint32_t ui32Base, uint32_t ui32Channel))ROM_USBTABLE[70])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define USBDMAChannelAddressSet ((void (*)(uint32_t ui32Base, uint32_t ui32Channel, void* pvAddress))ROM_USBTABLE[71])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define USBDMAChannelConfigSet \
    ((void (*)(uint32_t ui32Base, uint32_t ui32Channel, uint32_t ui32Endpoint, uint32_t ui32Config))ROM_USBTABLE[72])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define USBDMAChannelDisable ((void (*)(uint32_t ui32Base, uint32_t ui32Channel))ROM_USBTABLE[73])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define USBDMAChannelEnable ((void (*)(uint32_t ui32Base, uint32_t ui32Channel))ROM_USBTABLE[74])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define USBDMAChannelIntDisable ((void (*)(uint32_t ui32Base, uint32_t ui32Channel))ROM_USBTABLE[75])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define USBDMAChannelIntEnable ((void (*)(uint32_t ui32Base, uint32_t ui32Channel))ROM_USBTABLE[76])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define USBDMAChannelCountGet ((uint32_t(*)(uint32_t ui32Base, uint32_t ui32Channel))ROM_USBTABLE[77])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define USBDMAChannelCountSet ((void (*)(uint32_t ui32Base, uint32_t ui32Count, uint32_t ui32Channel))ROM_USBTABLE[78])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define USBDMAChannelIntStatus ((uint32_t(*)(uint32_t ui32Base))ROM_USBTABLE[79])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define USBDMAChannelStatus ((uint32_t(*)(uint32_t ui32Base, uint32_t ui32Channel))ROM_USBTABLE[80])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define USBDMAChannelStatusClear \
    ((void (*)(uint32_t ui32Base, uint32_t ui32Channel, uint32_t ui32Status))ROM_USBTABLE[81])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define USBHighSpeed ((void (*)(uint32_t ui32Base, bool bEnable))ROM_USBTABLE[82])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define USBHostEndpointPing ((void (*)(uint32_t ui32Base, uint32_t ui32Endpoint, bool bEnable))ROM_USBTABLE[83])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define USBHostEndpointSpeed ((void (*)(uint32_t ui32Base, uint32_t ui32Endpoint, uint32_t ui32Flags))ROM_USBTABLE[84])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define USBHostLPMConfig ((void (*)(uint32_t ui32Base, uint32_t ui32ResumeTime, uint32_t ui32Config))ROM_USBTABLE[85])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define USBHostLPMResume ((void (*)(uint32_t ui32Base))ROM_USBTABLE[86])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define USBHostLPMSend ((void (*)(uint32_t ui32Base, uint32_t ui32Address, uint32_t uiEndpoint))ROM_USBTABLE[87])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define USBLPMIntDisable ((void (*)(uint32_t ui32Base, uint32_t ui32Ints))ROM_USBTABLE[88])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define USBLPMIntEnable ((void (*)(uint32_t ui32Base, uint32_t ui32Ints))ROM_USBTABLE[89])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define USBLPMIntStatus ((uint32_t(*)(uint32_t ui32Base))ROM_USBTABLE[90])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define USBLPMLinkStateGet ((uint32_t(*)(uint32_t ui32Base))ROM_USBTABLE[91])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define USBEndpointPacketCountSet \
    ((void (*)(uint32_t ui32Base, uint32_t ui32Endpoint, uint32_t ui32Count))ROM_USBTABLE[92])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define USBULPIConfig ((void (*)(uint32_t ui32Base, uint32_t ui32Config))ROM_USBTABLE[93])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define USBULPIDisable ((void (*)(uint32_t ui32Base))ROM_USBTABLE[94])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define USBULPIEnable ((void (*)(uint32_t ui32Base))ROM_USBTABLE[95])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define USBULPIRegRead ((uint8_t(*)(uint32_t ui32Base, uint8_t ui8Reg))ROM_USBTABLE[96])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define USBULPIRegWrite ((void (*)(uint32_t ui32Base, uint8_t ui8Reg, uint8_t ui8Data))ROM_USBTABLE[97])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define USBOTGSessionRequest ((void (*)(uint32_t ui32Base, bool bStart))ROM_USBTABLE[98])
#endif
#if defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define USBDMANumChannels ((uint32_t(*)(uint32_t ui32Base))ROM_USBTABLE[99])
#endif
#if defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define USBEndpointDMAConfigSet \
    ((void (*)(uint32_t ui32Base, uint32_t ui32Endpoint, uint32_t ui32Config))ROM_USBTABLE[100])
#endif
#if defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define USBLPMRemoteWakeEnabled ((bool (*)(uint32_t ui32Base))ROM_USBTABLE[102])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define USBModeConfig ((void (*)(uint32_t ui32Base, uint32_t ui32Mode))ROM_USBTABLE[103])
#endif

//*****************************************************************************
//
// Macros for calling ROM functions in the Watchdog API.
//
//*****************************************************************************
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define WatchdogIntClear ((void (*)(uint32_t ui32Base))ROM_WATCHDOGTABLE[0])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define WatchdogRunning ((bool (*)(uint32_t ui32Base))ROM_WATCHDOGTABLE[1])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define WatchdogEnable ((void (*)(uint32_t ui32Base))ROM_WATCHDOGTABLE[2])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define WatchdogResetEnable ((void (*)(uint32_t ui32Base))ROM_WATCHDOGTABLE[3])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define WatchdogResetDisable ((void (*)(uint32_t ui32Base))ROM_WATCHDOGTABLE[4])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define WatchdogLock ((void (*)(uint32_t ui32Base))ROM_WATCHDOGTABLE[5])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define WatchdogUnlock ((void (*)(uint32_t ui32Base))ROM_WATCHDOGTABLE[6])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define WatchdogLockState ((bool (*)(uint32_t ui32Base))ROM_WATCHDOGTABLE[7])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define WatchdogReloadSet ((void (*)(uint32_t ui32Base, uint32_t ui32LoadVal))ROM_WATCHDOGTABLE[8])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define WatchdogReloadGet ((uint32_t(*)(uint32_t ui32Base))ROM_WATCHDOGTABLE[9])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define WatchdogValueGet ((uint32_t(*)(uint32_t ui32Base))ROM_WATCHDOGTABLE[10])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define WatchdogIntEnable ((void (*)(uint32_t ui32Base))ROM_WATCHDOGTABLE[11])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define WatchdogIntStatus ((uint32_t(*)(uint32_t ui32Base, bool bMasked))ROM_WATCHDOGTABLE[12])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define WatchdogStallEnable ((void (*)(uint32_t ui32Base))ROM_WATCHDOGTABLE[13])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define WatchdogStallDisable ((void (*)(uint32_t ui32Base))ROM_WATCHDOGTABLE[14])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define WatchdogIntTypeSet ((void (*)(uint32_t ui32Base, uint32_t ui32Type))ROM_WATCHDOGTABLE[15])
#endif

//*****************************************************************************
//
// Macros for calling ROM functions in the Software API.
//
//*****************************************************************************
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define Crc16Array ((uint16_t(*)(uint32_t ui32WordLen, const uint32_t* pui32Data))ROM_SOFTWARETABLE[1])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define Crc16Array3 \
    ((void (*)(uint32_t ui32WordLen, const uint32_t* pui32Data, uint16_t* pui16Crc3))ROM_SOFTWARETABLE[2])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define Crc16 ((uint16_t(*)(uint16_t ui16Crc, const uint8_t* pui8Data, uint32_t ui32Count))ROM_SOFTWARETABLE[3])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define Crc8CCITT ((uint8_t(*)(uint8_t ui8Crc, const uint8_t* pui8Data, uint32_t ui32Count))ROM_SOFTWARETABLE[4])
#endif
#if defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || defined(TARGET_IS_TM4C129_RA2)
#define Crc32 ((uint32_t(*)(uint32_t ui32Crc, const uint8_t* pui8Data, uint32_t ui32Count))ROM_SOFTWARETABLE[5])
#endif
#if defined(TARGET_IS_TM4C123_RA1) || defined(TARGET_IS_TM4C123_RA3) || defined(TARGET_IS_TM4C123_RB1) || \
    defined(TARGET_IS_TM4C123_RB2) || defined(TARGET_IS_TM4C129_RA0) || defined(TARGET_IS_TM4C129_RA1) || \
    defined(TARGET_IS_TM4C129_RA2)
#define pvAESTable ((void*)&(ROM_SOFTWARETABLE[7]))
#endif

#endif // __DRIVERLIB_ROM_H__

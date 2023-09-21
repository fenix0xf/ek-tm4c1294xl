# MIT License
#
# Copyright © 2023 Alexander Kotikov, alexandr.kotikov@gmail.com
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.

cmake_minimum_required(VERSION 3.24)

###
### Project: EK-TM4C1294XL, C11 language.
###
project(EK-TM4C1294XL C ASM)

### Set compiler standard to C11 and enable GNU extensions.
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON) # POSIX.1-2001 function strcasecmp() and __VA_OPT__.

### Project options.
set(LIBC_USE_CUSTOM ON) # Set to ON to disable default GCC libc.

### Set default build type to Release.
if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif ()

### GCC flags for MCU architecture
list(APPEND CFLAGS_ARCH -mthumb -march=armv7e-m -mtune=cortex-m4 -mfloat-abi=hard -mfpu=fpv4-sp-d16)

### GCC flags for compile and linking
if (LIBC_USE_CUSTOM)
    list(APPEND CFLAGS -nostdinc -ffreestanding -ggdb3 -fno-strict-aliasing -fno-strict-overflow -ffunction-sections -fdata-sections -fno-builtin -fno-common)
    list(APPEND LFLAGS -nostdlib -Wl,--gc-sections,--print-memory-usage)
else ()
    list(APPEND CFLAGS -ggdb3 -fno-strict-aliasing -fno-strict-overflow -ffunction-sections -fdata-sections -fno-builtin -fno-common)
    list(APPEND LFLAGS -nostartfiles -specs=nano.specs -Wl,--gc-sections,--print-memory-usage)
endif ()

### Set compiler and linker flags
add_compile_options(${CFLAGS_ARCH} ${CFLAGS})
add_link_options(${CFLAGS_ARCH} ${CFLAGS} ${LFLAGS})

### Global C warnings variable.
list(APPEND C_WARN
     -Werror
     -Wall
     -Wextra
     -Wpedantic
     -Wconversion
     -Wshadow
     -Wdouble-promotion
     -Wc++-compat
     -Wno-unused-function
)

list(APPEND TW_WARN
     -Wno-unused-parameter
     -Wno-old-style-declaration
     -Wno-conversion
     -Wno-address-of-packed-member
     -Wno-sign-compare
     -Wno-type-limits
)

### Custom C Run Time Library.
if (LIBC_USE_CUSTOM)
    list(APPEND LIBC_WARN
         -Wno-pedantic
         -Wno-unused-parameter
         -Wno-unused-variable
         -Wno-unused-but-set-variable
         -Wno-conversion
         -Wno-implicit-fallthrough
         -Wno-sign-compare
         -Wno-shadow
         -Wno-unused-label
         -Wno-maybe-uninitialized
         -Wno-c++-compat
    )

    set(LIBC_GCC_INCLUDES ${CMAKE_C_IMPLICIT_INCLUDE_DIRECTORIES})
    set(CMAKE_C_IMPLICIT_INCLUDE_DIRECTORIES "")

    list(FILTER LIBC_GCC_INCLUDES INCLUDE REGEX lib/gcc/)

    include_directories(SYSTEM
                        ${LIBC_GCC_INCLUDES}
                        ${CMAKE_SOURCE_DIR}/src/lib/libc/newlib/thumb/v7e-m+fp/hard/newlib/include
                        ${CMAKE_SOURCE_DIR}/src/lib/libc/newlib/libc/include
    )

    file(GLOB_RECURSE LIBC_COMMON_FILES RELATIVE ${CMAKE_SOURCE_DIR} src/lib/libc/newlib/libc/*.[h,c,s,S])
    file(GLOB_RECURSE LIBC_ARCH_HDRS RELATIVE ${CMAKE_SOURCE_DIR} src/lib/libc/newlib/thumb/*.[h])

#    file(GLOB_RECURSE LIBC_ARM_FILES RELATIVE ${CMAKE_SOURCE_DIR} src/lib/libc/newlib/libc_arm/*.[h,c,s,S])
    list(APPEND LIBC_ARM_FILES src/lib/libc/newlib/libc_arm/setjmp.S)
    list(APPEND LIBC_ARM_FILES src/lib/libc/newlib/libc_arm/strcmp.S)
    list(APPEND LIBC_ARM_FILES src/lib/libc/newlib/libc_arm/strcpy.c)
    list(APPEND LIBC_ARM_FILES src/lib/libc/newlib/libc_arm/aeabi_memcpy.c)
    list(APPEND LIBC_ARM_FILES src/lib/libc/newlib/libc_arm/aeabi_memcpy-armv7a.S)
    list(APPEND LIBC_ARM_FILES src/lib/libc/newlib/libc_arm/aeabi_memmove.c)
    list(APPEND LIBC_ARM_FILES src/lib/libc/newlib/libc_arm/aeabi_memmove-soft.S)
    list(APPEND LIBC_ARM_FILES src/lib/libc/newlib/libc_arm/aeabi_memset.c)
    list(APPEND LIBC_ARM_FILES src/lib/libc/newlib/libc_arm/aeabi_memset-soft.S)
    list(APPEND LIBC_ARM_FILES src/lib/libc/newlib/libc_arm/aeabi_memclr.c)
    list(APPEND LIBC_ARM_FILES src/lib/libc/newlib/libc_arm/memchr-stub.c)
    list(APPEND LIBC_ARM_FILES src/lib/libc/newlib/libc_arm/memchr.S)
    list(APPEND LIBC_ARM_FILES src/lib/libc/newlib/libc_arm/memcpy-stub.c)
    list(APPEND LIBC_ARM_FILES src/lib/libc/newlib/libc_arm/memcpy.S)
    list(APPEND LIBC_ARM_FILES src/lib/libc/newlib/libc_arm/strlen-stub.c)
    list(APPEND LIBC_ARM_FILES src/lib/libc/newlib/libc_arm/strlen.S)

    list(APPEND LIBC_FILES ${LIBC_COMMON_FILES} ${LIBC_ARM_FILES} ${LIBC_ARCH_HDRS})

    set_source_files_properties(${LIBC_FILES} PROPERTIES
                                COMPILE_OPTIONS "${LIBC_WARN}"
                                COMPILE_DEFINITIONS ""
    )
else ()
    set(LIBC_FILES "")
endif ()

### Global defines
add_compile_definitions(TIVAWARE_USE_ROM=0
                        TARGET_IS_TM4C129_RA2
                        PART_TM4C1294NCPDT
)

### Add includes for all targets
include_directories(${CMAKE_SOURCE_DIR}/src
                    ${CMAKE_SOURCE_DIR}/src/drv/tivaware
                    ${CMAKE_SOURCE_DIR}/src/lib/tnkernel
)

### TI Tivaware Drivers
file(GLOB_RECURSE TIVAWARE_FILES RELATIVE ${CMAKE_SOURCE_DIR} src/drv/tivaware/*.[h,c])
set_source_files_properties(${TIVAWARE_FILES} PROPERTIES
                            COMPILE_OPTIONS "${TW_WARN}"
                            COMPILE_DEFINITIONS "DEPRECATED;gcc;"
)

### HW Drivers
file(GLOB DRV_FILES RELATIVE ${CMAKE_SOURCE_DIR} src/drv/*.[h,c])

### Hardware Abstraction Layer.
file(GLOB_RECURSE HAL_FILES RELATIVE ${CMAKE_SOURCE_DIR} src/hal/*.[h,c])

### TN Kernel
file(GLOB_RECURSE TN_FILES RELATIVE ${CMAKE_SOURCE_DIR} src/lib/tnkernel/*.[h,c,S,s])

### Other libs.
file(GLOB LIB_FILES RELATIVE ${CMAKE_SOURCE_DIR} src/lib/*.[h,c])

### Firmware source files.
file(GLOB_RECURSE FIRMWARE_FILES RELATIVE ${CMAKE_SOURCE_DIR} src/firmware/*.[h,c])


###
### Firmware build target.
###
set(FIRMWARE_TARGET_NAME firmware)
set(FIRMWARE_LD_SCRIPT ${PROJECT_SOURCE_DIR}/src/${FIRMWARE_TARGET_NAME}.ld)
set(FIRMWARE_MAP_FILE ${CMAKE_BINARY_DIR}/${FIRMWARE_TARGET_NAME}.map)

add_executable(${FIRMWARE_TARGET_NAME}.elf
               ${LIBC_FILES}
               ${TIVAWARE_FILES}
               ${DRV_FILES}
               ${HAL_FILES}
               ${TN_FILES}
               ${LIB_FILES}
               ${FIRMWARE_FILES}
)

### TN Kernel config
target_compile_definitions(${FIRMWARE_TARGET_NAME}.elf PUBLIC
                           TN_SUPPORT_FPU=1
                           TN_USE_USER_TIMERS=1
                           TN_USE_MUTEXES=1
                           TN_USE_EVENTS=1
                           TN_USE_DYN_OBJ=0
                           TN_CHECK_PARAM=0
                           TN_STACK_CHECK=2
)

target_compile_definitions(${FIRMWARE_TARGET_NAME}.elf PUBLIC $<IF:$<CONFIG:Debug>,DEBUG=1,DEBUG=0>)
target_compile_options(${FIRMWARE_TARGET_NAME}.elf PUBLIC ${C_WARN})
set_target_properties(${FIRMWARE_TARGET_NAME}.elf PROPERTIES LINK_FLAGS "-Wl,-T,${FIRMWARE_LD_SCRIPT},-Map,${FIRMWARE_MAP_FILE}")
#target_link_libraries(${FIRMWARE_TARGET_NAME}.elf PUBLIC -lm) # Link with C math library libm.a

add_custom_command(TARGET ${FIRMWARE_TARGET_NAME}.elf POST_BUILD COMMAND ${CMAKE_OBJCOPY} ARGS -Oihex ${FIRMWARE_TARGET_NAME}.elf ${FIRMWARE_TARGET_NAME}.hex COMMENT "Generate HEX file...")
add_custom_command(TARGET ${FIRMWARE_TARGET_NAME}.elf POST_BUILD COMMAND ${CMAKE_OBJCOPY} ARGS -Obinary ${FIRMWARE_TARGET_NAME}.elf ${FIRMWARE_TARGET_NAME}.bin COMMENT "Generate BIN file...")
#add_custom_command(TARGET ${FIRMWARE_TARGET_NAME}.elf POST_BUILD COMMAND ${PROJECT_SOURCE_DIR}/checksum.py -b ${FIRMWARE_TARGET_NAME}.bin -e ${FIRMWARE_TARGET_NAME}.elf COMMENT "Update checksum in BIN and ELF file...")
#add_custom_command(TARGET ${FIRMWARE_TARGET_NAME}.elf POST_BUILD COMMAND ${PROJECT_SOURCE_DIR}/aes-256-ctr.py 0x208 ${FIRMWARE_TARGET_NAME}.bin ${FIRMWARE_TARGET_NAME}.eff COMMENT "Generate encrypted firmware file (EFF)...")

### Add the linker script file as depends of src/hal/hal.c for auto rebuild target on any ld script changes.
set_source_files_properties(src/hal/hal.c PROPERTIES OBJECT_DEPENDS ${FIRMWARE_LD_SCRIPT})

#add_custom_target(cmake_pre_build_update_build_date COMMAND ${PROJECT_SOURCE_DIR}/build-date.py ../src/build_date.h)
#add_dependencies(${FIRMWARE_TARGET_NAME}.elf cmake_pre_build_update_build_date)

#!/usr/bin/python3

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

import os
import io
import sys

# pip install crcmod-plus
import crcmod.predefined

# pip install pyelftools
import elftools.elf.elffile
import elftools.elf.sections

if len(sys.argv) != 2:
    print("Usage: checksum.py firmware.elf", file=sys.stderr)
    exit(1)

elf_file = sys.argv[1]

if not os.path.isfile(elf_file):
    print(f"checksum.py: ELF file not found: {elf_file}!", file=sys.stderr)
    sys.exit(1)

with open(elf_file, mode="r+b") as ef:
    elf = elftools.elf.elffile.ELFFile(ef)
    checksum_section = elf.get_section_by_name(".checksum")

    if checksum_section is None:
        print(f"checksum.py: .checksum section is not found!", file=sys.stderr)
        sys.exit(1)

    checksum_offset = checksum_section["sh_offset"]
    checksum_size = checksum_section["sh_size"]

    if checksum_size != 4:
        print(f"checksum.py: .checksum section size != 4! Size in ELF file = {checksum_size} bytes!", file=sys.stderr)
        sys.exit(1)

    checksum = crcmod.predefined.Crc("crc-32-mpeg")

    print(f"\nchecksum.py: Section Name    Type           VMA         Offset      Size")

    for section in elf.iter_sections():
        if section["sh_type"] == "SHT_NOBITS" or section["sh_type"] == "SHT_NULL":
            continue

        if section.name == ".checksum":
            break

        print(
            f"checksum.py: {section.name:15s} {section["sh_type"]:14s} 0x{section["sh_addr"]:08X}  0x{section["sh_offset"]:08X}  {section["sh_size"]}")

        checksum.update(section.data())

    ef.seek(checksum_offset, io.SEEK_SET)
    ef.write(checksum.crcValue.to_bytes(checksum_size, byteorder="little", signed=False))

    print(f"checksum.py:")
    print(f"checksum.py: Write checksum 0x{checksum.crcValue:08X} to {elf_file} at offset 0x{checksum_offset:08X}")

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
import sys
import pathlib
import subprocess

mcpu = "TM4C1294NCPDT"
interface = "jtag"
port = "3333"
speed = "8000"

# set remotetimeout 30 - fix for "Unknown remote qXfer reply: OK"
gdbinit_text_common = \
    "set remotetimeout 30\n" \
    "define target hookpost-remote\n" \
    "echo GDBINIT: Starting firmware hookpost-remote hook...\\n\n" \
    "monitor flash device = " + mcpu + "\n" \
    "monitor flash download = 1\n" \
    "monitor flash breakpoints = 0\n"

# gdbinit_text_fw_buf_clear = \
#     "echo GDBINIT: Clearing firmware update buffer...\\n\n" \
#     "monitor reset\n" \
#     "monitor writeu32 0x44000 0xFFFFFFFF\n"

gdbinit_text_fw_flashing_and_start = \
    "echo GDBINIT: Loading {0}...\\n\n" \
    "monitor reset\n" \
    "file {0}\n" \
    "load\n" \
    "monitor reset\n" \
    "echo GDBINIT: Starting {0}...\\n\n" \
    "end\n"

out_path = os.path.expanduser('~')
clear_fw_buf = False

if not os.path.exists(out_path):
    print("{0} is not exist!".format(out_path), file=sys.stderr)
    exit(1)

if len(sys.argv) < 2:
    print("Usage: gdbinit.py relative/firmware.elf [clear]", file=sys.stderr)
    exit(1)

# if len(sys.argv) == 3 and sys.argv[2] == "clear":
#     clear_fw_buf = True

fw_file_name = str(pathlib.Path(os.getcwd(), sys.argv[1]))

if os.name == 'nt':
    fw_file_name = fw_file_name.replace(os.sep, "/")

out_text = gdbinit_text_common

# if clear_fw_buf:
#     outText += gdbinit_text_fw_buf_clear

out_text += gdbinit_text_fw_flashing_and_start.format(fw_file_name)

gdbinit_file = pathlib.Path(out_path, ".gdbinit")
gdbinit_file.write_text(out_text)

#
# Restart JLink GDB Server.
#
if os.name == 'nt':
    subprocess.call(
        "taskkill /im JLinkGDBServerCL.exe",
        stdout=subprocess.DEVNULL,
        stderr=subprocess.DEVNULL
    )
    # creationflags = DETACHED_PROCESS (0x00000008)
    subprocess.Popen(
        "start \"\" /min "
        "JLinkGDBServerCL.exe"
        " -select usb"
        " -if " + interface +
        " -noir"
        " -nohalt"
        " -speed " + speed +
        " -device " + mcpu +
        " -endian little"
        " -port " + port +
        " -localhostonly 1"
        " -notimeout",
        creationflags=0x00000008,
        shell=True
    )

# elif os.name == 'posix':
#     subprocess.call(["killall", "-q", "JLinkGDBServerCLExe"])
#     subprocess.Popen(
#         "gnome-terminal"
#         " --geometry 80x18"
#         " -- "
#         "JLinkGDBServerCLExe"
#         " -select usb"
#         " -if " + interface +
#         " -noir"
#         " -nohalt"
#         " -speed " + speed +
#         " -device " + mcpu +
#         " -endian little"
#         " -port " + port +
#         " -localhostonly 1"
#         " -notimeout",
#         shell=True
#         )
#     time.sleep(1.0)  # 1000 mS
#     subprocess.call(["wmctrl", "-a", "CLion"])

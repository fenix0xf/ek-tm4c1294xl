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

mcpu = "TM4C1294NCPDT"

# set remotetimeout 30 - fix for "Unknown remote qXfer reply: OK"
out_text = \
    "set remotetimeout 30\n" \
    "define target hookpost-remote\n" \
    "echo GDBINIT: Starting firmware hookpost-remote hook...\\n\n" \
    "monitor flash device = " + mcpu + "\n" \
    "monitor flash download = 1\n" \
    "monitor flash breakpoints = 0\n" \
    "monitor reset\n" \
    "end\n"

out_path = os.path.expanduser('~')

if not os.path.exists(out_path):
    print("{0} is not exist!".format(out_path), file=sys.stderr)
    exit(1)

gdbinit_file = pathlib.Path(out_path, ".gdbinit")
gdbinit_file.write_text(out_text)

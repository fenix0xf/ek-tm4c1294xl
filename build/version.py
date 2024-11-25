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
import time
import pathlib
import subprocess

from datetime import datetime, timezone
from idlelib.run import flush_stdout


def git_hash_get():
    def _minimal_ext_cmd(cmd):
        # construct minimal environment
        env = {}
        for k in ['SYSTEMROOT', 'PATH']:
            v = os.environ.get(k)
            if v is not None:
                env[k] = v
        # LANGUAGE is used on win32
        env['LANGUAGE'] = 'C'
        env['LANG'] = 'C'
        env['LC_ALL'] = 'C'
        out = subprocess.Popen(cmd, stdout=subprocess.PIPE, env=env).communicate()[0]
        return out

    try:
        out = _minimal_ext_cmd(['git', 'rev-parse', '--short=8', 'HEAD'])
        git_revision = out.strip().decode('ascii')
    except OSError:
        git_revision = "00000000"

    return git_revision


if len(sys.argv) != 2:
    print("Usage: version.py version.h", file=sys.stderr)
    exit(1)

outFileName = sys.argv[1]

outTextFmt = \
    "/* Auto generated header. */\n\n" \
    "#pragma once\n\n" \
    "#define VERSION_BUILD_TIME      (0x{0:016X}u)            /* Seconds since 1970-01-01 00:00:00 UTC (as uint64_t). */\n" \
    "#define VERSION_BUILD_TIME_STR  \"{1}\" /* UTC time (as string). */\n" \
    "#define VERSION_BUILD_TIME_LSTR \"{2}\" /* Local time (as string). */\n\n" \
    "#define VERSION_GIT_HASH        ({3}) /* First 8 digits of git hash (as uint32_t). */\n" \
    "#define VERSION_GIT_HASH_STR    \"{4}\"    /* First 8 digits of git hash (as string). */\n"

utc = datetime.now(timezone.utc)
local = utc.astimezone()
git_hash_str = git_hash_get()
git_hash = f"0x{git_hash_str.upper()}u"

utc_timestamp = int(time.mktime(local.timetuple()))
tfmt = "%a %d %b %Y %H:%M:%S %z"
utc_date = utc.strftime(tfmt)
local_date = local.strftime(tfmt)

outText = outTextFmt.format(utc_timestamp, utc_date, local_date, git_hash, git_hash_str)

outFile = pathlib.Path(outFileName)
outFile.write_text(outText)

#!/usr/bin/env python3

import sys
import os
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))

from cpcommon import save_file # pyright: ignore [reportImplicitRelativeImport]

if len(sys.argv) != 2:
    print("Usage: <program> '242. Valid Anagram'")
    sys.exit(1)

problem = sys.argv[1]

save_file(problem, "leetcode")
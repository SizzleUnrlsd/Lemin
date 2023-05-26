#!/usr/bin/env -S python3

import sys, os

CODING_STYLE = "./coding-style.sh"
CODING_STYLE_REPORT = "coding-style-reports.log"
CODING_STYLE_REPORT_ERROR = "(hint: fix the file or remove it from the working set)"

def main():
    # Check if coding-style binary exists
    try:
        open(CODING_STYLE, "r")
    except:
        print("coding-style binary not found")
        return 1

    # Launch coding-style binary
    try:
        os.system(f"{CODING_STYLE} ./ ./")
    except:
        print("coding-style binary failed")
        return 1

    # Check if coding-style report exist
    try:
        open(CODING_STYLE_REPORT, "r")
    except:
        print("coding-style report not found")
        return 1

    # Read coding-style report
    try:
        with open(CODING_STYLE_REPORT, "r") as f:
            report = f.readlines()
    except:
        print("coding-style report read failed")
        return 1
    for line in report:
        if line.find(CODING_STYLE_REPORT_ERROR) == -1:
            print("coding-style failed")
            return 1
    print("coding-style pass")
    return 0

if __name__ == "__main__":
    sys.exit(main())
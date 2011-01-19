#!/usr/bin/python

import sys, os.path

def main(argv = sys.argv):
    if len(argv) == 1:
        string = sys.stdin.readline()
        while (string):
            print string.upper().strip()
            string = sys.stdin.readline()

    else:
        string = argv[1]
        print string.upper()


if __name__ == "__main__":
    sys.exit(main())

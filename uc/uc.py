#!/usr/bin/python

import sys, os.path

def main(argv = sys.argv):
    # Read from stdin if there aren't any command line arguments.
    if len(argv) == 1:
        string = sys.stdin.readline()
        while (string):
            print string.upper().strip()
            string = sys.stdin.readline()

    # Handle command line arguments.
    else:
        print " ".join([s.upper() for s in argv[1:]])


if __name__ == "__main__":
    sys.exit(main())

#!/usr/bin/python

import sys, os.path

def usage(program):
    sys.stderr.write("%s <rotation factor> <string>\n" % os.path.basename(program))


def rotate_char(factor, c):
    if c.isupper():
        offset = ord('A')
    else:
        offset = ord('a')

    if c.isalpha():
        r = chr((ord(c)-offset+factor) % 26 + offset)
    else:
        r = c

    return r


def rotate(factor, string):
    return ''.join([rotate_char(factor, c) for c in string])


def main(argv = sys.argv):
    if len(argv) != 3:
        usage(argv[0])
        return 1

    factor = int(argv[1])
    string = argv[2]
    print rotate(factor, string)


if __name__ == "__main__":
    sys.exit(main())

#!/usr/bin/python

import sys, os.path

def usage(program):
    sys.stderr.write("Usage: %s factor string\n" % os.path.basename(program))


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

def getInput():
    input = sys.stdin.readline()
    if (input):
        return (input.split(' '))
    else:
        return []


def main(argv = sys.argv):
    if len(argv) == 1:
        argv = getInput()
        while (argv):
            factor = int(argv[0])
            string = " ".join(argv[1:])
            print rotate(factor, string).strip()
            argv = getInput()

    elif len(argv) >= 3:
        factor = int(argv[1])
        string = " ".join(argv[2:])
        print rotate(factor, string).strip()

    else:
        usage(argv[0])
        sys.exit(1)



if __name__ == "__main__":
    sys.exit(main())

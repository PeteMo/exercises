#include <stdio.h>
#include <libgen.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void usage(char *program)
{
    fprintf(stderr, "Usage: %s factor string\n", basename(program));
}


char rotate_char(int factor, char c)
{
    char r;
    int offset, tmp;

    offset = isupper(c) ? 'A' : 'a';

    if (isalpha(c)) {
        /* C doesn't handle taking the modulus of negative numbers well; which
         * can happen if factor is negative. The modulus of a negative can be
         * determined by adding the divisor to the dividend until it is
         * positive, then taking the modulus. */
        tmp = c-offset+factor;
        while (tmp < 0) {
            tmp += 26;
        }
        r = (tmp % 26) + offset;
    }
    else {
        r = c;
    }

    return r;
}


char *rotate(int factor, char *string)
{
    int i, e;
    char *rotated_string = malloc(sizeof(char) * strlen(string));
    if (rotated_string == NULL) {
        fprintf(stderr, "Unable to allocate memory for rotated_string.\n");
        exit(1);
    }

    e = strlen(string);
    for (i=0; i < e; i++) {
        rotated_string[i] = rotate_char(factor, string[i]);
    }

    /* Make sure the null byte is at the proper place in the rotated string. 
     * It isn't if the last character is non-alpha. */
    rotated_string[e] = '\0';
    return rotated_string;
}


int main(int argc, char *argv[])
{
    if (argc != 3) {
        usage(argv[0]);
        return 1;
    }

    int factor = atoi(argv[1]);
    char *string = argv[2];
    char *rotated_string;

    rotated_string = rotate(factor, string);
    printf("%s\n", rotated_string);
    free(rotated_string);

    return 0;
}

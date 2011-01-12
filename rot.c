#include <stdio.h>
#include <libgen.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void usage(char *program)
{
    fprintf(stderr, "%s <rotation factor> <string>\n", basename(program));
}


char rotate_char(int factor, char c)
{
    char r;
    int offset, tmp;

    offset = isupper(c) ? 'A' : 'a';

    if (isalpha(c)) {
        // To handle taking modulus of negative numbers; can happen if factor is negative.
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
    int i;
    char *rotated_string = malloc(sizeof(char) * strlen(string));
    if (rotated_string == NULL) {
        fprintf(stderr, "Unable to allocate memory for rotated_string.\n");
        exit(1);
    }

    for (i=0; i < strlen(string); i++) {
        rotated_string[i] = rotate_char(factor, string[i]);
    }

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

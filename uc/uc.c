#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <error.h>

/* Read a line from stream not including the newline, resizing the buffer as
 * necessary. Returns the number of characters read or -1 on error or EOF. */
int uc_getline(char *buf, int size, FILE *stream)
{
    int i;

    if ((buf = fgets(buf, size, stream)) == NULL) {
        return -1;
    }

    /* If the last character is '\n' then we read the whole line. Remove the
     * newline and return. */
    if (buf[strlen(buf)-1] == '\n') {
        buf[strlen(buf)-1] = '\0';
        return strlen(buf);
    }
    else {

        /* Put everything back. */
        for (i = strlen(buf)-1; i >= 0; i--) {
            if (ungetc(buf[i], stdin) == EOF) {
                perror("Error calling ungetc in uc_getline");
                exit(1);
            }
        }

        /* Double the size of the buffer. */
        size += size;
        if ((buf = realloc(buf, size)) == NULL) {
            perror("Error calling realloc in uc_getline");
            exit(1);
        }

        /* Try again. */
        return (uc_getline(buf, size, stream));
    }
}

/* Convert each character in s to uppercase, in place. */
char *uc(char *s)
{
    int i;

    for (i = 0; i < strlen(s); i++) {
        s[i] = toupper(s[i]);
    }

    return s;
}

int main(int argc, char *argv[]) 
{
    int i;
    int size = 5;
    char *string;

    /* Read from stdin if no command line arguments. */
    if (argc == 1) {
        if ((string = malloc(sizeof(char) * size)) == NULL) {
            perror("Error calling malloc in main");
            exit(1);
        }

        while (uc_getline(string, size, stdin) > 0) {
            printf("%s\n", uc(string));
        }

        free(string);
    }
    /* Process each argument. */
    else {
        for(i = 1; i < argc; i++) {
            printf("%s ", uc(argv[i]));
        }
        printf("\n");
    }

    return 0;
}

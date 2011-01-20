#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <error.h>

/* Read a line from stream, resizing the buffer as necessary. Returns a pointer to the line
 * without a newline character or NULL on error. */
char *uc_getline(char *buf, int size, FILE *stream)
{
    int i;
    buf = fgets(buf, size, stream);

    if (buf == NULL) {
        return buf;
    }

    /* If the last character isn't '\n' then we didn't read the whole line. */
    while (buf[strlen(buf)-1] != '\n') {
        /* Double the size of the buffer. */
        size += size;
        if ((buf = realloc(buf, size)) == NULL) {
            perror("Error calling realloc in uc_getline");
            exit(1);
        }

        /* Put everything back and try again. */
        for (i = strlen(buf)-1; i >= 0; i--) {
            if (ungetc(buf[i], stdin) == EOF) {
                perror("Error calling ungetc in uc_getline");
                exit(1);
            }
        }
        buf = fgets(buf, size, stream);
    }

    /* Remove the newline. */
    buf[strlen(buf)-1] = '\0';

    return buf;
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
    int size = 20;
    char *string;

    /* Read from stdin if no command line arguments. */
    if (argc == 1) {
        if ((string = malloc(sizeof(char) * size)) == NULL) {
            perror("Error calling malloc in main");
            exit(1);
        }

        while ((string = uc_getline(string, size, stdin)) != NULL) {
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

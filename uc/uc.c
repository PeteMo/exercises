#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* Read a line from stream. */
char *getline(char *line, int size, FILE *stream)
{
    line = fgets(line, size, stream);

    /* Null indicates error or EOF. */
    if (line == NULL) {
        /* Do nothing. Returning NULL indicates an error/eof. */
    }

    /* If the last character isn't '\n' then we didn't read the whole line. */
    else if (line[strlen(line)-1] != '\n') {
        fprintf(stderr, "Unable to read the complete line.\n");
        exit(1);
    }

    /* If it is, then remove the newline. */
    else {
        line[strlen(line)-1] = '\0';
    }

    return line;
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
    int size = 100;
    char *string = malloc(size);

    if (argc == 1) {
        while ((string = getline(string, size, stdin)) != NULL) {
            printf("%s\n", uc(string));
        }
    }
    else {
        printf("%s\n", uc(argv[1]));
    }

    free(string);
    return 0;
}

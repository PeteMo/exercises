#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#ifdef linux
#include <error.h>
#endif

/* Read a line from stream not including the newline, resizing the buffer as
 * necessary. Returns the number of characters read or -1 on error or EOF. */
int uc_getline(char *buf, int size, FILE *stream)
{
    int i;
    char *tmp;

    if ((tmp = malloc(sizeof(char) * size)) == NULL) {
        perror("Error calling malloc in uc_getline");
        exit(1);
    }

    tmp = fgets(tmp, size, stream);

    if (tmp == NULL) {
        return -1;
    }

    strcpy(buf, tmp);

    /* If the last character isn't '\n' then we didn't read the whole line. */
    while (buf[strlen(buf)-1] != '\n') {
        printf("Realloc'ing\n");

        /* Put everything back. */
        for (i = strlen(buf)-1; i >= 0; i--) {
            printf("  Putting back `%c'\n", buf[i]);
            if (ungetc(buf[i], stdin) == EOF) {
                perror("Error calling ungetc in uc_getline");
                exit(1);
            }
        }

        /* Double the size of the buffer. */
        size += size;
        printf("    Increasing the size of buf to %d\n", size);
        if ((buf = realloc(buf, size)) == NULL) {
            perror("Error calling realloc in uc_getline");
            exit(1);
        }

        /* Try again. */
        printf("      Trying again\n");
        buf = fgets(buf, size, stream);
        printf("      Got %d chars\n", strlen(buf));
        
    }

    /* Remove the newline. */
    printf("        strlen(buf) = %d\n", strlen(buf));
    buf[strlen(buf)-1] = '\0';

    free(tmp);
    printf("        Returning\n");
    return strlen(buf);
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
            printf("Returned. strlen(string) = %d\n", strlen(string));
            printf("%s\n", uc(string));
        }

        printf("Freeing string: %p\n", string);
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

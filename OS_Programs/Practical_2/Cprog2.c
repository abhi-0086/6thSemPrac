// ChatGPT version 1.0 of code

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return -1;
    }

    FILE *fp = fopen(argv[1], "r+");
    if (fp == NULL)
    {
        perror("Error opening file");
        return -1;
    }

    int c;
    while ((c = fgetc(fp)) != EOF)
    {
        if (islower(c))
        {
            fseek(fp, -1, SEEK_CUR);
            fputc(toupper(c), fp);
        }
    }

    fclose(fp);
    return 0;
}

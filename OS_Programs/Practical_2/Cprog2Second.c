// ChatGPT version 2.0 of code
// suggested****

// SEEK_CUR is a constant defined in the stdio.h header file. It is one of three possible values that can be passed to the whence parameter of the fseek() function.

// fseek(fp, -1, SEEK_CUR) seeks to the current position of the file pointer, and then moves it back by one character position. This is done so that the next call to fputc() overwrites the lowercase character that was just read from the file with its uppercase equivalent.

#include <stdio.h>

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
        if (c >= 'a' && c <= 'z')
        {
            fseek(fp, -1, SEEK_CUR);
            fputc(c - 'a' + 'A', fp);
        }
    }

    fclose(fp);
    return 0;
}

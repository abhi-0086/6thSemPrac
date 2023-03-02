// manual copied code

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *fp, *ft;
    char ch;
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./a.out file name\n");
        exit(1);
    }
    fp = fopen(argv[1], "r");
    if (fp == NULL)
    {
        printf("can't open file");
        exit(1);
    }
    ft = fopen("temp", "w");
    while ((ch = fgetc(fp)) != EOF)
    {
        if (ch >= 97 && ch <= 122)
            ch = ch + 'A' - 'a';
        fputc(ch, ft);
    }
    fclose(ft);
    fclose(fp);
    ft = fopen("temp", "r");
    fp = fopen(argv[1], "w");
    if (ft != NULL)
    {
        while (!feof(ft))
        {
            ch = fgetc(ft);
            fputc(ch, fp);
        }
        fclose(ft);
        fclose(fp);
    }
    else
        printf("Error in opening file");
}
// ChatGPT version 2.0 of code
// suggested****

// SEEK_CUR is a constant defined in the stdio.h header file. It is one of three possible values that can be passed to the whence parameter of the fseek() function.

// fseek(fp, -1, SEEK_CUR) seeks to the current position of the file pointer, and then moves it back by one character position. This is done so that the next call to fputc() overwrites the lowercase character that was just read from the file with its uppercase equivalent.

#include <stdio.h>
int main(int argc, char *argv[])
{
    // Check if the program is run with the correct number of arguments
    if (argc != 2)
    {
        // Print an error message to standard error output (stderr)
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        // Return an error code (-1) to indicate that the program did not run successfully
        return -1;
    }
    // Open the file given as the argument in read/write mode
    FILE *fp = fopen(argv[1], "r+");
    // Check if the file was successfully opened
    if (fp == NULL)
    {
        // Print an error message, including a description of the error that occurred
        perror("Error opening file");
        // Return an error code (-1) to indicate that the program did not run successfully
        return -1;
    }
    int c;
    // Read each character in the file until the end of the file is reached (EOF)
    while ((c = fgetc(fp)) != EOF)
    {
        // Check if the character is a lowercase letter
        if (c >= 'a' && c <= 'z')
        {
            // Move the file pointer back one position to overwrite the lowercase letter
            fseek(fp, -1, SEEK_CUR);
            // Write the uppercase version of the letter to the file
            fputc(c - 'a' + 'A', fp);
        }
    }
    fclose(fp);
    return 0;
}

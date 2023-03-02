// Write a program to display a file page wise assuming a page has 10 lines and each line
// has 80 characters

#include <stdio.h>
#include <stdlib.h>
// header files that include standard input/output and standard library functions.
int main(int argc, char *argv[])
// main function that takes two arguments, an integer argument `argc` that indicates the number of command line arguments and a pointer to an array of character pointers `argv` that stores the command line arguments.
{
    char buff[10][80];
    // 2D character array called `buff` that can hold 10 lines of text, with each line having a maximum length of 80 characters.

    int i, j;
    // two integer variables used as loop counters in later parts of the program.

    char k;
    // character variable used to pause the program after printing each ten lines of text and wait for the user to press a key before continuing.

    FILE *fp;
    // pointer to a file stream that will be used to read data from a file.
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./a.out file name\n");
        exit(1);
    }
    // This `if` statement checks whether the program was run with exactly one command line argument, which should be the name of a file to read. If the program was run with the wrong number of arguments, an error message is printed to `stderr` and the program exits with a non-zero status code.

    fp = fopen(argv[1], "r");
    // This line opens the file specified by the first command line argument for reading using `fopen()`. The `fopen()` function returns a pointer to a file stream that is stored in the `fp` variable.

    while (!feof(fp))
    // loop that will continue reading lines from the file until the end of the file is reached, as determined by the `feof()` function.
    {
        for (i = 0; i < 10; i++)
            for (j = 0; j < 80; j++)
                buff[i][j] = '\0';
        // This loop sets each element of the `buff` array to the null character to clear out any data from the previous loop iteration.

        for (i = 0; i < 10; i++)
            fgets(buff[i], 80, fp);
        // This loop reads ten lines of text from the file using `fgets()` and stores each line in a row of the buff array.

        for (i = 0; i < 10; i++)
            printf("%s", buff[i]);
        // This loop prints out the ten lines of text that were just read from the file using `printf()`.

        scanf("%c", &k);
        // This line waits for the user to press a key before continuing, using `scanf()` to read a single character into the `k` variable.
    }
    fclose(fp); // closes the file stream using `fclose()`
    return 0;   // exit from the program by returning 0 as the exit status code
}
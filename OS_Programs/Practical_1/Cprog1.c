// ChatGPT version of code

// Write a program to display a file page wise assuming a page has 10 lines and each line
// has 80 characters

#include <stdio.h>
#define MAX_LINE_LEN 80       // Define a constant for maximum line length
#define MAX_LINES_PER_PAGE 10 // Define a constant for maximum number of lines per page

int main(int argc, char *argv[])
{
    if (argc != 2)
    { // Check if the user has provided a filename argument
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    FILE *fp = fopen(argv[1], "r"); // Open the file for reading
    if (fp == NULL)
    { // Check if the file was opened successfully
        fprintf(stderr, "Error: could not open file %s\n", argv[1]);
        return 1;
    }
    char line[MAX_LINE_LEN]; // Define a buffer for reading each line of the file
    int line_count = 0;      // Keep track of the number of lines printed so far
    while (fgets(line, MAX_LINE_LEN, fp) != NULL)
    {                         // Read each line of the file
        printf("%s\n", line); // Print the line to the console
        line_count++;         // Increment the line count
        if (line_count >= MAX_LINES_PER_PAGE)
        { // Check if we've printed enough lines for the current page
            printf("\nPress ENTER to continue...\n");
            getchar();      // Wait for the user to press ENTER
            line_count = 0; // Reset the line count for the next page
        }
    }
    fclose(fp); // Close the file
    return 0;   // Exit the program
}

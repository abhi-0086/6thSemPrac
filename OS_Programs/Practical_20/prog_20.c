#include <limits.h>
#include <stdio.h>
#include <unistd.h>

// Define PATH_MAX to be 255 if it is not already defined
#ifndef PATH_MAX
#define PATH_MAX 255
#endif

int main(void)
{
    char mycwd[PATH_MAX];
    // Get the current working directory and store it in mycwd array
    if (getcwd(mycwd, PATH_MAX) == NULL)
    {
        perror("Failed to get current working directory"); // Print error message if getcwd fails
        return 1; // Exit the program with error code
    }
    // Print the current working directory
    printf("Current working directory: %s\n", mycwd);
    return 0; // Exit the program
}

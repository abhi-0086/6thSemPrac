#include <stdio.h>
#include <stdlib.h>
// not working in windows, works in linux
int main() {
    FILE *fp; // Declare file pointer
    char buffer[1024]; // Declare buffer for reading from the pipe

    // Open the pipe
    fp = popen("ls -l | sort -n +4", "r"); // Open the pipe using popen() and specify the command to be executed
    if (fp == NULL) { // If the pipe cannot be opened, print an error message and exit with an error code
        printf("Failed to open pipe.\n"); // Note that the command will not be executed if the pipe cannot be opened
        return -1; // Exit with error code
    }

    // Read the output of the pipe
    while (fgets(buffer, sizeof(buffer), fp) != NULL) { // Read the output of the pipe using fgets() and print it to the screen
        printf("%s", buffer); // Note that fgets() will return NULL when the pipe is closed
    }

    // Close the pipe
    pclose(fp);
    return 0; // Exit with success code
}
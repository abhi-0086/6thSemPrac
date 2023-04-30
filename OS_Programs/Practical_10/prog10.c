// Importing necessary libraries
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// The main function
int main (int argc, char *argv[])
{
    // Declare variables
    pid_t childpid = 0; // process ID variable
    int i, n; // loop variables

    // Check for valid number of command-line arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: %s processes\n", argv[0]); // print error message
        return 1; // return error status code
    }

    n = atoi(argv[1]); // convert the command-line argument to an integer

    // Create child processes
    for (i = 1; i < n; i++) {
        if (childpid = fork()) // create a new process using fork()
            break; // break out of the loop if it is a child process
    }

    // Print process information for each process
    fprintf(stderr, "i:%d process ID:%ld parent ID:%ld child ID:%ld\n",
        i, (long)getpid(), (long)getppid(), (long)childpid);

    return 0; // return success status code
}

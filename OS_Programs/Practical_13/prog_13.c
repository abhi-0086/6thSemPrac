#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    // Declare a variable to store the process ID of the child process
    pid_t childpid;

    // Call fork() to create a new child process
    childpid = fork();

    // Check if fork() failed and print an error message if it did
    if (childpid == -1)
    {
        perror("Failed to fork");
        return 1;
    }

    // If fork() returns 0, the current process is the child process
    if (childpid == 0)
    {
        // Execute the "ls -l" command in the child process using execl()
        execl("/bin/ls", "ls", "-l", NULL); // man 2 exec

        // If execl() returns, there was an error, so print an error message and return failure
        perror("Child failed to exec ls");
        return 1;
    }

    // If fork() returns a positive value, the current process is the parent process
    // Wait for the child process to complete using wait() and check for errors
    if (childpid != wait(NULL))
    {
        perror("Parent failed to wait due to signal or error");
        return 1;
    }

    // Return success if everything completed without error
    return 0;
}
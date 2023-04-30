#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(void) {
    pid_t childpid; // declare variable to store child process ID

    childpid = fork(); // create child process and store its ID in childpid

    if (childpid == -1) { // check if fork() failed
        perror("Failed to fork"); // print error message
        return 1; // exit with error status
    }

    if (childpid == 0) { // code for child process
        printf("I am child %ld\n", (long)getpid()); // print child process ID
    } else { // code for parent process
        printf("I am parent %ld\n", (long)getpid()); // print parent process ID
    }

    return 0; // exit program
}

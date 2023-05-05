#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    pid_t pid; // declare a variable to store the process ID returned by fork()

    pid = fork(); // create a child process and store the process ID in the pid variable

    if (pid < 0) { // check if fork() failed
        fprintf(stderr, "Fork failed\n");
        exit(1);
    }
    if (pid == 0) { // code for child process
        printf("\nI am the child process, my pid is %d\n", getpid());
         exit(0); //terminate the child process
    } 
    else { // code for parent process
        printf("I am the parent process, my pid is %d", getpid());
    }

    return 0;
}

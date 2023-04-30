#include <stdio.h>      //include standard input/output library
#include <stdlib.h>     //include standard library for functions such as atoi()
#include <unistd.h>     //include library for functions such as fork()

int main(int argc, char *argv[]) {  //start of main function, takes command line arguments as inputs
    pid_t childpid = 0;     //declare and initialize process ID variable for child process
    int i, n;               //declare variables for loop iteration and number of processes
    if (argc != 2) {        //check if there is only one command line argument
        fprintf(stderr, "Usage: %s processes\n", argv[0]);  //print error message to stderr
        return 1;           //exit program with error status
    }
    n = atoi(argv[1]);      //convert command line argument to integer and assign to variable n
    for (i = 1; i <= n; i++) {   //iterate through loop until i is equal to n
        if ((childpid = fork()) <= 0) {  //if fork() returns a value less than or equal to 0, break out of loop
            break;
        }
        fprintf(stderr, "i:%d process ID:%ld parent ID:%ld child ID:%ld\n",   //print process information to stderr
            i, (long)getpid(), (long)getppid(), (long)childpid);
    }
    return 0;   //exit program with success status
}

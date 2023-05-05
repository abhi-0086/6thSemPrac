#include <stdio.h>      //include standard input/output library
#include <stdlib.h>     //include standard library for functions such as atoi()
#include <unistd.h>     //include library for functions such as fork()
#include<sys/types.h>
int main(int argc, char *argv[]) {  //start of main function, takes command line arguments as inputs
    //declare and initialize process ID variable for child process
    pid_t childpid = 0;  
    //declare variables for loop iteration and number of processes   
    int i, n; 
    //check if there is only one command line argument    
    if (argc != 2) {        
        fprintf(stderr, "Usage: %s processes\n", argv[0]);  //print error message to stderr
        return 1;           //exit program with error status
    }
     //convert command line argument to integer and assign to variable n
    n = atoi(argv[1]);     
    for (i = 1; i <= n; i++) {   //iterate through loop until i is equal to n
    //if fork() returns a value less than or equal to 0, break out of loop
        if ((childpid = fork()) <= 0) {  
            break;
        }
        //print process information to stderr
        fprintf(stderr, "i:%d process ID:%ld parent ID:%ld child ID:%ld\n",   
            i, (long)getpid(), (long)getppid(), (long)childpid);
    }
    return 0;   //exit program with success status
}

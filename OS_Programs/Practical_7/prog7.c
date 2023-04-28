#include<stdio.h> // Including the standard input/output library header file
#include <unistd.h> // Including the POSIX library header file

int main (void) // Beginning of the main function
{
    printf("I am process %ld\n", (long)getpid()); // Printing the process ID of the current process
    printf("My parent is %ld\n", (long)getppid()); // Printing the parent process ID of the current process
    return 0; // Returning 0 to indicate successful termination of the program
}

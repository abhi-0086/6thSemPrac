#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<fcntl.h>
#include<sys/stat.h>

// Main function takes two arguments, argc (argument count) and argv (argument vector)
main(int argc, char *argv[])
{
    // Check if the argument count is not equal to 2
    if(argc!=2)
    {
        fprintf(stderr,"Too Less Arguments"); // Print error message for incorrect usage
        exit(1); // Exit the program with error code
    }
    
    // Remove the directory with the specified name
    if(remove(argv[1])!=0)
        fprintf(stderr,"Error in Removing Directory"); // Print error message if the directory removal fails
    exit(1); // Exit the program with error code
}

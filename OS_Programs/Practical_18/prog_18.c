#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>

// Main function takes two arguments, argc (argument count) and argv (argument vector)
main(int argc, char *argv[])
{
    // Check if the argument count is not equal to 2
    if(argc!=2)
    {
        printf("Usages: ./a.out directory"); // Print error message for incorrect usage
        exit(1); // Exit the program with error code
    }
    
    // Create a directory with the specified name and access permissions
    if(mkdir(argv[1],744)!=0)
        printf("Error in Making Directory"); // Print error message if the directory creation fails
}

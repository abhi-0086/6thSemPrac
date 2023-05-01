/*Program to create a file using dup fun (redirect output to some
existing file.)*/

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<fcntl.h>
#include<sys/stat.h>
#include <unistd.h>

int main()
{
    int fd;
    // Open the file "test1" for writing or create it if it doesn't exist
    if((fd = open("test1", O_WRONLY|O_CREAT)) < 0)
    {
        printf("Error in opening file..\n");
        exit(1);
    }
    // Close standard output (file descriptor 1) to redirect the output
    close(1);
    // Duplicate file descriptor fd to 1 (stdout)
    dup(fd);
    // The next line will be written to the file "test1" instead of the console
    printf("New Fun");
    // Close the file descriptor fd and standard output
    close(fd);
    return (0);
}

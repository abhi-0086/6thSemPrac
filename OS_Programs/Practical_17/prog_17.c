#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

#define CREATE_FLAGS (O_WRONLY | O_CREAT | O_APPEND) // Define flags for file creation
#define CREATE_MODE (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH) // Define access permissions for the file

int main(void)
{
    int fd; // file descriptor

    // Open or create file "my.file" with the flags and mode specified
    fd = open("my.file", CREATE_FLAGS, CREATE_MODE);
    if (fd == -1)
    {
        perror("Failed to open my.file"); // Print error message if failed to open the file
        return 1; // Exit program with error code
    }

    // Duplicate the file descriptor to the standard output file descriptor
    if (dup2(fd, STDOUT_FILENO) == -1) //dup2
    {
        perror("Failed to redirect standard output"); // Print error message if failed to redirect standard output
        return 1; // Exit program with error code
    }

    // Close the file descriptor that was duplicated
    if (close(fd) == -1)
    {
        perror("Failed to close the file"); // Print error message if failed to close the file
        return 1; // Exit program with error code
    }

    // Write "OK" to the standard output file descriptor
    if (write(STDOUT_FILENO, "OK", 2) == -1)
    {
        perror("Failed in writing to file"); // Print error message if failed to write to file
        return 1; // Exit program with error code
    }

    return 0; // Exit program with success code
}

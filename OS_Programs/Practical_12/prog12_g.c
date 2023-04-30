#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>


int main() {
    int fd;         // file descriptor for the opened file
    pid_t pid;      // process ID variable

    // open file in write mode, create it if it doesn't exist, with permissions 0644
    fd = open("file.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) {   // check if file was successfully opened
        perror("Error opening file");   // display error message if open() failed
        exit(1);    // exit the program with status code 1
    }

    // fork a child process
    pid = fork();   // create a copy of the current process
    if (pid < 0) {  // check if fork() failed
        perror("Error forking process");    // display error message if fork() failed
        exit(1);    // exit the program with status code 1
    }
    else if (pid == 0) {    // child process
        // write to the opened file using the file descriptor fd
        char *str = "This is the child process.\n";
        write(fd, str, strlen(str));   // write string to file
        printf("Child process wrote to file.\n");
    }
    else {  // parent process
        // write to the opened file using the file descriptor fd
        char *str = "This is the parent process.\n";
        write(fd, str, strlen(str));   // write string to file
        printf("Parent process wrote to file.\n");
    }

    // close file descriptor
    close(fd);  // close the file

    return 0;   // exit the program with status code 0 (success)
}

    
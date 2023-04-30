#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    // Declare file pointer and file descriptor variables
    FILE *fp;
    int fd;
    // Declare a character variable for reading file
    char ch;

    // Open a file named "test" in write mode and write a line to it
    fp=fopen("test","w");
    fprintf(fp,"%s\n","This line is written by PARENT PROCESS");
    fflush(NULL); // Flushes all open output streams

    // Create a child process by calling fork()
    fd=fork();
    if(fd < 0) {
        // If fork() fails, print an error message and exit with code 1
        printf("Fork Error");
        exit(1);
    }
    if(fd == 0) { // Child process code
        // Write a line to the file using the file pointer
        fprintf(fp,"%s","This line is written by CHILD PROCESS\n");
        fclose(fp); // Close the file pointer
        fp=fopen("test","r"); // Open the file in read mode
        // Read the file character by character and print it to the console
        while(!feof(fp)) {
            printf("%c",getc(fp));
        }
    }
    if(fd > 0) { // Parent process code
        // Wait for the child process to complete and check for any errors
        if (fd != wait(NULL)) {
            perror("Parent failed to wait due to signal or error");
            return 1;
        }
    }
    // Close the file pointer and return 0 to indicate success
    fclose(fp);
    return 0;
}

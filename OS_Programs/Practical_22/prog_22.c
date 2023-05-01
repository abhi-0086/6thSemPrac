#include <stdio.h>
#include <time.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {

    struct stat statbuf; // Struct to hold file/directory information
    // Attempt to get status information for the specified file/directory
    if (stat(argv[1], &statbuf) == -1) {
        perror ("Failed to get status of file/directory"); // Print error message if failed
        return 1;
    }
    else {
        // If successful, determine if the specified path is a directory or a file using S_ISDIR macro
        if (S_ISDIR(statbuf.st_mode)) {
            printf("%s : is a directory\n",argv[1]);
        }
        else {
            printf("%s : is a file\n",argv[1]);
        }
    }
    return 0;
}

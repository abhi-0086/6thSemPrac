#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<fcntl.h>
#include<sys/stat.h>

main(int argc, char *argv[]) {

    struct stat statbuff; // Struct to hold file/directory information
    int check; // Return value of stat() function

    if(argc != 2) {
        printf("Can accept only two arguments"); // Print error message if incorrect number of arguments is passed
        exit(1);
    }

    // Get status information for the specified file/directory using stat() function
    check = stat(argv[1], &statbuff);

    // Check if stat() was successful
    if(check == 0) {
        // Determine the type of the specified file/directory using S_IS* macros
        if(S_ISREG(statbuff.st_mode)) {
            printf("Regular File");
        }
        else if(S_ISDIR(statbuff.st_mode)) {
            printf("Directory");
        }
        else if(S_ISCHR(statbuff.st_mode)) {
            printf("Character Device");
        }
        else {
            printf("Other File");
        }
    }
}

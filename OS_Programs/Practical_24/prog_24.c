#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<fcntl.h>
#include<sys/stat.h>

int main(int argc, char *argv[]) {

    struct stat statbuff; // Struct to hold file/directory information
    int check; // Return value of stat() function

    if(argc != 2) {
        printf("Can Accept only two arguments"); // Print error message if incorrect number of arguments is passed
        exit(1);
    }

    // Get status information for the specified file/directory using stat() function
    check = stat(argv[1], &statbuff);

    // Check if stat() was successful
    if(check == 0) {
        // Check permission for Owner
        if((statbuff.st_mode & S_IRUSR) == S_IRUSR) {
            printf("Owner has Read Permission\n");
        }
        if((statbuff.st_mode & S_IWUSR) == S_IWUSR) {
            printf("Owner has Write Permission\n");
        }
        if((statbuff.st_mode & S_IXUSR) == S_IXUSR) {
            printf("Owner has Execute Permission\n");
        }

        // Check permission for Group
        if((statbuff.st_mode & S_IRGRP) == S_IRGRP) {
            printf("Group has Read Permission\n");
        }
        if((statbuff.st_mode & S_IWGRP) == S_IWGRP) {
            printf("Group has Write Permission\n");
        }
        if((statbuff.st_mode & S_IXGRP) == S_IXGRP) {
            printf("Group has Execute Permission\n");
        }

        // Check permission for Others
        if((statbuff.st_mode & S_IROTH) == S_IROTH) {
            printf("Others has Read Permission\n");
        }
        if((statbuff.st_mode & S_IWOTH) == S_IWOTH) {
            printf("Others has Write Permission\n");
        }
        if((statbuff.st_mode & S_IXOTH) == S_IXOTH) {
            printf("Others has Executed Permission\n");
        }
    }
}

    #include <dirent.h>
    #include <errno.h>
    #include <stdio.h>

    int main(int argc, char *argv[]) {

        struct dirent *direntp; // Pointer to directory entry
        DIR *dirp; // Pointer to directory stream

        // Check if the correct number of arguments has been passed
        if (argc != 2) {
            fprintf(stderr, "Usage: %s directory_name\n", argv[0]);
            return 1;
        }
        // Attempt to open the specified directory
        if ((dirp = opendir(argv[1])) == NULL) {
            perror ("Failed to open directory"); // Print error message if failed
            return 1;
        }
        // Read and print each directory entry
        while ((direntp = readdir(dirp)) != NULL) {
            printf("%s\n", direntp->d_name);
        }
        // Close the directory stream and check for errors
        while ((closedir(dirp) == -1) && (errno == EINTR)) ;

        return 0;
    }

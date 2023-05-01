// Function to copy a file fromfd to tofd
#include <errno.h>
#include <unistd.h>
#define BLKSIZE 1024

int copyfile(int fromfd, int tofd) {
    char *bp;
    char buf[BLKSIZE];
    int bytesread;
    int byteswritten = 0;
    int totalbytes = 0;

    for (;;) {  // Infinite loop until end of file or error occurs
        // Read up to BLKSIZE bytes from fromfd
        while (((bytesread = read(fromfd, buf, BLKSIZE)) == -1) &&
               (errno == EINTR)) ;  // Handle interruption by signal

        if (bytesread <= 0)  // Real error or end-of-file on fromfd
            break;

        bp = buf;
        while (bytesread > 0) {
            // Write up to bytesread bytes to tofd
            while (((byteswritten = write(tofd, bp, bytesread)) == -1) &&
                   (errno == EINTR)) ;  // Handle interruption by signal

            if (byteswritten < 0)  // Real error on tofd
                break;

            totalbytes += byteswritten;
            bytesread -= byteswritten;
            bp += byteswritten;
        }

        if (byteswritten == -1)  // Real error on tofd
            break;
    }

    return totalbytes;
}

// Main program to copy a file
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#define READ_FLAGS O_RDONLY
#define WRITE_FLAGS (O_WRONLY | O_CREAT | O_EXCL)
#define WRITE_PERMS (S_IRUSR | S_IWUSR)

int main(int argc, char *argv[]) {
    int bytes;
    int fromfd, tofd;

    // Check for correct number of arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s from_file to_file\n", argv[0]);
        return 1;
    }

    // Open input file for reading
    if ((fromfd = open(argv[1], READ_FLAGS)) == -1) {
        perror("Failed to open input file");
        return 1;
    }

    // Create output file for writing
    if ((tofd = open(argv[2], WRITE_FLAGS, WRITE_PERMS)) == -1) {
        perror("Failed to create output file");
        return 1;
    }

    // Copy the contents of the input file to the output file
    bytes = copyfile(fromfd, tofd);

    // Print the number of bytes copied and the source and destination file names
    printf("%d bytes copied from %s to %s\n", bytes, argv[1], argv[2]);

    // Close the input and output files
    return 0;
}

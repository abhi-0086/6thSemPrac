#include <stdio.h>

int main(int argc, char *argv[]) {
    FILE *fromFile, *toFile;
    char ch;
    int bytes = 0;

    // Check for correct number of arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s from_file to_file\n", argv[0]);
        return 1;
    }

    // Open input file for reading
    if ((fromFile = fopen(argv[1], "rb")) == NULL) {
        perror("Failed to open input file");
        return 1;
    }

    // Open output file for writing
    if ((toFile = fopen(argv[2], "wb")) == NULL) {
        perror("Failed to create output file");
        return 1;
    }

    // Copy the contents of the input file to the output file
    while ((ch = fgetc(fromFile)) != EOF) {
        fputc(ch, toFile);
        bytes++;
    }

    // Print the number of bytes copied and the source and destination file names
    printf("%d bytes copied from %s to %s\n", bytes, argv[1], argv[2]);

    // Close the input and output files
    fclose(fromFile);
    fclose(toFile);

    return 0;
}
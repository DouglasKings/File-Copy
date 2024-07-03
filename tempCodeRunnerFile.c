#include <stdio.h>
#include <stdlib.h>

// Function prototype for the main function
int main(int argc, char *argv[]);

int main(int argc, char *argv[]) {
    // Check if the correct number of arguments are passed
    if (argc != 3) {
        printf("Usage: %s <source_file> <destination_file>\n", argv[0]);
        exit(1); // Exit the program with an error code
    }

    FILE *srcFile = fopen(argv[1], "rb"); // Open source file in binary mode for reading
    if (!srcFile) {
        perror("Error opening source file");
        exit(1);
    }

    FILE *destFile = fopen(argv[2], "wb"); // Open destination file in binary mode for writing
    if (!destFile) {
        perror("Error opening destination file");
        fclose(srcFile); // Close the source file if opening the destination fails
        exit(1);
    }

    // Read from source file and write to destination file
    char buffer[1024]; // Buffer to hold data read from source file
    size_t bytesRead;
    while ((bytesRead = fread(buffer, sizeof(char), sizeof(buffer), srcFile)) > 0) {
        fwrite(buffer, sizeof(char), bytesRead, destFile);
    }

    // Close both files after copying is done
    fclose(srcFile);
    fclose(destFile);

    return 0; // Successful execution
}
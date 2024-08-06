#include <stdio.h>
#include <stdlib.h>

#define MAX_INPUT_SIZE 100

int main() {
    char input[MAX_INPUT_SIZE];
    FILE *file;

    // Open the file for writing
    file = fopen("output.txt", "w");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Prompt the user for input
    printf("Enter some text (max %d characters): ", MAX_INPUT_SIZE - 1);
    if (fgets(input, MAX_INPUT_SIZE, stdin) == NULL) {
        perror("Error reading input");
        fclose(file);
        return 1;
    }

    // Write the input to the file
    fprintf(file, "%s", input);

    // Close the file
    fclose(file);

    printf("Input saved to 'output.txt'.\n");

    return 0;
}

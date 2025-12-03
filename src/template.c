#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 256

int main(int argc, char *argv[]) {
    FILE *file;
    char line[MAX_LINE];

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Could not open file %s\n", argv[1]);
        return 1;
    }

    while (fgets(line, sizeof(line), file) != NULL) {
        line[strcspn(line, "\n")] = 0;
        printf("Read: %s\n", line);
    }

    fclose(file);
    return 0;
}

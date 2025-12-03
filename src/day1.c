#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 256

int main(int argc, char *argv[]) {
    FILE *file;
    char line[MAX_LINE];
    int position = 50;
    int p1count = 0;
    int p2count = 0;

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

        char direction = line[0];
        int distance = atoi(&line[1]);
        int n = atoi(&line[1]);

        if (direction == 'L') {
            while (distance > 0) {
                distance--;
                position--;

                if (position % 100 == 0) {
                    p2count++;
                }
            }
        } else if (direction == 'R') {
            while (distance > 0) {
                distance--;
                position++;

                if (position % 100 == 0) {
                    p2count++;
                }
            }
        }

        if (position % 100 == 0) {
            p1count++;
        }

        printf("Rotated %c%d -> position: %d\n", direction, n, position);
    }

    fclose(file);

    printf("\nPassword 1: %d\n", p1count);
    printf("\nPassword 2: %d\n", p2count);
    return 0;
}

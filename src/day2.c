#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 512

int is_repeating(const char *str) {
    int len = strlen(str);
    for (int nparts = 2; nparts < 3; nparts++) {
        if (strlen(str) % nparts != 0) {
            return 0;
        }

        int partlength = len / nparts;

        for (int position = 0; position < partlength; position++) {
            if (str[position] != str[position + partlength]) {
                return 0;
            }
        }
    }
    return 1;
}

int main(int argc, char *argv[]) {
    FILE *file;
    char line[MAX_LINE];
    long c = 0;
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
        char *token = strtok(line, ",");
        while (token != NULL) {
            long start, end;
            sscanf(token, "%ld-%ld", &start, &end);

            for (long i = start; i < end + 1; i++) {
                char num_str[20];
                sprintf(num_str, "%ld", i);
                if (is_repeating(num_str)) {
                    c += i;
                }
            }

            token = strtok(NULL, ",");
        }
    }
    printf("result: %ld\n", c);

    fclose(file);
    return 0;
}

# Advent of Code in C

Solving Advent of Code 2025 puzzles in C.

## Prerequisites

Arch Linux: You should have `gcc` already. If not: `pacman -S base-devel`

Also recommended: Install the C/C++ extension in your editor

## Quick Start

### 1. Create a new solution

```bash
cp src/template.c src/day2.c
```

### 2. Add input files

Download from adventofcode.com:
- Test input → `input/dayX_test.txt`
- Real input → `input/dayX.txt`

### 3. Edit and implement

Edit `src/dayX.c` with your solution.

### 4. Build and test

```bash
make test-dayX    # Test with test input
make run-dayX     # Run with real input
make              # Compile all solutions
make clean        # Remove binaries
```

## C Basics for Advent of Code

### Reading from a file

```c
FILE *file = fopen("input.txt", "r");
char line[256];
while (fgets(line, sizeof(line), file) != NULL) {
    // Process each line
}
fclose(file);
```

### Parsing integers

```c
int num = atoi("123");              // string to int
int num = strtol("456", NULL, 10);  // alternative, safer
```

### String manipulation

```c
#include <string.h>

strlen(str);           // length
strcpy(dest, src);     // copy
strcmp(str1, str2);    // compare (-1, 0, 1)
strchr(str, 'c');      // find char
strtok(str, " ");      // split by delimiter
```

### Dynamic memory

```c
#include <stdlib.h>

int *arr = malloc(10 * sizeof(int));
arr[0] = 5;
free(arr);  // Always free!
```

### Common patterns

```c
// Read numbers from a file
FILE *f = fopen("input.txt", "r");
int num;
while (fscanf(f, "%d", &num) == 1) {
    // Process num
}
fclose(f);

// Sum array
int sum = 0;
for (int i = 0; i < size; i++) {
    sum += arr[i];
}

// Find max
int max = arr[0];
for (int i = 1; i < size; i++) {
    if (arr[i] > max) max = arr[i];
}
```

## Tips

1. **Memory leaks**: Always `free()` memory you allocate with `malloc()`
2. **Buffer overflows**: Be careful with fixed-size buffers
3. **Compilation warnings**: Don't ignore them - they often indicate bugs
4. **Test early**: Write and test incrementally
5. **Debug output**: Use `fprintf(stderr, ...)` to keep stdout clean

## Resources

- [C Standard Library Reference](https://en.cppreference.com/w/c)
- [GCC Manual](https://gcc.gnu.org/onlinedocs/)
- [Valgrind](https://valgrind.org/) - Memory debugging
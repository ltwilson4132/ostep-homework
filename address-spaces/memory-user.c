#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MEGABYTE 1048576

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <megabytes>\n", argv[0]);
        return 1;
    }

    int num_megabytes = atoi(argv[1]);
    int num_entries = num_megabytes * MEGABYTE / sizeof(int);

    int *array = malloc(num_entries * sizeof(int));
    if (!array) {
        printf("Error: unable to allocate %d MB of memory\n", num_megabytes);
        return 1;
    }

    printf("Allocated %d MB of memory\n", num_megabytes);

    srand(time(NULL));
    int i, sum = 0;

    while (1) {
        for (i = 0; i < num_entries; i++) {
            array[i] = rand();
            sum += array[i];
        }
    }

    return 0;
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "my_algos.h"
#include "utils.h"

#define MAX_ARRAY_SIZE 10000

void bubble_random_arrays(int size) {
    double total_time = 0.0;
    for (int array_iteration = 0; array_iteration < EXPERIMENT_ITER_COUNT; array_iteration++) {
        clock_t begin = clock();

        int * arr = allocate_array(size);
        if (arr == NULL) {
            fprintf(stderr, "Could not initialize array for size %d on iteration %d", size, array_iteration);
            return;
        }
        generate_array_values(arr, size);

        bubble_sort(arr, size);
        free(arr);

        clock_t end = clock();
        double elapsed = (double)(end - begin) / CLOCKS_PER_SEC;
        total_time = total_time + elapsed;
    }

    double avg_time = total_time / 1000;
    printf("Bubble sort execution average time for %d numbers: %lf seconds\n", size, avg_time);
}

void selection_random_arrays(int size) {
    double total_time = 0.0;
    for (int array_iteration = 0; array_iteration < EXPERIMENT_ITER_COUNT; array_iteration++) {
        clock_t begin = clock();

        int * arr = allocate_array(size);
        if (arr == NULL) {
            fprintf(stderr, "Could not initialize array for size %d on iteration %d", size, array_iteration);
            return;
        }
        generate_array_values(arr, size);

        selection_sort(arr, size);
        free(arr);

        clock_t end = clock();
        double elapsed = (double)(end - begin) / CLOCKS_PER_SEC;
        total_time = total_time + elapsed;
    }

    double avg_time = total_time / 1000;
    printf("Selection sort execution average time for %d numbers: %lf seconds\n", size, avg_time);

}

int main() {
    // initialize random number generator
    srand(time(NULL));

    printf("Enter a size for the array: ");
    char buffer[8]; // store in a buffer so that the string of user input can be stripped and converted to an unsigned integer
    scanf("%7s", buffer);

    int size = string_to_int(buffer);

    if (size <= 0 || size >= MAX_ARRAY_SIZE) { // array cannot be empty and the array cannot be larger than the max size for simplicity sake 
        fprintf(stderr, "Invalid size entered.\nMust be positive (unsigned) integer and less than %d\n", MAX_ARRAY_SIZE);
        return EXIT_FAILURE;
    }

    bubble_random_arrays(size);
    selection_random_arrays(size);

    bubble_random_arrays(ITERATION_1);
    bubble_random_arrays(ITERATION_2);
    bubble_random_arrays(ITERATION_3);

    selection_random_arrays(ITERATION_1);
    selection_random_arrays(ITERATION_2);
    selection_random_arrays(ITERATION_3);

    return 0;
}

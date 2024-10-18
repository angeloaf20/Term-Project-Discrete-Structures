#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define EXPERIMENT_ITER_COUNT 1000

#define ITERATION_1 500
#define ITERATION_2 2500
#define ITERATION_3 5000

void swap(int* a, int* b);

void bubble_sort(int* arr, int size);

void selection_sort(int* arr, int size);
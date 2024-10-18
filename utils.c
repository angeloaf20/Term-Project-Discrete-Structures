#include "utils.h"

int string_to_int(const char * num_string) {
    int num = 0;

    for (int i = 0; num_string[i] != '\0'; ++i) {
        if (num_string[i] >= 48 && num_string[i] <= 57) {
            num = num * 10 + (num_string[i] - 48);
        } else {
            return -1;
        }
    }

    return num;
}

int random_int(int min, int max) {
    return rand() % (max + 1 - min)  + min;
}

int* allocate_array(int size) {
    int * arr = (int *)malloc(sizeof(int) * size);

    if (arr == NULL) {
        fprintf(stderr, "Could not allocate memory for array.\n");
        return NULL;
    }

    return arr;
}

void generate_array_values(int* arr, int size) {
    for (int array_index = 0; array_index < size; array_index++) {
        int rand_num = random_int(1, 100);
        arr[array_index] = rand_num;
    }
}

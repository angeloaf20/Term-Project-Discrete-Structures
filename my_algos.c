#include "my_algos.h"

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int* arr, int size) {
   for(int j = size; j > 0; j--) {
       for(int i = 1; i < j; i++) {
         if (arr[i-1] > arr[i])
             swap(&arr[i-1], &arr[i]);
       }
   }
}

void selection_sort(int* arr, int size) {
    int iMin;
    for (int j = 0; j < size; j++){
        iMin = j;

        for (int i = j+1; i < size; i++) {
            if (arr[i] < arr[iMin]) {
                iMin = i;
            }
        }

        if (iMin != j) {
            swap(&arr[j], &arr[iMin]);
        }
    }
}
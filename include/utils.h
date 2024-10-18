#ifndef _UTILS_H_
#define _UTILS_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


int string_to_int(const char * num_string);

int random_int(int min, int max);

int* allocate_array(int size);

void generate_array_values(int* arr, int size);


#endif
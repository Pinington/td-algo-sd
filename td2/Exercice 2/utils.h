#ifndef UTILS_H
#define UTILS_H

#include <stdbool.h>
#include <stdio.h>

void swap_int(int *a, int *b);
bool is_sorted_nondecreasing(int *arr, int n);
void copy_array(int *src, int *dst, int n);
void arrays_equal(int* str, int* oth, int n);

#endif
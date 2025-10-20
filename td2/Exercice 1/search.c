#include <math.h>
#include <stdio.h>
#include "search.h"
#include "utils.h"

int linear_search(int *arr, int n, int target)
{
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) return i;
    }

    return -1;
}

int jump_search(int *arr, int n, int target)
{
    int step = (int)sqrt(n);

    int index = 0;
    int previous = 0;
    while (index < n && arr[index] < target) {
        previous = index;
        index += step;
    }

    for (int i = previous; i < min_int(n, index + 1); i++) {
        if (arr[i] == target) return i;
    }

    return -1;
}

int binary_search(int *arr, int n, int target)
{
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = (right + left) / 2;
        if (arr[mid] > target) {
            right = mid - 1;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            return mid;
        }
    }
    return -1;
}
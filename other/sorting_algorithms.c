#include <stdio.h>
#include <stdlib.h>

int* merge_sort(int* nums, int nums_size) {
    if (nums_size == 1) {
        int* ret = malloc(1 * sizeof(int));
        ret[0] = nums[0];
        return ret;
    }

    int* sorted_list = malloc(nums_size * sizeof(int));
    int half = nums_size / 2;

    int* left_list = merge_sort(nums, half);
    int* right_list = merge_sort(nums + half, nums_size - half);

    int left_value = 0; // Current index of the left list's element
    int right_value = 0;
    int size = 0; // The size of the sorted list

    while (left_value < half && right_value < nums_size - half) {
        if (left_list[left_value] < right_list[right_value]) {
            sorted_list[size++] = left_list[left_value++];
        } else {
            sorted_list[size++] = right_list[right_value++];
        }
    }

    // Copy any remaining elements
    while (left_value < half) {
        sorted_list[size++] = left_list[left_value++];
    }
    while (right_value < nums_size - half) {
        sorted_list[size++] = right_list[right_value++];
    }

    free(left_list);
    free(right_list);
    return sorted_list;
}


int main() {
    int test_list[] = {9, 2, 5, 4, 6, 5, 8};
    int test_list_size = sizeof(test_list) / sizeof(test_list[0]);
    int* sorted = merge_sort(test_list, test_list_size);

    printf("Sorted list: ");
    for (int i = 0; i < test_list_size; i++) {
        printf("%d ", sorted[i]);
    }
    printf("\n");

    free(sorted);
    return 0;
}

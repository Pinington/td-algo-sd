#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h"
#include "utils.h"

int main(void)
{
    // Test case
    int list[] = {1, 4, 2, -9, 0, -18, 23, 6};
    int size = sizeof(list) / sizeof(list[0]);

    clock_t begin, end;
    double time;

    // Selection Sort
    int list_selection[size];
    copy_array(list, list_selection, size);

    begin = clock();
    selection_sort(list_selection, size);
    end = clock();
    time = (double) (end - begin) / CLOCKS_PER_SEC;

    printf("Selection sort time: %lf seconds\n ~Result: ", time);
    print_array(list_selection, size);

    // Insertion sort
    int list_insertion[size];
    copy_array(list, list_insertion, size);

    begin = clock();
    insertion_sort(list_insertion, size);
    end = clock();
    time = (double) (end - begin) / CLOCKS_PER_SEC;

    printf("Insertion sort time: %lf seconds\n ~Result: ", time);
    print_array(list_insertion, size);

    // Bubble sort
    int list_bubble[size];
    copy_array(list, list_bubble, size);

    begin = clock();
    bubble_sort(list_bubble, size);
    end = clock();
    time = (double) (end - begin) / CLOCKS_PER_SEC;

    printf("Bubble sort time: %lf seconds\n ~Result: ", time);
    print_array(list_bubble, size);

    // Merge sort
    int list_merge[size];
    copy_array(list, list_merge, size);

    begin = clock();
    merge_sort(list_merge, size);
    end = clock();
    time = (double) (end - begin) / CLOCKS_PER_SEC;

    printf("Merge sort time: %lf seconds\n ~Result: ", time);
    print_array(list_merge, size);

    // Quick sort
    int list_quick[size];
    copy_array(list, list_quick, size);

    begin = clock();
    quick_sort(list_quick, size);
    end = clock();
    time = (double) (end - begin) / CLOCKS_PER_SEC;

    printf("Quick sort time: %lf seconds\n ~Result: ", time);
    print_array(list_quick, size);

    return 0;
}

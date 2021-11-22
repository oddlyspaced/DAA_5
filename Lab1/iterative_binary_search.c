// Iterative Binary Search

#include <stdio.h>
// #include <unistd.h>

void main() {
    int arr[] = {4, 2, 1, 3, 9, 2, 6, 8, 0, 11};
    int size = 9;
    int low = 0;
    int high = size;
    int value_to_find = 9;
    int mid_index = size / 2;
    while (arr[mid_index] != value_to_find) {
        // printf("L: %d M: %d H: %d\n", low, mid_index, high);
        int mid_value = arr[mid_index];
        if (value_to_find > mid_value) {
            low = mid_index + 1;
        }
        else if (value_to_find < mid_value) {
            high = mid_index - 1;
        }
        mid_index =  (low + high) / 2;
        // sleep(1);
    }
    printf("Value found at: %d", mid_index);
}
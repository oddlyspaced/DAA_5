#include<stdio.h>

void print_arr(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

void main() {
    int arr[] = {3, 5, 4, 7, 2, 8, 10, 1, 11, 0};
    int size = 10;
    print_arr(arr, size);
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                int t = arr[i];
                arr[i] = arr[j];
                arr[j] = t;                                
            }
        }
    }
    print_arr(arr, size);
}
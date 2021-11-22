#include<stdio.h>

void print_arr(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

int main() {
    int size;
    printf("\nEnter array size: ");
    scanf("%d", &size);
    int arr[size];

    printf("\nEnter values: ");
    int i;
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    print_arr(arr, size);
    
    int j;
    for (i = 0; i < size; i++) {
        int min = i;
        for (j = i + 1; j < size; j++) {
            if (arr[min] > arr[j]) {
                min = j;
            }
        }
        // swap
        int t = arr[min];
        arr[min] = arr[i];
        arr[i] = t;
    }

    print_arr(arr, size);

    return 0;
}
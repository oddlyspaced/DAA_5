// Iterative Insertion Sort
// Hardik Srivastava
// 199303069

#include<stdio.h>

void print_arr(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

int main() {
    printf("Enter array size: ");
    int size;
    scanf("%d", &size);

    printf("Enter array: ");    
    int arr[size], i;
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    
    print_arr(arr, size);
    int j, k;

    for (i = 1; i < size; i++) {
        k = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > k) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = k;
    }

    printf("Sorted Array:\n");
    print_arr(arr, size);
    return 0;
}
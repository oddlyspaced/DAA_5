// Recursive Binary Search
// Hardik Srivastava
// 199303069

#include<stdio.h>

// array, low, high, value to find
int search(int arr[], int l, int h, int f) {
    if (l == h) {
        return -1;
    }
    int m = (l + h) / 2;
    if (arr[m] == f) {
        return m;
    }
    else {
        if (arr[m] > f) {
            return search(arr, l, m, f);
        }
        else {
            return search(arr, m + 1, h, f);
        }
    }
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

    printf("Enter value to find: ");
    int value_to_find;
    scanf("%d", &value_to_find);

    int res = search(arr, 0, size - 1, value_to_find);
    if (res == -1) {
        printf("Value not found!");
    }
    else {
        printf("Value found at %d", res);
    }
    return 0;
}
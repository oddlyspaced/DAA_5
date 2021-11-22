#include<stdio.h>

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
            return search(arr, l, m - 1, f);
        }
        else {
            return search(arr, m + 1, h, f);
        }
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    printf("%d", search(arr, 0, 9, 81));
    return 0;
}
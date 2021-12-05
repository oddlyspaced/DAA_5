// Merge Sort
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

void merge_arr(int arr[], int size, int l, int m, int r) {
    // merge arrays
    int size_a = m + 1 - l;
    int size_b = r - m;

    int a[size_a];
    int b[size_b];

    int i, c = 0; // counter c for a and b
    for (i = l; i <= m; i++) { 
        a[c++] = arr[i];
    }
    c = 0;
    for (i = m + 1; i <= r; i++) {
        b[c++] = arr[i];
    }

    // merge algo
    int x = 0, y = 0; // x -> a  y -> b (starting counters)
    c = l;
    while (x < size_a && y < size_b) {
        if (a[x] <= b[y]) {
            arr[c] = a[x++];
        }
        else {
            arr[c] = b[y++];
        }
        c++;
    }

    // copy remaining
    while(x < size_a) {
        arr[c++] = a[x++];
    }
    while (y < size_b) {
        arr[c++] = b[y++];
    }

}

void merge_sort(int arr[], int size, int l, int r) {
    if (l < r) {
        int mid = (l + r) / 2;
        merge_sort(arr, size, l, mid);
        merge_sort(arr, size, mid + 1, r);
        merge_arr(arr, size, l, mid, r);
    }
}

int main() {
    int size;
    printf("\nEnter array size: ");
    scanf("%d", &size);
    printf("\nEnter values: ");
    int arr[size];
    int i;
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    print_arr(arr, size);  
    merge_sort(arr, size, 0, size - 1);
    print_arr(arr, size);  

}
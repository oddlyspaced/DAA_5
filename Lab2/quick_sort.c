// Quick Sort
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

int partition (int arr[], int l, int h) { 
    int pivot = arr[h];
    int i = l - 1;

    for (int j = l; j < h; j++) {
        if (arr[j] < pivot) {
            i++;
            int t = arr[i];
            arr[i] = arr[j];
            arr[j] = t;
        } 
    }
    int t = arr[i + 1];
    arr[i + 1] = arr[h];
    arr[h] = t;
    return i + 1; 
} 
  
void quickSort(int arr[], int l, int h) { 
    if (l < h) {
        int pi = partition(arr, l, h); 
        quickSort(arr, l, pi - 1); 
        quickSort(arr, pi + 1, h); 
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
    quickSort(arr, 0, size - 1);
    print_arr(arr, size);  

}
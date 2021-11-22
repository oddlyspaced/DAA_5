#include<stdio.h>

void print_arr(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n");
} 

int partition (int arr[], int low, int high) { 
    int pivot = arr[high]; // pivot 
    int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far
  
    for (int j = low; j < high; j++) {
        // If current element is smaller than the pivot 
        if (arr[j] < pivot) {
            i++; // increment index of smaller element
            // swap
            int t = arr[i];
            arr[i] = arr[j];
            arr[j] = t;
        } 
    }
    int t = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = t;
    return (i + 1); 
} 
  
/* The main function that implements QuickSort 
arr[] --> Array to be sorted, 
low --> Starting index, 
high --> Ending index */
void quickSort(int arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        /* pi is partitioning index, arr[p] is now 
        at right place */
        int pi = partition(arr, low, high); 
  
        // Separately sort elements before 
        // partition and after partition 
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
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
// Heap Sort
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

// k -> index
void heapify(int arr[], int size, int k) {
    // we consider that largest is root
    int largest = k;
    int l = 2 * k + 1; // 2k + 1
    int r = 2 * k + 2; // 2k + 2

    if (l < size) {
        if (arr[l] > arr[largest]) {
            // left node greater
            largest = l;
        }
    }

    if (r < size) {
        if (arr[r] > arr[largest]) {
            // right node greater
            largest = r;
        }
    }

    if (k != largest) {
        // swap values
        int t = arr[k];
        arr[k] = arr[largest];
        arr[largest] = t;
        
        heapify(arr, size, largest);
    }
}


void heap_sort(int arr[], int size) {
    // create heap
    int i;
    for (i = size / 2 - 1; i >= 0; i--) {
        heapify(arr, size, i);
    }

    for (i = size - 1; i > 0; i--) {
        int t = arr[0];
        arr[0] = arr[i];
        arr[i] = t;

        heapify(arr, i, 0);
    }
}

int main() {
    // int arr[] = {81, 89, 9, 11, 14, 76, 54, 22};
    // int size = 8;

    int size;
    printf("Enter size of array : \n");
    scanf("%d", &size);
    int arr[size];

    printf("Enter values : \n");
    int i;
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    print_arr(arr, size);
    heap_sort(arr, size);
    print_arr(arr, size);
    // make_heap(arr, size);
}
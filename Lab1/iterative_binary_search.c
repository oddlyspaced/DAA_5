// Iterative Binary Search
// Hardik Srivastava
// 199303069

#include <stdio.h>

int main() {
    printf("Enter array size: ");
    int n;
    scanf("%d", &n);

    printf("Enter array: ");    
    int arr[n], i;
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int low = 0;
    int high = n - 1;

    printf("Enter value to find: ");
    int value_to_find;
    scanf("%d", &value_to_find);
    
    int flag = 0;
    int mid_index;

    while (low < high) {
        mid_index =  (low + high) / 2;
        int mid_value = arr[mid_index];

        if (mid_value == value_to_find) {
            flag = 1;
            break;
        }

        if (value_to_find > mid_value) {
            low = mid_index + 1;
        }
        else if (value_to_find < mid_value) {
            high = mid_index;
        }
    }

    if (flag == 1) {
        printf("Value found at: %d", mid_index);
    }
    else {
        printf("Value not found");
    }
    return 0;
}
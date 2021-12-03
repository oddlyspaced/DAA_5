#include<stdio.h>

#define MAX 100

int main() {
    int size = 6;
    // int arr[4][3]={{1,2,3},{2,3,4},{3,4,5},{4,5,6}};     
    int adj[6][6] = {{0, 2, 4, 0, 0, 0}, {0, 0, 1, 7, 0, 0}, {0, 0, 0, 0, 3, 0}, {0, 0, 0, 0, 0, 1}, {0, 0, 0, 2, 0, 5}, {0, 0, 0, 0, 0, 0}};
    int max = 6;
    
    // find smallest dist node
    int current = 0;
    while (current != max - 1) {
        // find first smallest that is not 0
        int smallest = -1;
        int smallest_index = -1;

        int i;
        for (i = 0; i < max; i++) {
            int t = adj[current][i];
            if (t > 0) {
                if (smallest == -1) {
                    smallest_index = i;
                    smallest = t;
                }
                else if (smallest > t) {
                    smallest_index = i;
                    smallest = t;
                }
            }
        }
        printf("sma %d\n", smallest_index + 1);
        current = smallest_index;
    }



    return 0;
}
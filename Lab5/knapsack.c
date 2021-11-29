#include<stdio.h>

int main() {
    int n = 7;
    int profits[] = {10, 5, 15, 7, 6, 18, 3};
    int wts[] = {2, 3, 5, 7, 1, 4, 1};
    float rats[n];
    int size = 15;
    int i;
    for (i = 0; i < n; i++) {
        rats[i] = profits[i]/wts[i];
    }

    float items[n];
    float prof = 0;

    for (i = 0; i < n; i++) {
        items[i] = 0;
    }

    while(size > 0) {
        int max = 0;
        float rat = rats[max];
        for (i = 0; i < n; i++) {
            float t_rat = rats[i];
            if (rat < t_rat) {
                max = i;
                rat = t_rat;
            }
        }
        // found max
        int t_wt = wts[max];
        if (t_wt <= size) {
            items[max] = 1;
            rats[max] = -1;
            prof = prof + profits[max];
        }
        else {
            items[max] = (float)size/t_wt;
        }
        size = size - t_wt;
    }

    printf("\n");
    
    for (i = 0; i < n; i++) {
        printf("%0.5f\t", items[i]);
    }

    printf("\nFinal profit: %f", prof);

    

}
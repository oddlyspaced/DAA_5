#include<stdio.h>

int main() {
    int i;
    int n;
    printf("\nEnter number of items: ");
    scanf("%d", &n);

    printf("\nEnter profits: ");
    int profits[n];
    for (i = 0; i < n; i++) {
        scanf("%d", &profits[i]);
    }

    printf("\nEnter weights: ");
    int wts[n];
    for (i = 0; i < n; i++) {
        scanf("%d", &wts[i]);
    }

    int size;
    printf("\nEnter knapsack limit: ");
    scanf("%d", &size);

    // ratio array
    float rats[n];
    for (i = 0; i < n; i++) {
        rats[i] = profits[i]/wts[i];
    }

    // total calculated profit
    float prof = 0;

    // item ratio
    float items[n];
    for (i = 0; i < n; i++) {
        items[i] = 0;
    }

    while(size > 0) {
        // finding max ratio index
        int max = 0;
        float rat = rats[max];
        for (i = 1; i < n; i++) {
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
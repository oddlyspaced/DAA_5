#include<stdio.h>

#define MAX 9999

// int G[V][V] = {
//   {0, 9, 75, 0, 0},
//   {9, 0, 95, 19, 42},
//   {75, 95, 0, 51, 66},
//   {0, 19, 51, 0, 31},
//   {0, 42, 66, 31, 0}};

int main() {
    int V;
    scanf("%d", &V);

    int G[V][V];
    int i, j;
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            scanf("%d", &G[i][j]);
        }
    }


    int n;
    int selected[V];
    
    for (i = 0; i < V; i++) {
        selected[i] = 0;
    }
    
    // current edge as 0 (starting)
    n = 0;
    selected[0] = 1;
    
    int x, y;
    // one less than total
    while (n < V - 1) {
        int min = MAX;
        x = 0;
        y = 0;
        
        for (int i = 0; i < V; i++) {
            if (selected[i]) {
                for (int j = 0; j < V; j++) {
                    if (!selected[j] && G[i][j]) {  // not in selected and there is an edge
                    if (min > G[i][j]) {
                        min = G[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }
    }
    printf("%d - %d : %d\n", x, y, G[x][y]);
    selected[y] = 1;
    n++;
  }

  return 0;
}
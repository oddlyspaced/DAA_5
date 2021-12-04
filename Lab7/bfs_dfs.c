#include<stdio.h>

#define SIZE 5

int graph[SIZE][SIZE] = {
    {0, 1, 0, 1, 0},
    {0, 0, 1, 0, 1},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
};

void dfs(int node) {
    printf("%d\t", node);
    int i;
    for (i = 0; i < SIZE; i++) {
        if (graph[node][i] == 1) {
            // printf("%d\t", i);
            dfs(i);
        }
    }
}

void bfs(int node) {
    // printf("%d\t", node);
    int i;
    for (i = 0; i < SIZE; i++) {
        if (graph[node][i] == 1) {
            printf("%d\t", i);
        }
    }
    for (i = 0; i < SIZE; i++) {
        if (graph[node][i] == 1) {
            bfs(i);
        }
    }
}

int main() {
    dfs(0);
    printf("\n");
    printf("0\t");
    bfs(0);
}
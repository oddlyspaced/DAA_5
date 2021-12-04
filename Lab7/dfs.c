#include<stdio.h>

int graph[5][5] = {
    {0, 1, 0, 1},
    {0, 0, 1, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
};

void bfs(int node) {
    printf("%d\t", node);
    int i;
    for (i = node; i < 5; i++) {
        if (graph[node][i] == 1) {
            // printf("%d\t", i);
            bfs(i);
        }
    }
}

int main() {
    bfs(0);
}
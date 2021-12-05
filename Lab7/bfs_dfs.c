// BFS DFS
// Hardik Srivastava
// 199303069

#include<stdio.h>

#define V_MAX 99
int V;

int graph[V_MAX][V_MAX];

// int graph[SIZE][SIZE] = {
//     {0, 1, 0, 1, 0},
//     {0, 0, 1, 0, 1},
//     {0, 0, 0, 0, 0},
//     {0, 0, 0, 0, 0},
//     {0, 0, 0, 0, 0},
// };

void dfs(int node) {
    printf("%d\t", node);
    int i;
    for (i = 0; i < V; i++) {
        if (graph[node][i] == 1) {
            dfs(i);
        }
    }
}

void bfs(int node) {
    int i;
    for (i = 0; i < V; i++) {
        if (graph[node][i] == 1) {
            printf("%d\t", i);
        }
    }
    for (i = 0; i < V; i++) {
        if (graph[node][i] == 1) {
            bfs(i);
        }
    }
}

int main() {
    printf("Enter size : ");
    scanf("%d", &V);

    printf("Enter adjacency matrix : ");
    int i, j;
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("DFS : \n");
    dfs(0);

    printf("\nBFS\n");
    printf("0\t");
    bfs(0);
}
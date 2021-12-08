// Djikstra
// Hardik Srivastava
// 199303069

#include <stdio.h>

#define INFINITY 9999
#define MAX 10

void djikstra(int Graph[MAX][MAX], int n, int start) {
    int cost[MAX][MAX], distance[MAX], predecessor[MAX], visited[MAX], count, mindist, nextnode, i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (Graph[i][j] == 0) {
                cost[i][j] = INFINITY;
            }
            else {
                cost[i][j] = Graph[i][j];
            }
        }
    }
    
    for (i = 0; i < n; i++)  {
        distance[i] = cost[start][i];
        predecessor[i] = start;
        visited[i] = 0;
    }
    
    distance[start] = 0;
    visited[start] = 1;
    count = 1;
    while (count < n - 1) {
        mindist = INFINITY;
        for (i = 0; i < n; i++) {
			if (distance[i] < mindist && !visited[i]) {
				mindist = distance[i];
				nextnode = i;
			}
		}
		visited[nextnode] = 1;
    	for (i = 0; i < n; i++) {
			if (!visited[i]) {
        		if (mindist + cost[nextnode][i] < distance[i]) {
					distance[i] = mindist + cost[nextnode][i];
					predecessor[i] = nextnode;
				}
        	}
        }
    	count++;
	}
	for (i = 0; i < n; i++) {
		if (i != start) {
			printf("\nDistance from source to %d: %d\n", i, distance[i]);
			printf("Path = %d", i);
			j=i;
			do {
				j = predecessor[j];
				printf(" <- %d", j);
			} while(j != start);
    	}
    }
}

int main() {
	int Graph[MAX][MAX], i, j, n, u;
	printf("Enter the number of vertices:\n");
	scanf("%d",&n);
	printf("Enter an adjacency matrix: \n");
	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			scanf("%d",&Graph[i][j]);
		}
		printf("\n");
	}
	printf("Enter the starting vertex: \n");
	scanf("%d",&u);
	djikstra(Graph, n, u);
	return 0;
}
// Prims Algo
// Hardik Srivastava
// 199303069

#include <stdio.h>
#define MAX 9999
#define V_MAX 99
int V;

int mincost(int cost[], int visited[]) {
	int min = MAX, index, i;
	for(i = 0; i < V; i++) {
		if(visited[i] == 0 && cost[i] < min) {
			min = cost[i];
			index = i;
		}
	}
	return index;
}

void display(int parent[], int graph[V_MAX][V_MAX]) {
	int i, j, min;
	printf("Edge\t Weight\n");
	for(i = 1; i < V; i++) {
		min = 1;
		for(j = 1; j < V; j++) {
			if(graph[min][parent[min]] > graph[j][parent[j]]) {
				min = j;
			}
		}
		printf("%d - %d\t %d\n", parent[min], min, graph[min][parent[min]]);
		graph[min][parent[min]] = MAX;
	}
}

void prims(int Graph[V_MAX][V_MAX]) {
	int parent[V], cost[V], visited[V], start, i,j;
	for(i = 0 ; i < V; i++) {
		cost[i] = 9999;
		visited[i] = 0;
	}
	cost[0] = 0;
	parent[0] = -1;
	for(i = 0; i < V-1; i++) {
		start = mincost(cost,visited);
		visited[start] = 1;
		for(j = 0; j < V; j++) {
			if(Graph[start][j] != 0 && visited[j] == 0 && Graph[start][j] < cost[j]) {
				parent[j] = start;
				cost[j] = Graph[start][j];
			}
		}
	}
	display(parent, Graph);
}

int main() {
	printf("Enter size:\n");
	scanf("%d", &V);
	int graph[V_MAX][V_MAX];
	int i, j;
	for (i = 0; i < V; i++) {
		for (j = 0; j < V; j++) {
			scanf("%d", &graph[i][j]);
		}
	}
	prims(graph);
	return 0;
}

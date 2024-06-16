#include <stdio.h>
#include <limits.h>
#define MAX_VERTICES 100
int graph[MAX_VERTICES][MAX_VERTICES];
int n;
int minDistance(int dist[], int visited[]) {
    int min = INT_MAX, min_index,v;
    for (v = 0; v < n; v++) {
        if (visited[v] == 0 && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}
void printPath(int parent[], int j) {
    if (parent[j] == -1) {
        printf("%d ", j);
        return;
    }
    printPath(parent, parent[j]);
    printf("%d ", j);
}
void printSolution(int dist[], int parent[], int src) {
	int i;
    printf("Vertex\t Distance\tPath\n");
    for (i = 0; i < n; i++) {
        printf("%d -> %d \t %d\t\t%d ", src, i, dist[i], src);
        printPath(parent, i);
        printf("\n");
    }
}
void dijkstra(int src) {
    int dist[MAX_VERTICES],i,count,v;
    int visited[MAX_VERTICES];
    int parent[MAX_VERTICES];
    for (i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
        parent[i] = -1;
    }
    dist[src] = 0;
    for (count = 0; count < n - 1; count++)
	{
        int u = minDistance(dist, visited);
        visited[u] = 1;
        for (v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }
    printSolution(dist, parent, src);
}
int main() {
	int i,j;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix (use 0 for no edge, and a positive number for edge weights):\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);
    int source;
    printf("Enter the source vertex (0 to %d): ", n - 1);
    scanf("%d", &source);
    dijkstra(source);   
    return 0;
}

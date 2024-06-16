#include <stdio.h>
#include <stdlib.h>
#define MAX 20
void printSolution(int path[], int n)
{
	int i;
    printf("Hamiltonian Cycle: ");
    for (i = 0; i < n; i++)
        printf("%d ", path[i]);
    printf("%d\n", path[0]);
}
int isSafe(int v, int graph[MAX][MAX], int path[], int pos)
{
	int i;
    if (graph[path[pos - 1]][v] == 0)
        return 0;
    for (i = 0; i < pos; i++)
        if (path[i] == v)
            return 0;
    return 1;
}
int hamiltonianCycleUtil(int graph[MAX][MAX], int path[], int pos, int n)
{
	int v;
    if (pos == n)
	{
        if (graph[path[pos - 1]][path[0]] == 1)
            return 1;
        else
            return 0;
    }
    for (v = 1; v < n; v++)
	{
        if (isSafe(v, graph, path, pos))
		{
            path[pos] = v;
            if (hamiltonianCycleUtil(graph, path, pos + 1, n) == 1)
                return 1;
            path[pos] = -1;
        }
    }
    return 0;
}
int hamiltonianCycle(int graph[MAX][MAX], int n)
{
	int i;
    int *path = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
        path[i] = -1;
    path[0] = 0;
    if (hamiltonianCycleUtil(graph, path, 1, n) == 0)
	{
        printf("Solution does not exist\n");
        return 0;
    }
    printSolution(path, n);
    return 1;
}
int main()
{
    int n,i,j;
    int graph[MAX][MAX];
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++)
	{
        for (j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);
    }
    hamiltonianCycle(graph, n);
    return 0;
}

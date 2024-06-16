#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int findMin(int row[], int n) {
    int min = INT_MAX,i;
    for (i = 0; i < n; i++) {
        if (row[i] < min)
            min = row[i];
    }
    return min;
}

void reduceMatrix(int matrix[][100], int n) {
	int i,j;
    for (i = 0; i < n; i++) {
        int rowMin = findMin(matrix[i], n);
        if (rowMin != INT_MAX) {
            for (j = 0; j < n; j++) {
                if (matrix[i][j] != INT_MAX) {
                    matrix[i][j] -= rowMin;
                }
            }
        }
    }
    for (j = 0; j < n; j++) {
        int colMin = INT_MAX;
        for (i = 0; i < n; i++) {
            if (matrix[i][j] < colMin) {
                colMin = matrix[i][j];
            }
        }
        if (colMin != INT_MAX) {
            for (i = 0; i < n; i++) {
                if (matrix[i][j] != INT_MAX) {
                    matrix[i][j] -= colMin;
                }
            }
        }
    }
}

typedef struct {
    int cost;
    int path[100];
    int worker;
} Node;

Node* createNode(int path[], int cost, int worker) {
	int i;
    Node* node = (Node*)malloc(sizeof(Node));
    node->cost = cost;
    for (i = 0; i < 100; i++) {
        node->path[i] = path[i];
    }
    node->worker = worker;
    return node;
}

void printAssignment(int path[], int n, int cost) {
	int i;
    printf("Minimum cost: %d\n", cost);
    printf("Assignment of tasks to workers:\n");
    for (i = 0; i < n; i++) {
        printf("Worker %d assigned to Task %d\n", i, path[i]);
    }
}

void branchAndBound(int costMatrix[][100], int n) {
    int assignment[100] = {-1},i,j;
    int cost = 0;
    int worker = 0;
    Node* queue[10000];
    int front = 0, rear = 0;
    Node* root = createNode(assignment, cost, worker);
    queue[rear++] = root;
    while (front < rear) {
        Node* currentNode = queue[front++];
        if (currentNode->worker == n) {
            printAssignment(currentNode->path, n, currentNode->cost);
            free(currentNode);
            break;
        }
        for (i = 0; i < n; i++) {
            if (currentNode->path[i] == -1) {
                int newCost = currentNode->cost + costMatrix[currentNode->worker][i];
                int newPath[100];
                for (j = 0; j < 100; j++) {
                    newPath[j] = currentNode->path[j];
                }
                newPath[currentNode->worker] = i;
                Node* newNode = createNode(newPath, newCost, currentNode->worker + 1);
                queue[rear++] = newNode;
            }
        }
        free(currentNode);
    }
}
int main()
{
    int n,i,j;
    int costMatrix[100][100];

    printf("Enter the number of tasks: ");
    scanf("%d", &n);
    printf("Enter the cost matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &costMatrix[i][j]);
            if (costMatrix[i][j] == 0)
                costMatrix[i][j] = INT_MAX;
        }
    }
    reduceMatrix(costMatrix, n);
    branchAndBound(costMatrix, n);
   return 0;
}

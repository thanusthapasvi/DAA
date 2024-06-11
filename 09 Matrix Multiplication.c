#include <stdio.h>
#define MAX_SIZE 10
void multiplyMatrix(int A[][MAX_SIZE], int B[][MAX_SIZE], int C[][MAX_SIZE], int rowsA, int colsA, int colsB)
{
	int i,j,k;
    for (i = 0; i < rowsA; i++)
	{
        for (j = 0; j < colsB; j++)
		{
            C[i][j] = 0;
            for (k = 0; k < colsA; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
    }
}
void displayMatrix(int matrix[][MAX_SIZE], int rows, int cols)
{
	int i,j;
    for (i = 0; i < rows; i++)
	{
        for (j = 0; j < cols; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
}
int main()
{
    int rowsA, colsA, rowsB, colsB,i,j,k;
    printf("Enter the number of rows and columns for matrix A: \n");
    scanf("%d %d", &rowsA, &colsA);
    printf("Enter the elements of matrix A: \n");
    int A[MAX_SIZE][MAX_SIZE];
    for (i = 0; i < rowsA; i++)
	{
        for (j = 0; j < colsA; j++)
            scanf("%d", &A[i][j]);
    }
    printf("Enter the number of rows and columns for matrix B: \n");
    scanf("%d %d", &rowsB, &colsB);
    printf("Enter the elements of matrix B: \n");
    int B[MAX_SIZE][MAX_SIZE];
    for (i = 0; i < rowsB; i++)
	{
        for (j = 0; j < colsB; j++)
            scanf("%d", &B[i][j]);
    }
    if (colsA != rowsB)
	{
        printf("Matrices cannot be multiplied\n");
        return 0;
    }
    int result[MAX_SIZE][MAX_SIZE];
    multiplyMatrix(A, B, result, rowsA, colsA, colsB);
    printf("Resultant matrix after multiplication: \n");
    displayMatrix(result, rowsA, colsB);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#define N 20
void printSolution(int board[N][N], int n)
{
	int i,j;
    for (i = 0; i < n; i++)
	{
        for (j = 0; j < n; j++)
            printf("%2d ", board[i][j]);
        printf("\n");
    }
}
int isSafe(int board[N][N], int row, int col, int n)
{
    int i, j;
    for (i = 0; i < col; i++)
        if (board[row][i])
            return 0;
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return 0;
    for (i = row, j = col; j >= 0 && i < n; i++, j--)
        if (board[i][j])
            return 0;
    return 1;
}
int solveNQueens(int board[N][N], int col, int n)
{
	int i;
    if (col >= n)
        return 1;
    for (i = 0; i < n; i++)
	{
        if (isSafe(board, i, col, n))
		{
            board[i][col] = 1;
            if (solveNQueens(board, col + 1, n))
                return 1;
            board[i][col] = 0;
        }
    }
    return 0;
}
int main()
{
    int n;
    printf("Enter the number of queens: ");
    scanf("%d", &n);
    if (n > N)
	{
        printf("The maximum value for n is %d.\n", N);
        return 1;
    }
    int board[N][N] = {0};
    if (solveNQueens(board, 0, n) == 0)
	{
        printf("Solution does not exist.\n");
        return 0;
    }
    printSolution(board, n);
    return 0;
}

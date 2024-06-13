#include <stdio.h>
#include <limits.h>
int sum(int freq[], int i, int j)
{
    int s = 0,k;
    for (k = i; k <= j; k++)
        s += freq[k];
    return s;
}
int optimalBST(int keys[], int freq[], int n)
{
    int cost[n][n],i,length,r;
    for (i = 0; i < n; i++)
        cost[i][i] = freq[i];
    for (length = 2; length <= n; length++)
	{ 
        for (i = 0; i <= n - length; i++)
		{
            int j = i + length - 1;
            cost[i][j] = INT_MAX;
            int totalFreq = sum(freq, i, j);
            for (r = i; r <= j; r++)
			{
                int c = (r > i ? cost[i][r - 1] : 0) + (r < j ? cost[r + 1][j] : 0) + totalFreq;
                if (c < cost[i][j])
                    cost[i][j] = c;
            }
        }
    }

    return cost[0][n - 1];
}

int main()
{
    int n,i;
    printf("Enter the number of keys: ");
    scanf("%d", &n);
    int keys[n], freq[n];
    printf("Enter the keys: ");
    for (i = 0; i < n; i++)
        scanf("%d", &keys[i]);
    printf("Enter the frequencies: ");
    for (i = 0; i < n; i++)
        scanf("%d", &freq[i]);
    int optimal_cost = optimalBST(keys, freq, n);
    printf("Optimal cost: %d\n", optimal_cost);
    return 0;
}

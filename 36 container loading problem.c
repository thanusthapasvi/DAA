#include <stdio.h>
#include <stdlib.h>
int compare(const void *a, const void *b)
{
    return (*(int*)a - *(int*)b);
}
int main()
{
    int n, capacity, i, totalWeight = 0, totalContainers = 0;
    printf("Enter the number of containers: ");
    scanf("%d", &n);
    int weights[n], solution[n];
    printf("Enter the weights of the containers: ");
    for (i = 0; i < n; i++)
	{
        scanf("%d", &weights[i]);
        solution[i] = 0;
    }
    printf("Enter the maximum weight capacity of the loader: ");
    scanf("%d", &capacity);
    qsort(weights, n, sizeof(int), compare);
    for (i = 0; i < n; i++)
	{
        if (totalWeight + weights[i] <= capacity)
		{
            totalWeight += weights[i];
            solution[totalContainers] = weights[i];
            totalContainers++;
        } else
            break;
    }
    printf("Total number of containers loaded: %d\n", totalContainers);
    printf("Total weight of containers loaded: %d\n", totalWeight);
    printf("Weights of the containers loaded: ");
    for (i = 0; i < totalContainers; i++) {
        printf("%d ", solution[i]);
    }
    printf("\n");
    return 0;
}

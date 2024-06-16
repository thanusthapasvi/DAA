#include <stdio.h>
void sumOfSubsets(int set[], int subset[], int n, int subsetSize, int total, int nodeIndex, int targetSum) {
    if (total == targetSum)
	{
		int i;
        printf("{ ");
        for (i = 0; i < subsetSize; i++)
            printf("%d ", subset[i]);
        printf("}\n");
        return;
    }
    if (nodeIndex == n || total > targetSum)
        return;
    subset[subsetSize] = set[nodeIndex];
    sumOfSubsets(set, subset, n, subsetSize + 1, total + set[nodeIndex], nodeIndex + 1, targetSum);
    sumOfSubsets(set, subset, n, subsetSize, total, nodeIndex + 1, targetSum);
}
void findSumOfSubsets(int set[], int n, int targetSum)
{
    int subset[n];
    sumOfSubsets(set, subset, n, 0, 0, 0, targetSum);
}
int main()
{
    int set[] = {10, 7, 5, 18, 12, 20, 15};
    int n = sizeof(set) / sizeof(set[0]);
    int targetSum = 35;
    printf("Subsets of the set that sum to %d are:\n", targetSum);
    findSumOfSubsets(set, n, targetSum);
    return 0;
}

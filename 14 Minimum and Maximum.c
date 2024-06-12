#include <stdio.h>
int findMin(int arr[], int size)
{
    int min = arr[0],i;
    for (i = 1; i < size; i++)
	{
        if (arr[i] < min)
            min = arr[i];
    }
    return min;
}
int findMax(int arr[], int size)
{
    int max = arr[0],i;
    for (i = 1; i < size; i++)
	{
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}
int main()
{
    int n,i;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    int min = findMin(arr, n);
    int max = findMax(arr, n);
    printf("Minimum value in the array is: %d\n", min);
    printf("Maximum value in the array is: %d\n", max);
    return 0;
}

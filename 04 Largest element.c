#include <stdio.h>
int find_largest(int arr[], int n)
{
    int max = arr[0],i;
    for (i = 1; i < n; i++)
	{
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}
int main()
{
    int n,arr[10],i;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    int largest = find_largest(arr, n);
    printf("The largest element in the array is %d.\n", largest);
    return 0;
}

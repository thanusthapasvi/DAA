#include <stdio.h>
int main()
{
    int n, i, search, found = 0;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("Enter the element to search: ");
    scanf("%d", &search);
    for (i = 0; i < n; i++)
	{
        if (arr[i] == search)
		{
            found = 1;
            printf("Element found at index %d\n", i);
            break;
        }
    }
    if (!found)
        printf("Element not found in the array\n");
    return 0;
}

#include <stdio.h>
void insertSorted(int list[], int *n, int number)
{
    int i, j;
    for (i = 0; i < *n; i++) {
        if (list[i] > number)
		{
            for (j = *n; j > i; j--)
                list[j] = list[j - 1];
            list[i] = number;
            (*n)++;
            return;
        }
    }
    list[*n] = number;
    (*n)++;
}
int main() 
{
    int list[100], n,i, number;
    printf("Enter number of elements in the list: ");
    scanf("%d", &n);
    printf("Enter elements of the list in sorted order:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &list[i]);
    printf("Enter the number to insert: ");
    scanf("%d", &number);
    insertSorted(list, &n, number);
    printf("Updated list after insertion:\n");
    for (i = 0; i < n; i++)
        printf("%d ", list[i]);
    printf("\n");
    return 0;
}

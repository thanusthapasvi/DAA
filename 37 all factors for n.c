#include <stdio.h>
void printFactors(int n, int current)
{
    if (current > n)
        return;
    if (n % current == 0)
        printf("%d ", current);
    printFactors(n, current + 1);
}
int main()
{
    int n;
    printf("Enter a number to find its factors: ");
    scanf("%d", &n);
    printf("Factors of %d are: ", n);
    printFactors(n, 1);
    printf("\n");
   return 0;
}

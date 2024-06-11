#include <stdio.h>
long long factorial(int n)
{
    if (n == 0 || n == 1)
        return 1;
    else
        return n * factorial(n - 1);
}
int main()
{
    int number;
    printf("Enter a number to find its factorial: ");
    scanf("%d", &number);
    if (number < 0)
        printf("Factorial is not defined for negative numbers.\n");
    else
	{
        long long result = factorial(number);
        printf("The factorial of %d is %lld.\n", number, result);
    }
    return 0;
}

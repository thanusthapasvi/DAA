#include <stdio.h>
#include <math.h>
int count_digits(int num)
{
    if (num == 0)
        return 0;
    else
        return 1 + count_digits(num / 10);
}
int sum_of_powers(int num, int power)
{
    if (num == 0)
        return 0;
    else
        return pow(num % 10, power) + sum_of_powers(num / 10, power);
}
int armstrong(int num)
{
    int digits = count_digits(num);
    int sum = sum_of_powers(num, digits);
    return (num == sum);
}
int main()
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    if (armstrong(n))
        printf("%d is an Armstrong number.\n", n);
    else
        printf("%d is not an Armstrong number.\n", n);
    return 0;
}

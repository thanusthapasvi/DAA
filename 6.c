#include <stdio.h>
int is_prime(int num, int i)
{
    if (num <= 2)
        return (num == 2) ? 1 : 0;
    if (num % i == 0)
        return 0;
    if (i * i > num)
        return 1;
    return is_prime(num, i + 1);
}
int main()
{
    int number;
    printf("Enter a number to check if it is prime: ");
    scanf("%d", &number);
    if (is_prime(number, 2))
        printf("%d is a prime number.\n", number);
    else
        printf("%d is not a prime number.\n", number);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    long int num = 612852475143;
    long int i;

    while (num % 2 == 0)
    {
        num /= 2;
    }

    for (i = 3; i <= sqrt(num); i += 2)
    {
        while (num % i == 0 && num != i)
        {
            num /= i;
        }
    }

    printf("%ld\n", num);

    return (0);
}

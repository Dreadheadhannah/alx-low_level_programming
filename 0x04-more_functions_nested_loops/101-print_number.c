#include "main.h"

/**
 * print_number - prints an integer
 * @n: integer to print
 *
 * Return: void
 */
void print_number(int n)
{
    int divisor = 1, i, digit;

    if (n < 0)
    {
        _putchar('-');
        n *= -1;
    }

    for (i = 0; n / divisor > 9; i++)
        divisor *= 10;

    for (; divisor >= 1; divisor /= 10)
    {
        digit = n / divisor;
        _putchar(digit % 10 + '0');
    }
}

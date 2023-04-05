#include "main.h"

/**
 * wildcmp - Compares two strings and returns 1 if the strings can be considered
 * identical, otherwise returns 0.
 *
 * @s1: First string to be compared.
 * @s2: Second string to be compared, can contain the special character *.
 *
 * Return: 1 if the strings can be considered identical, otherwise return 0.
 */

int wildcmp(char *s1, char *s2)
{
    if (*s1 == '\0' && *s2 == '\0')
        return (1);

    if (*s2 == '*') {
        if (*s1 == '\0' && *(s2 + 1) == '\0')
            return (1);

        if (*s1 == '\0' || *(s2 + 1) == '\0')
            return (0);

        return (wildcmp(s1 + 1, s2) || wildcmp(s1, s2 + 1));
    }

    if (*s1 == *s2)
        return (wildcmp(s1 + 1, s2 + 1));

    return (0);
}

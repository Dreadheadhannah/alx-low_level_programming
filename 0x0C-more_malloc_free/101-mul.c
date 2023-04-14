#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void error_exit() {
    printf("Error\n");
    exit(98);
}

int main(int argc, char *argv[]) {
    int i, j, len1, len2, carry, num1, num2;
    int *result;

    if (argc != 3) {
        error_exit();
    }

    for (i = 1; i <= 2; i++) {
        for (j = 0; argv[i][j] != '\0'; j++) {
            if (!isdigit(argv[i][j])) {
                error_exit();
            }
        }
    }

    num1 = atoi(argv[1]);
    num2 = atoi(argv[2]);

    if (num1 == 0 || num2 == 0) {
        printf("0\n");
        return 0;
    }

    len1 = sprintf(NULL, "%d", num1);
    len2 = sprintf(NULL, "%d", num2);

    result = calloc(len1 + len2, sizeof(int));

    for (i = len1 - 1; i >= 0; i--) {
        carry = 0;
        for (j = len2 - 1; j >= 0; j--) {
            result[i + j + 1] += carry + ((num1 % 10) * (num2 % 10));
            carry = result[i + j + 1] / 10;
            result[i + j + 1] %= 10;
            num2 /= 10;
        }
        if (carry > 0) {
            result[i + j + 1] += carry;
        }
        num2 = atoi(argv[2]);
        num1 /= 10;
    }

    i = 0;
    while (result[i] == 0) {
        i++;
    }

    for (; i < len1 + len2; i++) {
        printf("%d", result[i]);
    }
    printf("\n");

    free(result);
    return 0;
}

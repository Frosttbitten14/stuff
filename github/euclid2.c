#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int value(int a, int b, int *x, int *y) {
    if (a == 0) {
        *x = 0;
        *y = 1;
        return b;
    }

    int x1, y1;
    int divisor = value(b % a, a, &x1, &y1);
    *x = y1 - (b / a) * x1;
    *y = x1;
    return divisor;
}

int main() {
    int a, b, x, y;
    printf("Въведете две числа: ");
    scanf("%d %d", &a, &b);
    int divisor = value(a, b, &x, &y);
    printf("НОД(%d, %d) = %d\n", a, b, divisor);
    printf("x = %d, y = %d\n", x, y);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int divisor(int a, int b) {
    while (b != 0) {
        int value = b;
        b = a % b;
        a = value;
    }
    return a;
}

int main() {
    int num1, num2;
    printf("Въведете две числа: ");
    scanf("%d %d", &num1, &num2);
    printf("НОД(%d, %d) = %d\n", num1, num2, divisor(num1, num2));
    return 0;
}
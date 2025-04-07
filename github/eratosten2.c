#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX 1000

void eratosten(int n) {
    bool prime[MAX + 1];
    for (int i = 0; i <= n; i++)
        prime[i] = true;
    for (int p = 2; p * p <= n; p++) {
        if (prime[p]) {
            for (int i = p * p; i <= n; i += p) {
                prime[i] = false;
            }
        }
    }

    printf("Това са простите числа до %d: ", n);
    for (int i = 2; i <= n; i++) {
        if (prime[i]) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main() {
    int n;
    printf("Въведете число за N: ");
    scanf("%d", &n);
    if (n > MAX) {
        printf("Грешно въвеждане!", MAX);
        return 1;
    }
    eratosten(n);
    return 0;
}

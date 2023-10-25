#include <stdio.h>

int main() {
    int n;
    printf("Input value of n: ");
    scanf("%d", &n);

    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i * i;
    }

    printf("Sum of S is: %d\n", sum);
    return 0;
}
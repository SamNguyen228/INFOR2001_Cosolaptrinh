#include <stdio.h>

int main() {
    int N, i, isPrime = 1;

    printf("Nhap so nguyen duong N: ");
    scanf("%d", &N);

    if (N <= 1) {
        isPrime = 0;
    } else {
        for (i = 2; i <= N / 2; i++) {
            if (N % i == 0) {
                isPrime = 0;
                break;
            }
        }
    }

    if (isPrime) {
        printf("%d la so nguyen to", N);
    } else {
        printf("%d khong la so nguyen to", N);
    }

    return 0;
}

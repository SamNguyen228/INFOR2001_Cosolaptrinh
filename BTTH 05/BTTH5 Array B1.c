#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Hàm trao đổi hai phần tử
void swap(int arr[], int a, int b) {
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

// Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int b = 0; b < n - i - 1; b++) {
            if (arr[b] > arr[b + 1]) {
                swap(arr, b, b + 1);
            }
        }
    }
}

// Selection Sort
void selectionSort(int arr[], int n) {
    for (int a = 0; a < n - 1; a++) {
        int minIndex = a;
        for (int b = a + 1; b < n; b++) {
            if (arr[b] < arr[minIndex]) {
                minIndex = b;
            }
        }
        if (minIndex != a) {
            swap(arr, a, minIndex);
        }
    }
}

int main() {
    int arr[] = { 10, 2, 1, 12, 3, 6, 0, 20 };
    int n = sizeof(arr) / sizeof(arr[0]);

    clock_t start_bubble = clock();
    bubbleSort(arr, n);
    clock_t end_bubble = clock();
    double time_taken_bubble = (double)(end_bubble - start_bubble) / CLOCKS_PER_SEC;

    clock_t start_selection = clock();
    selectionSort(arr, n);
    clock_t end_selection = clock();
    double time_taken_selection = (double)(end_selection - start_selection) / CLOCKS_PER_SEC;

    printf("Mang da sap xep: ");
    for (int a = 0; a < n; a++) {
        printf("%d ", arr[a]);
    }
    printf("\n");

    printf("Thoi gian thuc thi Bubble Sort: %f giay\n", time_taken_bubble);
    printf("Thoi gian thuc thi Selection Sort: %f giay\n", time_taken_selection);

    return 0;
}
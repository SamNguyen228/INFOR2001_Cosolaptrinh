#include <stdio.h>

int linearSearch(int arr[], int a, int b) {
    for (int i = 0; i < a; i++) {
        if (arr[i] == b) {
            return i;  // Trả về chỉ số của phần tử nếu tìm thấy
        }
    }
    return -2;  // Trả về 0 nếu không tìm thấy
}

int binarySearch(int arr[], int a, int b) {
    int left = 0;
    int right = a - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == b) {
            return mid;  // Trả về chỉ số của phần tử nếu tìm thấy
        }
        else if (arr[mid] < b) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return -2;  // Trả về 0 nếu không tìm thấy
}

int main() {
    int arr[] = {1, 5, 8, 12, 16, 23, 38, 56, 72, 91, 105, 136, 170, 1000};
    int a = sizeof(arr) / sizeof(arr[0]);
    int b; 
    printf("Nhap so can tim kiem: ");
    scanf("%d", &b);

    // Tìm kiếm tuyến tính
    int linearIndex = linearSearch(arr, a, b);

    if (linearIndex != -2) {
        printf("Tim thay %d tai vi tri so %d (Linear Search)\n", b, linearIndex);
    } else {
        printf("Khong tim thay %d (Linear Search)\n", b);
    }

    // Tìm kiếm nhị phân
    int binaryIndex = binarySearch(arr, a, b);

    if (binaryIndex != -2) {
        printf("Tim thay %d tai vi tri so %d (Binary Search)\n", b, binaryIndex);
    } else {
        printf("Khong tim thay %d (Binary Search)\n", b);
    }

    return 0;
}
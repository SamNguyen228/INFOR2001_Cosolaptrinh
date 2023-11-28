#include <stdio.h>
#define Max_Students 50

float calculateAverage(int arr[], int size) {
    int sum = 0;
    for (int a = 0; a < size; a++) {
        sum += arr[a];
    }
    float average = (float) sum / size;
    return average;
}

int main() {
    int scores[Max_Students];
    int numStudents;
    printf("Nhap so luong sinh vien: ");
    scanf("%d", &numStudents);
    if (numStudents > Max_Students) {
        printf("So luong sinh vien vuot qua gioi han.");
        return 0;
    }
    printf("Nhap diem cua sinh vien:\n");
    for (int a = 0; a < numStudents; a++) {
        printf("Sinh vien %d: ", a + 1);
        scanf("%d", &scores[a]);
    }
    float average = calculateAverage(scores, numStudents);
    printf("Diem trung binh cua lop la: %.2f\n", average);

    return 0;
}
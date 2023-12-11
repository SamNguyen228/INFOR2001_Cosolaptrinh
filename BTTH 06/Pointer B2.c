#include <stdio.h>
#include <stdlib.h>

int main() {
    int a;
    printf("Input the number of elements in the array: ");
    scanf("%d", &a);

    //CAP PHAT BO NHO DONG CHO MANG
    int* array = (int*)malloc(a * sizeof(int)); 
    if (array == NULL) {
        printf("Cannot allocate dynamic memory! \n");
        return 0;
    }

    // NHAP GIA TRI CHO MANG
    printf("Input the elements of the array:\n");
    for (int i = 0; i < a; i++) {
        scanf("%d", &array[i]);
    }

    // HIEN THI MANG
    printf("The array just input is:\n");
    for (int i = 0; i < a; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // GIAI PHONG BO NHO
    free(array);

    return 0;
}
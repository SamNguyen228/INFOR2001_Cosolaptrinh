#include <stdio.h>

void InputArray(int *arr, int n){                  //HAM NHAP MANG
    printf("Input the elements of the array:\n");
    for (int i = 0; i < n; i++){
        printf("arr<%d> = ", i);
        scanf("%d", arr + i);
    }
}

void PrintArray(int *arr, int n){                 //HAM IN MANG
    printf("The elements of the array are:\n");
    for (int i = 0; i < n; i++){
        printf("%d ", *(arr + i));
    }
    printf("\n");
}

int Search(int *arr, int n, int a){          //HAM TIM KIEM PHAN TU TRONG MANG
    for (int i = 0; i < n; i++){
        if (*(arr + i) == a){
            return i;
        }
    }
    return -1;                 // TRA VE GIA TRI -1 NEU KHONG TIM THAY
}

int main(){
    int n;
    printf("Input size of array: ");
    scanf("%d", &n);
    int arr[n];
    InputArray(arr, n);
    PrintArray(arr, n);
    int a;
    printf("Input the element need to search for: ");
    scanf("%d", &a);
    int index = Search(arr, n, a);
    if (index != -1){
        printf("The element %d appears at position %d in the array!\n", a, index);
    }else{
        printf("The element %d does not exist in the array!\n", a);
    }

    return 0;
}
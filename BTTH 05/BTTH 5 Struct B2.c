#include <stdio.h>
#include <string.h>

struct Student {
    int ID;
    char name[30];
    float GPA;
};

struct Student students[30];
int studentCount = 0;

int searchStudentById(struct Student students[], int n, int searchID) {
    for (int i = 0; i < n; i++) {
        if (students[i].ID == searchID) {
            return i;
        }
    }
    return -1; 
}

int main() {
    struct Student sv[2];
    for(int i=0; i<2; i++){
        printf("Nhap thong tin sinh vien thu %d\n", i+1);
        printf("Nhap ID sinh vien: ");
        scanf("%d",&sv[i].ID);
        printf("Nhap ho va ten: ");
        getchar();
        fgets(sv[i].name, 30, stdin);
        printf("Nhap GPA: ");
        scanf("%f",&sv[i].GPA);
    }
    int searchID;
    printf("\n Nhap ID can tim kiem: ");
    scanf("%d", &searchID);
    int result = searchStudentById(sv, 2, searchID);
    if (result != -1) {
        printf("Sinh vien can tim la sinh vien thu %d \n", result + 1);
    } else {
        printf("Khong tim thay sinh vien \n");
    }

    return 0;
}
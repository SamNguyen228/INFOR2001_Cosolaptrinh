#include<stdio.h>
#include<string.h>

struct Student{
    char name[30];
    int age;
    int ID;
    float GPA;
};

    struct Student inputStudent() {
    	struct Student a;
    printf("Nhap ho ten: ");
    fgets(a.name, sizeof(a.name), stdin);
    printf("Nhap ma so: ");
    scanf("%d", &a.ID);
    printf("Nhap tuoi: ");
    scanf("%d", &a.age);
    printf("Nhap diem trung binh: ");
    scanf("%f", &a.GPA);
    getchar();

    return a;
}

void displayStudent(struct Student a) {
    printf("\nThong tin sinh vien:\n");
    printf("Ten: %s", a.name);
    printf("Ma so: %d\n", a.ID);
    printf("Tuoi: %d\n", a.age);
    printf("Diem trung binh (gpa): %.2f\n", a.GPA);
}

int main() {
    struct Student students[50];  
    for (int i = 0; i < 50; i++) {
        printf("\nNhap thong tin cho sinh vien thu %d:\n", i + 1);
        students[i] = inputStudent();
    }
    for (int i = 0; i < 50; i++) {
        displayStudent(students[i]);
    }
    return 0;
}





#include<stdio.h>
#include<string.h>

struct Employee {
    int employeeID;      
    char name[20];       
    char position[30];   
    float salary;  
};

struct Employee inputEmployee(){
    struct Employee a;
    printf("Nhap ma nhan vien: ");
    scanf("%d", &a.employeeID);
    getchar(); 
    printf("Nhap ho ten nhan vien: ");
    fgets(a.name, sizeof(a.name), stdin);
    a.name[strcspn(a.name, "\n")] = '\0';  
    printf("Nhap chuc vu: ");
    fgets(a.position, sizeof(a.position), stdin);
    a.position[strcspn(a.position, "\n")] = '\0';
    printf("Nhap luong: ");
    scanf("%f", &a.salary);
    return a;
}

void displayEmployee(struct Employee a){
    printf("\nThong tin nhan vien:\n");
    printf("Ma nhan vien: %d\n", a.employeeID);
    printf("Ten: %s\n", a.name);
    printf("Chuc vu: %s\n", a.position);
    printf("Luong: %.2f\n", a.salary);
}

void addEmployee(struct Employee arr[], int *n) {
    if (*n < 10) {
        arr[*n] = inputEmployee();
        (*n)++;
        printf("Da them nhan vien thanh cong!\n");
    } else {
        printf("Danh sach nhan vien da day, khong the them nhan vien moi!\n");
    }
}

int deleteEmployee(struct Employee arr[], int *n, int employeeID) {
    int found = 0;
    int newCount = 0;  
    for (int i = 0; i < *n; i++){
        if (arr[i].employeeID == employeeID){
            found = 1;
        } else {
            arr[newCount] = arr[i];
            newCount++;
        }
    }
    if (found){
        (*n)--;
        printf("Da xoa nhan vien co ma nhan vien %d!\n", employeeID);
    } else {
        printf("Khong tim thay nhan vien co ma nhan vien %d!\n", employeeID);
    }
    return found;
}

void sortEmployeesById(struct Employee arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int b = 0; b < n - i - 1; b++) {
            if (arr[b].employeeID > arr[b + 1].employeeID) {
                struct Employee temp = arr[b];
                arr[b] = arr[b + 1];
                arr[b + 1] = temp;
            }
        }
    }
}

int main() {
    struct Employee employees[1];  
    int employeeCount = 0; 
    addEmployee(employees, &employeeCount);
    for (int i = 0; i < employeeCount; i++) {
        displayEmployee(employees[i]);
    }
    addEmployee(employees, &employeeCount);
    for (int i = 0; i < employeeCount; i++) {
        displayEmployee(employees[i]);
    }
    int employeeIdToDelete;
    printf("Nhap ma nhan vien can xoa: ");
    scanf("%d", &employeeIdToDelete);
    deleteEmployee(employees, &employeeCount, employeeIdToDelete);
    for (int i = 0; i < employeeCount; i++) {
        displayEmployee(employees[i]);
    }
    sortEmployeesById(employees, employeeCount);
    printf("\nDanh sach nhan vien sau khi sap xep theo ma nhan vien:\n");
    for (int i = 0; i < employeeCount; i++) {
        displayEmployee(employees[i]);
    }
    return 0;
}
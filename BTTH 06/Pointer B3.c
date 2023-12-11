#include <stdio.h>
#include <stdlib.h>

// DINH NGHIA CAU TRUC BOOK
typedef struct {
    char name[50];
    char author[50];
    float price;
} Book;

int main() {
    int a;
    printf("Input the number of books: ");
    scanf("%d", &a);

    // CAP PHAT BO NHO DONG
    Book* Booklist = (Book*)malloc(a * sizeof(Book));
    if (Booklist == NULL) {
        printf("Unable to allocate dynamic memory \n");
        return 0;
    }

    // NHAP THONG TIN CHO TUNG QUYEN SACH
    printf("Input information for each book:\n");
    for (int i = 0; i < a; i++) {
        printf("Input the %d book information:\n", i + 1);
        printf("Name of Book: ");
        scanf(" %[^\n]s", Booklist[i].name);
        printf("Author of Book: ");
        scanf(" %[^\n]s", Booklist[i].author);
        printf("Price of Book: ");
        scanf("%f", &Booklist[i].price);
    }

    // HIEN THI DANH SACH SACH
    printf("List of Books:\n");
    for (int i = 0; i < a; i++) {
        printf("The %d book information:\n", i + 1);
        printf("Name of Book: %s\n", Booklist[i].name);
        printf("Author of Book: %s\n", Booklist[i].author);
        printf("Price of Book: %.2f\n", Booklist[i].price);
    }

    // GIAI PHONG BO NHO
    free(Booklist);

    return 0;
}
#include <stdio.h>
#include <conio.h>
#include <string.h>

struct Book{
        int bookId;
        char bookName[50];
        char bookAuthor[50];
        float bookPrice;
        unsigned int bookTotalQuantity;
        unsigned int bookCurrentQuantity;
};

void addBook(struct Book Book1){
    printf("Enter book name: ");
    gets(Book1.bookName);
    printf("Enter book author: ");
    gets(Book1.bookAuthor);
    printf("Enter book price: ");
    scanf("%f", &Book1.bookPrice);
    printf("Enter book total quantity: ");
    scanf("%d", &Book1.bookTotalQuantity);
    printf("Enter book current quantity: ");
    scanf("%d", &Book1.bookCurrentQuantity);
}
void printBook(struct Book Book1){
    printf("Book ID: %d\n", Book1.bookId);
    printf("Book name: %s\n", Book1.bookName);
    printf("Book author: %s\n", Book1.bookAuthor);
    printf("Book price: %.2f\n", Book1.bookPrice);
    printf("Book total quantity: %d\n", Book1.bookTotalQuantity);
    printf("Book current quantity: %d\n", Book1.bookCurrentQuantity);
}

void main(){
    struct Book Book2;
    addBook(Book2);
    printBook(Book2);
}
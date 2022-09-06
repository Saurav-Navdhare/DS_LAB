#include <stdio.h>
#include "DtoB.c"
#include "DtoO.c"
#include "DtoH.c"
#include "BtoD.c"
//importing all the header files in one main program
//showing menu for user to choose the option

void showMenu()
{
    printf("\nEnter 1 for Decimal to Binary Conversion\n");
    printf("Enter 2 for Decimal to Octal Conversion\n");
    printf("Enter 3 for Decimal to HexaDecimal Conversion\n");
    printf("Enter 4 for Binary to Decimal Conversion\n");
    printf("Else press any key to Exit\n");
}
//getting a character from user to choose the option

char getChoice()
{
    char i;
    scanf("%c", &i);
    if (i == '1' || i == '2' || i == '3' || i == '4')
    {
        return i;
    }
    return '0';
}

void seperator()
{
    printf("\n----------X----------\n");
}
//main driver function
void main()
{
    int num;
    char choice = '1';
    while (choice != '0')
    {
        showMenu();
        choice = getChoice();
        if (choice == '1')//calling decimal to binary function
        {
            printf("Doing Decimal to Binary Conversion");
            printf("%s", "\nenter decimal number: ");
            scanf("%d", &num);
            seperator();
            DtoB(num);
            seperator();
            continue;
        }
        else if (choice == '2') //calling decimal to octal fucntion
        {
            printf("Doing Decimal to Octal Conversion");
            printf("%s", "\nenter decimal number: ");
            scanf("%d", &num);
            seperator();
            DtoO(num);
            seperator();
            continue;
        }
        else if (choice == '3') // calling decimal to hexadecimal function
        {
            printf("Doing Decimal to Hexadecimal Conversion");
            printf("\nEnter a decimal number: ");
            scanf("%d", &num);
            seperator();
            DtoH(num);
            seperator();
            continue;
        }
        else
        {
            printf("Doing Binary to Decimal Conversion");//calling binary to decimal function
            printf("\nEnter a Binary number: ");
            scanf("%d", &num);
            seperator();
            BtoD(num);
            seperator();
            continue;
        }
    }
}
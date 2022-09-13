#include <stdio.h>
#include <conio.h>
#define MAXBD 100
int stackBD[MAXBD];
int topBD = -1;
int num;
void pushBD();
void popBD();
void BtoD(int num1)
{
    num = num1;
    while (num1 > 0)
    {
        if (num1 % 10 >= 2)
        {
            printf("Not a Binary Form");
            return;
        }
        num1 /= 10;
    }
    printf("Binary Form: %d\n", num);
    pushBD();
    popBD();
}
void pushBD()
{
    int rem;

    int dec_value = 0;
    int base = 1;
    int temp = num;
    while (temp)
    {
        int last_digit = temp % 10;
        temp = temp / 10;
        dec_value += last_digit * base;
        base = base * 2;

        if (topBD >= MAXBD)
        {
            printf("\nSTACK OVERFLOW!");
        }
        else
        {
            topBD++;
            stackBD[topBD] = dec_value;
        }
    }
}
void popBD()
{
    int i;
    printf("Its decimal form: ");
    printf("%d", stackBD[topBD]);
    if (topBD < 0)
    {
        printf("\nStack is empty!");
    }
}
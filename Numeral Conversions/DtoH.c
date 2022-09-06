//including the standard header file
//define max length of stack
//defining the popping function for the stack
//checking if the stack is empty or not
//defining the main function
#include <stdio.h>
#include <conio.h>
#include <process.h>

#define sizeDH 50

char stDH[sizeDH];
int topDH = -1;
//defining the stack
void pushDH(char);
int popDH();
int isEmptyDH();
int isFullDH();
//defining the pushing function for the stack
int DtoH(int num)
{
    int n, r;
    char ch;
    n = num;
    //checking if the number is 0
    while (n >= 1)
    {
        r = n % 16;
        //checking if the remainder is greater than 9
        if (r < 10)
            pushDH(r + 48);
        //pushing the number into stack
        else
            pushDH(r + 55);
        n = n / 16;
    }
//printing the hexadecimal form of the number by popping the values from the stack
    printf("%s %d", "\nDECIMAL        :: ", num);
    printf("%s", "\nHEXADECIMAL    :: ");

    while (!isEmptyDH())
        printf("%c", popDH());

    return 0;
}

//defining the pushing function for the stack

int isEmptyDH()
{
    if (topDH == -1)
        return 1;

    return 0;
}


//defining the popping function for the stack
int isFullDH()

{
    //checking if the stack is full or not
    if (topDH == sizeDH - 1)
        return 1;

    return 0;
}

//defining the pushing function for the stack
void pushDH(char r)
{


    //checking if the stack is full or not
    if (isFullDH())
        printf("%s", "\nSTACK OVERFLOW\n");
    else
        stDH[++topDH] = r;
}

//defining the popping function for the stack
int popDH()
{
    //checking if the stack is empty or not
    if (isEmptyDH())
    {
        return 0;
        printf("%s", "\nSTACK UNDERFLOW\n");
    }
    else
    //popping the value from the stack
        return stDH[topDH--];
}
//including the standard header file

//define max length of stack

#include <stdio.h>
#include <conio.h>
#define MAXBD 100
int stackBD[MAXBD];
int topBD = -1;
int num;
//pushing the values into the stack

void pushBD();
//popping the values from the stack
void popBD();
//checking if the stack is empty
void BtoD(int num1)
{
    num = num1;
    while (num1 > 0)
    {
        //checking if the number is binary
        if (num1 % 10 >= 2)
        {
            printf("Not a Binary Form");
            return;
        }
        //dividing the number by 10 and pushing the remainder into the stack
        num1 /= 10;
    }
    //printing the binary form
    printf("Binary Form: %d\n", num);
    //calling the push function
    pushBD();
    //calling the pop function
    popBD();
}
//defining the pushing function for the stack
void pushBD()
{
    int rem;

    int dec_value = 0;
    int base = 1;
    int temp = num;
    while (temp)
    {
        //getting the last digit
        int last_digit = temp % 10;
        //dividing the number by 10
        temp = temp / 10;
        //multiplying the last digit with the base value and adding it to the decimal value
        dec_value += last_digit * base;
        //multiplying the base by 2 for the next digit

        base = base * 2;
//checking if the stack is full or not

        if (topBD >= MAXBD)  
        {
            printf("\nSTACK OVERFLOW!");
        }
        else
        {
            //incrementing the top value
            topBD++;
            //pushing the value into the stack
            stackBD[topBD] = dec_value;
        }
    }
}
//defining the pop fuunction
void popBD()
{
    int i;
    printf("Its decimal form: ");
    //printing the decimal form
    printf("%d", stackBD[topBD]);
    //checking if the stack is empty or not
    if (topBD < 0)
    {
        printf("\nStack is empty!");
    }
}
//including the standard header file
//define max length of stack
//defining the popping function for the stack
//checking if the stack is empty or not

#include <stdio.h>
#include <conio.h>
#include <process.h>
#define MAXDB 50

int isEmpty(int topDB, int stack_arr[]);
void pushDB(int x, int *topDB, int stack_arr[]);
int popDB(int *topDB, int stack_arr[]);
//defining the main function
//defining the stack
//defining the top of the stack
//defining the number
//defining the decimal value
int DtoB(int num)

{
        int stack[MAXDB], topDB = -1, rem;
        printf("Decimal is: %d\n", num);
        printf("Binary Equivalent is : ");
        //checking if the number is 0
        while (num != 0)
        {
                rem = num % 2;
                pushDB(rem, &topDB, stack);
                num /= 2;
        }
        //printing the binary form of the number by popping the values from the stack
        while (topDB != -1)
                printf("%d", popDB(&topDB, stack));
}

//defining the pushing function for the stack 
void pushDB(int x, int *topDB, int stack_arr[])
{
        //checking if the stack is full or not 
        if (*topDB == (MAXDB - 1))
                printf("Stack Overflow\n");
        else
        {
                //incrementing the top of the stack 
                *topDB = *topDB + 1;
                //pushing the value into the stack 
                stack_arr[*topDB] = x;
        }
}
//defining the popping function for the stack
int popDB(int *topDB, int stack_arr[])
{
        int x;
        //checking if the stack is empty or not
        if (*topDB == -1)
        {
                printf("Stack Underflow\n");
                exit(1);
        }
        else
        {
                //popping the value from the stack
                x = stack_arr[*topDB];
                *topDB = *topDB - 1;
        }
        return x;
}
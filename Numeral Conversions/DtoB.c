#include <stdio.h>
#include <conio.h>
#include <process.h>
#define MAXDB 50

int isEmpty(int topDB, int stack_arr[]);
void pushDB(int x, int *topDB, int stack_arr[]);
int popDB(int *topDB, int stack_arr[]);

int DtoB(int num)

{
        int stack[MAXDB], topDB = -1, rem;
        printf("Decimal is: %d\n", num);
        printf("Binary Equivalent is : ");
        while (num != 0)
        {
                rem = num % 2;
                pushDB(rem, &topDB, stack);
                num /= 2;
        }
        while (topDB != -1)
                printf("%d", popDB(&topDB, stack));
}

void pushDB(int x, int *topDB, int stack_arr[])
{
        if (*topDB == (MAXDB - 1))
                printf("Stack Overflow\n");
        else
        {
                *topDB = *topDB + 1;
                stack_arr[*topDB] = x;
        }
}

int popDB(int *topDB, int stack_arr[])
{
        int x;
        if (*topDB == -1)
        {
                printf("Stack Underflow\n");
                exit(1);
        }
        else
        {
                x = stack_arr[*topDB];
                *topDB = *topDB - 1;
        }
        return x;
}
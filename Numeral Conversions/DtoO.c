//including all standard header files
//defining the max length of the stack

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define sizeDO 50
//defining the stack
int stBO[sizeDO];
int topBO = -1;
//defining the top of the stack
void pushDO(int);
int popDO();
int isEmptyDO();
int isFullDO();
//defining the pushing function for the stack
//defining the popping function for the stack
int DtoO(int num)
{
    int n, r;

    n = num;
    while (n >= 1)
    {
        //checking if the number is 0
        r = n % 8;
        pushDO(r);
        n = n / 8;
    }
//printing the octal form of the number by popping the values from the stack

    printf("DECIMAL :: %d\n", num);
    printf("%s", "OCTAL   :: ");
//checking if the stack is empty or not
    while (!isEmptyDO())
    {
        printf("%d", popDO());
    }
}
//defining the pushing function for the stack

int isEmptyDO()
{
    if (topBO == -1)
        return 1;

    return 0;
}
//defining the popping function for the stack
int isFullDO()
{
    //checking if the stack is full or not
    if (topBO == sizeDO - 1)
        return 1;

    return 0;
}
//defining the pushing function for the stack
void pushDO(int r)
{
    if (isFullDO())
        printf("%s", "\nSTACK OVERFLOW\n");
    else
        stBO[++topBO] = r;
}
//defining the popping function for the stack
int popDO()
{
    if (isEmptyDO())
    {
        return 0;
        printf("%s", "\nSTACK UNDERFLOW\n");
    }
    else
        return stBO[topBO--];
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define sizeDO 50

int stBO[sizeDO];
int topBO = -1;

void pushDO(int);
int popDO();
int isEmptyDO();
int isFullDO();

int DtoO(int num)
{
    int n, r;

    n = num;
    while (n >= 1)
    {
        r = n % 8;
        pushDO(r);
        n = n / 8;
    }

    printf("DECIMAL :: %d\n", num);
    printf("%s", "OCTAL   :: ");

    while (!isEmptyDO())
    {
        printf("%d", popDO());
    }
}

int isEmptyDO()
{
    if (topBO == -1)
        return 1;

    return 0;
}

int isFullDO()
{
    if (topBO == sizeDO - 1)
        return 1;

    return 0;
}

void pushDO(int r)
{
    if (isFullDO())
        printf("%s", "\nSTACK OVERFLOW\n");
    else
        stBO[++topBO] = r;
}

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
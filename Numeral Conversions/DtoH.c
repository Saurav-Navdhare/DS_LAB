#include <stdio.h>
#include <conio.h>
#include <process.h>

#define sizeDH 50

char stDH[sizeDH];
int topDH = -1;

void pushDH(char);
int popDH();
int isEmptyDH();
int isFullDH();

int DtoH(int num)
{
    int n, r;
    char ch;
    n = num;
    while (n >= 1)
    {
        r = n % 16;
        if (r < 10)
            pushDH(r + 48);
        else
            pushDH(r + 55);
        n = n / 16;
    }

    printf("%s %d", "\nDECIMAL        :: ", num);
    printf("%s", "\nHEXADECIMAL    :: ");

    while (!isEmptyDH())
        printf("%c", popDH());

    return 0;
}

int isEmptyDH()
{
    if (topDH == -1)
        return 1;

    return 0;
}

int isFullDH()
{
    if (topDH == sizeDH - 1)
        return 1;

    return 0;
}

void pushDH(char r)
{
    if (isFullDH())
        printf("%s", "\nSTACK OVERFLOW\n");
    else
        stDH[++topDH] = r;
}

int popDH()
{
    if (isEmptyDH())
    {
        return 0;
        printf("%s", "\nSTACK UNDERFLOW\n");
    }
    else
        return stDH[topDH--];
}
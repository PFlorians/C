#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <dos.h>
#include <windows.h>
/*
*********************************************
bitove operacie sa robia len s celymi nezapornymi cislami
XOR ^ nulovy ak sa bity rovnaju
inak 1
x= x << 1 - nasobenie 2
t.j. napr. 0001 0011 1010 1011 << 1 -pridam jednu nulu na koniec
0011 0111 0101 0110
x=x >> 1 posun doprava / delenie 2

rychlejsie ako bezne nasobenie a delenie
vyrazy treba zatvorkovat koli priorite >> a <<
jednotkovy doplnok ~x z 1 urobi 0 a z 0 urobi 1
binarne cisla sa indexuju od zadu a od 0
napr: 2^3 = 0000 1000
                 3.2.1.0.
*********************************************
*/
int main()
{
    char c;

    while(c!='k')
    {
    printf("b pre binarny konvertor\n");
    printf("k pre koniec\n");
    scanf("%c", &c);
    getchar();
    if (c=='b')
    {
        system("C:\\Users\\Prometeus\\Desktop\\C\\decimal_binary\\bin\\Debug\\decimal_binary.exe");
    }

    else if(c=='k')
    {
        break;
    }
    }
    return 0;
}

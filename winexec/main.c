#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define WIN32_DEFAULT_LIBS
int main()
{
    char c;
     WinExec("C:\\users\\Prometeus\\Desktop\\C\\winexec\\diamant.exe", SW_SHOWNORMAL);
    /*while (c!='k' && (c=getchar())=='\n'){
        printf("ak chcete diamant tak d>\n");
        printf("ak chcete minihru tak m>\n");
        printf("koniec k>\n");
        scanf("%c", &c);
        if (c=='d' || c=='D'){
            WinExec("C:\\users\\Prometeus\\Desktop\\C\\winexec\\diamant.exe", SW_SHOWNORMAL);
        }
        else if (c=='m' || c=='M'){
            WinExec("C:\\users\\Prometeus\\Desktop\\C\\winexec\\hra_kapitola1_minihra.exe", SW_SHOWNORMAL);
        }
        else if (c=='k' || c=='K'){
            printf("Dovidenia\n");
            return 0;
        }
        else{
            ;
        }
    }*/
    return 0;
}

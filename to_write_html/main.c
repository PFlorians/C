#include <stdio.h>
#include <stdlib.h>

int main()
{
    char **a;
    int i, j, riadky, znvr=100, zvacsi;//znvr znaky v riadku
    printf("kolko riadkov?>\n");
    scanf("%d", &riadky);

    a=(char**)malloc(riadky*sizeof(char*));
    for (i=0;i<riadky;i++){
        a[i]=(char*)malloc(znvr*sizeof(char));
    }
        //vysledkom je matica
        for(i=0;i<riadky;i++){
            for (j=0;j<znvr;j++){
                a[i][j]='a';
            }
        }
        /*for (i=0;i<riadky;i++){
            scanf("%s", a[i]);//zaplnanie po riadkoch nemoze byt &a[i], lebo toto je smernik a & je adresa a[0] v pamati
        }*/
        for (i=0;i<riadky;i++){
                for (j=0;j<znvr;j++){
            printf("%c\t", a[i][j]);
                }
        }
        printf("o kolko zvacsit>\n");
        scanf("%d", &zvacsi);
        a=(char**)realloc(a, riadky+zvacsi*sizeof(char*));
        for (i=0;i<znvr+zvacsi;i++){
            a[i]=(char*)realloc(a[i], znvr+zvacsi*sizeof(char));
        }
        for (i=riadky; i<riadky+zvacsi; i++){
            for (j=0; j<znvr; j++){
                a[i][j]='b';
            }
        }
        for (i=0;i<riadky+zvacsi;i++){
            for (j=0;j<znvr;j++){
            printf("%c\n", a[i][j]);
            }
        }
        for(i=0;i<riadky;i++){
            for (j=0;j<znvr;j++){
                free((void*) a[i][j]);
            }
        }
    return 0;
}

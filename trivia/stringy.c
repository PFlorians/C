#include <stdio.h>
#include <stdlib.h>//potrebujem koli malloc
#include <string.h>//pre "retazce"

int main()
{
    int i;//pomocna premenna
    //retazec je len pole znakov - charov, 1char = 1B t.j. 8 bit t.j. 2^8 moznych znakov - vid ASCII tabulku
    //deklaracie:
    char *r=NULL;//retazec -> smernik na nealokovany priestor
    char r2[20];//retazec so statickou velkostou
    //kazdy retazec musi byt ukonceny znakom \0 t.j. nieco ako nula
    r=(char*)malloc(sizeof(char));//dynamicka alokacia pamate na string

    printf("zadajte retazec: \n");
    scanf("%s", r);//precitat nieco do retazca zo vstupu
    printf("%s %d\n", r, strlen(r));
    //retazec 2
    printf("zadajte retazec 2 max velkost 20 pismen: \n");
    scanf("%s", r2);//precitat nieco do retazca zo vstupu, ak presiahne 20 pismen tak pretecie buffer
    printf("%s %d %d\n", r2, strlen(r2), (int)r2[1]);
    //co ak to chcem sparsovat?
    //je prve pismeno velke?
    if((((int)r[0]) - 65)>=0 && (((int)r[0]) - 65)<=25)
    {
        printf("velke\n");
        //je na konci bodka?
        if(((int)r[strlen(r)])==46)
        {
            printf("je to veta\n");
        }
        else
        {
            printf("chyba bodka\n");
        }
    }
    else
    {
        printf("chyba velke pismeno\n");
    }

    free(r);//dealokovanie alokovanej pamate
    return 0;
}

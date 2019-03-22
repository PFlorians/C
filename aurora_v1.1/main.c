/*Author: Florians, Patrik
*Callsign: BlueSphinx
*Date: 31.01.2014
*Version: 1.1,a.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
   FILE*fw;
   int a[200], b[200], i, vysledok[200], kontrola[200], spravne=0, nespravne=0, pocetpr;
   int v, d, de;//pre delenie
    char n, c;
    if ((fw=fopen("zaznam.txt", "a"))==NULL){
        printf("Chyba 001\n");
    }
    for(i=0;i<200;i++){
        a[i]=0;
        b[i]=0;
        vysledok[i]=0;
        kontrola[i]=0;
    }
    printf("***************Vitajte***************\n");
    printf("Program spustite klavesou enter\n");
    while(n!='k' && (c=getchar())=='\n'){
    printf("s pre scitanie\n");
    printf("n pre nasobenie\n");
    printf("o pre odcitanie\n");
    printf("d pre delenie\n");
    printf("k pre koniec\n");
    scanf("%c", &n);

    if (n=='k' || n=='K'){
        return 0;
        printf("Thank you for playing\n");
        printf("Dakujeme za hranie nasej hry\n");
    }
    //scitanie
    else if (n=='s' || n=='S'){
            fprintf(fw, "************zaciatok sekvencneho bloku->scitanie************\n");
    printf("zadajte pocet prikladov:>\n");
    scanf("%d", &pocetpr);
    srand(time(NULL));
    for (i=0;i<pocetpr;i++){//menit pocty
        a[i]=rand()%100;
        b[i]=rand()%100+1;
    }
    for(i=0;i<pocetpr;i++){
        printf("%d + %d\n", a[i], b[i]);
        fprintf(fw, "%d + %d\n", a[i], b[i]);
        kontrola[i]=a[i]+b[i];
        fprintf(fw, "Spravny vysledok: %d\n", kontrola[i]);
        scanf("%d", &vysledok[i]);                          //*****treba prirobit poistku v pripade desatinnych cisel*****
        fprintf(fw, "Vasa odpoved: %d\n", vysledok[i]);
        if (vysledok[i]==kontrola[i]){
            printf("spravne\n");
            spravne++;
        }
        else{
            printf("nespravne\n");
            nespravne++;
        }
    }
    fprintf(fw, "Spravne: %d\n", spravne);
    fprintf(fw, "Nespravne: %d\n", nespravne);
    fprintf(fw, "************koniec sekvencneho bloku->scitanie************\n");
    printf("pocet spravnych: %d\n", spravne);
    printf("pocet nespravnych: %d\n", nespravne);
    }
    //nasobenie
   else if (n=='n' || n=='N'){
            fprintf(fw, "************zaciatok sekvencneho bloku->nasobenie************\n");
      printf("zadajte pocet prikladov:>\n");
    scanf("%d", &pocetpr);
    srand(time(NULL));
    for (i=0;i<pocetpr;i++){//menit pocty
        a[i]=rand()%10;
        b[i]=rand()%10;
    }
    for(i=0;i<pocetpr;i++){
        printf("%d * %d\n", a[i], b[i]);
        fprintf(fw, "%d * %d\n", a[i], b[i]);
        kontrola[i]=a[i]*b[i];
        fprintf(fw, "Spravna odpoved: %d\n", kontrola[i]);
        scanf("%d", &vysledok[i]);
        fprintf(fw, "Vasa odpoved: %d\n", vysledok[i]);
        if (vysledok[i]==kontrola[i]){
            printf("spravne\n");
            spravne++;
        }
        else{
            printf("nespravne\n");
            nespravne++;
        }
    }
    fprintf(fw, "Spravne: %d\n", spravne);
    fprintf(fw, "Nespravne: %d\n", nespravne);
    fprintf(fw, "************koniec sekvencneho bloku->nasobenie************\n");
    printf("pocet spravnych: %d\n", spravne);
    printf("pocet nespravnych: %d\n", nespravne);
    }
    //odcitanie
    else if (n=='o' || n=='O'){
            fprintf(fw, "************zaciatok sekvencneho bloku->odcitanie************\n");
        printf("zadajte pocet prikladov:>\n");
    scanf("%d", &pocetpr);
    srand(time(NULL));
    for (i=0;i<pocetpr;i++){//menit pocty
        a[i]=rand()%100;
        b[i]=rand()%50;
    }
    for(i=0;i<pocetpr;i++){
        printf("%d - %d\n", a[i], b[i]);
        fprintf(fw, "%d - %d\n", a[i], b[i]);
        kontrola[i]=a[i]-b[i];
        fprintf(fw, "Spravna odpoved: %d\n", kontrola[i]);
        scanf("%d", &vysledok[i]);
        fprintf(fw, "Vasa odpoved: %d\n", vysledok);
        if (vysledok[i]==kontrola[i]){
            printf("spravne\n");
            spravne++;
        }
        else{
            printf("nespravne\n");
            nespravne++;
        }
    }
    fprintf(fw, "Spravne: %d\n", spravne);
    fprintf(fw, "Nespravne: %d\n", nespravne);
    fprintf(fw, "************koniec sekvencneho bloku->odcitanie************\n");
    printf("pocet spravnych: %d\n", spravne);
    printf("pocet nespravnych: %d\n", nespravne);

    }
    //delenie
    else if (n=='d' || n=='D'){
            fprintf(fw, "************zaciatok sekvencneho bloku->delenie************\n");
      printf("zadajte pocet prikladov:>\n");
    scanf("%d", &pocetpr);
    srand(time(NULL));

    for(i=0;i<pocetpr;i++){
            d=rand()%9+1;//pocty
            de=rand()%9+1;
            v=d*de;
            if (d>de){
                     kontrola[i]=v/de;//pre vacsiu variabilitu
                        if (kontrola[i]==kontrola[i-1]){//vacsia nevyspitatelnost
                            kontrola[i]=v/d;
                            printf("%d / %d\n", v, d);
                            fprintf(fw, "%d / %d\n", v, d);
                            fprintf(fw, "Spravna odpoved: %d\n", kontrola[i]);
                            scanf("%d", &vysledok[i]);
                            fprintf(fw, "Vasa odpoved: %d\n", vysledok[i]);

                                if (vysledok[i]==kontrola[i]){
                                    printf("spravne\n");
                                    spravne++;
                                    }
                                else{
                                    printf("nespravne\n");
                                    nespravne++;
                                }
                        }
                        else{
                printf("%d / %d\n", v, de);
                fprintf(fw, "%d / %d\n", v, de);
                fprintf(fw, "Spravna odpoved: %d\n", kontrola[i]);
                scanf("%d", &vysledok[i]);
                fprintf(fw, "Vasa odpoved: %d\n", vysledok[i]);

                    if (vysledok[i]==kontrola[i]){
                        printf("spravne\n");
                        spravne++;
                        }
                    else{
                        printf("nespravne\n");
                        nespravne++;
                    }
                }
                }
            else if(d<de){
                    kontrola[i]=v/d;//overenie vysledkov
                        if (kontrola[i]==kontrola[i-1]){//dva rovnake vysledky
                            kontrola[i]=v/de;
                            printf("%d / %d\n", v, de);
                            fprintf(fw, "%d / %d\n", v, de);
                            fprintf(fw, "Spravna odpoved: %d\n", kontrola[i]);
                            scanf("%d", &vysledok[i]);
                            fprintf(fw, "Vasa odpoved: %d\n", vysledok[i]);

                                if (vysledok[i]==kontrola[i]){
                                    printf("spravne\n");
                                    spravne++;
                                    }
                                else{
                                    printf("nespravne\n");
                                    nespravne++;
                                }
                            }
                        else{
                            printf("%d / %d\n", v, d);
                            fprintf(fw, "%d / %d\n", v, d);
                            fprintf(fw, "Spravna odpoved: %d\n", kontrola[i]);
                            scanf("%d", &vysledok[i]);
                            fprintf(fw, "Vasa odpoved: %d\n", vysledok[i]);

                                if (vysledok[i]==kontrola[i]){
                                    printf("spravne\n");
                                    spravne++;
                                    }
                                else{
                                    printf("nespravne\n");
                                    nespravne++;
                                }
                            }
                        }
            d=de=v=0;
        }
    fprintf(fw, "Spravne: %d\n", spravne);
    fprintf(fw, "Nespravne: %d\n", nespravne);
    fprintf(fw, "************koniec sekvencneho bloku->delenie************\n");
    printf("pocet spravnych: %d\n", spravne);
    printf("pocet nespravnych: %d\n", nespravne);
    }
    else
    {
    printf("neplatny vstup\n");
    }
    }
    if (fclose(fw)!=NULL){
        printf("Chyba 002\n");
    }
    getchar();
    return 0;
}

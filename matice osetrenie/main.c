#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <dirent.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_sf_bessel.h>
void scan()//ukze obsah priecinka
{
    DIR *d;
  struct dirent *dir;
  d = opendir(".");//otvori priecinok v ktorom sa nachadza
  if (d)
  {
    while ((dir = readdir(d)) != NULL)
    {
      printf("%s\n", dir->d_name);
    }
    closedir(d);//koniec prace s priecinkom
  }
}
void foo(FILE **f,float ***matica, int **tempest, int *riadkov)//nacitava do matice
{
   char c, buf[1000], zaporne[100];
    int i, kolik, j=0, n=0, vr=0;
    float cislo;
     i=kolik=0;

    while ((c=getc(*f))!=EOF)
    {
        if(c=='\n')
        {
            (*riadkov)++;
        }
    }
    rewind(*f);
    (*tempest)=(int*)malloc((*riadkov)*sizeof(int));

    //printf("faza1 ok\n");
     while ((c=getc(*f))!=EOF)
     {
         if (c==' ')
         {
             vr++;
         }
         if (c=='\n')
         {
             vr++;
             (*tempest)[i]=vr;//cisla v riadku
             vr=0;
             i++;
         }
     }
     //printf("faza2 ok,\n");
     i=kolik=0;
     (*matica)=(float**)malloc((*riadkov)*sizeof(float*));
     for(i=0;i<(*riadkov)+1;i++)
     {
         (*matica)[i]=(float*)malloc(((*tempest)[i])*sizeof(float));
     }
     rewind(*f);
    fscanf((*f), "%f", &cislo);//koli podmienke
    //printf("faza3 ok\n");

    rewind(*f);
     i=kolik=j=n=vr=0;
    while((c=getc(*f))!=EOF)//neberie prve cislo
    {
        zaporne[vr]=c;
        if (isdigit(c) || (isdigit(c) && zaporne[vr-1]=='-') || (c=='-') || (c=='.') || c==',')//problem so znamienkom a desatinnou bodkou
        {
            buf[i]=c;
            //printf("%c", buf[i]);
            i++;
            kolik++;
        }
        else if (!isdigit(c) && c!='.' && c!=',')//desatinna bodka(ciarka)
        {
            buf[i]='\0';
          // printf("%s ", buf);

            (*matica)[j][n]=atof(buf);
             //printf("%.2f ", (*matica)[j][n]);
             //printf("j: %d, n: %d\n", j,n);
            n++;
            i=0;
        }
        if (c=='\n')
        {
                j++;
            for(i=0;i<kolik;i++)
            {
                buf[i]=0;
            }
            i=0;
            kolik=0;
                n=0;
                //putchar('\n');
        }
        vr++;
    }
    (*matica)[0][0]=cislo;
//printf("faza4 ok\n");
}

void add(float ****matica, int riadkov1, int **temp1, int riadkov2, int **temp2)
{
    FILE *f;
    int i, j;
    float vysledna[riadkov1][(*temp1)[0]];
    char yn, nazov[255];
    if (riadkov1==riadkov2 && (*temp1)[0]==(*temp2)[1])//rovnaky rozmer
    {
    for(i=0;i<riadkov1;i++)
    {
        for(j=0;j<(*temp1)[0];j++)
        {
            vysledna[i][j]=(*matica)[0][i][j]+(*matica)[1][i][j];
        }
    }
    for(i=0;i<4;i++)
    {
        for(j=0;j<5;j++)
        {
            printf("%.2f ", vysledna[i][j]);
        }
        putchar('\n');
    }
    //zapisanie do suboru ukoncenie
    printf("Zelate si zapisat do suboru?[Y/N]\n");
    scanf("%c", &yn);
    getchar();
    if(yn=='Y' || yn=='y')
    {
        printf("meno suboru\n");
        gets(nazov);
        if((f=fopen(nazov, "w"))==NULL)
        {
            printf("chyba zapisovanie\n");
        }
        else
        {
            for(i=0;i<4;i++)
            {
                for(j=0;j<5;j++)
                {
                    fprintf(f, "%.2f ", vysledna[i][j]);
                }
                putc('\n', f);
            }
        }
        fclose(f);
    }
    }
    else
    {
        printf("matice nemaju rovnaky rozmer");
    }
}
void sub(float ****matica, int riadkov1, int **temp1, int riadkov2, int **temp2)
{
    FILE *f;
    int i, j;
    float vysledna[riadkov1][(*temp1)[0]];
    char yn, nazov[255];
    //operacia
    if (riadkov1==riadkov2 && (*temp1)[0]==(*temp2)[1])//rovnaky rozmer
    {
    for(i=0;i<riadkov1;i++)
    {
        for(j=0;j<(*temp1)[0];j++)
        {
            vysledna[i][j]=(*matica)[0][i][j]-(*matica)[1][i][j];
        }
    }
    //zobrazenie
     for(i=0;i<4;i++)
    {
        for(j=0;j<5;j++)
        {
            printf("%.2f ", vysledna[i][j]);
        }
        putchar('\n');
    }
    }
    printf("Zelate si vysledok ulozit do suboru?[Y/N]\n");
    scanf("%c", &yn);
    getchar();
    if(yn=='Y' || yn=='y')
    {
        printf("meno suboru\n");
        gets(nazov);
        if((f=fopen(nazov, "w"))==NULL)
        {
            printf("chyba zapisovanie\n");
        }
        else
        {
            for(i=0;i<4;i++)
            {
                for(j=0;j<5;j++)
                {
                    fprintf(f, "%.2f ", vysledna[i][j]);
                }
                putc('\n', f);
            }
        }
        fclose(f);
    }
    else
    {
        printf("matice nemaju rovnaky rozmer\n");
    }

}
void mp(float ****matica, int **temp1, int riadkov1, int **temp2, int riadkov2)
{
    FILE *f;
    int i, j, k, err=0, c_c;//c2
    float **vysledna, spolu=0;
    char yn, nazov[255];
    printf("%d\n", riadkov1);
    for(i=0;i<riadkov2;i++)//overenie rovnakeho poctu cisel v kazdom riadku
    {
        c_c=(*temp2)[i];

        if((c_c!=(*temp2)[i+1] && i<riadkov2-1))//nerovnaky pocet stlpcov
        {
            printf("Matice nemozno nasobit1\n");
            err=1;
            break;
        }
    }
    if((riadkov1!=c_c && err==0))
    {
        printf("Matice nemozno nasobit\n");
        err=1;
    }
    else if((riadkov1==c_c && err==0) )//rovnako vela cisel ako je stlpcov
    {
        printf("%d %d\n", riadkov1, (*temp2)[0]);
    vysledna=(float**)malloc(riadkov1*sizeof(float*));
    for(i=0;i<riadkov1;i++)
    {
        //d=(*temp2)[i];
        vysledna[i]=(float*)malloc((*temp2)[0]*sizeof(float));
    }
    for(i=0;i<riadkov1;i++)
    {
        for(j=0;j<(*temp2)[0];j++)//stlpcov musi byt rovnako vela
        {
            for(k=0;k<riadkov2;k++)
            {
                spolu=spolu+((*matica)[0][i][k])*((*matica)[1][k][j]);
            }
            vysledna[i][j]=spolu;
            spolu=0;
        }
    }
    for(i=0;i<riadkov1;i++)
    {
        for(j=0;j<(*temp2)[0];j++)
        {
            printf("%f", vysledna[i][j]);
        }
        putchar('\n');
    }
    }

    else
    {
        printf("Pozor, necakana chyba: %d r2: %d c_c:%d, t: %d, t2:%d\n", riadkov1, riadkov2, c_c, (*temp1)[0], (*temp2)[0]);
    }
    if(err!=1)
    {
    printf("Zelate si zapisat do suboru?[Y/N]\n");
    scanf("%c", &yn);
    getchar();
    if(yn=='Y' || yn=='y')
    {
        printf("meno suboru\n");
        gets(nazov);
        if((f=fopen(nazov, "w"))==NULL)
        {
            printf("chyba zapisovanie\n");
        }
        else
        {
            for(i=0;i<4;i++)
            {
                for(j=0;j<5;j++)
                {
                    fprintf(f, "%.2f ", vysledna[i][j]);
                }
                putc('\n', f);
            }
        }
        fclose(f);
    }
    }
}
void smp(float ****matica, int **temp1, int riadkov1, int **temp2, int riadkov2)
{
     FILE *f;
    int i, j, sc=0, kt=0, riadky;//c2
    float **vysledna;
    char yn, nazov[255];
    printf("akym cislom chcete nasobit?\n");
    scanf("%d", &sc);
    printf("ktoru maticu chcete nasobit?\n");
        scanf("%d", &kt);
        getchar();
        if(kt==1)
        {
            riadky=riadkov1;
            vysledna=(float**)malloc(riadky*sizeof(float*));
            for(i=0;i<riadky;i++)
            {
                vysledna[i]=(float*)malloc((*temp1)[0]*sizeof(float));
            }
            for(i=0;i<riadky;i++)
            {
                for(j=0;j<(*temp1)[0];j++)
                {
                    vysledna[i][j]=((*matica)[0][i][j])*sc;
                }
            }
            for(i=0;i<riadky;i++)
            {
                for(j=0;j<(*temp1)[0];j++)
                {
                    printf("%.2f", vysledna[i][j]);
                }
                putchar('\n');
            }
            printf("Zelate si vysledok zaznamenat do suboru?[Y/N]\n");
            scanf("%c", &yn);
            getchar();
                if(yn=='Y' || yn=='y')
                {
                    printf("Zadajte nazov\n");
                    gets(nazov);
                    if ((f=fopen(nazov, "w"))==NULL)
                    {
                        printf("Problem s otvaranim\n");
                    }
                    else
                    {
                        for(i=0;i<riadky;i++)
                        {
                            for(j=0;j<(*temp1)[0];j++)
                            {
                                fprintf(f, "%.2f", vysledna[i][j]);
                            }
                            putc('\n', f);
                        }
                    }
            }
        }
        else if(kt==2)
        {
            riadky=riadkov2;
            vysledna=(float**)malloc(riadky*sizeof(float*));
            for(i=0;i<riadky;i++)
            {
                vysledna[i]=(float*)malloc((*temp2)[0]*sizeof(float));
            }
            for(i=0;i<riadky;i++)
            {
                for(j=0;j<(*temp2)[0];j++)
                {
                    vysledna[i][j]=((*matica)[1][i][j])*sc;
                }

                putchar('\n');
            }
            for(i=0;i<riadky;i++)
            {
                for(j=0;j<(*temp2)[0];j++)
                {
                    printf("%.2f", vysledna[i][j]);
                }
                putchar('\n');
            }
            printf("Zelate si vysledok zaznamenat do suboru?[Y/N]\n");
            scanf("%c", &yn);
            getchar();
                if(yn=='Y' || yn=='y')
                {
                    printf("Zadajte nazov\n");
                    gets(nazov);
                    if ((f=fopen(nazov, "w"))==NULL)
                    {
                        printf("Problem so otvaranim\n");
                    }
                    else
                    {
                        for(i=0;i<riadky;i++)
                        {
                            for(j=0;j<(*temp2)[0];j++)
                            {
                                fprintf(f, "%.2f", vysledna[i][j]);
                            }
                            putc('\n', f);
                        }
                    }
            }

        }
        else
        {
            printf("zvolte cislo 1 alebo cislo 2\n");
        }

}
int main()
{
    FILE *f[2];
    char choose, meno1[255], meno2[255];
    int i, j, u, *temp1=NULL, *temp2=NULL, riadkov1=0, riadkov2=0;
    int opened=0, loaded=0;
    //int riadky_p=0, riadky_d=0;
    float ***storage=NULL;

    while(choose!='k' || choose!='K')
    {
        printf("s -scan priecinka\n");
        printf("c -nacitaj\n");
        printf("a -scitanie\n");
        printf("o -odcitanie\n");
        printf("m -nasobenie 2 matic\n");
        printf("n -skalarne nasobenie\n");
        printf("k -koniec\n");
        scanf("%c", &choose);
        getchar();
        if (choose=='c' || choose=='C')
        {
            if(storage==NULL)
            {
                    //printf("%d\n", storage);
                    storage=(float***)malloc(4*sizeof(float**));//pocet matic
                    foo(&f[0],&storage[0], &temp1, &riadkov1);//volanie funkcie
                    for(u=0;u<1;u++)
                    {
                        for(i=0;i<riadkov1;i++)
                        {
                            for(j=0;j<temp1[i];j++)
                            {
                                printf(">>%.2f<< ", storage[u][i][j]);
                            }
                        putchar('\n');
                        }
                    }
                    putchar('\n');

                    //printf("volam\n");
                    //znova alokujem vo foo
                    foo(&f[1], &storage[1], &temp2, &riadkov2);
                    //return 0;
                    for(u=1;u<2;u++)
                    {
                        for(i=0;i<riadkov2;i++)
                        {
                            for(j=0;j<temp2[i];j++)
                            {
                                printf(">>%.2f<< ", storage[u][i][j]);
                            }
                            putchar('\n');
                        }
                    }
                    loaded=1;
        }//podm
        else
        {
            //printf("%d\n", storage);
            free(storage);
            storage[0]=NULL;
            //free(storage[1]);
            storage[1]=NULL;
            storage=NULL;
            //free(*temp1);
            //free(*temp2);
            //temp1=NULL;
            //temp2=NULL;
            riadkov1=0;
            riadkov2=0;
        }
    }//koniec nacitania
    else if(choose=='s' || choose=='S')
    {
        if(opened==0)
        {
            scan();
            printf("Zadajte nazvy: \n");
            gets(meno1);
            printf("Dakujem\n");
            gets(meno2);
            if((f[0]=fopen(meno1, "r"))==NULL)
            {
                printf("Prepacte, ale subor bud neexistuje, alebo ste zadali zly nazov\n");
            }
            if((f[1]=fopen(meno2, "r"))==NULL)
            {
                printf("Prepacte, ale subor bud neexistuje, alebo ste zadali zly nazov\n");
            }
            opened=1;//true false
        }
        /*else
        {
            if(fclose(f[0])==EOF)
            {
                printf("wtf\n");
            }
            if(fclose(f[1])==EOF)
            {
                printf("wtf\n");
            }
            scan();
            printf("Zadajte nazvy suborov: \n");
            gets(meno1);
            printf("ok\n");
            gets(meno2);
            if((f[0]=fopen(meno1, "r"))==NULL)
            {
                printf("Prepacte, ale subor bud neexistuje, alebo ste zadali zly nazov\n");
            }
            if((f[1]=fopen(meno2, "r"))==NULL)
            {
                printf("Prepacte, ale subor bud neexistuje, alebo ste zadali zly nazov\n");
            }
        }*/
    }
    else if(choose=='a' || choose=='A')
    {
        if(loaded==1)
        {
        add(&storage, riadkov1, &temp1, riadkov2, &temp2);
        fclose(f[0]);
        fclose(f[1]);
        return 0;
        }
        else
        {
            printf("zabudli ste nacitat matice(stlacte 'c')\n");
        }
    }
    else if(choose=='o' || choose=='O')
    {
        if(loaded==1)
        {
        sub(&storage, riadkov1, &temp1, riadkov2, &temp2);
        fclose(f[0]);
        fclose(f[1]);
        return 0;
        }
        else
        {
            printf("zabudli ste nacitat matice(stlacte 'c')\n");
        }
    }
    else if(choose=='m' || choose=='M')
    {
        if(loaded==1)
        {
        mp(&storage, &temp1, riadkov1, &temp2, riadkov2);
        fclose(f[0]);
        fclose(f[1]);
        return 0;
        }
        else
        {
            printf("zabudli ste nacitat matice(stlacte 'c')\n");
        }
    }
    else if(choose=='n' || choose=='N')
    {
        if(loaded==1)
        {
        smp(&storage, &temp1, riadkov1, &temp2, riadkov2);
        fclose(f[0]);
        fclose(f[1]);
        return 0;
        }
        else
        {
            printf("zabudli ste nacitat matice(stlacte 'c')\n");
        }
    }
    else if(choose=='k' || choose=='K')
    {
       break;
    }
    }
    fclose(f[0]);
    fclose(f[1]);
    return 0;
}

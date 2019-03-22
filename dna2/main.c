#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define A(a) ((!B((a))) && (!((a)>=0 && (a)<=32)))?1:0
#define B(a)  ((a)=='A' || (a)=='C' || (a)=='G' || (a)=='T')?1:0
#define ABS(a) ((a)>=0)?(a):(a)*-1
#define X(a) ((a)>='a' && (a)<='z')?((a)-'a')+'A':(a)
//b abeceda X
//a prazdne znaky a nepatri do X
void v(FILE *f)
{
    int p, i=0;
    char c;
    printf("cislo>\n");
    scanf("%d", &p);
    if(p<1 || p>20)
    {
        printf("Nespravny pocet nukleotidov na riadok\n");
    }
    else
    {
        rewind(f);
        while((c=getc(f))!=EOF)
        {
            if(i<p && c!='\n')
            {
                putchar(c);
                i++;
            }
            else
            {
                if(c!='\n')
                {
                    putchar('\n');
                    i=0;
                }
            }
        }
        putchar('\n');
    }
}


void n(FILE *f, int *i, char **b)
{
    int j=0,flag;
    char c;
    rewind(f);
    while((c=getc(f))!=EOF)
    {
        putchar(c);
        if(B(X(c)) && j<1000)
        {
            (*b)[j]=c;//b
            j++;
        }
        else if(c>=1000 || A(c))
        {
            flag=-1;
            break;
        }
    }
    if(flag==-1)
    {
        printf("Sekvencia nesplna podmienky\n");
    }
    else
    {
        (*i)=j-1;
        //a(*b)=a;
    }
}

void h(char *a, int i)
{
    int t[4];
    int j;
    j=0;
    for(j=0;j<4;j++)
    {
        t[j]=0;
    }
    j=0;

    for(j=0;j<i;j++)
    {
       printf("%c %d\n", X(a[j]), j);
        if(X(a[j])=='A')
        {
            t[0]++;
        }
        else if(X(a[j])=='C')
        {
            t[1]++;
        }
        else if(X(a[j])=='G')
        {
            t[2]++;
        }
        else if(X(a[j])=='T')
        {
            t[3]++;
        }
    }

    printf("A: %d\n", t[0]);
    printf("C: %d\n", t[1]);
    printf("G: %d\n", t[2]);
    printf("T: %d\n", t[3]);
}

void p(char *a, int i)
{
    int flag=0;
    char sek[10], buff[11];
    int j, k, l=0, t;

    scanf("%s", sek);
    j=0;
    while(sek[j]!='\0')
    {
        if(B(X(sek[j]))==0)
        {
            printf("Neplatny vstup\n");
            flag=-1;
            break;
        }
        j++;
    }
    k=strlen(sek);

    if(flag==0)
    {
        while(l<i)
        {
            for(j=0;j<k;j++)
            {
                buff[j]=a[l+j];
            }
            buff[j]='\0';
            if(strcmp(sek, buff)==0)
            {
               // printf("%d ", l);
                if(l-3<0)
                {
                    for(j=l-3;j<l;j++)
                    {
                        putchar('-');
                    }

                    for(j=0;j<k+3;j++)
                    {
                        printf("%c", a[l+j]);
                    }
                    putchar('\n');
                }
                else if(l+k+3>i)
                {
                    //printf("data: %d %d %d\n", i-l, i, l);

                    j=l-3;
                    t=l-3;

                    while(j<t+(k+6))
                    {
                        if(j<i && B(a[j]))
                        {
                            printf("%c", a[j]);
                        }
                        else
                        {
                            putchar('-');
                        }
                        j++;
                    }

                    putchar('\n');
                }
                else
                {
                    //printf(" pr3 ");
                    for(j=0;j<k+6;j++)
                    {
                        printf("%c", a[l-3+j]);
                    }
                    putchar('\n');
                }
            }
        l++;
        }
    }
}

void kom(char *a, int i)
{
    int j;
    for(j=i;j>=0;j--)
    {
        if(a[j]=='A')
        {
            putchar('T');
        }
        else if(a[j]=='T' )
        {
            putchar('A');
        }
        else if(a[j]=='C')
        {
            putchar('G');
        }
        else if(a[j]=='G')
        {
            putchar('C');
        }
    }
    printf("\n");
}
void d(char *a, int i)
{
    char n1, n2;
    int j, pn1=0;
    double sum=0, p=0, vz=0;
    int t;
    printf("zadajte n1 a n2\n");
    getchar();
    scanf("%c %c", &n1, &n2);
    n1=X(n1);
    n2=X(n2);
    //printf("n1: %c, n2: %c\n", n1, n2);
    //system("pause");
    //getchar();
    if(B(X(n1)) && B(X(n2)))
    {
        for(j=0;j<i;j++)
        {
            if(a[j]==n1)
            {
                pn1++;
            }
        }
        for(j=0;j<i;j++)
        {
            if(a[j]==n1 && pn1>0)//dalsie A
            {
                t=j;
                while(t!=i)
                {
                    if(a[t]==n2)//zbiera C cka
                    {
                        sum=sum+vz;
                        p++;
                        vz++;
                    }
                    else
                    {
                        vz++;
                    }
                    t++;
                }
                vz=0;
                pn1--;
            }
        }
        printf("%.2lf\n", sum/p);
    }
    else
    {
        printf("Neplatny vstup\n");
    }
}
int main()
{
    FILE *f;
    char c='0';
    int i=0;//i je dlzka pola

    char *a=NULL;
    if((f=fopen("DNAsekvencia.dat", "r"))==NULL)
    {
        printf("Neotvoreny subor\n");
    }

    printf("v -vypis\n");
    printf("n -nacitanie\n");
    printf("h -histogram\n");
    printf("p -podsekvencia\n");
    printf("c -komplementarne vlakno\n");
    printf("d -priemer\n");
    printf("k -koniec\n");
    scanf("%c", &c);
    while(c!='k' || c!='K')
    {
        if(c==0)
        {
            printf("v -vypis\n");
            printf("n -nacitanie\n");
            printf("h -histogram\n");
            printf("p -podsekvencia\n");
            printf("c -komplementarne vlakno\n");
            printf("d -priemer\n");
            printf("k -koniec\n");
            getchar();
            scanf("%c", &c);
        }

        if(c=='v' || c=='V')
        {
            v(f);
            c=0;
        }
        else if(c=='n' || c=='N')
        {
            if(a!=NULL)
            {
                /*for(j=0;j<i;j++)
                {
                    printf("j:%d %c\n",j, a[j]);
                }*/
                free(a);
                a=NULL;
                a=(char*)malloc(1001*sizeof(char));
                for(i=0;i<1001;i++)
                {
                    a[i]=0;
                }
                i=0;
                n(f, &i, &a);
            }
            else
            {
                i=0;
                a=(char*)malloc(1001*sizeof(char));
                n(f, &i, &a);//alt &a a **b
            }

            c=0;
        }
        else if(c=='h' || c=='H')
        {
            if(a==NULL)
            {
                printf("Sekvencia nie je nacitana\n");
            }
            else
            {
                h(a, i);
            }
            c=0;
        }
        else if(c=='p' || c=='P')
        {
            if(a==NULL)
            {
                printf("Sekvencia nie je nacitana\n");
                c=0;
            }
            else
            {
                p(a, i);
                c=0;
            }
        }
        else if(c=='c' || c=='C')
        {
            if(a==NULL)
            {
                printf("Sekvencia nie je nacitana\n");
                c=0;
            }
            else
            {
                kom(a, i);
                c=0;
            }
        }
        else if(c=='d' || c=='D')
        {
            if(a==NULL)
            {
                printf("Sekvencia nie je nacitana\n");
                c=0;
            }
            else
            {
                d(a, i);
                c=0;
            }
        }
        else if(c=='k' || c=='K')
        {
            break;
        }
    }
    if(fclose(f)==EOF)
    {
        printf("Subor nemozno zatvorit\n");
    }
    return 0;
}

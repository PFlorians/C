/*autor: Patrik Florians
*IDE: Code::Blocks 12.11
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
typedef struct x
{
    char s[12];
    char i[15];
    char n[102];
    char a[102];
    char d[10];
    char c[10];
    struct x *next;
}X;

void n(FILE **f, X**fi, X**ac, int *bm)
{
    char b[102], dem;
    int count=0, count1=0, bl=0;
    if (*fi==NULL && *ac==NULL && (*f)!=NULL)
    {
        *fi=(X*)malloc(sizeof(X));
        *ac=*fi;
        while(count!=6)
        {
            fgets(b, 102, (*f));
            if (b[0]=='*')
            {
             ;
            }
            else
            {
                if (count==0)
                {
                    strcpy(*(&((*fi)->s)), b);//tu je zmena
                   // printf(">%s<\n", (*fi)->s);
                    count++;
                }
                else if(count==1)
                {
                    strcpy(*(&((*fi)->i)), b);
                    //printf(">%s<\n", (*fi)->i);
                    count++;
                }
                else if(count==2)
                {
                    strcpy(*(&((*fi)->n)), b);
                    //printf(">%s<\n", (*fi)->n);
                    count++;
                }
                else if(count==3)
                {
                    strcpy(*(&((*fi)->a)), b);
                    //printf(">%s<\n", (*fi)->a);
                    count++;
                }
                else if(count==4)
                {
                    strcpy(*(&((*fi)->d)), b);
                    //printf(">%s<\n", (*fi)->d);
                    count++;
                }
                else if(count==5)
                {
                    strcpy(*(&((*fi)->c)), b);
                    //printf(">%s<\n", (*fi)->c);
                    count++;
                }
                if(count>=6)
                {
                    bl++;
                    //printf("sest\n");
                    //count = 0;
                    (*ac)->next=(X*)malloc(sizeof(X));
                    (*ac)=(*ac)->next;
                }
            }
        }
        while(fgets(b, 102, (*f))!=NULL)
        {
             if (b[0]=='*')
            {
             ;
            }
            else
            {
            if (count1==0 && count>=6)
                {
                    strcpy(*(&((*ac)->s)), b);
                   // printf(">%s<\n", (*ac)->s);
                    count1++;
                }
            else if(count1==1)
                {
                    strcpy(*(&((*ac)->i)), b);
                    //printf(">%s<\n", (*ac)->i);
                    count1++;
                }
                else if(count1==2)
                {
                    strcpy(*(&((*ac)->n)), b);
                    //printf(">%s<\n", (*ac)->n);
                    count1++;
                }
                else if(count1==3)
                {
                    strcpy(*(&((*ac)->a)), b);
                   // printf(">%s<\n", (*ac)->a);
                    count1++;
                }
                else if(count1==4)
                {
                    strcpy(*(&((*ac)->d)), b);
                    //printf(">%s<\n", (*ac)->d);
                    count1++;
                }
                else if(count1==5)
                {
                    strcpy(*(&((*ac)->c)), b);
                    //printf(">%s<\n", (*ac)->c);
                    count1++;
                }
                if(count1>=6)
                {
                    bl++;
                    if((dem=getc(*f))=='*')
                    {
                    ungetc(dem, (*f));
                    count1=0;
                    (*ac)->next=(X*)malloc(sizeof(X));
                    (*ac)=(*ac)->next;
                    }
                    else
                    {
                        (*ac)->next=NULL;
                    }
                }
            }
        }
    }

    printf("Nacitalo sa %d zaznamov\n", bl);
    *bm=bl;
    rewind(*f);
}

void v(X **fi, X **ac, int *b)
{
    int i;
    (*ac)=(*fi);
    if((*fi)!=NULL)
    {
        for(i=0;i<(*b);i++)
        {
            printf("%d.\n", i+1);
            printf("signatura: %s", (*ac)->s);
            printf("isbn: %s", (*ac)->i);
            printf("nazov: %s", (*ac)->n);
            printf("autori: %s", (*ac)->a);
            printf("datum: %s", (*ac)->d);
            printf("preukaz: %s", (*ac)->c);
            if((*ac)->next==NULL)
            {
                break;
            }
            else
            {
                (*ac)=(*ac)->next;
            }
        }
    }
}
void p(X **fi, X **ac, int *b, X **al)
{
    int kam, i, d=0;
    char c[102];
    (*ac)=(*fi);
    scanf("%d", &kam);
    if (kam>=2 && kam<=(*b))//nacitavanie
    {
        for(i=0;i<(*b)+1;i++)
        {
            if (i==kam-2)
            {
                *al=(X*)malloc(sizeof(X));
                scanf("%s", c);
                d=strlen(c);
                c[d]='\n';
                c[d+1]='\0';
                strcpy(*(&((*al)->s)), c);
                scanf("%s", c);
                d=strlen(c);
                c[d]='\n';
                c[d+1]='\0';
                strcpy(*(&((*al)->i)), c);
                scanf("%s", c);
                d=strlen(c);
                c[d]='\n';
                c[d+1]='\0';
                strcpy(*(&((*al)->n)), c);
                scanf("%s", c);
                d=strlen(c);
                c[d]='\n';
                c[d+1]='\0';
                strcpy(*(&((*al)->a)), c);
                scanf("%s", c);
                d=strlen(c);
                c[d]='\n';
                c[d+1]='\0';
                strcpy(*(&((*al)->d)), c);
                scanf("%s", c);
                d=strlen(c);
                c[d]='\n';
                c[d+1]='\0';
                strcpy(*(&((*al)->c)), c);
                (*al)->next=(*ac)->next;
                (*ac)->next=(*al);
            }
            else
            {
                (*ac)=(*ac)->next;
            }
        }
        (*ac)->next=NULL;
    }
   if(kam==1)
    {
        for(i=0;i<(*b)+1;i++)
        {
            if (i==kam-1)
            {
                *al=(X*)malloc(sizeof(X));
                scanf("%s", c);
                d=strlen(c);
                c[d]='\n';
                c[d+1]='\0';
                strcpy(*(&((*al)->s)), c);
                scanf("%s", c);
                d=strlen(c);
                c[d]='\n';
                c[d+1]='\0';
                strcpy(*(&((*al)->i)), c);
                scanf("%s", c);
                d=strlen(c);
                c[d]='\n';
                c[d+1]='\0';
                strcpy(*(&((*al)->n)), c);
                scanf("%s", c);
                d=strlen(c);
                c[d]='\n';
                c[d+1]='\0';
                strcpy(*(&((*al)->a)), c);
                scanf("%s", c);
                d=strlen(c);
                c[d]='\n';
                c[d+1]='\0';
                strcpy(*(&((*al)->d)), c);
                scanf("%s", c);
                d=strlen(c);
                c[d]='\n';
                c[d+1]='\0';
                strcpy(*(&((*al)->c)), c);
               if((*ac)==(*fi))
               {
                   (*al)->next=(*fi);
                   (*ac)=(*al);
               }
            }
            else
            {
                (*ac)=(*ac)->next;
            }
        }
        (*fi)=(*al);
        (*ac)->next=NULL;
    }
    if(kam>(*b) || kam<=0)
    {
        for(i=0;i<=(*b);i++)
        {
            if(i==(*b)-1)
            {
                *al=(X*)malloc(sizeof(X));
                scanf("%s", c);
                d=strlen(c);
                c[d]='\n';
                c[d+1]='\0';
                strcpy(*(&((*al)->s)), c);
                scanf("%s", c);
                d=strlen(c);
                c[d]='\n';
                c[d+1]='\0';
                strcpy(*(&((*al)->i)), c);
                scanf("%s", c);
                d=strlen(c);
                c[d]='\n';
                c[d+1]='\0';
                strcpy(*(&((*al)->n)), c);
                scanf("%s", c);
                d=strlen(c);
                c[d]='\n';
                c[d+1]='\0';
                strcpy(*(&((*al)->a)), c);
                scanf("%s", c);
                d=strlen(c);
                c[d]='\n';
                c[d+1]='\0';
                strcpy(*(&((*al)->d)), c);
                scanf("%s", c);
                d=strlen(c);
                c[d]='\n';
                c[d+1]='\0';
                strcpy(*(&((*al)->c)), c);
                (*al)->next=NULL;
                (*ac)->next=(*al);
            }
            else
            {
                (*ac)=(*ac)->next;
            }
        }
    }

    /*(*ac)=(*fi);
    for(i=0;i<(*b)+1;i++)//vypis
    {
        printf("%d.\n", i+1);
        printf("s: %s", (*ac)->s);
        printf("s: %s", (*ac)->i);
        printf("s: %s", (*ac)->n);
        printf("s: %s", (*ac)->a);
        printf("s: %s", (*ac)->d);
        printf("s: %s", (*ac)->c);
        if((*ac)->next==NULL)
        {
            break;
        }
        else
        {
            (*ac)=(*ac)->next;
        }
    }*/
    (*b)=(*b)+1;
}
void h(X**fi, X**ac, int *b)
{
    int no, co=0,i, o=0;
    scanf("%d", &no);
    (*ac)=(*fi);
    if((*b)!=0)
    {
    for (i=0;i<(*b);i++)
    {
        co=atoi((*ac)->c);
        if (no==co)
        {
            printf("%d.\n", i+1);
            printf("signatura: %s", (*ac)->s);
            printf("isbn: %s", (*ac)->i);
            printf("nazov: %s", (*ac)->n);
            printf("autori: %s", (*ac)->a);
            printf("datum: %s", (*ac)->d);
            printf("preukaz: %s", (*ac)->c);
            o=1;
        }
        else if(no!=co && (*ac)->next==NULL)
        {
            printf("Pre dane cislo preukazu pozicky neevidujeme\n");
            break;
        }
        else
        {
            ;
        }
        if((*ac)->next==NULL)
        {
            //printf("null\n");
            break;
        }
        else
        {
            (*ac)=(*ac)->next;
        }
    }
    if (o==0 && i==(*b))
    {
        printf("Pre dane cislo preukazu pozicky neevidujeme\n");
    }
    }
    else
    {
         printf("Pre dane cislo preukazu pozicky neevidujeme\n");
    }
}
void z(X**fi, X**ac, int *b)
{
    char m[102], t[102];
    int i, j, temp, done=0, pocet=0;
    X *ten;//prev
    getchar();
    gets(m);

    for(i=0;i<=strlen(m);i++)
    {
        t[i]=toupper(m[i]);
        m[i]=t[i];
        t[i]=0;
    }
    (*ac)=(*fi);
//    p=(*fi);
    ten=(*fi);
    temp=strlen(m);
    m[temp]='\n';
    m[temp+1]='\0';
for (i=0;i<(*b);i++)
    {
        temp=strlen(ten->a);

        for(j=0;j<=temp;j++)
            {

                t[j]=toupper(ten->a[j]);
                if(j==temp)
                {
                    t[j]='\0';
                    if (strcmp(t, m)==0)
                    {
                        done=1;
                        break;
                    }
                }
            }
            if(done==1)
            {
                break;
            }
            else
            {
                if(ten->next!=NULL)
                {
                ten=ten->next;
                }
                else
                {
                    break;
                }
            }
    }

    (*ac)=(*fi);
    if((*fi)==ten)
    {
        (*fi)=(*fi)->next;
    }
    else
    {
        //act=((*fi));
        while((*ac)->next!=ten)
        {
            (*ac)=(*ac)->next;
        }

        (*ac)->next = ten->next;
        free(ten);
        pocet++;
    }

    /*ten=(*fi);
    temp=0;
    for (i=0;i<(*b);i++)
    {
        temp=strlen(ten->a);
        for(j=0;j<=temp;j++)
            {
                t[j]=toupper(ten->a[j]);
                if(j==temp)
                    {
                        t[j]='\0';
                if (strcmp(t, m)==0)
                {
                    clean=0;
                     done=1;
                    break;
                }
            }
        }
        if(done==1)
            {
                break;
            }
            else{
        if(ten->next!=NULL)
                {
                ten=ten->next;
                }
                else
                {
                    break;
                }
            }
    }

}*/
printf("zmazalo sa %d zaznamov\n", pocet);
}

void a(X**fi, X**ac, int *b)
{
    float no, co=0;
    int i, j, num=0;
    scanf("%f", &no);//mesiace a dni
    (*ac)=(*fi);
    for (i=0;i<(*b);i++)
    {
        co=atof((*ac)->d);
        if (co<=no)
        {
            num++;
            for(j=0;j<strlen((*ac)->d);j++)
            {
                if (j==3)//desiatky a nuly
                {
                    if((*ac)->d[3]>='0' && (*ac)->d[3]<='9')
                    {
                        (*ac)->d[3]=(*ac)->d[3]+1;
                    }
                    else if((*ac)->d[3]>=9)
                    {
                        (*ac)->d[3]='0';
                        if ((*ac)->d[3]=='0')
                        {
                            if((*ac)->d[2]>='0' && (*ac)->d[2]<='9')
                            {
                                (*ac)->d[2] = (*ac)->d[2]+1;
                            }
                            else if ((*ac)->d[2]>='9')
                            {
                                (*ac)->d[2]='0';
                                if ((*ac)->d[2]=='0')
                                {
                                     if((*ac)->d[1]>='0' && (*ac)->d[1]<='9')
                                    {
                                        (*ac)->d[1] = (*ac)->d[1]+1;
                                    }
                                    else if ((*ac)->d[1]>='9')
                                    {
                                        (*ac)->d[1]='0';
                                        if ((*ac)->d[1]=='0')
                                        {
                                            if((*ac)->d[0]>='0' && (*ac)->d[0]<='9')
                                            {
                                                (*ac)->d[0]=(*ac)->d[0]+1;
                                            }
                                            else if((*ac)->d[0]>='9')
                                            {
                                                (*ac)->d[3]='0';
                                                (*ac)->d[2]='0';
                                                (*ac)->d[1]='0';
                                                (*ac)->d[0]='0';
                                            }
                                        }
                                    }
                                    else
                                    {
                                        (*ac)->d[1]='0';
                                    }
                                }
                            }
                            else
                            {
                                (*ac)->d[2]=0;
                            }
                        }
                    }
                    else
                    {
                        (*ac)->d[3]='0';
                    }
                }
            }
        }
        if((*ac)->next==NULL)
        {
            //printf("null\n");
            break;
        }
        else
        {
            (*ac)=(*ac)->next;
        }
    }
    printf("Aktualizovalo sa %d zaznamov\n", num);
}
int main()
{
    FILE *f;
    X *fi=NULL, *ac=NULL, *al=NULL;
    int b=0;
    char c;
    //f=fopen("kniznica.txt", "r");
    while((c!='k' || c!='K')/* && ((c=getchar())=='\n')*/)
    {
        /*printf("n -nacitanie\n");
        printf("v -vypis\n");
        printf("p -pridanie\n");
        printf("h -preukzy\n");
        printf("a -aktualizacia\n");*/
        scanf("%c", &c);
        //getchar();
        if(c=='n' || c=='N')
        {
            f=fopen("kniznica.txt", "r");
            if(fi==NULL && ac==NULL)
            {
                n(&f, &fi, &ac, &b);
            }
            else
            {
                fi=NULL;
                ac=NULL;
                n(&f, &fi, &ac, &b);
            }

        }
        else if(c=='v' || c=='V')
        {
            if(f!=NULL)
            {
            v(&fi, &ac, &b);
            }
            else
            {
                printf("Subor nebol otvoreny\n");
            }
        }
        else if(c=='p' || c=='P')
        {
            if(fi!=NULL)
            {
                p(&fi, &ac, &b, &al);
            }
            else
            {
                printf("Subor nebol otvoreny\n");
            }
        }
        else if(c=='h' || c=='H')
        {
            if(fi!=NULL)
            {
            h(&fi, &ac, &b);
            }
            else
            {
                printf("Subor nebol otvoreny\n");
            }
        }
        else if(c=='z' || c=='Z')
        {
         if(fi!=NULL)
            {
            z(&fi, &ac, &b);
            }
            else
            {
                printf("Subor nebol otvoreny\n");
            }
        }
        else if(c=='a' || c=='A')
        {
            if(fi!=NULL)
            {
            a(&fi, &ac, &b);
            }
            else
            {
                printf("Subor nebol otvoreny\n");
            }
        }
        else
        {
            ;
        }
        if(c=='k' || c=='K')
        {
            break;
        }
    }

    fclose(f);
    return 0;
}

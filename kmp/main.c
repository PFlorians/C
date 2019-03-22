#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//kmp porovnavanie
int *prefix(char *p)
{
    int m=strlen(p);
    int pref[m];//zacinam od indexu 1
    int i=0;
    int j;
    pref[0]=0;
    for(j=1;j<m;j++)
    {
        while(i>0 && p[i]!=p[j])
        {
            i=pref[i];
        }
        if(p[i]==p[j])
        {
            i++;
        }
        pref[j]=i;
    }
    for(i=0;i<m;i++)
    {
        printf("%d ", pref[i]);
    }
    return pref;
}
int kmp(char *t, char *p)
{
    int m=strlen(p);
    int n=strlen(t);
    int *pref=prefix(p);
    int i=0;
    int j;
    for(j=0;j<n;j++)
    {
        while(i>0 && p[i]!=t[j])
        {
            i=pref[i];
        }
        if(p[i]==t[j])
        {
            i++;
        }
        if(i==m)
        {
            putchar('\n');
            printf("index: %d %d %d\n", j, j-m, j-i+1);
            return j-i+1;
        }
    }

    return -1;
}
int main()
{
    char *txt="ACAT ACGACACAGT";
    char *p="ACACAGT";
    int index;
    index=kmp(txt, p);
    return 0;
}

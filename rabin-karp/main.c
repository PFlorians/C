#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define abs(n) ((n)<0)?(n)*-1:(n)
//pocet znakov ascii abecedy je 256
#define d 256
//prvocislo pre hash funkciu
#define q 101
int rabinKarp(char *s, char *p)
{
    int m=strlen(p);
    int n=strlen(s);
    int i, j;
    int hp=0, hs=0;
    int h=1;

    for(i=0;i<m-1;i++)
    {
        h=(int)pow(d, m-1)%q;
    }
    //vypocet pre hashovacie hodnoty hp a hs
    for(i=0;i<m;i++)
    {
        hp=(d*hp+(int)p[i])%q;
        hs=(d*hs+(int)s[i])%q;
    }
    //jadro algoritmu
    for(i=0;i<=n-m;i++)
    {
        if(hp=hs)
        {
            for(j=0;j<m;j++)
            {
                if(p[j]!=s[i+j])
                {
                    break;
                }
            }
            //podpodmineka ak hp==hs a s[i...i+m-1]==p[1...m]
            if(j==m)
            {
                printf("vzor najdeny index: %d\n", i);
                return i;
            }
        }
        //prehladavanie dalsie podretazca ak predosle neplati
        if(i<n-m)
        {
            hs=(d*(hs-(int)s[i]*h)+s[i+m])%q;
            hs=abs(hs);//(hs<0)?hs+q:hs;//alebo abs(hs)
        }
    }
    return -1;
}
int main()
{
    char *t="trustthehardtoothbrushes";
    char *p="tooth";
    rabinKarp(t, p);
    return 0;
}

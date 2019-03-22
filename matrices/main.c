#include <stdio.h>
#include <stdlib.h>
void n(FILE **f, double **a)
{
    char c;
    int lines=0, *numbers, num=0;
    while((c=getc(*f))!=EOF)
    {
        if(c==' ')
        {
            ;
        }
        else if(c=='\n')
        {
            lines++;//riadky
        }
    }
    printf("%d\n", lines);
    numbers=(int*)malloc(lines*sizeof(int));
    rewind(*f);
     while((c=getc(*f))!=EOF)
    {
        if (c!=' ' && c!='\n')
        {

        }
    }
}
int main()
{
    FILE *f, *f2;
    double **ar, **a, **b;
    f=fopen("sparse.txt", "r");
    f2=fopen("sparse2.txt", "r");
    n(&f, &a);
    return 0;
}

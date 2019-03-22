#include <stdio.h>
#include <stdlib.h>

void shellSort(int a[], int n)
{
    int gap, i, j, tmp;
    gap=n;
    printf("%d\n", gap);
    while(gap)
    {
        printf("gap: %d\n", gap);
        for(i=gap;i<n;i++)
        {
            tmp=a[i];
            j=i;
            printf("%d %d\n", gap, i);
            //for(j=i;j>=h && t<a[j-h];j=j-h)
            while(j>=gap && tmp<a[j-gap])
            {
                printf("lower cycle: %d %d\n", j, j-gap);
                a[j]=a[j-gap];
                j=j-gap;
            }
            printf("j<gap||tmp>a[j-gap] %d %d j: %d gap: %d\n", tmp, a[j], j, gap);
            a[j]=tmp;
        }
        gap=gap/2;
    }
    printr(a, n);
}
void printr(int a[], int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d ", a[i]);
    }
}
int main()
{
    int a[12]={35, 5, 87, 158, 3, -45, 9, 0, 1, 1, 1, 3};
    //int a[] = {4, 65, 2, -31, 0, 99, 2, 83, 782, 1};
    shellSort(a, 12);
    return 0;
}

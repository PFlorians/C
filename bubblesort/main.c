#include <stdio.h>
#include <stdlib.h>

void bubblesort(int a[], int n)
{
    int i, j;
    int tmp;
    for(i=n;i>=0;i--)
    {
        for(j=0;j<i;j++)
        {
            if(a[j]>a[j+1])
            {
                tmp=a[j];
                a[j]=a[j+1];
                a[j+1]=tmp;
            }
        }
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
    bubblesort(a, 12);
    return 0;
}

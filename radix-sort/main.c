#include <stdio.h>
#include <stdlib.h>
//zatail nejde
int findMax(int a[], int n)
{
    int i, max=-99999;
    for(i=0;i<n;i++)
    {
        if(a[i]>max)
        {
            max=a[i];
        }
    }
    return max;
}
void printr(int a[], int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d ", a[i]);
    }
}
void countSortV2(int a[], int n, int exp)
{
    int res[n];
    int i, count[10];

    for(i=0;i<10;i++)
    {
        count[i]=0;
    }
    for(i=0;i<n;i++)
    {
        count[(a[i]/exp)%10]++;
        printf("%d %d\n", (a[i]/exp)%10, a[i]);
    }
    for(i=1;i<10;i++)
    {
        count[i]=count[i]+count[i-1];
    }
    for(i=n-1;i>=0;i--)
    {
        res[count[(a[i]/exp)%10]-1]=a[i];
        count[(a[i]/exp)%10]--;
    }
    for(i=0;i<n;i++)
    {
        a[i]=res[i];
    }
}
void radixSort(int a[], int n)
{
    int max=findMax(a, n);
    int exp=1;

    for(exp=1;max/exp>0;exp=exp*10)
    {
        countSortV2(a, n, exp);
    }
}
int main()
{
    //int a[12]={35, 5, 87, 158, 3, -45, 9, 0, 1, 1, 1, 3};
    //int a[] = {4, 65, 2, -31, 0, 99, 2, 83, 782, 1};
    //int a[]={4, 5, 9, 8, 4, 2, 2, 7, 6, 1};
    int a[]={346, 22,31,212,157,102,568,435,8,14,5};
    radixSort(a, 11);
    printr(a, 11);
    return 0;
}

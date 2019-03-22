#include <stdio.h>
#include <stdlib.h>
//zlozitost O(n^2), nestabilny vdaka velkemu prehadzovaniu prvkov pobabre postupnost klucov a elementov a tym porusi podmienku stability
void selectionSort(int a[], int n)
{
    int i, j, tmp;
    int min;//max index min index a max index
    for(i=0;i<n;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[min])//> ak descending pri max
            {
                min=j;
            }
        }
        tmp=a[i];
        a[i]=a[min];
        a[min]=tmp;
    }
    printr(a, n);
}
void stableSelectionSort(int a[], int n)
{
    int i, j, tmp;
    int min;
    int k, val;
    for(i=0;i<n;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[min])
            {
                min=j;
            }
        }
        val=a[min];//miesto obycajneho switchu reprezentuje posun hodnot
        for(k=min;k>i;k--)
        {
            a[k]=a[k-1];
        }
        a[k]=val;
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
    int a2[4]={2, 3, 1, 1};
    //selectionSort(a, 12);
    //stableSelectionSort(a2, 4);
    stableSelectionSort(a, 12);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
//O(n^2) stabilny, komparacny

void insertionSort(int a[], int n)
{
    int i, j;
    int tmp;
    for(i=0;i<n;i++)
    {
        j=i-1;
        tmp=a[i];
        while(j>=0 && tmp<a[j])//zarucuje stabilitu algoritmu
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=tmp;
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
    insertionSort(a, 12);
    return 0;
}

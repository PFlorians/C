#include <stdio.h>
#include <stdlib.h>
#define min(a,b) ((a)<(b))?(a):(b)
//O(nlog(n)) -> cas, pamat O(n)
/*//end1 a end2 je ako left roght pri deleni
void merge(int a[], int end1, int end2)
{
    int i=0;
    int j=end1;
    int k=0;
    int tmp[end2];

    //najmensi z oboch
    while(i<end1 && j<end2)
    {
        if(a[i]<a[j])
        {
            tmp[k]=a[i];
            i++;
        }
        else
        {
            tmp[k]=a[j];
            j++;
        }
        k++;
    }
    while(i<end1)
    {
        tmp[k]=a[i];
        i++;
        k++;
    }
    while(j<end2)
    {
        tmp[k]=a[j];
        j++;
        k++;
    }
    for(i=0;i<end2;i++)
    {
        a[i]=tmp[i];
    }
}
void mergeSort(int a[], int n)
{
    int i, j;

    for(i=1;i<n;i=2*i)
    {
        for(j=0;j<n-i;j=j+(2*i))
        {
            merge(&(a[j]), i, min((2*i), n-j));
        }
    }
    printr(a, n);
}*/
//verzia 2

void merge(int a[], int l, int n, int r)
{
    int i, j, k;
    int end1=n-l+1;
    int end2=r-n;
    int tl[end1], tr[end2];

    for(i=0;i<end1;i++)
    {
        tl[i]=a[l+i];
    }
    for(j=0;j<end2;j++)
    {
        tr[j]=a[n+j+1];//2+0+1, 2+1+1, 2+2+1 ak size==5
    }
    i=j=0;
    k=l;
    while(i<end1 && j<end2)
    {
        if(tl[i]<=tr[j])//'<=' je dovod stability v tejto implementacii
        {
            a[k]=tl[i];
            i++;
        }
        else
        {
            a[k]=tr[j];
            j++;
        }
        k++;
    }
    while(i<end1)
    {
        a[k]=tl[i];
        i++;
        k++;
    }
    while(j<end2)
    {
        a[k]=tr[j];
        j++;
        k++;
    }
    printr(a, 6);
}
//l-odkial r-pokial
void mergeSort(int a[], int l, int r)//l aj r lebo je to rekurzivna funkcia
{
    int n;//polovica vzdy polovica
    if(l<r)
    {
        n=(l+r)/2;
        mergeSort(a, l, n);//toto je lava polovica delenia
        mergeSort(a, n+1, r);
        merge(a, l, n, r);
    }

}
void printr(int a[], int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d ", a[i]);
    }
    putchar('\n');
}
int main()
{
    //int a[12]={35, 5, 87, 158, 3, -45, 9, 0, 1, 1, 1, 3};
    int a[6]={5, 1, 3, 5, 9, 7};
    mergeSort(a, 0, 6);
    printr(a, 6);
    return 0;
}

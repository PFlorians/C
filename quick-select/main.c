#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int *tmp;
    tmp=*a;
    *a=*b;
    *a=tmp;
}
int partition(int a[], int l, int r)
{
    int i;
    int s=l, e=r-1;
    int pivot=a[e];

    for(i=l;i<e;i++)
    {
        if(a[i]<=pivot)
        {
            swap(&a[i], &a[s]);
            s++;
        }
    }
    swap(&a[s], &a[e]);
    return s;
}
int quickSelect(int a[], int l, int r, int k)
{
    int q;
    printf("l: %d, r: %d k: %d\n", l, r, k);
    if(k>0 && k<r-l+1)
    {
        q=partition(a, l, r);
        printf("pivInd: %d\n", q);
        if(q-l==k-1)//k je zadane ze tretie ale vracana hodnota je index
        {
            printf("pripad1: q-l: %d q: %d l: %d val: %d\n", q-l, q, l, a[q]);
            return a[q];
        }
        else if(q-l>k-1)
        {
            printf("pripad2: %d q: %d l: %d k-q+l-1: %d\n", q-l, q, l, k-q+l-1);
            return quickSelect(a, l, q-1, k);
        }
        else
        {
            printf("pripad3: %d q: %d l: %d\n", q-l, q, l);
            return quickSelect(a, q+1, r, k-q+l-1);
        }
    }
    else
    {
        printf("k je vacsie nez velksot pola %d r-l+1: %d\n", k, r-l+1);
        return 99999;
    }
}
int main()
{
    int a[]={3, 7, 9, 1, 2, 26, 57, 124, 32};
    printf("vysledok %d\n", quickSelect(a, 0, 9, 3));
    return 0;
}

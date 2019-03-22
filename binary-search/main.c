#include <stdio.h>
#include <stdlib.h>

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
        if(tl[i]<=tr[j])
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
int binarySearch(int a[], int size, int target)
{
    int low=0;
    int high=size-1;
    int middle=(low+high)/2;
    int test;

    while(low<=high)
    {
        if(a[middle]<target)
        {
            low=middle+1;
        }
        else if(a[middle]==target)
        {
            printf("element found: %d\n", middle);
            return middle;
        }
        else
        {
            high=middle-1;
        }
        middle=(low+high)/2;
    }
    return -1;//onfailure
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
    srand(time(NULL));
    mergeSort(a, 0, 12);
    printr(a, 12);
    binarySearch(a, 12, 35);
    return 0;
}

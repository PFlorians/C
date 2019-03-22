#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//pivot je hodnota->kluc podla ktoreho sa zoraduje pole, hodnoty mensie ako kluc vlavo, vacsie vpravo
//particia pola na dve casti a[p...q] a a[q+1...r] kde p je start(index 0) a end je konecny index a.length
//lomutov model particie
int partition(int a[], int start, int end)
{
    int s=start, e=end-1;
    int pivot=a[e];
    //printf("pivot: %d\n", pivot);
    int i, tmp;
    for(i=start;i<e;i++)
    {
        printf("i: %d a[i]: %d\n", i, a[i]);
        if(a[i]<=pivot)
        {
            printf("prehadzujem: %d s %d\n", a[i], a[s]);
            tmp=a[i];
            a[i]=a[s];
            a[s]=tmp;
            s++;
        }
    }
    printf("prehadzujem zaver: %d s %d\n", a[s], a[e]);

    tmp=a[s];
    a[s]=a[e];
    a[e]=tmp;

    printr(a, 12);
    printf("\nend of partition %d\n", s);
    return s;
}
int partitionZostupne(int a[], int start, int end)
{
    int s=start, e=end-1;
    int pivot=a[e];
    printf("e: %d\n", a[e]);
    int i, tmp;
    for(i=start;i<e;i++)
    {
        printf("i: %d a[i]: %d, s: %d\n", i, a[i], s);
        if(a[i]>=pivot)
        {
            printf("prehadzujem: %d s %d\n", a[i], a[s]);
            tmp=a[i];
            a[i]=a[s];
            a[s]=tmp;
            s++;
        }
    }
    printf("prehadzujem zaver: %d s %d\n", a[s], a[e]);

    tmp=a[s];
    a[s]=a[e];
    a[e]=tmp;

    printr(a, 12);
    printf("\nend of partition %d pivot: %d\n", s, pivot);
    return s;
}
int hoarePartition(int a[], int start, int end)
{
    int s=start, e=end;
    int pivot=a[start];
    int tmp;

    while(s<e)
    {
        while(a[e]>pivot)
        {
            e--;
        }
        printf("koniec prvej slucky\n");
        while(a[s]<pivot)
        {
            s++;
        }
        printf("koniec druhej slucky\n");
        if(s<e)
        {
            printf("swapujem a[s:%d]=%d z a[e:%d]=%d\n", s, a[s], e, a[e]);
            tmp=a[s];
            a[s]=a[e];
            a[e]=tmp;
        }
        else
        {
            printf("returning %d\n", e);
            return e;
        }
    }
}
void quickSort(int a[], int start, int end)
{
    int q;//hranica cokolvek <q je mensie ako pivot a cokolvek >q je vacsie ako pivot toto nije pivot ale jeho pozicia
    if(start<end)
    {
        q=partitionZostupne(a, start, end);//hoarePartition(a, start, end);//partition(a, start, end);
        quickSort(a, start, q);
        quickSort(a, q+1, end);
    }
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
    quickSort(a, 0, 12);
    printr(a, 12);
    return 0;
}

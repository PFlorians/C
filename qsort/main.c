// uloha-11-2.c -- Tyzden 11 - Uloha 2
// Patrik Florians, 9.12.2015 20:23:20

#include <stdio.h>
#include <stdlib.h>

// Utriedi n cisel v poli a
void utried1(int *a, int n)
{
 int i, j, p, tmp;
  if(n>=2)
  {
      p=a[(n/2)];
        //printf("pivot: %d\n", p);
        //exit(0);
      i=0;
      j=n-1;
      while(1)
      {
          while(a[i]<p)
          {
              i++;
          }
          while(a[j]>p)
          {
              j--;
          }
          if(i>=j)
          {
              break;
          }
          printf("i: %d j: %d \n", i, j);
          tmp=a[i];
          a[i]=a[j];
          a[j]=tmp;
      }
      utried(a, i);
      utried(a+i, n-i);
  }

}
void hsort(int *arr, int N)
{
    if(N==0) // check if heap is empty
      return;

    int t; /* the temporary value */
    int n = N, parent = N/2, index, child; /* heap indexes */
    /* loop until array is sorted */
    while (1) {
        if (parent > 0) {
            /* first stage - Sorting the heap */
            printf("case1.0\n");
            t = arr[--parent];  /* save old value to t */
        } else {
            /* second stage - Extracting elements in-place */
            printf("case2.0\n");
            n--;                /* make the heap smaller */
            if (n == 0) {
                return; /* When the heap is empty, we are done */
            }
            t = arr[n];         /* save lost heap entry to temporary */
            arr[n] = arr[0];    /* save root entry beyond heap */
        }
        /* insert operation - pushing t down the heap to replace the parent */
        index = parent; /* start at the parent index */
        child = index * 2 + 1; /* get its left child index */
        printf("case 3.0 in: %d ch: %d tmp: %d\n", index, child, t);
        while (child < n) {
            /* choose the largest child */
            if (child + 1 < n  &&  arr[child + 1] > arr[child]) {
                child++; /* right child exists and is bigger */
                printf("case 4.0 child raising: %d\n", child);
            }
            /* is the largest child larger than the entry? */
            if (arr[child] > t) {
                arr[index] = arr[child]; /* overwrite entry with child */
                index = child; /* move index to the child */
                child = index * 2 + 1; /* get the left child and go around again */
                printf("overwrite in: %d, ch: %d\n", index, child);
            } else {
                break; /* t's place is found */
            }
        }
        /* store the temporary value at its new location */
        printf("end in: %d chld: %d tmp: %d\n", index, child, t);
        arr[index] = t;
    }
}
void sort(int *a, int n)
{
    int tmp;
    int hn=n, par=n/2, hi, hc;//heap n, parent, heap index, heap child
    if(n>0)
    {
    /*if(n==0)
    {
        return;
    }*/
        while(1)
        {
            if(par>0)
            {
                par--;
                tmp=a[par];
                printf("case1.0\n");
            }
            else
            {
                printf("case2.0\n");
                hn--;
                if(hn==0)
                {
                   // break;
                   return;
                }
                tmp=a[hn];
                a[hn]=a[0];
            }
            hi=par;
            hc=hi * 2 + 1;//lchild
            printf("case 3.0 in: %d ch: %d tmp: %d\n", hi, hc, tmp);
            while(hc<hn)
            {
                if(hc+1<hn && a[hc+1]>a[hc])
                {
                    hc++;
                    printf("case 4.0 child raising: %d\n", hc);
                }
                if(a[hc]>tmp)
                {
                    a[hi]=a[hc];
                    hi=hc;
                    hc=hi * 2 + 1;
                    printf("overwrite in: %d, ch: %d\n", hi, hc);
                }
                else
                {
                    break;
                }
            }
            printf("end in: %d chld: %d tmp: %d\n", hi, hc, tmp);
            a[hi]=tmp;
        }
    }
}
void radix(int *a, int n)
{
    int i, j, k;
    int list[10][n], pozl[10];
    int max=0, repeat=0;//najvacsie cislo, pocet opak pre cifry
    int divisor=1;
    int l;
    for(i=0;i<n;i++)
    {
        if(a[i]>max)
        {
            max=a[i];
        }
    }
    while(max>0)
    {
        repeat++;
        max/=10;
    }
    printf("pocet: %d\n", repeat);
    for(i=0;i<repeat;i++)
    {
        printf("pass: %d divisor: %d\n", i, divisor);
        for(j=0;j<10;j++)
        {
            pozl[j]=0;
        }
        for(j=0;j<n;j++)
        {
            k=(a[j]/divisor)%10;
            //printf("%d %d %d\n", k,  pozl[k], pozl[k]);
            list[k][pozl[k]++]=a[j];
        }
        j=0;
        for(k=0;k<10;k++)
        {

       printf("sucasnych[%d]: %d\n", k, pozl[k]);
            for(l=0;l<pozl[k];l++)
            {
                a[j++]=list[k][l];
            }
        }
        divisor*=10;
    }
}
radix_sort(int *arr, int n)
{
 int bucket[10][n],buck[10];
 int i,j,k,l,num,div,large,passes;

 div=1;
 num=0;
 large=arr[0];

 for(i=0 ; i<n ; i++)
 {
     printf("iteracia %d\n", i);
  if(arr[i] > large)
   {
    large = arr[i];
   }

  while(large > 0)
  {
   num++;
   large = large/10;
  }
    printf("pocet: %d\n", num);
  for(passes=0 ; passes<num ; passes++)
  {
      printf("pass: %d divisor: %d\n", passes, div);
   for(k=0 ; k<10 ; k++)
   {
    buck[k] = 0;
   }
   for(i=0 ; i<n  ;i++)
   {
    l = ((arr[i]/div)%10);
    bucket[l][buck[l]++] = arr[i];
   }

   i=0;
   for(k=0 ; k<10 ; k++)
   {
       printf("sucasnych[%d]: %d\n", k, buck[k]);
    for(j=0 ; j<buck[k] ; j++)
    {
        printf("i: %d\n", i);
     arr[i++] = bucket[k][j];
     printf("i: %d\n", i);
    }
   }
   div*=10;
  }
 }
}
void countingSort1(int *a, int n, int max)
{
    int i, j;
    int final[n], tmp[max+1];

    for(i=0;i<=max;i++)
    {
        tmp[i]=0;
    }
    for(j=0;j<n;j++)
    {
        printf("a: %d\n", a[j]);
        tmp[a[j]]=tmp[a[j]]+1;
        printf("tmp: %d\n", tmp[a[j]]);
    }
    printf("phase2\n");
    for(i=1;i<=max;i++)
    {
        printf("tmp2.0: %d %d\n", tmp[i], tmp[i-1]);
        tmp[i]=tmp[i]+tmp[i-1];
        printf("tmp2.1: %d %d\n", tmp[i], tmp[i-1]);
    }
    for(j=n-1;j>=0;j--)
    {
        printf("%d %d\n", tmp[a[j]], a[j]);
        final[tmp[a[j]]]=a[j];
        printf("f: %d a: %d\n", final[tmp[a[j]]], a[j]);
        tmp[a[j]]=tmp[a[j]]-1;
        printf("tmp_new: %d\n", tmp[a[j]]);
    }
    j=0;
    for(i=1;i<n+1;i++)
    {
        a[j]=final[i];
        j++;
    }
}
void countingSort(int *a, int n, int m)
{
    int i, j;
    int final[n], tmp[n];
    for(i=0;i<n;i++)
    {
        tmp[i]=0;
    }
    for(i=0;i<n;i++)
    {
        tmp[(a[i]/m)%n]+=1;
    }
    for(j=1;j<n;j++)
    {
        tmp[j]=tmp[j]+tmp[j-1];
    }
    for(i=n-1;i>=0;i--)
    {
        final[tmp[(a[i]/m)%n]-1]=a[i];
        tmp[(a[i]/m)%n]-=1;
    }

    for(i=0;i<n;i++)
    {
        a[i]=final[i];
    }
}
void utried2(int *a, int n)
{
    int max=0, i;
    for(i=0;i<n;i++)
    {
        if(a[i]>max)
        {
            max=a[i];
        }
    }
    countingSort1(a, n, max);
}
void utried(int *a, int n)
{
    countingSort(a, n, 1);
    countingSort(a, n, n);
}
int main(void)
{
  int i, *x, n, *y;

  scanf("%d", &n);
  x = (int*)malloc(n * sizeof(int));
  y=(int*)malloc(n * sizeof(int));
  for (i = 0; i < n; i++)
    scanf("%d", &x[i]);

for(i=0;i<n;i++)
{
      y[i]=x[i];
}

  utried(x, n);
//printf("##############################\n");
  //radix_sort(x, n);

  printf("%d", x[0]);
  for (i = 1; i < n; i++)
  {
    printf(" %d", x[i]);
    if (x[i-1] > x[i])
    {
      //printf(" -- CHYBA\n");
      //return 0;
    }
  }
  printf("\n");
/*printf("%d", y[0]);
  for (i = 1; i < n; i++)
  {
    printf(" %d", y[i]);
    if (y[i-1] > y[i])
    {
      printf(" -- CHYBA\n");
      return 0;
    }
  }
  printf("\n");*/
  printf("OK\n");
  return 0;
}

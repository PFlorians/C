#include <stdio.h>
#include <stdlib.h>
#define lchild(x) 2*(x)+1
#define rchild(x) 2*(x)+2
#define parent(x) (x)/2

typedef struct node
{
    int val;
}node;

typedef struct maxHeap
{
    int size;
    node *n;
}maxHeap;

void levelOrder(maxHeap *h)
{
    int i;

    for(i=0;i<h->size;i++)
    {
        printf("%d ", h->n[i].val);
    }
    putchar('\n');
}
maxHeap *newHeap()
{
    maxHeap *tmp;
    tmp=malloc(sizeof(maxHeap));
    tmp->size=0;
    tmp->n=NULL;
    return tmp;
}
void swap(node *n1, node *n2)
{
    node tmp;
    tmp=*n1;
    *n1=*n2;
    *n2=tmp;
}
maxHeap insert(maxHeap *h, int val)
{
    maxHeap *tmp;
    int i;
    node new;
    if(h->size)
    {
       h->n=realloc(h->n, (h->size+1)*sizeof(node));
    }
    else
    {
       h->n=malloc(sizeof(node));
    }

    new.val=val;
    i=h->size;
    h->size++;
    while(i && new.val>h->n[parent(i)].val)
    {
        h->n[i]=h->n[parent(i)];
        i=parent(i);
    }
    h->n[i]=new;
}
void maxHeapify(maxHeap *h, int index)
{
    int largest=index;//ondefault

    if(h->n[lchild(index)].val>h->n[index].val && lchild(index)<h->size)
    {
        largest=lchild(index);
    }

    if(h->n[rchild(index)].val>h->n[largest].val && rchild(index)<h->size)
    {
        largest=rchild(index);
    }

    if(largest!=index)//ak toto plati tak koren musi byt zmeneny, heapify je rekurzivna f-cia iducea zdola hore
    {
        swap(&(h->n[largest]), &(h->n[index]));
        maxHeapify(h, largest);
    }
}
maxHeap *buildMaxHeap(int *a, int size)
{
    maxHeap *h;
    int i;
    node n;
    h=(maxHeap*)malloc(sizeof(maxHeap));
    h->size=0;
    h->n=NULL;
    for(i=0;i<size;i++)
    {
        if(h->size)
        {
            h->n=realloc(h->n, (h->size+1)*sizeof(node));
        }
        else
        {
            h->n=malloc(sizeof(node));
        }
        n.val=a[i];
        h->n[h->size]=n;
        h->size++;
    }
    for(i=(h->size-1)/2;i>=0;i--)//minus jedna koli indexu
    {
        maxHeapify(h, i);
    }
    return h;
}
void printr(int a[], int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d ", a[i]);
    }
}
void heapsort(int *a, int size)
{
    maxHeap *h;
    h=buildMaxHeap(a, size);
    int i=0, b[size];

    while(h->size>=1)//az dokym sa halda nevyprazdni
    {
        b[i]=h->n[0].val;
        i++;
        swap(&(h->n[0]), &(h->n[h->size-1]));//toto je v podstate odstranovanie maxima stale dookola
        h->size--;
        maxHeapify(h, 0);
    }

    printr(b, 8);
}
int main()
{
    int a[]={6,5,3,1,8,7,2,4};
    heapsort(a, 8);
    //printr(a, 8);
    return 0;
}

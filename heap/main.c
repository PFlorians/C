#include <stdio.h>
#include <stdlib.h>

#define lchild(x) 2*(x)+1
#define rchild(x) 2*(x)+2
#define parent(x) (x)/2

typedef struct node
{
    int data;

}node;

typedef struct minHeap
{
    int size;
    node *n;
}minHeap;

void levelOrder(minHeap *h)
{
    int i;
    for(i=0;i<h->size;i++)
    {
        printf("%d ", h->n[i].data);
    }
}
void swap(node *n1, node *n2)
{
    node tmp;
    tmp=*n1;
    *n1=*n2;
    *n2=tmp;
}
minHeap *newMinHeap()
{
    minHeap *h;

    h=(minHeap*)malloc(sizeof(minHeap));
    h->size=0;
    h->n=NULL;
    return h;
}
void insert(minHeap *h, int data)
{
    node nd;
    int i;
    nd.data=data;
    if(h->size)
    {
        h->n=realloc(h->n, (h->size+1)*sizeof(node));
    }
    else
    {
        h->n=malloc(sizeof(node));
    }

    i=(h->size)++;

    printf("i: %d, data: %d\n", i, data);
    while(i && h->n[parent(i)].data>nd.data)//zmenit na h->n[parent(i)].data<nd.data pri max heap
    {
        printf("i: %d par(i): %d %d>%d\n", i, parent(i), h->n[parent(i)].data, nd.data);
        h->n[i]=h->n[parent(i)];
        i=parent(i);
    }
    h->n[i]=nd;
}

void heapify(minHeap *h, int i)
{
    int smallest;//largest pri max-heap

    if(lchild(i)<h->size && h->n[lchild(i)].data < h->n[i].data)//max-heap druha cast na= h->n[lchild(i)].data > h->n[i].data
    {
        smallest=lchild(i);
    }
    else
    {
        smallest=i;
    }
    if(rchild(i)<h->size && h->n[rchild(i)].data<h->n[smallest].data)//tak ako v hore uvedenej podm
    {
        smallest=rchild(i);
    }
    if(smallest!=i)
    {
        printf("heapify switching: %d with %d\n", h->n[i].data, h->n[smallest].data);
        swap(&(h->n[i]), &(h->n[smallest]));//ked je nahodou niekde narusena rovnovaha tak sa proste vymenia dva uzly
        heapify(h, smallest);//takto sa kontroluje cely strom(halda) vzdy pocnuc nejakym vrcholom tj smallest
    }
}
void delete(minHeap *h)
{
    if(h->size)
    {
        printf("mazanie najmensieho prvku: %d\n", h->n[0].data);
        h->n[0]=h->n[--(h->size)];//vymen prvy za posledny zmensi udaj o velkosti resp pocte uzlov
        printf("nahrada: %d\n", h->n[0].data);
        h->n=realloc(h->n, (h->size)*sizeof(node));//odstrani ten posledny list
        heapify(h, 0);//kedze som vymenil male za velke tak treba najst najmensi vrchol v strome aby sa dodrzala haldovitost
    }
    else
    {
        printf("heap is empty\n");
    }
}
void buildMinHeap(minHeap *h, int *a, int size)
{
    int i;
    node nd;
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
        nd.data=a[i];
        h->n[(h->size)++]=nd;
    }
    for(i=(h->size-1)/2;i>=0;i--)
    {
        heapify(h, i);
    }
}

void preOrder(minHeap *h, int i)
{
    if(lchild(i)<h->size)
    {
        preOrder(h, lchild(i));
    }
    if(rchild(i)<h->size)
    {
        preOrder(h, rchild(i));
    }
    printf("%d ", h->n[i].data);
}
int main()
{
    minHeap *h;
    h=newMinHeap();
    insert(h, 7);
    insert(h, 10);
    insert(h, 9);
    insert(h, 1);
    insert(h, 2);
    insert(h, 8);

    levelOrder(h);
    putchar('\n');
    delete(h);
    levelOrder(h);
    putchar('\n');
    return 0;
}

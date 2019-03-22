#include <stdio.h>
#include <stdlib.h>

#define lchild(x) 2*(x)+1
#define rchild(x) 2*(x)+2
#define parent(x) (x)/2
#define abs(x) ((x)<0)?-(x):(x)
typedef struct node
{
    int data;
}node;
typedef struct maxHeap
{
    int size;
    node *n;
}maxHeap;
typedef struct minHeap
{
    int size;
    node *n;
}minHeap;
void swap(node *a, node *b)
{
    node tmp;
    tmp=*a;
    *a=*b;
    *b=tmp;
}
minHeap *newMinHeap()
{
    minHeap *mh;
    mh=malloc(sizeof(minHeap));
    mh->size=0;
    mh->n=NULL;
    return mh;
}
maxHeap *newMaxHeap()
{
    maxHeap *mh;
    mh=malloc(sizeof(maxHeap));
    mh->size=0;
    mh->n=NULL;
    return mh;
}
void insert_min(minHeap *mh, int data)
{
    int i;
    node newNode;
    printf("insertmin: %d\n", data);
    if(mh->size)
    {
        mh->n=realloc(mh->n, (mh->size+1)*sizeof(node));
    }
    else
    {
        mh->n=malloc(sizeof(node));
    }

    newNode.data=data;
    i=mh->size;
    mh->size++;
    while(i && newNode.data<mh->n[parent(i)].data)
    {
        mh->n[i]=mh->n[parent(i)];
        i=parent(i);
    }
    mh->n[i]=newNode;
    printMiHeap(mh);
}
void insert_max(maxHeap *mh, int data)
{
    int i;
    node newNode;
    printf("insertmax: %d\n", data);
    if(mh->size)
    {
        mh->n=realloc(mh->n, (mh->size+1)*sizeof(node));
    }
    else
    {
        mh->n=malloc(sizeof(node));
    }
    newNode.data=data;
    i=mh->size;//size da vzdycky posledny index cize zaciname odspodu podla tvaru haldy
    mh->size++;

    while(i && newNode.data>mh->n[parent(i)].data)
    {
        mh->n[i]=mh->n[parent(i)];
        i=parent(i);
    }
    mh->n[i]=newNode;
    printMxHeap(mh);
}
void minHeapify(minHeap *mh, int root)//kontrola haldovitosti
{
    int smallest=root;

    if(lchild(root)<mh->size && mh->n[lchild(root)].data<mh->n[root].data)
    {
        smallest=lchild(root);
    }
    if(rchild(root)<mh->size && mh->n[rchild(root)].data<mh->n[smallest].data)
    {
        smallest=rchild(root);
    }
    if(smallest!=root)
    {
        swap(&(mh->n[root]), &(mh->n[smallest]));
        minHeapify(mh, smallest);
    }
}
void maxHeapify(maxHeap *mh, int root)
{
    int largest=root;

    if(lchild(root)<mh->size && mh->n[lchild(root)].data>mh->n[root].data)
    {
        largest=lchild(root);
    }
    if(rchild(root)<mh->size && mh->n[rchild(root)].data>mh->n[largest].data)
    {
        largest=rchild(root);
    }
    if(largest!=root)
    {
        swap(&(mh->n[root]), &(mh->n[largest]));
        maxHeapify(mh, largest);
    }
}
int getMinVal(minHeap *mh)
{
    return mh->n[0].data;
}
int getMaxVal(maxHeap *mh)
{
    return mh->n[0].data;
}
void deleteMin(minHeap *mh)
{
    if(mh->size)
    {
        mh->size--;
        mh->n[0]=mh->n[mh->size];
        mh->n=realloc(mh->n, (mh->size)*sizeof(node));
        minHeapify(mh, 0);
        printMiHeap(mh);
    }
    else
    {
        printf("halda je prazdna\n");
        return;
    }
}
void deleteMax(maxHeap *mh)
{
    if(mh->size)
    {
        mh->size--;
        mh->n[0]=mh->n[(mh->size)];
        mh->n=realloc(mh->n, (mh->size)*sizeof(node));
        maxHeapify(mh, 0);
        printMxHeap(mh);
    }
    else
    {
        printf("maxHeap je prazdna\n");
    }
}
void insertInt(minHeap *mi, maxHeap *mx, int data)
{
    int top;
    insert_max(mx, data);

    if((mx->size-mi->size)>1 || (mi->size!=0 && mx->n[0].data>mi->n[0].data))
    {
        top=mx->n[0].data;
        printf("pripad1: %d\n", top);
        deleteMax(mx);
        insert_min(mi, top);
    }
    if((mi->size!=0) && (mi->size-mx->size)>1)
    {
        top=mi->n[0].data;
        printf("pripad2: %d\n", top);
        deleteMin(mi);
        insert_max(mx, top);
    }
}
void printMedian(minHeap *mi, maxHeap *mx)
{
    if(mi->size==mx->size)
    {
        printf("median hodnot je %d mx: %d mi: %d\n", (abs(mx->n[0].data - mi->n[0].data))/2, mx->n[0].data, mi->n[0].data);
    }
    else if(mx->size>mi->size)
    {
        printf("median vacsia halda %d\n", mx->n[0].data);
    }
    else
    {
        printf("median mensia halda %d\n", mi->n[0].data);
    }
}

void printMxHeap(maxHeap *h)
{
    int i;
    for(i=0;i<h->size;i++)
    {
        printf("%d ", h->n[i].data);
    }
    putchar('\n');
}
void printMiHeap(minHeap *h)
{
    int i;
    for(i=0;i<h->size;i++)
    {
        printf("%d ", h->n[i].data);
    }
    putchar('\n');
}
int main()
{
    minHeap *mi;
    maxHeap *mx;
    mi=newMinHeap();
    mx=newMaxHeap();
    insertInt(mi, mx, 2);
    insertInt(mi, mx, 9);
    insertInt(mi, mx, 7);
    insertInt(mi, mx, 4);
    insertInt(mi, mx, 1);
    printMedian(mi, mx);
    insertInt(mi, mx, 6);
    insertInt(mi, mx, 8);
    insertInt(mi, mx, 5);
    printMedian(mi, mx);
    printf("max: \n");
    printMxHeap(mx);
    printf("min: \n");
    printMiHeap(mi);
    return 0;
}

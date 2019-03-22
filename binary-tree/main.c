#include <stdio.h>
#include <stdlib.h>
/*
* teoreticke poznatky
* existuju dve mozne implementacie polia a[] alebo struktura
* ani jedna implementacia sa nevyhne pouzitiu struktury struct node{int data, node left, node right};
* v pripade struktur su left a right smerniky v kvazi spajanom zozname, velkost pouzivajuca smerniky je INF
* polia maju obmedzenu velkost pripadne pouzivaju realloc()
* hlavne operacie su insert, delete, findMin/max, buildTree, find
* traverzia cez strom je inorder, preorder, postorder alebo depth-first ci breadth-first algoritmy
*/
//binarny vyhladavaci strom
typedef struct node//cely strom je mnozniou takychto uzlov
{
    int data;
    struct node *left;
    struct node *right;
}node;

node *newTree(int data)
{
    node *root;

    root=(node*)malloc(sizeof(node));
    root->data=data;
    root->left=root->right=NULL;

    return root;
}
//operacia insert
node *insert(node *n, int data)
{
    if(n==NULL)
    {
        return newTree(data);
    }
    else if(data<n->data)
    {
        n->left=insert(n->left, data);
    }
    else if(data>n->data)
    {
        n->right=insert(n->right, data);
    }
    return n;
}
node *findMin(node *n)
{
    if(n==NULL)
    {
        return NULL;
    }
    if(n->left)
    {
        return findMin(n->left);
    }
    else
    {
        return n;
    }
}
node *findMax(node *n)
{
    if(n==NULL)
    {
        return NULL;
    }
    if(n->right)
    {
        return findMax(n->right);
    }
    else
    {
        return n;
    }
}
node *find(node *n, int data)
{
    if(n==NULL)
    {
        return NULL;
    }
    else if(data<n->data)
    {
        return find(n->left, data);
    }
    else if(data>n->data)
    {
        return find(n->right, data);
    }
    else
    {
        return n;//najedene moze to byt aj root
    }
}
// traversing functions
void preOrder(node *n)
{
    if(n==NULL)
    {
        return;
    }
    printf("%d ", n->data);
    preOrder(n->left);
    preOrder(n->right);
}
void inOrder(node *n)
{
    if(n==NULL)
    {
        return;
    }
    inOrder(n->left);
    printf("%d ", n->data);
    inOrder(n->right);
}
node *delete(node *n, int data)
{
    node *tmp;

    if(n==NULL)
    {
        printf("element not found\n");
    }
    else if(data<n->data)
    {
        n->left=delete(n->left, data);
    }
    else if(data>n->data)
    {
        n->right=delete(n->right, data);
    }
    else
    {
        if(n->left && n->right)//pripad vrchol obe deti
        {
            //vymazat bud min z praveho podstromu alebo max z laveho podstromu
            tmp=findMin(n->right);
            n->data=tmp->data;//nahradime hodnotou inehi uzla posledneho lebo to je jednoduchsi pripad
            n->right=delete(n->right, tmp->data);//teraz uz len odstranit ten posledny list
        }
        else
        {
            if(n->left==NULL)
            {
                n=n->right;
            }
            else if(n->right==NULL)
            {
                n=n->left;
            }
        }
    }
    return n;
}
int main()
{
    node *root, *tmp;

    tmp=root=newTree(20);
    root=insert(root, 31);
    root=insert(root, 45);
    root=insert(root, 10);
    root=insert(root, 28);

    root=delete(root, 20);
    preOrder(root);
    putchar('\n');
    inOrder(root);
    return 0;
}

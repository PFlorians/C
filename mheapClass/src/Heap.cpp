#include "../include/Heap.h"
#include <cstring>
#include <stdio.h>
int Heap::counter = 0;

Heap::Heap()
{
    counter++;
    size=0;
}
int Heap::getSize()
{
    return this->size;
}
int Heap::getCounter()
{
    return Heap::counter;
}
void Heap::setSize(int i)
{
    this->size=i;
}
void Heap::swap(void **obj1, void **obj2, unsigned int objsize)//pass address here
{
    void *tmp=new char[objsize];//podobne ako *tmp=new char[objsize]
    /*memcpy(&tmp, &obj1, objsize);
    memcpy(&obj1, &obj2, objsize);
    memcpy(&obj2, &tmp, objsize);*/
    tmp=(*obj1);
    (*obj1)=(*obj2);
    (*obj2)=tmp;
    printf("swap %d %d \n", (*obj1), (*obj2));
}

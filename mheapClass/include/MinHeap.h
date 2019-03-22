#ifndef MINHEAP_H
#define MINHEAP_H
#include "heap.h"
#include <iostream>
#include <vector>

#define lchild(x) 2*(x)+1
#define rchild(x) 2*(x)+2
#define parent(x) (x)/2
using namespace std;

class MinHeap: public Heap
{
    private:
        vector<heapObject *> h;
    public:
        MinHeap();
        ~MinHeap(){};//musi byt aj keby nadtrieda mala pure virtual ~destr() = 0; musel by existovat inline Class::~Class(){};
        //ak nieje definovany konstruktor a dojde k likvidacii objektu tak nastane nedefinovane spravanie lebo by nemal spravanie
        void ins(void *_object, int priority=4);//custom implemented version
        void del();//vymaze posledny objekt vzhladom na podmienky haldovitosti
        void heapify(int index);
        vector<heapObject*> getHeapObjectVector();
        heapObject getMin();
};

#endif // MINHEAP_H

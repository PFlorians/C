#ifndef HEAP_H
#define HEAP_H
#include <iostream>
typedef struct heapObject//objekt ktory sa uklada do heapu, toto je wrapper resp. container
{
    void *_objp;
    int priority;
    int index;
}heapObject; //cele pole ma byt z tejto veci zlozene

class Heap//absrtact
{
    private:
        int size;//pocita pocet uzlov
        static int counter;//pocita mnozstvo hald
    public:
        Heap();//init basic properties
        virtual ~Heap(){};
        virtual void ins(void *_object, int priority=4)=0;//should not be implemented here
        virtual void del()=0;//vymaze posledny objekt vzhladom na podmienky haldovitosti
        virtual void heapify(int index)=0;
        int getSize();
        int getCounter();
    protected:
        void setSize(int i);//nikto okrem min alebo max heap
        void swap(void *obj1, void *obj2);//adresa musi byt argumentom
        void swap(void **obj1, void **obj2, unsigned int objsize);//adresa musi byt argumentom

};

#endif // HEAP_H

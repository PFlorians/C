#include "../include/MinHeap.h"
#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <typeinfo>
#include <cxxabi.h>

using namespace std;

//constructor /dest
MinHeap::MinHeap()
{
    this->setSize(0);
}
heapObject MinHeap::getMin()
{
   // return this->h.at(0);
}

//utilitary
vector<heapObject*> MinHeap::getHeapObjectVector()
{
    return this->h;
}

//algorithmic overload
void MinHeap::ins(void *_object, int priority)//4 vyhradene ako default hodnota
{
    void *trace[20];
    char **stopa;

    int *status;
    heapObject *hp=new heapObject();
    int i, velkost;
    hp->_objp=_object;
    hp->priority=(priority==4)?3:priority;

    void *tmp=NULL;
    const type_info & t=typeid(_object);
    printf("nazov: %s \n", abi::__cxa_demangle(t.name(), 0, 0, status));

    //printf("type objektu ktory sem vchadza: %s\n", t)
    if(this->getSize()==0)
    {
        hp->index=0;
        this->h.push_back(hp);
        i=this->getSize();//increment potom pre podminku kde size==0
        this->setSize(this->h.size());
    }
    else//nieco tam uz musi byt
    {
        hp->index=(this->h.back())->index+1;//ten index je len orientacny(zatial)
        this->h.push_back(hp);//najprv len dozadu, prvok je posledny
        i=this->getSize();//increment potom pre podminku kde size==0
        this->setSize(this->h.size());
        printf("velkost s vkladanym: %d\n", this->getSize());
        //printf("pare addr: %d chil: %d %d %d %d\n", this->h.at(parent(i)), this->h.at(i), i, parent(i), hp);
        //printf("parent: %d size: %d\n", (this->h.at(parent(i))), sizeof(this->h.at(i)));
        //debug
        /*h1=static_cast<void*>(this->h.at(parent(i)));
        h2=static_cast<void*>(this->h.at(i));
        printf("p: %d c: %d sz: %d\n", h1, h2, sizeof(this->h.at(i)));
        memcpy(&tmp, &h1, sizeof(heapObject));
        memcpy(&h1, &h2, sizeof(heapObject));
        memcpy(&h2, &tmp, sizeof(heapObject));
        //tmp=h1;
        //h1=h2;
        //h2=tmp;
        printf("p: %d c: %d\n", h1, h2);
        exit(1);*/
        /*while(i && ((this->h.at(parent(i)))->priority > hp->priority))
        {
            printf("pred prehodenim: %d %d \n", this->h.at(i), this->h.at(parent(i)));

            tmp=static_cast<void*>(this->h.at(parent(i)));
            this->h.at(parent(i))=(this->h.at(i));
            this->h.at(i)=static_cast<heapObject*>(tmp);

            //this->swap(static_cast<void*>(this->h.at(i)), (static_cast<void*>(this->h.at(parent(i)))), sizeof(heapObject));
            printf("po prehodeni: %d %d \n",  this->h.at(i), this->h.at(parent(i)));
            i=parent(i);
        }*/
        //printf("velkost: %d index: %d\n", this->getSize(), parent(i));
        //this->h.insert(this->h.begin()+i, hp);//tu sa uz presne vklada na zistenu poziciu
        //this->h.pop_back();
    }
    for(i=0;i<this->h.size();i++)
    {
        printf("i: %d priorita: %d adresa_obj: %d\n", i, this->h.at(i)->priority, this->h.at(i)->_objp);
    }
//implementacia while cyklu insert into vid algoritmus
}
void MinHeap::del()
{

}
void MinHeap::heapify(int index)
{
    int smallest;


}
//getters/setters

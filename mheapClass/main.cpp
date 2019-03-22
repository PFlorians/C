#include <iostream>
#include <vector>
#include "include/MinHeap.h"
#include <stdio.h>
#include <typeinfo>
#include <cxxabi.h>
#include "DebugUtilitary.h"
#include <csignal>

//https://gcc.gnu.org/faq.html
using namespace std;
using namespace duc;
typedef struct testLeaf
{
    int data;
}testLeaf;

int main()
{
    int *status;
    SignalHandlers sh;
   // void (SignalHandlers::*handle1)(int) = NULL;
    void (*handle1)(int);
    void (*smerovac)(int);
    smerovac = reinterpret_cast<void (*)(int)> (&SignalHandlers::invalidMemoryAccessSignal);//nebezpecny cast, je lepsie sa tomu vyhnut
    //bolo by lepsie to riesit cez static metody alebo obycajne funkcie bez triedy
    handle1 = signal(SIGSEGV, smerovac);
    //sh->setBacktraceFname("subor.cfg");
    //printf("subor: %s\n", sh->getBacktraceFname());
    return 0;
    testLeaf *tl = new testLeaf;
    testLeaf *tl1 = new testLeaf;
    testLeaf *tl2 = new testLeaf;
    testLeaf *tl3 = new testLeaf;
    tl->data=777;
    tl1->data=123;
    tl2->data=444;
    const type_info &t = typeid(tl);
    printf("demangled: %s\n", abi::__cxa_demangle(t.name(), 0, 0, status));

    MinHeap *mh=new MinHeap();
    vector<heapObject*> h = mh->getHeapObjectVector();
    // << tl << " " << *tl << " " << &tl <<  endl;
    printf("%d %d %d %d\n", tl, tl1, tl2, tl3);
    mh->ins(tl);
    mh->ins(tl1, 1);
    mh->ins(tl2, 2);
    mh->ins(tl3, 2);
    h=mh->getHeapObjectVector();
    //printf("%d\n", h.front()->_objp);
    //cout << h.front().index << " data: " << tl << endl;
    //cout << "obj2: " << h.back().index << " data: " << h.back().data << endl;
    //mh->ins(tl);

    delete tl;
    delete tl1;
    delete tl2;
    delete tl3;
    delete mh;
    return 0;
}

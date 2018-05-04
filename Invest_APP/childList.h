#ifndef CHILDLIST_H_INCLUDED
#define CHILDLIST_H_INCLUDED

#include <iostream>
using namespace std;

#define next(P) P->next
#define prev(P) P->prev
#define first(L) L.first
#define last(L) L.last
#define info(P) P->info

typedef struct infotypeChild;
typedef struct elmlist_child *address_child;

struct infotypeChild{
    string namaOrang;
    int budget;
};

struct elmlist_child{
    infotypeChild info;
    address_child next;
    address_child prev;

 };
struct List_child{
    address_child first;
    address_child last;
};

address_child searchChild(List_child L,string nama);
void createList(List_child &L);
void insertFirst(List_child &L, address_child P);
void deleteChild(List_child &L, address_child &Prec, string nama);
address_child alokasi(infotypeChild x);
void dealokasi(address_child &P);
void printInfo(List_child L);

#endif // CHILDLIST_H_INCLUDED

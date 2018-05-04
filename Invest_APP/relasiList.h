#ifndef RELASILIST_H_INCLUDED
#define RELASILIST_H_INCLUDED

#include "relasiList.h"
#include "childList.h"
#include "parentList.h"

#include <iostream>
using namespace std;

#define next(P) P->next
#define info(P) P->info
#define first(L) L.first
#define child(P) P->child
#define parent(P) P->parent

typedef struct elmlist_relasi *address_relasi;

struct infotype_relasi {
    string  tgl_join;
    string tgl_keluar;
    float keuntungan;
    int jumlah_pohon;
    float kerugian;
    int total;
};

struct elmlist_relasi{
    infotype_relasi info;
    address_relasi next;
    address_child child;
    address_parent parent;
};

struct list_relasi{
    address_relasi first;
};

void createList(list_relasi &L);
address_relasi alokasi(infotype_relasi x,List_parent LP,List_child LC,string namaOrang,string namaPohon);
address_relasi searchRelasi(list_relasi L,string nama1);
void insertFirst(list_relasi &L, address_relasi P);
void insertLast(list_relasi &L, address_relasi P);
void dealokasi(address_relasi &P);
void tengah2(int width, char* s);
void printInfo(list_relasi L);

#endif // RELASILIST_H_INCLUDED

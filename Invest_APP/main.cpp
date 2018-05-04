#include <iostream>
#include <stdlib.h>
#include <conio.h>

using namespace std;

#include "parentList.h"
#include "relasiList.h"
#include "menu.h"
#include "childList.h"

int main()
{
    List_parent LP;
    createList(LP);
    infotypeParent X;
    address_parent P,L;
    string cari;
    X.namaPohon = "Mangga";
    X.biayaPohon = 250000;
    X.profitPohon = 2;
    X.lossPohon = 10;
    X.stockPohon = 20;
    insertFirst(LP,P = alokasi(X));
    X.namaPohon = "Pisang";
    X.biayaPohon = 250000;
    X.profitPohon = 11;
    X.lossPohon = 0;
    X.stockPohon = 10;
    insertFirst(LP,P = alokasi(X));
    X.namaPohon = "Manggis";
    X.biayaPohon = 250000;
    X.profitPohon = 15;
    X.lossPohon = 0;
    X.stockPohon = 70;
    insertFirst(LP,P = alokasi(X));
    X.namaPohon = "Cabe";
    X.biayaPohon = 250000;
    X.profitPohon = 1;
    X.lossPohon = 10;
    X.stockPohon = 15;
    insertFirst(LP,P = alokasi(X));
    //cari = "iii";
    //deleteParent(LP,L,cari);
    //printInfo(LP);
    List_child LC;
    createList(LC);
    infotypeChild C;
    address_child ch;
    C.namaOrang = "Joga";
    C.budget = 1000000;
    insertFirst(LC,alokasi(C));
    C.namaOrang = "Kajo";
    C.budget = 5600000;
    insertFirst(LC,alokasi(C));
    C.namaOrang = "Loga";
    C.budget = 2500000;
    insertFirst(LC,alokasi(C));
    //printInfo(LC);
    list_relasi LR;
    createList(LR);
    infotype_relasi rl;
    rl.jumlah_pohon = 5;
    rl.tgl_join = "1";
    rl.tgl_keluar = "2";
    address_relasi R = alokasi(rl,LP,LC,"Kajo","Mangga");
    insertFirst(LR,R);
    rl.jumlah_pohon = 2;
    R = alokasi(rl,LP,LC,"Kajo","Manggis");
    insertFirst(LR,R);
    rl.jumlah_pohon = 3;
    rl.tgl_join = "1";
    rl.tgl_keluar = "2";
    R = alokasi(rl,LP,LC,"Joga","Mangga");
    insertFirst(LR,R);
    menuLogin(LP,LC,LR);
}

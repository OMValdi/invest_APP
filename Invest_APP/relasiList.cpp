#include "relasiList.h"
#include <string.h>
#include <fstream>
#include <cstdlib>
#include <iomanip>

void createList(list_relasi &L){
    first(L) = NULL;
}

address_relasi alokasi(infotype_relasi x,List_parent LP,List_child LC,string namaOrang,string namaPohon){
    address_parent P = searchParent(LP,namaPohon);
    address_child C = searchChild(LC,namaOrang);
    if ((P!=NULL)&&(C!=NULL)){
        address_relasi R;
        R = new elmlist_relasi;
        child(R) = C;
        parent(R) = P;
        info(R).tgl_join = x.tgl_join;
        info(R).tgl_keluar = x.tgl_keluar;
        info(R).jumlah_pohon = x.jumlah_pohon;
        info(R).keuntungan = (info(P).profitPohon*(info(P).biayaPohon*info(R).jumlah_pohon))/100;
        info(R).kerugian = (info(P).lossPohon*(info(P).biayaPohon*info(R).jumlah_pohon))/100;
        info(R).total = info(P).biayaPohon*info(R).jumlah_pohon+(info(R).keuntungan - info(R).kerugian);
        next(R) = NULL;
        return R;
    } else if ((P==NULL)&&(C!=NULL)){
        cout<<"Nama pohon tidak ditemukan"<<endl;
    } else if ((P!=NULL)&&(C==NULL)){
        cout<<"Nama investor tidak ditemukan"<<endl;
    } else {
        cout<<"Nama investor dan nama pohon tidak valid"<<endl;
    }
}

address_relasi searchRelasi(list_relasi L,string nama1){
    if(first(L)!=NULL){
        address_relasi P = first(L);
        do {
            if(info(parent(P)).namaPohon==nama1){
                return P;
            }
        } while(P!=NULL);
        return NULL;
    }
}

void insertFirst(list_relasi &L, address_relasi P){
    if (first(L) == NULL){
        first(L) = P;
        }else{
            address_relasi Q = first(L);
            while(next(Q)!=NULL){
                Q = next(Q);
            } next(Q) = P;
        }
}
void insertLast(list_relasi &L, address_relasi P){
    address_relasi Q;
    if (first(L) == NULL){
        insertFirst(L,P);
    }else{
    Q =first(L);
    while (next(Q) != NULL){
        Q = next(Q);
    }
    next(Q) = P;
}
}
void tengah3(int width, char* s) {
     int l = strlen(s);
     int pos = (int)((width - l) / 2);
     for (int i = 0; i < pos; i++) { cout << " "; }
     cout << s;
}

void printInfo(list_relasi L) {
    address_relasi P;
    tengah3(7,"No. ");
    tengah3(23,"Nama investor/ pohon");
    tengah3(25,"Harga Pohon (Rp)");
    tengah3(15,"Kuantitas");
    tengah3(25,"Keuntungan (ROI)(Rp)");
    tengah3(26,"Kerugian (LOSS)(Rp)");
    tengah3(20,"Total (Rp)");
    cout<<endl<<endl;
    if (first(L)!=NULL){
         address_relasi P= first(L);
            int i = 1;
        do{
        cout<<" "<<setiosflags(ios::left)<<setw(8)<<i++;
        cout<<" "<<setiosflags(ios::left)<<setw(1)<<info(child(P)).namaOrang;
        cout<<"/";
        cout<<" "<<setiosflags(ios::left)<<setw(17)<<info(parent(P)).namaPohon;
        cout<<" "<<setiosflags(ios::left)<<setw(18)<<info(parent(P)).biayaPohon;
        cout<<" "<<setiosflags(ios::left)<<setw(13)<<info(P).jumlah_pohon;
        cout<<" "<<setiosflags(ios::left)<<setw(22)<<info(P).keuntungan;
        cout<<" "<<setiosflags(ios::left)<<setw(17)<<info(P).kerugian;
        cout<<" "<<setiosflags(ios::left)<<setw(17)<<info(P).total<<endl;
        P = next(P);
        } while (P!=NULL);
    } else {
        cout<<" "<<setiosflags(ios::left)<<setw(8)<<"Kosong";
    }
}

void dealokasi(address_relasi &P){
    next(P) = NULL;
}

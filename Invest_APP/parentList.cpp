#include "parentList.h"
#include <string.h>
#include <fstream>
#include <cstdlib>
#include <iomanip>

void createList(List_parent &L)
{
    first(L)=NULL;
    last(L)=NULL;
}

void dealokasi(address_parent& P){
    delete P;
}

address_parent alokasi(infotypeParent x)
{
    if (x.namaPohon!=""){
        address_parent P;
        P = new elmlist_parent;
        info(P).namaPohon = x.namaPohon;
        info(P).biayaPohon = x.biayaPohon;
        info(P).profitPohon = x.profitPohon;
        info(P).lossPohon = x.lossPohon;
        info(P).stockPohon = x.stockPohon;
        next(P) = NULL;
        return P;
    }
}

void insertFirst(List_parent &L, address_parent P) {
    if(first(L) == NULL) {
        first(L) = P;
        last(L) = P;
        next(P) = NULL;
        prev(P) = NULL;
    } else {
        if (!searchParent(L,info(P).namaPohon)){
            next(P) = first(L);
            prev(first(L)) = P;
            first(L) = P;
        } else {
            cout<<"Maaf nama pohon telah tersedia"<<endl;
        }
    }

}

void tengah2(int width, char* s) {
     int l = strlen(s);
     int pos = (int)((width - l) / 2);
     for (int i = 0; i < pos; i++) { cout << " "; }
     cout << s;
}

void printInfo(List_parent L) {
    address_parent P;
    tengah2(24,"No. ");
    tengah2(20,"Nama Pohon");
    tengah2(25,"Harga Pohon (Rp)");
    tengah2(20,"Keuntungan (ROI)");
    tengah2(20,"Kerugian (LOSS)");
    tengah2(20,"Stock pohon");
    cout<<endl<<endl;
    if(first(L)!=NULL) {
        P = first(L);
            int i = 1;
        do{
        cout<<" "<<setiosflags(ios::right)<<setw(7);
        cout<<" "<<setiosflags(ios::left)<<setw(3)<<i++;
        cout<<" "<<setiosflags(ios::left)<<setw(15)<<info(P).namaPohon;
        cout<<" "<<setiosflags(ios::left)<<setw(15)<<info(P).biayaPohon;
        cout<<" "<<setiosflags(ios::left)<<setw(15)<<info(P).profitPohon<<"%";
        cout<<" "<<setiosflags(ios::left)<<setw(14)<<info(P).lossPohon<<"%";
        cout<<" "<<setiosflags(ios::left)<<setw(17)<<info(P).stockPohon<<endl;
        P = next(P);
    }while(P != NULL);
    } else {
        cout<<" "<<setiosflags(ios::right)<<setw(7);
        cout<<" "<<setiosflags(ios::left)<<setw(8)<<"Kosong";
    }
}

address_parent searchParent(List_parent L,string nama){

    if(first(L)!=NULL){
        address_parent P = first(L);
        do {
            if(info(P).namaPohon==nama){
                return P;
            } else if (info(last(L)).namaPohon==nama){
                return last(L);
            }
            if (P!=last(L)){
                P = next(P);
            }
        } while(P!=last(L));
        return NULL;
    }
}

void deleteParent(List_parent &L, address_parent& Prec, string nama){
    if(first(L)==NULL);
    else{
        Prec = searchParent(L,nama);
        if (Prec == NULL){
            cout<<"data tidak ada"<<endl;
        } else if (Prec!=NULL){
            if ((Prec==first(L))&&(Prec==last(L))){
               first(L) = NULL;
               last(L) = NULL;
            } else if (Prec == first(L)){
                if (next(Prec)==last(L)){
                    first(L) = last(L);
                    next(Prec) = NULL;
                    prev(first(L)) = NULL;
                } else {
                    first(L) = next(Prec);
                    next(Prec) = NULL;
                    prev(first(L)) = NULL;
                }
            } else if (Prec == last(L)){
                if (prev(Prec)==first(L)){
                    last(L) = first(L);
                    next(last(L)) = NULL;
                    prev(Prec) = NULL;
                } else {
                    last(L) = prev(Prec);
                    next(last(L)) = NULL;
                    prev(Prec) = NULL;
                }
            } else {
                next(prev(Prec)) = next(Prec);
                prev(next(Prec)) = prev(Prec);
                prev(Prec) = NULL;
                next(Prec) = NULL;
            }
        }
    }
}

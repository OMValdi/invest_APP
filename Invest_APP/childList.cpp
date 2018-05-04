#include "childList.h"

void createList(List_child &L){
    first(L) = NULL;
    last(L) = NULL;

}

address_child alokasi(infotypeChild x){
    address_child P = new elmlist_child;
    info(P) = x;
    next(P) = NULL;
    prev(P) = NULL;
    return P;

}

address_child searchChild(List_child L,string nama){
    if(first(L)!=NULL){
        address_child Q = NULL;
        address_child P = first(L);
        do {
            if(info(P).namaOrang==nama){
                return P;
            } else if (info(last(L)).namaOrang==nama){
                return last(L);
            }
            if (P!=last(L)){
                P = next(P);
            }
        } while(P!=last(L));
        return NULL;
    }
}

void insertFirst(List_child &L, address_child P){
    if (first(L) == NULL){
        first(L) = P;
        last(L) = P;
        next(P) = P;
        prev(P) = P;
    } else{
        if (!searchChild(L,info(P).namaOrang)){
            next(last(L)) = P;
            prev(P) = last(L);
            next(P) = first(L);
            prev(first(L)) = P;
            first(L) = P;
        } else {
            cout<<"nama Anda telah terdaftar"<<endl;
        }
    }
}

void printInfo(List_child L){
   if (first(L)!=NULL){
    address_child P = first(L);
    cout<<info(P).namaOrang<<" -> ";
    cout<<info(P).budget<<endl;
    P = next(P);
    do {
       cout<<info(P).namaOrang<<" -> ";
       cout<<info(P).budget<<endl;
       P = next(P);
    }while(P != first(L));
   }
}

void deleteChild(List_child &L, address_child &Prec, string nama){
    if (first(L)==NULL);
    else {
        Prec = searchChild(L,nama);
        if (Prec == NULL) {
            cout<<"Nama tidak ditemukan"<<endl;
        } else if (Prec!=NULL){
            if ((Prec==first(L))&&(Prec==last(L))){
                next(Prec) = NULL;
                last(L) = NULL;
                first(L) = NULL;
                last(L) = NULL;
            } else if (Prec == first(L)){
                if (next(Prec)==last(L)){
                    first(L) = last(L);
                    next(last(L)) = last(L);
                    prev(last(L)) = last(L);
                    next(Prec) = NULL;
                    prev(Prec) = NULL;
                } else {
                    first(L) = next(Prec);
                    next(last(L)) = first(L);
                    prev(first(L)) = last(L);
                    next(Prec) = NULL;
                    prev(Prec) = NULL;
                }
            } else if (Prec == last(L)){
                if (prev(Prec)==first(L)){
                    last(L) = first(L);
                    next(last(L)) = last(L);
                    prev(last(L)) = last(L);
                    next(Prec) = NULL;
                    prev(Prec) = NULL;
                } else {
                    last(L) = prev(Prec);
                    next(last(L)) = first(L);
                    prev(first(L)) = last(L);
                    next(Prec) = NULL;
                    prev(Prec) = NULL;
                }
            } else {
                next(prev(Prec)) = next(Prec);
                prev(next(Prec)) = prev(Prec);
                prev(Prec) = NULL;
                next(Prec) = NULL;            }
        }
    }
}

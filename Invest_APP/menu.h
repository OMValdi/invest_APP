#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "stdlib.h"
#include "conio.h"

using namespace std;

#include "parentList.h"
#include "relasiList.h"
#include "childList.h"

List_parent LP;
List_child LC;
list_relasi LR;

void menuLogin(List_parent& LP,List_child& LC,list_relasi& LR);
void menuAdmin(List_parent& LP,List_child& LC,list_relasi& LR);
void editPermission(List_parent& LP, list_relasi& LR);
void addPohon(List_parent& LP);
void addInvestor(List_child& LC);
void addRelasi(List_parent& LP, List_child& LC, list_relasi& LR);
void delParent(list_relasi LR,List_parent& LP);
void delInvestasi(List_parent& LP, list_relasi LR);
void menuInvestor(List_parent& LP, list_relasi& LR, List_child& LC);

void menuLogin(List_parent& LP,List_child& LC,list_relasi& LR){
    int userChoise;
    do{
        system("cls");
        cout<<"USER LOGIN \n";
        cout<<"=========== \n";
        cout<<"[1] ADMIN"<<endl;
        cout<<"[2] INVESTOR \n\n"<<endl;
        cout<<"[99] exit aplication \n";
        cout<<"Pilihan Anda : ";
        cin>>userChoise;
        if(userChoise==99){
            system("cls");
            cout<<"Thank you for coming..";
        } else if (userChoise>2){
            system("cls");
            cout<<"Tidak ada pilihan menu "<<userChoise;
            getch();
        } else if (userChoise==1){
            menuAdmin(LP,LC,LR);
        }else if (userChoise== 2){
            menuInvestor(LP,LR,LC);
        }

    } while (userChoise!=99);
}

void menuAdmin(List_parent& LP,List_child& LC,list_relasi& LR){
    int userChoise;
    do{
        system("cls");
        cout<<"USER LOGIN >> ADMIN \n";
        cout<<"==================== \n";
        cout<<"[1] Lihat data pohon \n";
        cout<<"[2] Lihat data investor \n";
        cout<<"[3] Lihat data investasi \n";
        cout<<"[4] Edit data pohon \n";
        cout<<"[5] Tambah data pohon\n";
        cout<<"[6] Hapus data pohon \n\n";
        cout<<"[99] Kembali ke menu login\n";
        cout<<"Pilihan Anda : ";
        cin>>userChoise;
        if(userChoise==99){
            //menuLogin(LP,LC,LR);
        } else if (userChoise>6){
            system("cls");
            cout<<"Tidak ada pilihan menu "<<userChoise;
            getch();
        } else if (userChoise==1){
            system("cls");
            cout<<"... >> ADMIN >> LIHAT DATA POHON \n";
            cout<<"================================= \n";
            printInfo(LP);
            getch();
        } else if (userChoise==2){
            system("cls");
            cout<<"... >> ADMIN >> LIHAT DATA INVESTOR \n";
            cout<<"==================================== \n";
            printInfo(LC);
            getch();
        } else if (userChoise==3){
            system("cls");
            cout<<"... >> ADMIN >> LIHAT INVESTASI \n";
            cout<<"================================ \n";
            printInfo(LR);
            getch();
        } else if(userChoise==4){
            editPermission(LP,LR);
        } else if(userChoise==5){
            addPohon(LP);
        } else if(userChoise==6){
            delParent(LR,LP);
        }
    } while (userChoise!=99);
}
void menuInvestor(List_parent& LP, list_relasi& LR, List_child& LC){
    int userChoise;
    do{
        system("cls");
        cout<<"USER LOGIN >> INVESTOR \n";
        cout<<"==================== \n";
        cout<<"[1] Tambah Investor \n";
        cout<<"[2] Tambah Relasi Investasi \n";
        cout<<"[3] Lihat Data Investasi\n";
        cout<<"[4] Hapus data Investasi \n\n";
        cout<<"[99] Kembali ke menu login\n";
        cout<<"Pilihan Anda : ";
        cin>>userChoise;
        if(userChoise==99){
            //menuLogin(LP,LC,LR);
        } else if (userChoise>6){
            system("cls");
            cout<<"Tidak ada pilihan menu "<<userChoise;
            getch();
        } else if (userChoise==1){
            addInvestor(LC);
        } else if (userChoise==2){
            addRelasi(LP,LC,LR);
        } else if (userChoise==3){
            system("cls");
            cout<<"... >> ADMIN >> LIHAT INVESTASI \n";
            cout<<"================================ \n";
            printInfo(LR);
            getch();
        } else if(userChoise==4){
            editPermission(LP,LR);
        } else if(userChoise==5){
            addPohon(LP);
        } else if(userChoise==6){
            delParent(LR,LP);
        }
    } while (userChoise!=99);

}

void editPermission(List_parent& LP, list_relasi& LR){
    address_relasi R;
    system("cls");
    cout<<"...<< ADMIN << EDIT DATA POHON \n";
    cout<<"=============================== \n";
    cout<<"Masukkan nama pohon : ";
    string jawab;
    string cariPohon;
    cin>>cariPohon;
    address_parent P = searchParent(LP,cariPohon);
    if (P!=NULL){
        cout<<endl;
        cout<<"Ubah keuntungan? [Y/N] : ";
        cin>>jawab;
        if ((jawab=="Y")||(jawab=="y")){
            cout<<"Masukkan persentase keuntungan : ";
            cin>>info(P).profitPohon;
        }
        cout<<"\n==================================="<<endl;
        cout<<"Ubah kerugian? [Y/N] : ";
        cin>>jawab;
        if ((jawab=="Y")||(jawab=="y")){
            cout<<"Masukkan persentase kerugian : ";
            int loss;
            cin>>loss;
            info(P).lossPohon = loss;
        }
        cout<<"\n==================================="<<endl;
        cout<<"Tambah stock pohon? [Y/N] : ";
        cin>>jawab;
        if ((jawab=="Y")||(jawab=="y")){
            cout<<"Masukkan tambahan jumlah pohon : ";
            int sedia;
            cin>>sedia;
            info(P).stockPohon = info(P).stockPohon + sedia;
        }
        cout<<"\n==================================="<<endl;
        cout<<"Ubah harga pohon [Y/N] : ";
        cin>>jawab;
        if ((jawab=="Y")||(jawab=="y")){
            cout<<"Masukkan harga pohon : ";
            int harga;
            cin>>harga;
            info(P).biayaPohon = harga;
        }
        cout<<"\n==================================="<<endl;
        address_relasi Q = first(LR);
        do {
            if (info(parent(Q)).namaPohon==cariPohon){
                info(Q).keuntungan = (info(P).profitPohon*(info(P).biayaPohon*info(Q).jumlah_pohon))/100;
                info(Q).kerugian = (info(P).lossPohon*(info(P).biayaPohon*info(Q).jumlah_pohon))/100;
                info(Q).total = info(P).biayaPohon*info(Q).jumlah_pohon+(info(Q).keuntungan - info(Q).kerugian);
            }
            Q = next(Q);
        } while (Q!=NULL);
        cout<<"click to continue...";
        getch();
    } else {
        cout<<"Data tidak ditemukan";
        getch();
    }
}

void addPohon(List_parent& LP){
    string namaTree;
    infotypeParent X;
    system("cls");
    cout<<"... << ADMIN << TAMBAH POHON\n";
    cout<<"=============================\n";
    cout<<"Masukkan nama pohon : ";
    cin>>namaTree;
    if (!searchParent(LP,namaTree)){
        X.namaPohon = namaTree;
        cout<<"Masukkan harga pohon : ";
        cin>>X.biayaPohon;
        cout<<"Masukkan keuntungan pohon : ";
        cin>>X.profitPohon;
        cout<<"Masukkan kerugian pohon : ";
        cin>>X.lossPohon;
        cout<<"Masukkan ketersediaan pohon : ";
        cin>>X.stockPohon;
        insertFirst(LP,alokasi(X));
    }else{
        cout<<"Maaf data sudah ada...";
        getch();
    }
}

void delParent(list_relasi LR,List_parent& LP){
    system("cls");
    string nama;
    bool periksa = false;
    address_parent P;
    cout<<"... << ADMIN << HAPUS POHON \n";
    cout<<"============================ \n";
    cout<<"Masukkan nama pohon : ";
    cin>>nama;
    P = searchParent(LP,nama);
    if (P!=NULL){
        address_relasi R = first(LR);
        do{
           if(info(parent(R)).namaPohon==nama){
                periksa = true;
           } R = next(R);
        }while((R!=NULL)&&(periksa==false));
        if (periksa==false){
            deleteParent(LP,P,nama);
            cout<<"Data pohon berhasil dihapus";
            dealokasi(P);
            getch();
        } else {
            cout<<"Data pohon tidak bisa dihapus...";
            getch();
        }
    } else {
        cout<<"Data pohon tidak ada...";
        getch();
    }
}
void addInvestor(List_child& LC){
    string namaInvestor;
    infotypeChild X;
    system("cls");
    cout<<"... << ADMIN << TAMBAH POHON\n";
    cout<<"=============================\n";
    cout<<"Masukkan nama Investor : ";
    cin>>namaInvestor;
    if(!searchChild(LC, namaInvestor)){
        X.namaOrang = namaInvestor;
        cout<<"Budget : ";
        cin>>X.budget;
        insertFirst(LC,alokasi(X));
    }else{
        cout<<"Maaf Data Sudah Ada ";
    }
}
void addRelasi(List_parent& LP, List_child& LC, list_relasi& LR){
    address_relasi R;
    infotype_relasi x;
     system("cls");
    cout<<"...<< INVESTOR << TAMBAH DATA \n";
    cout<<"=============================== \n";
    cout<<"Masukkan nama pohon : ";
    string cariPohon;
    cin>>cariPohon;
    address_parent P = searchParent(LP,cariPohon);
    cout<<"Nama Investor : ";
    string namaOrang;
    cin>>namaOrang;
    address_child Q = searchChild(LC,namaOrang);
        if((P!= NULL)&& (Q != NULL)){
        cout<<endl;
        cout<<"Tanggal Join : ";
        cin>>x.tgl_join;
        cout<<"Tanggal Keluar : ";
        cin>>x.tgl_keluar;
        cout<<"Jumlah Pohon : ";
        int jumlah;
        cin>>jumlah;
         if ((Q == NULL) && (P == NULL)){
                    cout << "Kosong!\n";
                }
                else{
                    if(info(Q).budget< info(P).biayaPohon)
                    {
                        cout << "Budget Kurang\n";
                    }else{
                        info(Q).budget = info(Q).budget - info(P). biayaPohon;

                        R = alokasi(x,LP,LC,cariPohon,namaOrang);
                        insertLast(LR,R);
        }

         if ((P == NULL) && (R == NULL)){
                    cout << "Kosong!\n";
                }else if(info(P).stockPohon<=0){
                        cout << "Stok habis\n";
                    }else if (info(P).stockPohon < jumlah){
                            cout<<"Stock Kurang\n";
                    }


                    else{
                        info(P).stockPohon = info(P).stockPohon - jumlah;
                         R = alokasi(x,LP,LC,cariPohon,namaOrang);
                        insertFirst(LR,R);

                }
}
}
}

void delInvestasi(List_parent& LP, list_relasi LR){



}
#endif // MENU_H_INCLUDED

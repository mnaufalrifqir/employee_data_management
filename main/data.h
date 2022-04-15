#ifndef DATA_H_INCLUDED
#define DATA_H_INCLUDED

#include <iostream>
using namespace std;

#define first(List_toko) List_toko.first
#define last(List_toko) List_toko.last
#define info(T) T->info
#define next(T) (T)->next
#define nextPegawai(P) (P)->nextPegawai

typedef struct elm_toko *adr_toko;
typedef struct elm_pegawai *adr_pegawai;

struct toko{
    string nama_toko;
    string jenis_toko;
    string daerah;
};

struct elm_toko{
    toko info;
    adr_toko next;
    adr_pegawai nextPegawai;
};

struct elm_pegawai{
    string info;
    adr_pegawai next;
};

struct mll{
    adr_toko first;
    adr_toko last;
};

void create_list(mll &list_toko);
void newElm_toko(toko info, adr_toko &T);
void newElm_pegawai(string info, adr_pegawai &P);
void insertToko(mll &list_toko, adr_toko T);
void deleteToko(mll &list_toko, string nama_toko, adr_toko &T);
void showData_Toko(mll list_toko);
adr_toko searchToko(mll list_toko, string nama_toko);
void insertPegawai(mll &list_toko, adr_toko T, adr_pegawai P);
void deletePegawai(mll &list_toko, adr_toko &X, adr_pegawai &P, string nama_pegawai);
void showPegawai (mll list_toko, adr_toko T);
adr_pegawai searchPegawai (mll list_toko, adr_toko T, string nama_pegawai);
void showAllData(mll list_toko);
int jumlahPegawai(mll list_toko);
bool cariPegawai(mll list_toko, string namaPegawai);

#endif // DATA_H_INCLUDED

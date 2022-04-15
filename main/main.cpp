#include "data.h"
#include <iostream>
using namespace std;

int main()
{
    mll L;
    string nama_pegawai, namaToko;
    adr_toko T;
    adr_pegawai P;
    toko data;
    int menu;
    char cek;
    bool valid;

    create_list(L);
    cout<<"======MENU======"<<endl;
    cout<<"1. Tambah data toko"<<endl;
    cout<<"2. Tambah data pegawai"<<endl;
    cout<<"3. Hapus data toko "<<endl;
    cout<<"4. Hapus data pegawai"<<endl;
    cout<<"5. Tampilkan data toko"<<endl;
    cout<<"6. Tampilkan data pegawai disebuah toko "<<endl;
    cout<<"7. Cari data toko"<<endl;
    cout<<"8. Cari data pegawai"<<endl;
    cout<<"9. Menghitung total data pegawai"<<endl;
    cout<<"10. Cari pegawai dari semua data toko"<<endl;
    cout<<"11. Tampilkan semua data"<<endl;
    cout<<"0. Exit"<<endl;
    cout<<"Masukkan menu : "<<endl;
    cin>>menu;
    while (menu != 0){
        if (menu == 1){
            cout<<"Masukkan nama toko : "<<endl;
            cin>>data.nama_toko;
            cout<<"Masukkan jenis toko : "<<endl;
            cin>>data.jenis_toko;
            cout<<"Masukkan daerah toko : "<<endl;
            cin>>data.daerah;
            newElm_toko(data, T);
            insertToko(L, T);
            cout<<"Kembali ke menu utama? (Y/N) : "<<endl;
            cin>>cek;
            if (cek == 'N'){
                break;
            }
        }else if (menu == 2){
            cout<<"Masukkan Nama Pegawai :"<<endl;
            cin>>nama_pegawai;
            cout<<"Masukkan nama toko : "<<endl;
            cin>>namaToko;
            T = searchToko(L, namaToko);
            if (T != NULL){
                newElm_pegawai(nama_pegawai, P);
                insertPegawai(L, T, P);
            }else{
                cout<<"Toko tidak terdaftar"<<endl;
            }
            cout<<"Kembali ke menu utama? (Y/N) : "<<endl;
            cin>>cek;
            if(cek == 'N'){
                break;
            }
        }else if (menu == 3){
            cout<<"Masukkan nama toko : "<<endl;
            cin>>namaToko;
            deleteToko(L, namaToko, T);
            if (T != NULL){
                cout<<"Toko "<<info(T).nama_toko<<" berhasil dihapus"<<endl;
            }else{
                cout<<"Toko tidak terdaftar"<<endl;
            }
            cout<<"Kembali ke menu utama? (Y/N) : "<<endl;
            cin>>cek;
            if(cek == 'N'){
                break;
            }
        }else if (menu == 4){
            cout<<"Masukkan Nama Pegawai :"<<endl;
            cin>>nama_pegawai;
            deletePegawai(L, T, P, nama_pegawai);
            if (P != NULL){
                cout<<"Pegawai dengan nama : "<<info(P)<<" berhasil dihapus dari"<<info(T).nama_toko<<endl;
            }else{
                cout<<"Pegawai tidak terdaftar dalam list"<<endl;
            }
            cout<<"Kembali ke menu utama? (Y/N) : "<<endl;
            cin>>cek;
            if(cek == 'N'){
                break;
            }
        }else if (menu == 5){
            showData_Toko(L);
            cout<<"Kembali ke menu utama? (Y/N) : "<<endl;
            cin>>cek;
            if(cek == 'N'){
                break;
            }
        }else if (menu == 6){
            cout<<"Masukkan nama toko : "<<endl;
            cin>>namaToko;
            T = searchToko(L, namaToko);
            if (T != NULL){
                showPegawai(L, T);
            }else{
                cout<<"Toko tidak terdaftar"<<endl;
            }
            cout<<"Kembali ke menu utama? (Y/N) : "<<endl;
            cin>>cek;
            if(cek == 'N'){
                break;
            }
        }else if (menu == 7){
            cout<<"Masukkan nama toko : "<<endl;
            cin>>namaToko;
            T = searchToko(L, namaToko);
            if (T != NULL){
                cout<<"Toko tersebut ada dalam list"<<endl;
            }else{
                cout<<"Toko tersebut tidak ada dalam list"<<endl;
            }
            cout<<"Kembali ke menu utama? (Y/N) : "<<endl;
            cin>>cek;
            if(cek == 'N'){
                break;
            }
        }else if(menu == 8){
            cout<<"Masukkan nama toko : "<<endl;
            cin>>namaToko;
            cout<<"Masukkan Nama Pegawai :"<<endl;
            cin>>nama_pegawai;
            T = searchToko(L, namaToko);
            if (T != NULL){
                P = searchPegawai(L, T, nama_pegawai);
                if (P != NULL){
                    cout<<"pegawai tersebut ada dalam list"<<endl;
                }else{
                    cout<<"pegawai tersebut tidak ada dalam list"<<endl;
                }
            }else{
                cout<<"Toko tidak terdaftar"<<endl;
            }
            cout<<"Kembali ke menu utama? (Y/N) : "<<endl;
            cin>>cek;
            if(cek == 'N'){
                break;
            }
        }else if(menu == 9){
            cout<<"Total pegawai yang terdaftar dari seluruh toko : "<<jumlahPegawai(L)<<endl;
            cout<<"Kembali ke menu utama? (Y/N) : "<<endl;
            cin>>cek;
            if(cek == 'N'){
                break;
            }
        }else if(menu == 10){
            cout<<"Masukkan Nama Pegawai :"<<endl;
            cout<<nama_pegawai;
            valid = cariPegawai(L, nama_pegawai);
            if (valid == true){
                cout<<"Pegawai dengan nama "<<nama_pegawai<<" terdaftar dalam list"<<endl;
            }else{
                cout<<"Pegawai dengan nama "<<nama_pegawai<<" tidak terdaftar dalam list"<<endl;
            }
            cout<<"Kembali ke menu utama? (Y/N) : "<<endl;
            cin>>cek;
            if(cek == 'N'){
                break;
            }
        }else if (menu = 11){
            showAllData(L);
            cout<<"Kembali ke menu utama? (Y/N) : "<<endl;
            cin>>cek;
            if(cek == 'N'){
                break;
            }
        }
        cout<<"======MENU======"<<endl;
        cout<<"1. Tambah data toko"<<endl;
        cout<<"2. Tambah data pegawai"<<endl;
        cout<<"3. Hapus data toko "<<endl;
        cout<<"4. Hapus data pegawai"<<endl;
        cout<<"5. Tampilkan data toko"<<endl;
        cout<<"6. Tampilkan data pegawai disebuah toko "<<endl;
        cout<<"7. Cari data toko"<<endl;
        cout<<"8. Cari data pegawai"<<endl;
        cout<<"9. Menghitung total data pegawai"<<endl;
        cout<<"10. Cari pegawai dari semua data toko"<<endl;
        cout<<"11. Tampilkan semua data"<<endl;
        cout<<"0. Exit"<<endl;
        cout<<"Masukkan menu : "<<endl;
        cin>>menu;
    }
    cout<<"ANDA TELAH KELUAR DARI PROGRAM"<<endl;
}

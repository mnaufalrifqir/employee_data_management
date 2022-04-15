#include "data.h"

void create_list(mll &list_toko){
    first(list_toko) = NULL;
    last(list_toko) = NULL;
}

void newElm_toko(toko info, adr_toko &T){
    T = new elm_toko;
    info(T) = info;
    next(T) = NULL;
    nextPegawai(T) = NULL;
}

void newElm_pegawai(string info, adr_pegawai &P){
    P = new elm_pegawai;
    info(P) = info;
    next(P) = NULL;
}

void insertToko(mll &list_toko, adr_toko T){
    adr_toko P;
    if (first(list_toko) == NULL){
        first (list_toko) = T;
        last(list_toko) = T;
    }else{
        P = first(list_toko);
        while (next(P) != NULL){
            P = next(P);
        }
        next(P) = T;
        last(list_toko) = T;
    }
}

void deleteToko(mll &list_toko, string nama_toko, adr_toko &T){
    adr_toko prec;
    prec = first(list_toko);
    T = searchToko(list_toko, nama_toko);
    if (T != NULL){
        if (T == first(list_toko)){
            if (T == last(list_toko)){
                last(list_toko) = NULL;
            }
            first(list_toko) = next(T);
            next(T) = NULL;
        }else{
            while (next(prec) != T){
                prec = next(prec);
            }
            next(prec) = next(T);
            if (T == last(list_toko)){
                last(list_toko) = prec;
            }
            next(T) = NULL;
        }
    }
}

void showData_Toko(mll list_toko){
    adr_toko T;
    T = first(list_toko);
    while (T != NULL){
        cout<<info(T).nama_toko<<" || "<<info(T).jenis_toko<<" || "<<info(T).daerah<<endl;
        T = next(T);
    }
}

adr_toko searchToko(mll list_toko, string nama_toko){
    adr_toko P;
    P = first(list_toko);
    while (P != NULL){
        if (info(P).nama_toko == nama_toko){
            return P;
        }
        P = next(P);
    }
    return NULL;
}

void insertPegawai(mll &list_toko, adr_toko T, adr_pegawai P){
    adr_pegawai Q;
    if (nextPegawai(T) == NULL){
        nextPegawai(T) = P;
    }else{
        Q = nextPegawai(T);
        while (next(Q) != NULL){
            Q = next(Q);
        }
        next(Q) = P;
    }
}

void deletePegawai(mll &list_toko, adr_toko &X, adr_pegawai &P, string nama_pegawai){
    adr_toko T;
    adr_pegawai prec;
    T = first(list_toko);
    while (T != NULL){
        P = searchPegawai (list_toko, T, nama_pegawai);
        if (P != NULL){
            if (P == nextPegawai(T)){
                nextPegawai(T) = next(P);
                next (P) = NULL;
                X = T;
            }else{
                prec = nextPegawai(T);
                while (next(prec) != P){
                    prec = next(prec);
                }
                next(prec) = next(P);
                next(P) = NULL;
                X = T;
            }
        }
        T = next(T);
    }
}

void showPegawai (mll list_toko, adr_toko T){
    adr_pegawai P;
    int i;
    i = 1;
    P = nextPegawai(T);
    if (P == NULL){
        cout<<"Pegawai Kosong"<<endl;
    }else{
        cout<<"List pegawai di "<<info(T).nama_toko<<endl;
        while (P != NULL){
            cout<<i<<". "<<info(P)<<endl;
            P = next(P);
            i = i + 1;
        }
    }
}

adr_pegawai searchPegawai (mll list_toko, adr_toko T, string nama_pegawai){
    adr_pegawai P;
    P = nextPegawai(T);
    while (P != NULL){
        if (info(P) == nama_pegawai){
            return P;
        }
        P = next(P);
    }
    return NULL;
}

void showAllData(mll list_toko){
    adr_pegawai P;
    adr_toko T;
    T = first(list_toko);
    while (T != NULL){
        cout<<info(T).nama_toko<<" || "<<info(T).jenis_toko<<" || "<<info(T).daerah<<endl;
        cout<<"Pegawai : "<<endl;
        P = nextPegawai(T);
        while (P != NULL){
            cout<<info(P)<<" "<<endl;
        P = next(P);
        }
    cout<<" "<<endl;
    T = next(T);
    }
}

int jumlahPegawai(mll list_toko){
    int i = 0;
    adr_pegawai P;
    adr_toko Q = first(list_toko);
    while (Q != NULL){
        P = nextPegawai(Q);
        while (P != NULL){
            i = i + 1;
            P = next(P);
        }
        Q = next(Q);
    }
    return i;
}

bool cariPegawai(mll list_toko, string namaPegawai){
    adr_pegawai P;
    adr_toko Q;
    Q = first(list_toko);
    while (Q != NULL){
        P = nextPegawai(Q);
        while (P != NULL){
            if(info(P) == namaPegawai){
                return true;
            }
            P = next(P);
        }
        Q = next(Q);
    }
    return false;
}

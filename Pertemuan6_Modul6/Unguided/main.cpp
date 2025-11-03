#include "Doublylist.h"

using namespace std;

int main() {
    List L;
    CreateList(L);
    address P;
    infotype data;

    for (int i = 1; i <= 4; i++) {
        cout << "masukkan nomor polisi: ";
        cin >> data.nopol;
        cout << "masukkan warna kendaraan: ";
        cin >> data.warna;
        cout << "masukkan tahun kendaraan: ";
        cin >> data.thnBuat;

        if (findElm(L, data) != Nil) {
            cout << "nomor polisi sudah terdaftar\n" << endl;
        } else {
            P = alokasi(data);
            insertLast(L, P);
            cout << endl;
        }
    }

    printInfo(L);

    infotype cari;
    cout << "\nMasukkan Nomor Polisi yang dicari : ";
    cin >> cari.nopol;

    address found = findElm(L, cari);
    cout << endl;
    if (found != Nil) {
        cout << "Nomor Polisi : " << found->info.nopol << endl;
        cout << "Warna        : " << found->info.warna << endl;
        cout << "Tahun        : " << found->info.thnBuat << endl;
    } else {
        cout << "Data dengan nomor polisi " << cari.nopol << " tidak ditemukan." << endl;
    }

    string hapusNopol;
    cout << "\nMasukkan Nomor Polisi yang akan dihapus : ";
    cin >> hapusNopol;
    deleteByNopol(L, hapusNopol);

    printInfo(L);

    return 0;
}
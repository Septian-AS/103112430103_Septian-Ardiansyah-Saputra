#include "QueuePengiriman.h"

int main() {
    QueueEkspedisi Q;
    createQueue(Q);

    int pilihan;

    do {
        cout << "--- Komaniya Ekspress ---" << endl;
        cout << "1. Input Data Paket" << endl;
        cout << "2. Hapus Data Paket" << endl;
        cout << "3. Tampilkan Queue Paket" << endl;
        cout << "4. Hitung Total Biaya Pengiriman" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilihan anda : ";
        cin >> pilihan;

        switch (pilihan) {
        case 1: {
            Paket P;
            cout << "Kode Resi : ";
            cin >> P.KodeResi;
            cout << "Nama Pengirim : ";
            cin >> P.NamaPengirim;
            cout << "Berat Barang : ";
            cin >> P.BeratBarang;
            cout << "Tujuan : ";
            cin >> P.Tujuan;

            enQueue(Q, P);
            break;
        }

        case 2:
            deQueue(Q);
            break;

        case 3:
            viewQueue(Q);
            break;

        case 4:
            cout << "Total Biaya Pengiriman : Rp "
                 << TotalBiayaPengiriman(Q) << endl;
            break;
        }

        cout << endl;

    } while (pilihan != 0);

    return 0;
}
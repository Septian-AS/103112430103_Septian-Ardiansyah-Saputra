#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    float uts;
    float uas;
    float tugas;
    float nilaiAkhir;
};

float nilaiAkhir(float uts, float uas, float tugas) {
    return (0.3 * uts) + (0.4 * uas) + (0.3 * tugas);
}

int main() {
    Mahasiswa data[10];
    int jumlah;

    cout << "Input jumlah mahasiswa (max. 10) : ";
    cin >> jumlah;

    if (jumlah > 10) {
        cout << "Jumlah mahasiswa melebihi batas (max. 10)!" << endl;
        return 0;
    }

    for (int i = 0; i < jumlah; i++) {
        cout << "\nData Mahasiswa ke - " << i + 1 << endl;
        cout << "Nama   : ";
        cin >> data[i].nama;
        cout << "NIM    : ";
        cin >> data[i].nim;
        cout << "UTS    : ";
        cin >> data[i].uts;
        cout << "UAS    : ";
        cin >> data[i].uas;
        cout << "Tugas  : ";
        cin >> data[i].tugas;

        data[i].nilaiAkhir = nilaiAkhir(data[i].uts, data[i].uas, data[i].tugas);
    }

    cout << "\n=============================================\n";
    cout << "               DATA MAHASISWA\n";
    cout << "=============================================\n";
    cout << "No\tNIM\tNama\t\tNilai Akhir\n";
    cout << "---------------------------------------------\n";
    
    for (int i = 0; i < jumlah; i++) {
        cout << i + 1 << "\t" << data[i].nim << "\t" << data[i].nama << "\t\t"
             << data[i].nilaiAkhir << endl;
    }

    return 0;
}

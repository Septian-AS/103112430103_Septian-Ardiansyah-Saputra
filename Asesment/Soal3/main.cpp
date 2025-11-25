#include "StackMahasiswa.h"
using namespace std;

Mahasiswa create(string nama, string nim, float t, float uts, float uas) {
    Mahasiswa M;
    M.Nama = nama;
    M.NIM = nim;
    M.NilaiTugas = t;
    M.NilaiUTS = uts;
    M.NilaiUAS = uas;
    return M;
}

int main() {
    StackMahasiswa S;
    createStack(S);

    Push(S, create("Venti", "11111", 75.7, 82.1, 65.5));
    Push(S, create("Xiao", "22222", 87.4, 88.9, 81.9));
    Push(S, create("Kazuha", "33333", 92.3, 88.8, 82.4));
    Push(S, create("Wanderer", "44444", 95.5, 85.5, 90.5));
    Push(S, create("Lynette", "55555", 77.7, 65.4, 79.9));
    Push(S, create("Chasca", "66666", 99.9, 93.6, 87.3));

    cout << "Stack awal:" << endl;
    View(S);
    cout << endl;

    Pop(S);

    cout << "Setelah Pop 1x:" << endl;
    View(S);
    cout << endl;

    Update(S, 3, create("Heizou", "77777", 99.9, 88.8, 77.7));

    cout << "Setelah Update posisi 3:" << endl;
    View(S);
    cout << endl;

    cout << "Searching Nilai Akhir 85.5 - 95.5:" << endl;
    SearchNilaiAkhir(S, 85.5, 95.5);
    cout << endl;

    cout << "Max Nilai Akhir:" << endl;
    MaxNilaiAkhir(S);

    return 0;
}

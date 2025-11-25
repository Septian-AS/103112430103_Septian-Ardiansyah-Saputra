#include "StackMahasiswa.h"
using namespace std;

bool isEmpty(StackMahasiswa S) {
    return S.Top == -1;
}

bool isFull(StackMahasiswa S) {
    return S.Top == MAX - 1;
}

void createStack(StackMahasiswa &S) {
    S.Top = -1;
}

void Push(StackMahasiswa &S, Mahasiswa M) {
    if (!isFull(S)) {
        S.Top++;
        S.dataMahasiswa[S.Top] = M;
    }
}

void Pop(StackMahasiswa &S) {
    if (!isEmpty(S)) {
        S.Top--;
    }
}

void Update(StackMahasiswa &S, int posisi, Mahasiswa M) {
    int index = posisi - 1;
    if (index >= 0 && index <= S.Top) {
        S.dataMahasiswa[index] = M;
    }
}

void View(StackMahasiswa S) {
    for (int i = S.Top; i >= 0; i--) {
        cout << i + 1 << ". " 
             << S.dataMahasiswa[i].Nama << " | "
             << S.dataMahasiswa[i].NIM << " | "
             << S.dataMahasiswa[i].NilaiTugas << " | "
             << S.dataMahasiswa[i].NilaiUTS << " | "
             << S.dataMahasiswa[i].NilaiUAS << endl;
    }
}

void SearchNilaiAkhir(StackMahasiswa S, float minAkhir, float maxAkhir) {
    for (int i = S.Top; i >= 0; i--) {
        float NA = 0.2 * S.dataMahasiswa[i].NilaiTugas +
                    0.4 * S.dataMahasiswa[i].NilaiUTS +
                    0.4 * S.dataMahasiswa[i].NilaiUAS;
        if (NA >= minAkhir && NA <= maxAkhir) {
            cout << "Posisi " << i + 1 << " : " 
                 << S.dataMahasiswa[i].Nama 
                 << " | Nilai Akhir = " << NA << endl;
        }
    }
}

void MaxNilaiAkhir(StackMahasiswa S) {
    if (isEmpty(S)) return;
    float maks = -1;
    int idx = 0;
    for (int i = 0; i <= S.Top; i++) {
        float NA = 0.2 * S.dataMahasiswa[i].NilaiTugas +
                    0.4 * S.dataMahasiswa[i].NilaiUTS +
                    0.4 * S.dataMahasiswa[i].NilaiUAS;
        if (NA > maks) {
            maks = NA;
            idx = i;
        }
    }
    cout << "Nilai akhir terbesar ada di posisi " << idx + 1 << endl;
    cout << S.dataMahasiswa[idx].Nama << " | " 
         << S.dataMahasiswa[idx].NIM << " | NA = " << maks << endl;
}
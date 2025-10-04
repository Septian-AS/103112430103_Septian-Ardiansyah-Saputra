#include<iostream>
using namespace std;

void ubahPanjangLebar(int* Panjang, int* Lebar) {
    *Panjang = 12;
    *Lebar = 6;
}

int main (){
    int panjang = 10, lebar = 5, luas = 0, keliling;
    int* ptrPanjang = &panjang;
    int* ptrLebar = &lebar;

    cout << "--- Nilai Awal ---" << endl;
    cout << "Panjang : " << panjang << endl;
    cout << "Lebar : " << lebar << endl;

    luas = (*ptrPanjang) * (*ptrLebar);
    keliling = 2 * ((*ptrPanjang) + (*ptrLebar));

    cout << "\n--- Hasil Perhitungan ---" << endl;
    cout << "Luas Persegi Panjang : " << luas << endl;
    cout << "Keliling Persegi Panjang : " << keliling << endl;

    ubahPanjangLebar(ptrPanjang, ptrLebar);

    luas = (*ptrPanjang) * (*ptrLebar);
    keliling = 2 * ((*ptrPanjang) + (*ptrLebar));

    cout << "\n--- Nilai Setelah Diubah Melalui Pointer ---" << endl;
    cout << "Panjang Baru : " << *ptrPanjang << endl;
    cout << "lebar Baru : " << *ptrLebar << endl;
    cout << "Luas Baru : " << luas << endl;
    cout << "Keliling Baru : " << keliling << endl;

    return 0;
}
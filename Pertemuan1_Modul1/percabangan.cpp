#include<iostream>
using namespace std;

int main(){
    int angka1, angka2;
    cout << "Masukkan angka pertama: ";
    cin >> angka1;
    cout << "Masukkan angka kedua: ";
    cin >> angka2;

    if (angka1 > angka2) {
        cout << " kurang dari " << endl;
    } else if (angka1 < angka2) {
        cout << " lebih dari " << endl;
    }

    if (angka1 == angka2) {
        cout << " sama dengan " << endl;
    } else if (angka1 != angka2) {
        cout << "angka berbeda" << endl;
    }

    int pilihan;
    cout << "Menu" << endl;
    cout << "1. penjumlahan" << endl;
    cout << "2. pengurangan" << endl;
    cout << "masukkan pilihan : " ;
    cin >> pilihan;
    
    switch (pilihan) {
        case 1:
        cout << "penjumlahan: " << angka1 + angka2 << endl;
        cout << endl;
        break;
        case 2:
        cout << "pengurangan: " << angka1 - angka2 << endl;
        cout << endl;
        break;
        default:
        cout << "pilihan salah" << endl;
    }

    return 0;
}
#include<iostream>
using namespace std;

int main(){
    int angka1, angka2;
    cout << "Masukkan angka pertama: ";
    cin >> angka1;
    cout << "Masukkan angka kedua: ";
    cin >> angka2;

    cout << "Hasil penjumlahan: " << angka1 + angka2 << endl;
    cout << "Hasil pengurangan: " << angka1 - angka2 << endl;
    cout << "Hasil perkalian: " << angka1 * angka2 << endl;
    cout << "Hasil pembagian: " << angka1 / angka2 << endl;
    cout << "Hasil modulus: " << angka1 % angka2 << endl;
    return 0;
    
}
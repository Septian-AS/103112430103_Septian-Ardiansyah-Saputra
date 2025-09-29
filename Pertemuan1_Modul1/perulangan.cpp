#include<iostream>
using namespace std;

int main(){
    int angka1;
    cout << "Masukkan angka: ";
    cin >> angka1;
    
    for (int i = 1; i <= angka1; i++) {
        cout << i << " - ";
    }
    cout << endl;

    int j = 10;
    while (j > angka1) {
        cout << j << " - ";
        j--;
    }

    cout << endl;
    int k = 10;
    do{
        cout << k << " - ";
    } while (k < angka1);

    return 0;
    
    } 
#include<iostream>
using namespace std;

void ubahNilai(int* ptr) {
    *ptr = 20;
}

int main(){
    int x = 10;
    cout << "Nilai sebelum diubah: " << x << endl;

    ubahNilai(&x);
    cout << "Nilai setelah diubah: " << x << endl;

    return 0;
}
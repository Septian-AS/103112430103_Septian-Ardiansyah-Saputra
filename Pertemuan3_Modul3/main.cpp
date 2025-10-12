#include<iostream>
#include "Mahasiswa.h"
#include<cstdlib>
using namespace std;

int main() {
    mahasiswa mhs;

    inputMhs(mhs);

    cout << "Rata-rata nilai adalah: " << rata2(mhs) << endl;
    system("pause");

    return 0;
}
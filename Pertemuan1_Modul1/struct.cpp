#include<iostream>
using namespace std;

int main(){
    const int MAX = 3;
    struct rapot{
        string nama;
        float nilai;
    };
    rapot Mahasiswa[MAX];

    for(int i = 0; i < MAX; i++){
        cout << "masukan nama Mahasiswa : ";
        cin >> Mahasiswa[i].nama;
        cout << "masukan nilai Mahasiswa : ";
        cin >> Mahasiswa[i].nilai;
        cout << endl;
    }

    int j = 0;
    while(j < MAX){
        cout << "Nama Mahasiswa : " << Mahasiswa[j].nama << ", Nilai : " << Mahasiswa[j].nilai << endl;
        j++;
    }
    return 0;
}
#include<iostream>
using namespace std;

int main(){
    int arr[5];

    for (int i = 0; i < 5; i++){
        cout << "Masukkan value indeks ke-" << i << " : ";
        cin >> arr[i];
    }
    int j = 0;
    while (j < 5){
        cout << "Isi indeks ke-" << j << " : " << arr[j] << endl;
        j++;
    }
    return 0;
}
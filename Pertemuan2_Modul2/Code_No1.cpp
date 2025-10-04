#include<iostream>
using namespace std;

void hasil(int arr[3][3]) {
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

void jumlahMatriks(int A[3][3], int B[3][3]) {
    int c[3][3];
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            c[i][j] = A[i][j] + B[i][j];
        }
    }

    cout << "Hasil Penjumlahan : " << endl;
    hasil(c); 
}

void kurangMatriks(int A[3][3], int B[3][3]) {
    int c[3][3];
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            c[i][j] = A[i][j] - B[i][j];
        }
    }

    cout << "Hasil Pengurangan : " << endl;
    hasil(c); 
}

void kaliMatriks(int A[3][3], int B[3][3]) {
    int c[3][3] = {0};
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            for (int k = 0; k < 3; k++){
                c[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    cout << "Hasil Perkalian : " << endl;
    hasil(c); 
}

int main() {
    int arrA[3][3] = {
        {7, 12, 22},
        {31, 6, 41},
        {15, 19, 36}
    };
    int arrB[3][3] = {
        {11, 34, 7},
        {3, 25, 41},
        {5, 18, 33}
    };
    int pilihan;

    do {
        cout << "\n--- Menu Program Matriks ---" << endl;
        cout << "1. Penjumlahan Matriks" << endl;
        cout << "2. Pengurangan Matriks" << endl;
        cout << "3. Perkalian Matriks" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilih Menu (1-4) : ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: 
            jumlahMatriks(arrA, arrB);
            break;
            case 2:
            kurangMatriks(arrA, arrB);
            break;
            case 3:
            kaliMatriks(arrA, arrB);
            break;
        }
    } while (pilihan != 4);
    
    return 0;
}

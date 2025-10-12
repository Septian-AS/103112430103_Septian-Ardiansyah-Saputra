#include <iostream>
using namespace std;

void tampilArray(int arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

void tukarPosisi(int A[3][3], int B[3][3], int baris, int kolom) {
    int temp = A[baris][kolom];
    A[baris][kolom] = B[baris][kolom];
    B[baris][kolom] = temp;
}

void tukarPointer(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main() {
    int A[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int B[3][3] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };

    int x = 10, y = 20;
    int *p1 = &x;
    int *p2 = &y;

    cout << "Array A awal :" << endl;
    tampilArray(A);

    cout << "\nArray B awal :" << endl;
    tampilArray(B);

    tukarPosisi(A, B, 1, 2);

    cout << "\nPointer awal :" << endl;
    cout << "x = " << x << ", y = " << y << endl;

    cout << "\nArray A setelah ditukar :" << endl;
    tampilArray(A);

    cout << "\nArray B setelah ditukar :" << endl;
    tampilArray(B);

    tukarPointer(p1, p2);

    cout << "\nPointer setelah ditukar :" << endl;
    cout << "x = " << x << ", y = " << y << endl;

    return 0;
}

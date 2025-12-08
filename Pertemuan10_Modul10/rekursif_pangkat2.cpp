#include <iostream>
using namespace std;

int pangkat_2(int x) {
    if (x == 0) {
        return 1;
    } else {
        return 2 * pangkat_2(x - 1);
    }
}

int main() {
    cout << "=== REKURSIF PANGKAT 2 ===" << endl;

    int x;
    cout << "Masukkan nilai x: ";
    cin >> x;
    cout << endl;
    cout << "2 pangkat dari " << x << " adalah : " << pangkat_2(x) << endl;

    return 0;
}
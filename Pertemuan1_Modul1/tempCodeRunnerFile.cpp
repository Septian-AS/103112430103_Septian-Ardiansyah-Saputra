#include <iostream>
#include <string>
using namespace std;

string satuan[] = {"nol", "satu", "dua", "tiga", "empat", "lima", "enam", "tujuh", "delapan", "sembilan"};

    string keHuruf (int n) {
        switch (n) {
            case 0: return "nol";
            case 10: return "sepuluh";
            case 11: return "sebelas";
            case 100: return "seratus";
        }

        if (n < 10) return satuan[n];
        if (n < 20) return satuan [n % 10] + " belas";

        if (n < 100) {
            string result = satuan[n / 10] + " puluh";
            if (n % 10 != 0) {
                result += " " + satuan[n % 10];
            }
            
            return result;
        }

        return "input melebihi batas";
}

int main() {
    int n;
    cout << "Masukkan angka (0-100): ";
    cin >> n;

    cout << keHuruf(n) << endl;
    return 0;
} 
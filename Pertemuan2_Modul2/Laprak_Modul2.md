# <h1 align="center">Laporan Praktikum Modul 2 - Pengenalan Bahasa C++ (Bagian Kedua)</h1>
<p align="center">Septian Ardiansyah Saputra - 103112430103</p>

## Dasar Teori
Array adalah struktur data linear yang menyimpan sekumpulan elemen bertipe sama dalam lokasi memori bersebelahan, sehingga memungkinkan akses cepat melalui indeks [1]. Pointer merupakan variabel yang menyimpan alamat memori dari variabel lain dan digunakan untuk manipulasi data maupun pengelolaan memori secara efisien dalam C++ [2]. Fungsi adalah blok kode yang diberi nama, dapat menerima parameter, dan biasanya mengembalikan nilai untuk memudahkan modularitas program [3]. Prosedur dalam C++ direpresentasikan sebagai fungsi dengan tipe kembalian `void` yang digunakan untuk mengeksekusi serangkaian instruksi tanpa mengembalikan nilai [4]. Parameter fungsi adalah variabel formal yang menerima nilai atau referensi dari argumen aktual, dengan mekanisme _pass by value, pass by reference, maupun pass by pointer_ [5].

### A. Array<br/>

#### 1. Array Satu Dimensi
Array yang terdiri dari satu larik data saja.
#### 2. Array Dua Dimensi
Array dua dimensi berbentuk seperti tabel, jadi bisa digunakan untuk menyimpan data dalam bentuk tabel.
#### 3. Array Berdimensi Banyak
Array yang memiliki banyak indeks (lebih dari 2), indeks array menyatakan dimensi array.

### B. Pointer<br/>

#### 1. Data dan Memori
Semua data yang digunakan oleh komputer disimpan di dalam memori (RAM) komputer.
#### 2. Pointer dan Alamat
Pointer merupakan variabel yang berisi integer dalam format heksadesimal. Pointer digunakan untuk menyimpan alamat memori variabel lain, sehingga pointer dapat mengakses nilai dari variabel lain sesuai alamat dituju.
#### 3. Pointer dan Array
Operasi yang bisa dilakukan dengan array, juga bisa dilakukan oleh pointer.
#### 4. Pointer dan String
String adalah bentuk data yang sering digunakan untuk mengolah data teks atau kalimat. Pointer digunakan untuk mengakses karakter string

### C. Fungsi<br/>
Fungsi merupakan blok dari kode yang dirancang untuk melaksanakan tugas khusus dengan tujuan :
- Program menjadi terstruktur.
- Mengurangi pengulangan kode (duplikasi kode).

### D. Prosedur<br/>
Prosedur adalah fungsi yang tidak mengembalikan nilai. Dalam C++ dikenal sebagai fungsi void.

### E. Parameter Fungsi<br/>

#### 1. Parameter Formal dan Parameter Aktual
Parameter formal adalah variabel yang ada pada daftar parameter ketika mendefinisikan fungsi. Parameter aktual adalah parameter yang dipakai untuk memanggil fungsi.
#### 2. Cara melewatkan Parameter
- Call by Value (nilai disalin, variabel asli tidak berubah)
- Call by Pointer (mengirim alamat variabel sehingga bisa diubah nilainya)
- Call by Reference (variabel asli langsung terhubung ke parameter fungsi)

## Guided

### 1. Array 1

```C++
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
```
Guided 1 membuat program untuk meminta pengguna mengisi 5 nilai ke dalam array lalu menampilkannya kembali sesuai indeks.

### 2. Array 2

```C++
#include<iostream>
using namespace std;

void tampilkanHasil(int arr[2][2]){
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    int arrA[2][2] = {
        {1, 2},
        {3, 4}
    };
    int arrB[2][2] = {
        {2, 3},
        {4, 5}
    };
    int arrC[2][2] = {0};
    int arrD[2][2] = {0};
    
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            arrC[i][j] = arrA[i][j] + arrB[i][j];
        }
    }

    cout << "Hasil penjumlahan : " << endl;
    tampilkanHasil(arrC);

    cout << endl;

    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            for (int k = 0; k < 2; k++){
                arrD[i][j] += arrA[i][k] * arrB[k][j];
            }
        }
    }

    cout << "Hasil perkalian : " << endl;
    tampilkanHasil(arrD);

    return 0;
}
```
Guided 2 membuat program untuk menjumlahkan dan mengalikan dua matriks 2×2 lalu menampilkan hasilnya.

### 3. Array Pointer

```C++
#include<iostream>
using namespace std;

int main(){
    int arr[] = {10, 20, 30, 40, 50};
    int *pArr = arr;

    for (int i = 0; i < 5; ++i){
        cout << "Elemen array ke-" << i+1 << " menggunakan pointer: " << *(pArr + i) << endl;
    }

    for (int i = 0; i < 5; ++i){
        cout << "Elemen array ke-" << i+1 << " menggunakan indeks: " << arr[i] << endl;
    }

    return 0;
}
```
Guided 3 membuat program untuk menampilkan isi array menggunakan pointer dan indeks untuk menunjukkan bahwa keduanya setara.

### 4. Function Prosedur

```C++
#include<iostream>
using namespace std;

int cariMax(int arr[], int ukuran){
    int MAX = arr[0];
    for (int i = 1; i < ukuran; i++){
        if (arr[i] > MAX){
            MAX = arr[i];
        }
    }
    return MAX;
}

void operasiAritmatika(int arr[], int ukuran){
    int totalJumlah = 0;
    for (int i = 0; i < ukuran; i++){
        totalJumlah += arr[i];
    }
    cout << "total penjumlahan : " << totalJumlah << endl;

    int totalKali = 1;
    for (int i = 0; i < ukuran; i++){
        totalKali *= arr[i];
    }
    cout << "total perkalian : " << totalKali << endl;
}

int main(){
    const int ukuran = 5;
    int arr[ukuran];
    for (int i = 0; i < ukuran; i++){
        cout << "Masukkan nilai array ke-" << i << " : ";
        cin >> arr[i];
    }
    cout << endl;
    cout << "Nilai terbesar dalam array : " << cariMax(arr, ukuran) << endl;

    operasiAritmatika(arr, ukuran);
    return 0;
}
```
Guided 4 membuat program untuk meminta input 5 angka, lalu menampilkan nilai terbesar, jumlah semua angka, dan hasil perkaliannya.

### 5. Call by Pointer

```C++
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
```
Guided 5 membuat program untuk menunjukkan bahwa nilai variabel bisa diubah melalui pointer.

### 6. Call by Reference

```C++
#include<iostream>
using namespace std;

void ubahNilai(int& ref){
    ref = 20;
}

int main(){
    int x = 10;
    cout << "Nilai sebelum diubah: " << x << endl;

    ubahNilai(x);
    cout << "Nilai setelah diubah: " << x << endl;

    return 0;
}
```
Guided 6 membuat program untuk menunjukkan cara mengubah nilai variabel menggunakan reference.

## Unguided 

### 1. Soal Unguided 1
Buatlah program yang dapat melakukan operasi penjumlahan, pengurangan, dan perkalian 
matriks 3x3 tersebut. Buat prosedur untuk masing-masing operasi yang dilakukan;
jumlahMatriks() untuk operasi penjumlahan, kurangMatriks() untuk pengurangan, dan 
kaliMatriks() untuk perkalian. Buat program tersebut menggunakan menu switch-case 
seperti berikut ini :

```
--- Menu Program Matriks ---
1. Penjumlahan matriks
2. Pengurangan matriks
3. Perkalian matriks
4. Keluar
```

```C++
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
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/Septian-AS/103112430103_Septian-Ardiansyah-Saputra/blob/main/Pertemuan2_Modul2/Output/Soal1.png)

Program ini digunakan untuk melakukan penjumlahan, pengurangan, dan perkalian matriks 3×3 lalu menampilkan hasilnya.

### 2. Soal Unguided 2
Buatlah program menghitung luas dan keliling persegi panjang dengan proses perhitungan 
dan perubahan nilainya menggunakan pointer, seperti berikut:
1) Buatlah 3 variabel integer di fungsi main(): panjang (beri nilai 10), lebar (beri nilai 5), dan
luas (beri nilai 0).
2) Deklarasikan dua pointer: ptrPanjang yang menunjuk ke variabel panjang, dan ptrLebar
yang menunjuk ke variabel lebar.
3) Hitung luas persegi panjang tersebut dan simpan hasilnya ke dalam variabel luas. 
Syarat: Proses perhitungan ini wajib menggunakan ptrPanjang dan ptrLebar.
4) Cetak nilai luas ke layar.
5) Setelah itu, ubah nilai panjang menjadi 12 dan lebar menjadi 6, juga hanya melalui
pointer ptrPanjang dan ptrLebar.
6) Cetak nilai panjang dan lebar yang baru untuk membuktikan bahwa
nilainya telah berubah.

```C++
#include<iostream>
using namespace std;

void ubahPanjangLebar(int* Panjang, int* Lebar) {
    *Panjang = 12;
    *Lebar = 6;
}

int main (){
    int panjang = 10, lebar = 5, luas = 0, keliling;
    int* ptrPanjang = &panjang;
    int* ptrLebar = &lebar;

    cout << "--- Nilai Awal ---" << endl;
    cout << "Panjang : " << panjang << endl;
    cout << "Lebar : " << lebar << endl;

    luas = (*ptrPanjang) * (*ptrLebar);
    keliling = 2 * ((*ptrPanjang) + (*ptrLebar));

    cout << "\n--- Hasil Perhitungan ---" << endl;
    cout << "Luas Persegi Panjang : " << luas << endl;
    cout << "Keliling Persegi Panjang : " << keliling << endl;

    ubahPanjangLebar(ptrPanjang, ptrLebar);

    luas = (*ptrPanjang) * (*ptrLebar);
    keliling = 2 * ((*ptrPanjang) + (*ptrLebar));

    cout << "\n--- Nilai Setelah Diubah Melalui Pointer ---" << endl;
    cout << "Panjang Baru : " << *ptrPanjang << endl;
    cout << "lebar Baru : " << *ptrLebar << endl;
    cout << "Luas Baru : " << luas << endl;
    cout << "Keliling Baru : " << keliling << endl;

    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/Septian-AS/103112430103_Septian-Ardiansyah-Saputra/blob/main/Pertemuan2_Modul2/Output/Soal2.png)

Program ini menghitung luas dan keliling persegi panjang sebelum dan sesudah nilai panjang–lebar diubah melalui pointer.

## Kesimpulan
Praktikum ini membahas penggunaan array, pointer, fungsi, prosedur, dan parameter fungsi dalam C++. Array digunakan untuk menyimpan sekumpulan data yang dapat diolah melalui perulangan, misalnya untuk operasi penjumlahan, pengurangan, maupun perkalian matriks. Pointer berfungsi menyimpan alamat memori dari variabel sehingga memungkinkan pengaksesan dan perubahan nilai secara tidak langsung. Fungsi digunakan untuk memisahkan logika program agar lebih terstruktur, sedangkan prosedur merupakan fungsi yang tidak mengembalikan nilai dan biasanya digunakan untuk menampilkan hasil atau melakukan suatu proses tertentu. Parameter fungsi bisa dikirim melalui value, pointer, maupun reference. Secara keseluruhan, praktikum ini menekankan pemahaman dasar struktur data sederhana serta konsep array, pointer, fungsi, prosedur, dan parameter fungsi untuk membuat program yang lebih fleksibel dan efisien.

## Referensi
[1] Stroustrup, B. (2013). _The C++ Programming Language_ (4th ed.). Addison-Wesley.
<br>[2] Jerkins, J. A., Rawajfih, Y., & Ray, D. A. (2023). Common C++ Pointer Misconceptions: Essence and Treatment. _Journal of Computing Sciences in Colleges_. ACM Digital Library.
<br>[3] Malik, D. S. (2018). _C++ Programming: From Problem Analysis to Program Design_ (8th ed.). Cengage Learning.
<br>[4] Deitel, P., & Deitel, H. (2017). _C++ How to Program_ (10th ed.). Pearson.
<br>[5] Budd, T. (2009). _An Introduction to Object-Oriented Programming with C++_ (4th ed.). Addison-Wesley.
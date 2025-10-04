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
- Call by Value
- Call by Pointer
- Call by Reference

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
Diketahui 2 buah matriks 3x3 seperti dibawah ini :

$E=mc^2$
$$\left[ \begin{array}{cc} 1 & 2 \\ 3 & 4\end{array} \right]$$


Buatlah program yang dapat melakukan operasi penjumlahan, pengurangan, dan perkalian 
matriks 3x3 tersebut. Buat prosedur untuk masing-masing operasi yang dilakukan;
jumlahMatriks() untuk operasi penjumlahan, kurangMatriks() untuk pengurangan, dan 
kaliMatriks() untuk perkalian. Buat program tersebut menggunakan menu switch-case 
seperti berikut ini :
```C++
source code unguided 1
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

contoh :
![Screenshot Output Unguided 1_1](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan1_Modul1/Output-Unguided1-1.png)

##### Output 2
![Screenshot Output Unguided 1_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

penjelasan unguided 1 

### 2. (isi dengan soal unguided 2)

```C++
source code unguided 2
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

contoh :
![Screenshot Output Unguided 2_1](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan1_Modul1/Output-Unguided2-1.png)

##### Output 2
![Screenshot Output Unguided 2_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

penjelasan unguided 2

### 3. (isi dengan soal unguided 3)

```C++
source code unguided 3
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

contoh :
![Screenshot Output Unguided 3_1](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan1_Modul1/Output-Unguided3-1.png)

##### Output 2
![Screenshot Output Unguided 3_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

penjelasan unguided 3

## Kesimpulan
...

## Referensi
[1] Stroustrup, B. (2013). _The C++ Programming Language_ (4th ed.). Addison-Wesley.
<br>[2] Jerkins, J. A., Rawajfih, Y., & Ray, D. A. (2023). Common C++ Pointer Misconceptions: Essence and Treatment. _Journal of Computing Sciences in Colleges_. ACM Digital Library.
<br>[3] Malik, D. S. (2018). _C++ Programming: From Problem Analysis to Program Design_ (8th ed.). Cengage Learning.
<br>[4] Deitel, P., & Deitel, H. (2017). _C++ How to Program_ (10th ed.). Pearson.
<br>[5] Budd, T. (2009). _An Introduction to Object-Oriented Programming with C++_ (4th ed.). Addison-Wesley.

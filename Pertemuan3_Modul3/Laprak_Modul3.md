# <h1 align="center">Laporan Praktikum Modul 3 - Abstract Data Type (ADT)</h1>
<p align="center">Septian Ardiansyah Saputra - 103112430103</p>

## Dasar Teori
Abstract Data Type (ADT) adalah konsep yang mendefinisikan tipe data beserta operasi-operasinya tanpa menampilkan detail implementasi, sehingga mendukung prinsip abstraction dan information hiding dalam pemrograman, ADT memisahkan antara antarmuka dan implementasi untuk meningkatkan modularitas[1]. ADT digunakan untuk meningkatkan keandalan dan keterbacaan perangkat lunak dengan memformalkan spesifikasi operasi dan tipe data secara terstruktur[2]. Pendekatan aljabar dalam ADT memastikan konsistensi logika antar operasi pada tipe data. Dengan demikian, ADT menjadi dasar penting dalam pengembangan struktur data dan sistem perangkat lunak yang terstruktur[3].

### A. Abstract Data Type (ADT)<br/>
ADT adalah TYPE dan sekumpulan PRIMITIF (operasi dasar) terhadap TYPE tersebut. Selain itu, dalam sebuah ADT yang lengkap, disertakan pula definisi invarian dari TYPE dan aksioma yang berlaku. ADT merupakan definisi STATIK.

#### 1. Kelompok PRIMITIF
- Konstruktor/Kreator, pembentuk nilai _type_.
- Selector, untuk mengakses tipe komponen.
- Prosedur pengubah nilai komponen.
- Tipe validator komponen.
- Destruktor/Dealokator, "menghancurkan" nilai objek/variabel.
- Baca/Tulis, interface dengan _input/output_ device.
- Operator relasional.
- Aritmatika.
- Konversi dari tipe tersebut ke tipe dasar dan sebaliknya.

#### 2. Definisi/Spesifikasi Type dan Primitif/Header fungsi (.h)
- Spesifikasi _type_ sesuai dengan kaidah bahasa yang dipakai.
- Spesifikasi dari primitif sesuai dengan kaidah dalam konteks prosedural, yaitu Fungsi (nama, domain, range, dan prekondisi) dan Prosedur (_Initial state_, _Final state_, dan proses yang dilakukan).

#### 3. Body/Realisasi dari Primitif (.c)
Berupa kode program dalam bahasa yang bersangkutan. Realisasi fungsi dan prosedur harus sedapat mungkin memanfaatkan _selector_ dan konstruktor.

## Guided 

### 1. Mahasiswa.h

```C++
#ifndef MAHASISWA_H
#define MAHASISWA_H

struct mahasiswa {
    char nim[10];
    int nilai1, nilai2;
};

void inputMhs(mahasiswa &m);
float rata2(mahasiswa m);

#endif
```
Guided 1 membuat program header file ADT `Mahasiswa`.

### 2. Mahasiswa.cpp

```C++
#include<iostream>
#include "Mahasiswa.h"
using namespace std;

void inputMhs(mahasiswa &m) {
    cout << "Input NIM: ";
    cin >> m.nim;
    cout << "Input Nilai 1: ";
    cin >> m.nilai1;
    cout << "Input Nilai 2: ";
    cin >> m.nilai2;
}

float rata2(mahasiswa m) {
    return (float)(m.nilai1 + m.nilai2) / 2;
}
```
Guided 2 membuat implementasi dari fungsi-fungsi pada ADT `mahasiswa`.

### 3. main.cpp

```C++
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
```
Guided 3 membuat program utama yang menggunakan ADT `mahasiswa`.

## Unguided 

### 1. Soal Unguided 1
Buat program yang dapat menyimpan data mahasiswa (max. 10) ke dalam sebuah _array_ dengan field nama, nim, uts, uas, tugas, dan nilai akhir. Nilai akhir diperoleh dari FUNGSI dengan rumus 0.3 * uts + 0.4 * uas + 0.3 * tugas.

```C++
#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    float uts;
    float uas;
    float tugas;
    float nilaiAkhir;
};

float nilaiAkhir(float uts, float uas, float tugas) {
    return (0.3 * uts) + (0.4 * uas) + (0.3 * tugas);
}

int main() {
    Mahasiswa data[10];
    int jumlah;

    cout << "Input jumlah mahasiswa (max. 10) : ";
    cin >> jumlah;

    if (jumlah > 10) {
        cout << "Jumlah mahasiswa melebihi batas (max. 10)!" << endl;
        return 0;
    }

    for (int i = 0; i < jumlah; i++) {
        cout << "\nData Mahasiswa ke - " << i + 1 << endl;
        cout << "Nama   : ";
        cin >> data[i].nama;
        cout << "NIM    : ";
        cin >> data[i].nim;
        cout << "UTS    : ";
        cin >> data[i].uts;
        cout << "UAS    : ";
        cin >> data[i].uas;
        cout << "Tugas  : ";
        cin >> data[i].tugas;

        data[i].nilaiAkhir = nilaiAkhir(data[i].uts, data[i].uas, data[i].tugas);
    }

    cout << "\n=============================================\n";
    cout << "               DATA MAHASISWA\n";
    cout << "=============================================\n";
    cout << "No\tNIM\tNama\t\tNilai Akhir\n";
    cout << "---------------------------------------------\n";
    
    for (int i = 0; i < jumlah; i++) {
        cout << i + 1 << "\t" << data[i].nim << "\t" << data[i].nama << "\t\t"
             << data[i].nilaiAkhir << endl;
    }

    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/Septian-AS/103112430103_Septian-Ardiansyah-Saputra/blob/main/Pertemuan3_Modul3/Output/Soal1.png)

Program ini untuk mengelola data mahasiswa menggunakan array dari `struct`, di mana pengguna menginput `nama`, `NIM`, `UTS`, `UAS`, dan `tugas`, kemudian program menghitung nilai akhir menggunakan fungsi `nilaiAkhir()`.


### 2. Soal Unguided 2
Buatlah ADT pelajaran sebagai berikut di dalam file "pelajaran.h":
```
Type pelajaran <
     namaMapel : string
     kodeMapel : string
>
function create_pelajaran(namapel : string, kodepel : string) → pelajaran
procedure tampil_pelajaran(input pel : pelajara)
```
Buatlah implementasi ADT pelajaran pada file "pelajaran.cpp"
Cobalah hasil implementasi ADT pada file "main.cpp"

- pelajaran.h
```C++
#ifndef PELAJARAN_H
#define PELAJARAN_H

#include <string>
using namespace std;

struct pelajaran {
    string namaMapel;
    string kodeMapel;
};

pelajaran create_pelajaran(string namapel, string kodepel);
void tampil_pelajaran(pelajaran pel);

#endif
```

- pelajaran.cpp
```C++
#include <iostream>
#include "pelajaran.h"
using namespace std;

pelajaran create_pelajaran(string namapel, string kodepel) {
    pelajaran p;
    p.namaMapel = namapel;
    p.kodeMapel = kodepel;
    return p;
}

void tampil_pelajaran(pelajaran pel) {
    cout << "nama pelajaran : " << pel.namaMapel << endl;
    cout << "nilai : " << pel.kodeMapel << endl;
}
```

- main.cpp
```C++
#include <iostream>
#include <string>
#include "pelajaran.h"
using namespace std;

int main() {
    string namapel = "Struktur Data";
    string kodepel = "STD";

    pelajaran pel = create_pelajaran(namapel, kodepel);
    tampil_pelajaran(pel);

    return 0;
}
```

### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/Septian-AS/103112430103_Septian-Ardiansyah-Saputra/blob/main/Pertemuan3_Modul3/Output/Soal2.png)

Ketiga program tersebut membentuk ADT `pelajaran`, di mana file header `pelajaran.h` mendefinisikan struktur data dan deklarasi fungsi, file `pelajaran.cpp` berisi implementasi fungsi `create_pelajaran()` untuk membuat data pelajaran dan `tampil_pelajaran()` untuk menampilkannya, sedangkan file `main.cpp` berfungsi sebagai program utama yang memanggil kedua fungsi tersebut untuk menampilkan data pelajaran di layar.


### 3. Soal Unguided 3
Buatlah program dengan ketentuan :
- 2 buah _array_ 2D _integer_ berukuran 3x3 dan 2 buah _pointer integer_
- fungsi/prosedur yang menampilkan isi sebuah _array integer_ 2D
- fungsi/prosedur yang akan menukarkan isi dari 2 _array integer_ 2D pada posisi tertentu
- fungsi/prosedur yang akan menukarkan isi dari variabel yang ditunjuk oleh 2 buah _pointer_

```C++
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
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/Septian-AS/103112430103_Septian-Ardiansyah-Saputra/blob/main/Pertemuan3_Modul3/Output/Soal3.png)

Program ini menggunakan array 2D dan pointer, di mana fungsi `tampilArray()` digunakan untuk menampilkan isi array 3×3, `tukarPosisi()` untuk menukar elemen pada posisi tertentu antara dua array, dan `tukarPointer()` menukarkan nilai dua variabel melalui pointer. Dan kemudian menampilkan hasil sebelum dan sesudah ditukar.

## Kesimpulan
Dari materi ini, dapat disimpulkan bahwa konsep Abstract Data Type (ADT) merupakan bagian penting dalam pemrograman terstruktur dan berorientasi data. ADT digunakan untuk memisahkan antara definisi tipe data dan implementasi operasinya, sehingga program menjadi modular, mudah diperluas, dan terpelihara. Melalui penerapan konsep ini dalam berbagai contoh program, saya dapat memahami keterkaitan antara struktur data dan abstraksi dalam pengembangan perangkat lunak.

## Referensi
[1] Cook, W. R. (2009). Object-Oriented Programming Versus Abstract Data Types. University of Texas at Austin. https://www.cs.utexas.edu/~wcook/papers/OOPvsADT/CookOOPvsADT90.pdf
<br>[2] Berztiss, A. T. (1985). Specification and Implementation of Abstract Data Types. Science of Computer Programming, 5(1), 1–21.https://www.sciencedirect.com/science/article/pii/S006524580860131X
<br>[3] Thomas, M. (1987). Implementing Algebraically Specified Abstract Data Types. TAPSOFT 1987. https://www.dcs.gla.ac.uk/~muffy/papers/Tapsoft_87.pdf
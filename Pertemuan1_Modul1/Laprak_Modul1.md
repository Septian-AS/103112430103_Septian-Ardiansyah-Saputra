# <h1 align="center">Laporan Praktikum Modul 1 - Code Blocks IDE & Pengenalan Bahasa C++ (Bagian Pertama)</h1>
<p align="center">Septian Ardiansyah Saputra - 103112430103</p>

## Dasar Teori
C++ adalah bahasa pemrograman tingkat menengah yang dikembangkan oleh Bjarne Stroustrup pada awal tahun 1980-an sebagai pengembangan dari bahasa C. C++ mendukung paradigma pemrograman prosedural maupun berorientasi objek sehingga banyak digunakan dalam pengembangan perangkat lunak yang membutuhkan efisiensi sekaligus modularitas [1]. Operasi aritmatika merupakan operasi dasar dalam pemrograman yang melibatkan penjumlahan, pengurangan, perkalian, dan pembagian. Dalam bahasa C++, operator aritmatika seperti +, -, *, dan / digunakan untuk mengolah data bertipe numerik, baik bilangan bulat maupun pecahan [2]. Fungsi terbilang (konversi angka ke tulisan) adalah algoritma yang digunakan untuk mengubah nilai numerik menjadi representasi kata [3]. Pola segitiga merupakan salah satu contoh penerapan loop bersarang (nested loop) dalam pemrograman. Pola ini dapat berbentuk segitiga rata kiri, rata kanan, atau segitiga sama sisi [4].

### A. Dasar Pemrograman C++<br/>
#### 1. Struktur Program C++
Program C++ biasanya terdiri dari:

- `#include <iostream>` → library standar input-output<br>
- `int main()` → fungsi utama yang pertama kali dijalankan<br>
- `{ ... }` → blok kode perintah
#### 2. Tipe Data

- `int` → bilangan bulat (contoh : 2, -1)
- `float / double` → bilangan desimal (contoh : 3.14, 9.8)
- `char` → karakter tunggal (contoh : 'S', 'a', 'S')
- `string` → teks (contoh : "Septian")
- `bool` → logika (contoh : true/false)
#### 3. Operator Aritmatika

- Penjumlahan (`+`)
- Pengurangan (`-`)
- Perkalian (`*`)
- Pembagian (`/`)
- Modulus (`%`)

### B. Input dan Output<br/>
#### 1. Fungsi `cout()` (output)
Digunakan untuk mencetak data.
#### 2. Fungsi `cin()` (input)
Digunakan untuk meminta inputan dari user.
#### 3. Kombinasi Input-Output
Input akan diproses kemudian langsung ditampilkan.

### C. Percabangan<br/>
#### 1. If–Else
Digunakan untuk membuat keputusan berdasarkan kondisi.
#### 2. Switch–Case
Cocok digunakan jika banyak pilihan.

### D. Perulangan<br/>
#### 1. While Loop
Digunakan jika perulangan berdasarkan kondisi.
#### 2. For Loop
Digunakan jika jumlah iterasi sudah diketahui.
#### 3. Do–While Loop
Menjalankan perintah minimal sekali sebelum cek kondisi.

## Guided

### 1. Hello World

```C++
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<string> msg {"Hello World"};

    for (const string& word : msg)
    {
        cout << word << " ";
    }
    cout << endl;
}
```
Guided 1 membuat program Hello World.

### 2. Program Input Output

```C++
#include<iostream>
using namespace std;

int main()
{
    int angka;
    cout << "masukkan angka: ";
    cin >> angka;
    cout << "Angka yang dimasukkan: " << angka << endl;
    return 0;
}
```
Guided 2 memasukan input dan mengeluarkan output.

### 3. Operator Aritmatika

```C++
#include<iostream>
using namespace std;

int main(){
    int angka1, angka2;
    cout << "Masukkan angka pertama: ";
    cin >> angka1;
    cout << "Masukkan angka kedua: ";
    cin >> angka2;

    cout << "Hasil penjumlahan: " << angka1 + angka2 << endl;
    cout << "Hasil pengurangan: " << angka1 - angka2 << endl;
    cout << "Hasil perkalian: " << angka1 * angka2 << endl;
    cout << "Hasil pembagian: " << angka1 / angka2 << endl;
    cout << "Hasil modulus: " << angka1 % angka2 << endl;
    return 0;
    
} 
```
Guided 3 membuat program aritmatika Penjumlahan, Pengurangan, Perkalian, Pembagian, dan Modulus.

### 4. Percabangan

```C++
#include<iostream>
using namespace std;

int main(){
    int angka1, angka2;
    cout << "Masukkan angka pertama: ";
    cin >> angka1;
    cout << "Masukkan angka kedua: ";
    cin >> angka2;

    if (angka1 > angka2) {
        cout << " kurang dari " << endl;
    } else if (angka1 < angka2) {
        cout << " lebih dari " << endl;
    }

    if (angka1 == angka2) {
        cout << " sama dengan " << endl;
    } else if (angka1 != angka2) {
        cout << "angka berbeda" << endl;
    }

    int pilihan;
    cout << "Menu" << endl;
    cout << "1. penjumlahan" << endl;
    cout << "2. pengurangan" << endl;
    cout << "masukkan pilihan : " ;
    cin >> pilihan;
    
    switch (pilihan) {
        case 1:
        cout << "penjumlahan: " << angka1 + angka2 << endl;
        cout << endl;
        break;
        case 2:
        cout << "pengurangan: " << angka1 - angka2 << endl;
        cout << endl;
        break;
        default:
        cout << "pilihan salah" << endl;
    }

    return 0;
} 
```
Guided 4 membuat program percabangan yang bisa menentukan hasil yang nantinya akan keluar, seperti penjumlahan dan pengurangan.

### 5. Perulangan

```C++
#include<iostream>
using namespace std;

int main(){
    int angka1;
    cout << "Masukkan angka: ";
    cin >> angka1;
    
    for (int i = 1; i <= angka1; i++) {
        cout << i << " - ";
    }
    cout << endl;

    int j = 10;
    while (j > angka1) {
        cout << j << " - ";
        j--;
    }

    cout << endl;
    int k = 10;
    do{
        cout << k << " - ";
    } while (k < angka1);

    return 0;
    
    } 
```
Guided 5 membuat program perulangan yang dapat mengulang angka tergantung dari input user.

### 6. Struct

```C++
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
```
Guided 6 membuat program Struct untuk input nama dan nilai.

## Unguided 

### 1. Soal Unguided 1

Buatlah program yang menerima input-an dua buah bilangan bertipe float, kemudian memberikan output-an hasil penjumlahan, pengurangan, perkalian, dan pembagian dari dua bilangan tersebut.

```C++
#include <iostream>
using namespace std;

int main() {
    float a, b;

    cout << "Masukkan bilangan pertama : ";
    cin >> a;
    cout << "Masukkan bilangan kedua : ";
    cin >> b;

    cout << "Penjumlahan = " << a + b << endl;
    cout << "Pengurangan = " << a - b << endl;
    cout << "Perkalian   = " << a * b << endl;

    if (b != 0)
        cout << "Pembagian   = " << a / b << endl;
    else
        cout << "Tidak bisa dibagi nol" << endl;

    return 0;
} 
```
### Output Unguided 1 :

##### Output
![Screenshot Output Unguided 1_1](https://github.com/Septian-AS/103112430103_Septian-Ardiansyah-Saputra/blob/main/Pertemuan1_Modul1/Output/Soal1.png)

Program ini meminta dua bilangan dari pengguna lalu menampilkan **penjumlahan, pengurangan, perkalian**, dan **pembagian** (jika bilangan kedua tidak nol), menggunakan **operator aritmatika** dan **percabangan if-else**.

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
<br>[2] Mirzoeva, K. A. (2023). _Methodology for solving a number of problems in Python and C++ languages with the application of mathematical knowledge. TAJIIR: The American Journal of Interdisciplinary Research_, 19–23. https://theamericanjournals.com/index.php/tajiir/article/view/4518
<br>[3] Asnawi, C., & Setiawan, C. B. (2019). Perancangan fungsi terbilang generik menggunakan teknik rekursi. _Jurnal Teknomatika_, 9(1), 1–8.
<br>[4] Cetin, I. (2015). _Students' Understanding of Loops and Nested Loops. Journal of Computers in Mathematics and Science Teaching_, 34(1), 5–22. https://www.tandfonline.com/doi/full/10.1080/14926156.2015.1014075
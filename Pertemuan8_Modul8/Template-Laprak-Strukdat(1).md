# <h1 align="center">Laporan Praktikum Modul 8 - Queue</h1>
<p align="center">Septian Ardiansyah Saputra - 103112430103</p>

## Dasar Teori
Queue adalah struktur data linear yang bekerja berdasarkan prinsip _First In First Out_ (FIFO), artinya elemen yang pertama kali dimasukkan akan menjadi elemen yang pertama kali dikeluarkan [1]. Operasi dasar dalam queue meliputi _enqueue_ (menambahkan elemen ke bagian belakang antrian) dan _dequeue_ (menghapus elemen dari bagian depan antrian) [1]. Implementasi queue dapat menggunakan struktur data _linked list_ untuk memperoleh fleksibilitas dinamis dalam pengalokasian memori, sebagaimana diterapkan dalam aplikasi manajemen antrian berbasis web yang menggunakan _linked list_ [2]. Studi perbandingan pada struktur data juga menunjukkan bahwa pemilihan implementasi queue (_array_ vs _linked list_) memengaruhi performa penghapusan elemen serta efisiensi operasi dalam pemrosesan data skala besar [3].

### A. Pengertian Queue<br/>
Queue (dibaca : kyu) merupakan struktur data yang dapat diumpamakan seperti sebuah antrean. Prinsip dasar dalam Queue adalah FIFO (_First in First out_), proses yang pertama masuk akan diakses terlebih dahulu. Dalam pengimplementasian struktur Queue dalam C dapat menggunakan tipe data _array_ dan _linked list_.

### B. Operasi-Operasi dalam Queue<br/>
Dalam queue ada dua operasi utama, yaitu operasi penyisipan (_Insert_/_Enqueue_) dan operasi pengambilan (_Delete_/_Dequeue_).
#### 1. Insert (Enqueue)
Operasi penyisipan selalu dilakukan pada akhir (_tail_).
#### 2. Delete (Dequeue)
Operasi _delete_ dilakukan pada awal (_head_).

### C. Primitif-Primitif dalam Queue<br/>
Primitif-primitif pada queue tersimpan pada ADT queue, seperti pada materi sebelumnya, primitif-primitifnya tersimpan pada file `.h` dan `.c`.

## Guided

### 1. Guided 1
- queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H
#define Nil NULL

#include <iostream>
using namespace std;

typedef struct node *address;

struct node {
    int dataAngka;
    address next;
};

struct queue {
    address head;
    address tail;
};

bool isEmpty(queue Q);
void createQueue(queue &Q);
address alokasi(int angka);
void dealokasi(queue &node);

void enQueue(queue &Q, address nodeBaru);
void deQueue(queue &Q);
void updateQueue(queue &Q, int posisi);
void viewQueue(queue Q);
void searchData(queue Q, int data);

#endif
```
- queue.cpp
```C++
#include "queue.h"
#include <iostream>

using namespace std;

bool isEmpty(queue Q){
    if(Q.head == Nil){
        return true;
    } else {
        return false;
    }
}

void createQueue(queue &Q){
    Q.head =  Q.tail = Nil;
}

address alokasi(int angka){
    address nodeBaru = new node;
    nodeBaru->dataAngka = angka;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node){
    node->next = Nil;
    delete node;
}

void enQueue(queue &Q, address nodeBaru){
    if(isEmpty(Q) == true){
        Q.head = Q.tail = nodeBaru;
    } else {
        Q.tail->next = nodeBaru;
        Q.tail = nodeBaru;
    }
    cout << "Node " << nodeBaru->dataAngka << " berhasil ditambahkan kedalam queue!" << endl;
}

void deQueue(queue &Q){
    address nodeHapus;
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        nodeHapus = Q.head;
        Q.head = Q.head->next;
        nodeHapus->next = Nil;
        if(Q.head == Nil){
            Q.tail = Nil;
        }
        dealokasi(nodeHapus);
        cout << "node " <<  nodeHapus->dataAngka << " berhasil dihapus dari queue!" << endl;
    }
}

void updateQueue(queue &Q, int posisi){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        if(posisi == 0){
            cout << "Posisi tidak valid!" << endl;
        } else {
            address nodeBantu = Q.head;
            int count = 1;
            bool found = false;
            while(nodeBantu != Nil){
                if(count < posisi){
                    nodeBantu = nodeBantu->next;
                    count++;
                } else if(count == posisi){
                    cout << "Update node poisisi ke-" << posisi << endl;
                    cout << "Masukkan angka : ";
                    cin >> nodeBantu->dataAngka;
                    cout << "Data berhasil diupdate!" << endl;
                    cout << endl;
                    found = true;
                    break;
                }
            }
            if(found == false){
                cout << "Posisi " << posisi << " tidak valid!" << endl;
            }
        }
    }
}

void viewQueue(queue Q){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        address nodeBantu = Q.head;
        while(nodeBantu != Nil){
            cout << nodeBantu->dataAngka << " ";
            nodeBantu = nodeBantu->next;
        }
    }
    cout << endl;
}

void searchData(queue Q, int data){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        address nodeBantu = Q.head;
        int posisi = 1;
        bool found = false;
        cout << "Mencari data " << data << "..." << endl;
        while(nodeBantu != Nil){
            if(nodeBantu->dataAngka == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << endl;
                found = true;
                cout << endl;
                break;
            } else {
                posisi++;
                nodeBantu = nodeBantu->next;
            }
        }
        if(found == false){
            cout << "Data " << data << " tidak ditemukan didalam queue!" << endl;
            cout << endl;
        }
    }
}
```
- main.cpp
```C++
#include "queue.h"
#include <iostream>

using namespace std;

int main(){
    queue Q;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createQueue(Q);

    nodeA = alokasi(1);
    nodeB = alokasi(2);
    nodeC = alokasi(3);
    nodeD = alokasi(4);
    nodeE = alokasi(5);

    enQueue(Q, nodeA);
    enQueue(Q, nodeB);
    enQueue(Q, nodeC);
    enQueue(Q, nodeD);
    enQueue(Q, nodeE);
    cout << endl;

    cout << "--- Queue setelah enQueue ---" << endl;
    viewQueue(Q);
    cout << endl;
    
    deQueue(Q);
    deQueue(Q);
    cout << endl;

    cout << "--- Queue setelah deQueue 2 kali ---" << endl;
    viewQueue(Q);
    cout << endl;

    updateQueue(Q, 2);
    updateQueue(Q, 1);
    updateQueue(Q, 4);
    cout << endl;

    cout << "--- Queue setelah update ---" << endl;
    viewQueue(Q);
    cout << endl;

    searchData(Q, 4);
    searchData(Q, 9);
    
    return 0;
}
```
Guided 1 mengimplementasikan struktur data queue berbasis _linked list_ yang mendukung operasi _enqueue_, _dequeue_, _update_, pencarian, dan penampilan isi antrian, lalu mengujinya melalui fungsi `main()`.

### 2. Guided 2

- queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H

#define MAX_QUEUE 5

struct Queue {
    int info[MAX_QUEUE];
    int head;
    int tail;
    int count;
};

void createQueue(Queue &Q);

bool isEmpty(Queue Q);

bool isFull(Queue Q);

void enqueue(Queue &Q, int x);

int dequeue(Queue &Q);

void printInfo(Queue Q);
#endif
```
- queue.cpp
```C++
#include "queue.h" 
#include <iostream>

using namespace std;

void createQueue(Queue &Q) {
    Q.head = 0; 
    Q.tail = 0; 
    Q.count = 0;
}

bool isEmpty(Queue Q) {
    return Q.count == 0; //Kembalikan true jika jumlah elemen adalah 0
}

bool isFull(Queue Q) {
    return Q.count == MAX_QUEUE; // Kembalikan true jika jumlah elemen sama dengan maks
}

// Definisi prosedur untuk menambahkan elemen (enqueue)
void enqueue(Queue &Q, int x) {
    if (!isFull(Q)) { 
        Q.info[Q.tail] = x; // Masukkan data (x) ke posisi ekor (tail)
        // Pindahkan ekor secara circular (memutar)
        Q.tail = (Q.tail + 1) % MAX_QUEUE; 
        Q.count++; //Tambah jumlah elemen
    } else { 
        cout << "Antrean Penuh!" << endl;
    }
}

//Definisi fungsi untuk menghapus elemen (dequeue)
int dequeue(Queue &Q) {
    if (!isEmpty(Q)) { 
        int x = Q.info[Q.head]; // Ambil data di posisi  (head)
        Q.head = (Q.head + 1) % MAX_QUEUE;
        Q.count--; // Kurangi jumlah elemen
        return x;
    } else {
        cout << "Antrean Kosong!" << endl;
        return -1;
    }
}

// Definisi prosedur untuk menampilkan isi queue 
void printInfo(Queue Q) {
    cout << "Isi Queue: [ ";
    if (!isEmpty(Q)) { 
        int i = Q.head; // Mulai dari head
        int n = 0; //Penghitung elemen yang sudah dicetak
        while (n < Q.count) { // Ulangi sebanyak jumlah elemen
            cout << Q.info[i] << " "; // Cetak info
            i = (i + 1) % MAX_QUEUE; // Geser i secara circular
            n++; // Tambah penghitung
        }
    }
    cout << "]" << endl;
}
```
- main.cpp
```C++
#include <iostream>
#include "queue.h"

using namespace std;

int main(){
    Queue Q;

    createQueue(Q);
    printInfo(Q);

    cout << "\nEnqueue 3 elemen" << endl;
    enqueue(Q, 5);
    printInfo(Q);
    enqueue(Q, 2);
    printInfo(Q);
    enqueue(Q, 7);
    printInfo(Q);

    cout << "\nDequeue 1 Elemen" << endl;
    cout << "Elemen keluar: " << dequeue(Q) << endl;
    printInfo(Q);

    cout << "\nEnqueue 1 Elemen" << endl;
    enqueue(Q, 4);
    printInfo(Q);

    cout << "\nDequeue 2 Elemen" << endl;
    cout << "Elemen keluar: " << dequeue(Q) << endl;
    cout << "Elemen keluar: " << dequeue(Q) << endl;
    printInfo(Q);

    return 0;
}
```
Guided 2 mengimplementasikan _circular queue_ berbasis _array_ yang mendukung operasi _enqueue_, _dequeue_, dan _print_ untuk mengelola antrian berukuran tetap.

## Unguided 

### 1. Soal Unguided 1
Buatlah ADT Queue menggunakan ARRAY sebagai berikut di dalam file “queue.h”:
```
    Type infotype: integer
    Type Queue: <
        info : array [5] of infotype {index array dalam C++ dimulai dari 0}
        head, tail : integer
    >
    procedure CreateQueue (input/output Q: Queue)
    function isEmptyQueue (Q: Queue) → boolean
    function isFullQueue (Q: Queue) → boolean
    procedure enqueue (input/output Q: Queue, input x: infotype)
    function dequeue (input/output Q: Queue) → infotype
    procedure printInfo (input Q: Queue)
```
Buatlah implementasi ADT Queue pada file “queue.cpp” dengan menerapkan mekanisme queue Alternatif 1 (head diam, tail bergerak).
```
int main() {
    cout << "Hello World" << endl;
    Queue Q;
    createQueue(Q);

    cout<<"----------------------"<<endl;
    cout<<" H - T \t | Queue info"<<endl;
    cout<<"----------------------"<<endl;
    printInfo(Q);
    enqueue(Q,5); printInfo(Q);
    enqueue(Q,2); printInfo(Q);
    enqueue(Q,7); printInfo(Q);
    dequeue(Q); printInfo(Q);
    enqueue(Q,4); printInfo(Q);
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);

    return 0;
}
```
- queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H

#define MAX 5
#include <iostream>
using namespace std;
typedef int infotype;

struct Queue {
    infotype info[MAX];
    int head;
    int tail;
};

void createQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);

#endif
```
- queue.cpp
```C++
#include "queue.h"

void createQueue(Queue &Q){
    Q.head = 0;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q){
    return (Q.tail == -1);
}

bool isFullQueue(Queue Q){
    return (Q.tail == MAX - 1);
}

void enqueue(Queue &Q, infotype x){
    if(isFullQueue(Q)){
        cout << "Queue penuh!" << endl;
        return;
    }
    Q.tail++;
    Q.info[Q.tail] = x;
}

infotype dequeue(Queue &Q){
    if(isEmptyQueue(Q)){
        cout << "Queue kosong!" << endl;
        return -1;
    }
    infotype x = Q.info[0];

    for(int i = 0; i < Q.tail; i++){
        Q.info[i] = Q.info[i+1];
    }
    Q.tail--;

    return x;
}

void printInfo(Queue Q){
    if(isEmptyQueue(Q)){
        cout << Q.head-1 << " - " << Q.tail << " | ";
    } else {
        cout << Q.head << " - " << Q.tail << " \t| ";
    }

    if(isEmptyQueue(Q)){
        cout << "empty queue";
    } else {
        for(int i = Q.head; i <= Q.tail; i++){
            cout << Q.info[i] << " ";
        }
    }
    cout << endl;
}
```
- main.cpp
```C++
#include "queue.h"

int main(){
    cout << "Hello world!" << endl;
    Queue Q;
    createQueue(Q);

    cout << "----------------------" << endl;
    cout << " H - T \t| Queue info" << endl;
    cout << "----------------------" << endl;
    printInfo(Q);
    
    enqueue(Q, 5); printInfo(Q);
    enqueue(Q, 2); printInfo(Q);
    enqueue(Q, 7); printInfo(Q);
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);
    enqueue(Q,4); printInfo(Q);
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);

    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/Septian-AS/103112430103_Septian-Ardiansyah-Saputra/blob/main/Pertemuan8_Modul8/Output/Soal1.png)

Program ini mengimplementasikan queue berbasis _array_ dengan pergeseran elemen saat _dequeue_. Lengkap dengan operasi membuat queue, memeriksa penuh/kosong, _enqueue_, _dequeue_, dan menampilkan isi antrian.

### 2. Soal Unguided 2
Buatlah implementasi ADT Queue pada file “queue.cpp” dengan menerapkan mekanisme queue Alternatif 2 (head bergerak, tail bergerak).
- queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H

#define MAX 5
#include <iostream>
using namespace std;
typedef int infotype;

struct Queue {
    infotype info[MAX];
    int head;
    int tail;
};

void createQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);

#endif
```
- queue.cpp
```C++
#include "queue.h"

void createQueue(Queue &Q){
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q){
    return (Q.head == -1 && Q.tail == -1);
}

bool isFullQueue(Queue Q){
    return (Q.tail == MAX - 1);
}

void enqueue(Queue &Q, infotype x){
    if(isFullQueue(Q)){
        cout << "Queue penuh!" << endl;
        return;
    }
    if(isEmptyQueue(Q)){
        Q.head = Q.tail = 0;
    } else {
        Q.tail++;
    }
    Q.info[Q.tail] = x;
}

infotype dequeue(Queue &Q){
    if(isEmptyQueue(Q)){
        cout << "Queue kosong!" << endl;
        return -1;
    }
    infotype x = Q.info[Q.head];
    Q.head++;

    if (Q.head > Q.tail) {
    Q.head = -1;
    Q.tail = -1;
    }

    return x;
}

void printInfo(Queue Q){
    if(isEmptyQueue(Q)){
        cout << Q.head << " - " << Q.tail << " | ";
    } else {
        cout << Q.head << " - " << Q.tail << " \t| ";
    }

    if(isEmptyQueue(Q)){
        cout << "empty queue";
    } else {
        for(int i = Q.head; i <= Q.tail; i++){
            cout << Q.info[i] << " ";
        }
    }
    cout << endl;
}
```
- main.cpp
```C++
#include "queue.h"

int main(){
    cout << "Hello world!" << endl;
    Queue Q;
    createQueue(Q);

    cout << "----------------------" << endl;
    cout << " H - T \t| Queue info" << endl;
    cout << "----------------------" << endl;
    printInfo(Q);
    
    enqueue(Q, 5); printInfo(Q);
    enqueue(Q, 2); printInfo(Q);
    enqueue(Q, 7); printInfo(Q);
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);
    enqueue(Q,4); printInfo(Q);
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);

    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/Septian-AS/103112430103_Septian-Ardiansyah-Saputra/blob/main/Pertemuan8_Modul8/Output/Soal2.png)

Program ini mengimplementasikan queue statis berbasis _array_ dengan indeks _head_-_tail_ yang bergerak maju tanpa pergeseran elemen. Lengkap dengan operasi membuat _queue_, cek kosong/penuh, _enqueue_, _dequeue_, dan menampilkan isi antrian.

### 3. Soal Unguided 3
Buatlah implementasi ADT Queue pada file “queue.cpp” dengan menerapkan mekanisme queue Alternatif 3 (head dan tail berputar)
- queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H

#define MAX 5
#include <iostream>
using namespace std;
typedef int infotype;

struct Queue {
    infotype info[MAX];
    int head;
    int tail;
    int count;
};

void createQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);

#endif
```
- queue.cpp
```C++
#include "queue.h"

void createQueue(Queue &Q){
    Q.head = -1;
    Q.tail = -1;
    Q.count = 0;
}

bool isEmptyQueue(Queue Q){
    return (Q.count == 0);
}

bool isFullQueue(Queue Q){
    return (Q.count == MAX);
}

void enqueue(Queue &Q, infotype x){
    if(isFullQueue(Q)){
        cout << "Queue penuh!" << endl;
        return;
    }
    if(isEmptyQueue(Q)){
        Q.head = 0;
        Q.tail = 0;
    } else {
        Q.tail = (Q.tail + 1) % MAX;
    }
    Q.info[Q.tail] = x;
    Q.count++;
}

infotype dequeue(Queue &Q){
    if(isEmptyQueue(Q)){
        cout << "Queue kosong!" << endl;
        return -1;
    }
    infotype x = Q.info[Q.head];
    Q.head = (Q.head + 1) % MAX;
    Q.count--;

    if(Q.count == 0){
        Q.head = -1;
        Q.tail = -1;
    }

    return x;
}

void printInfo(Queue Q){
    if(isEmptyQueue(Q)){
        cout << Q.head << " - " << Q.tail << " | ";
    } else {
        cout << Q.head << " - " << Q.tail << " \t| ";
    }

    if(isEmptyQueue(Q)){
        cout << "empty queue";
    } else {
        int i = Q.head;
        int n = 0;
        while(n < Q.count){
            cout << Q.info[i] << " ";
            i = (i + 1) % MAX;
            n++;
        }
    }
    cout << endl;
}
```
- main.cpp
```C++
#include "queue.h"

int main(){
    cout << "Hello world!" << endl;
    Queue Q;
    createQueue(Q);

    cout << "----------------------" << endl;
    cout << " H - T \t| Queue info" << endl;
    cout << "----------------------" << endl;
    printInfo(Q);
    
    enqueue(Q, 5); printInfo(Q);
    enqueue(Q, 2); printInfo(Q);
    enqueue(Q, 7); printInfo(Q);
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);
    enqueue(Q,4); printInfo(Q);
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);

    return 0;
}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/Septian-AS/103112430103_Septian-Ardiansyah-Saputra/blob/main/Pertemuan8_Modul8/Output/Soal3.png)

Program ini mengimplementasikan _circular queue_ berbasis _array_ dengan mekanisme _head_-_tail_ melingkar dan penghitung elemen (_count_) untuk menjalankan operasi _enqueue_, _dequeue_, dan menampilkan isi antrian.

## Kesimpulan
Materi ini menunjukkan implementasi berbagai bentuk queue, mulai dari queue statis hingga _circular queue_, yang semuanya bekerja dengan prinsip FIFO untuk mengatur data secara berurutan. Melalui penggunaan _array_, _pointer_, _head_-_tail_, dan mekanisme pergeseran atau perputaran indeks, setiap versi queue menegaskan bagaimana struktur data ini digunakan untuk menangani proses antrian secara efisien. Dengan memahami perbedaan cara kerja _enqueue_, _dequeue_, pemeriksaan kosong/penuh, serta cara menampilkan data, saya dapat memilih dan menerapkan tipe queue yang paling sesuai dengan kebutuhan pemrograman maupun pemecahan masalah komputasi.

## Referensi
[1] Gunawan, R., Yuana, H., & Kirom, S. (2023). Implementasi metode queue pada sistem antrian online berbasis web: studi kasus UPTD Puskesmas Sananwetan. _JATI (Jurnal Mahasiswa Teknik Informatika), 7_(3), 1538–1545. https://doi.org/10.36040/jati.v7i3.6687
<br>[2] Sahid, S., Pasaribu, F. S., Monika F., & Lubis, M. R. (2025). Implementasi queue berbasis linked list pada aplikasi web manajemen antrian print mahasiswa. _Jurnal Ilmu Komputer dan Informatika, 2_(2), 19–22. https://jurnal.globalscients.com/index.php/jiki/article/view/709
<br>[3] Sarevska, M. (2024). Data structures comparison for element deletion including queue. _WSEAS Communications_. https://wseas.com/journals/communications/2024/a305104-015(2024).pdf
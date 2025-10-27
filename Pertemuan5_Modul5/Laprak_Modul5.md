# <h1 align="center">Laporan Praktikum Modul 5 - Singly Linked List (Bagian Kedua)</h1>
<p align="center">Septian Ardiansyah Saputra - 103112430103</p>

## Dasar Teori
Proses _searching_ pada struktur data _singly linked list_ dilakukan secara berurutan dari node awal hingga node yang dicari ditemukan atau mencapai akhir list [1]. Untuk meningkatkan efisiensi, para peneliti telah mengusulkan metode seperti penggunaan dual pointer (_fast_ dan _slow_) untuk menandai elemen tengah dan menerapkan logika mirip _binary search_, meskipun struktur list memiliki keterbatasan dalam akses acak [2]. Dengan menambahkan indeks tambahan (_lane linked list_) yang menggunakan pola matematis (kuadrat/kubik) untuk mempercepat pencarian dengan meminimalkan ketergantungan pada traversal linear penuh [3].

### A. Searching<br/>
_Searching_ merupakan operasi dasar _list_ dengan melakukan aktivitas pencarian terhadap node tertentu. Proses ini berjalan dengan mengunjungi setiap node dan berhenti setelah node yang dicari ketemu. Dengan melakukan operasi _searching_, operasi-operasi seperti _insert after_, _delete after_, dan _update_ akan lebih mudah.

## Guided 

### 1. List Buah
- listBuah.h
```C++
#ifndef LISHBUAH_H
#define LISHBUAH_H
#define Nil NULL

#include <iostream>
using namespace std;

struct buah{
    string nama;
    int jumlah;
    float harga;
};

typedef buah dataBuah;

typedef struct node *address;

struct node{
    dataBuah isidata;
    address next;
};

struct linkedlist{
    address first;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, int jumlah, float harga);
void dealokasi(address &node);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);
void delFirst(linkedlist &List);
void delLast(linkedlist &List);
void delAfter(linkedlist &List, address nodeHapus, address nodePrev);
int nbList(linkedlist List);
void deleteList(linkedlist &List);
void printList(linkedlist List);

void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);

#endif
```
- listBuah.cpp
```C++
#include "listBuah.h"
#include <iostream>
using namespace std;

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedlist &List) {
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, int jumlah, float harga) { 
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jumlah = jumlah; 
    nodeBaru->isidata.harga = harga;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

//prosedur-prosedur untuk delete / menghapus node yang ada didalam list
void delFirst(linkedlist &List){
    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "Node pertama berhasil terhapus!" << endl;
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &List){
    address nodeHapus, nodePrev;
    if(isEmpty(List) == false){
        nodeHapus = List.first;
        if(nodeHapus->next == Nil){
            List.first->next = Nil;
            dealokasi(nodeHapus);
        } else { 
            while(nodeHapus->next != Nil){
                nodePrev = nodeHapus; 
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil; 
            dealokasi(nodeHapus);
        }
        cout << "Node terakhir berhasil terhapus!" << endl;
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else { //jika list tidak kosong
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
            cout << "Node setelah node " << nodePrev->isidata.nama << " berhasil terhapus!" << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

//function untuk menampilkan jumlah node didalam list
int nbList(linkedlist List) {
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next; 
    }
    return count;
}

//prosedur untuk menghapus list (menghapus semua node didalam list)
void deleteList(linkedlist &List){
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus); 
    }
    List.first = Nil; 
    cout << "List berhasil terhapus!" << endl;
}

/*----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - PART 1 (UPDATE) -----*/
//prosedur-prosedur untuk melakukan update data node
void updateFirst(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama buah : ";
        cin >> List.first->isidata.nama;
        cout << "Jumlah : ";
        cin >> List.first->isidata.jumlah;
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateLast(linkedlist List){
    if (isEmpty(List) == true) {
        cout << "List Kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        cout << "masukkan update data node terakhir : " << endl;
        cout << "Nama buah : ";
        cin >> nodeBantu->isidata.nama;
        cout << "Jumlah : ";
        cin >> nodeBantu->isidata.jumlah;
        cout << "Harga : ";
        cin >> nodeBantu->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateAfter(linkedlist List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama buah : ";
            cin >> nodeBantu->isidata.nama;
            cout << "Jumlah : ";
            cin >> nodeBantu->isidata.jumlah;
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}
```
- main.cpp
```C++
#include "listBuah.h"

#include <iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataBuah dtBuah;

    nodeA = alokasi("Jeruk", 100, 3000);
    nodeB = alokasi("Apel", 75, 4000);
    nodeC = alokasi("Pir", 87, 5000);
    nodeD = alokasi("Semangka", 43, 11500);
    nodeE = alokasi("Durian", 15, 31450);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    cout << "Jumlah node : " << nbList(List) << endl;
    cout << endl;

    updateFirst(List);
    updateLast(List);
    updateAfter(List, nodeD);

    cout << "--- ISI LIST SETELAH DILAKUKAN UPDATE ---" << endl;
    printList(List);
    cout << "Jumlah node : " << nbList(List) << endl;
    cout << endl;

    return 0;
}
```
Guided 1 membuat program untuk mengimplementasikan _Singly Linked List_ pada data buah yang mencakup operasi _insert_, _delete_, _update_, dan _traversing list_ dengan pengelolaan memori dinamis.

### 2. Binary Search

```C++
#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void append(Node*&head, int value) {
    Node* newNode = new Node{value, nullptr};
    if (!head) head = newNode;
    else {
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }
}

Node* binarySearch(Node* head, int key) {
    int size = 0;
    for (Node* current = head; current; current = current->next) size++;
    Node* start = head;
    Node* end = nullptr;

    while (size > 0) {
        int mid = size / 2;
        Node* midNode = start;

        for (int i = 0; i < mid; ++i) midNode = midNode->next;

        if (midNode->data == key) return midNode;
        if (midNode->data < key) {
            start = midNode->next;
        }
        else {
            end = midNode;
        }
        size -= mid;
    }
    return nullptr;
}

int main() {
    Node* head = nullptr;
    append(head, 10); append(head, 20); append(head, 30); append(head, 40); append(head, 50);
    
    Node* result = binarySearch(head, 20);
    cout << (result ? "Found" : "Not Found") << endl;

    return 0;
}
```
Guided 2 membuat program yang berfungsi untuk membuat linked list sederhana dan mencari elemen tertentu di dalamnya menggunakan algoritma _binary search_.

### 3. Linear Search

```C++
#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* linearSearch(Node* head, int key) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == key)
            return current;
        current = current->next;
    }
    return nullptr;
}

void append(Node*&head, int value) {
    Node* newNode = new Node{value, nullptr};
    if (!head) head = newNode;
    else {
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }
}

int main() {
    Node* head = nullptr;
    append(head, 10); append(head, 20); append(head, 30);
    
    Node* result = linearSearch(head, 20);
    cout << (result ? "Found" : "Not Found") << endl;

    return 0;
}
```
Guided 3 membuat program yang digunakan untuk membuat linked list sederhana dan mencari data tertentu di dalamnya menggunakan algoritma _linear search_.

## Unguided 

### 1. Soal Unguided 1
Implementasikan program C++ yang menggunakan algoritma Binary Search pada Linked List untuk mencari elemen tertentu. Program harus mampu:
1. Membuat linked list dengan menambahkan node di akhir
2. Mengimplementasikan binary search pada linked list
3. Menampilkan detail proses pencarian dan hasil akhir
```C++
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

//Fungsi untuk menambahkan node baru di akhir linked list
void append(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr};
    if (!head) head = newNode;
    else {
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }
}

//Fungsi untuk menampilkan linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data;
        if (temp->next) cout << " -> ";
        temp = temp->next;
    }
    cout << " -> NULL" << endl;
}

//Fungsi untuk menghitung panjang linked list
int getLength(Node* head) {
    int count = 0;
    while (head) {
        count++;
        head = head->next;
    }
    return count;
}

//Fungsi untuk mengambil node berdasarkan indeks tertentu
Node* getNodeAt(Node* head, int index) {
    for (int i = 0; i < index && head; i++) head = head->next;
    return head;
}

//Fungsi Binary Search pada linked list
Node* binarySearch(Node* head, int key) {
    int left = 0;
    int right = getLength(head) - 1;
    int iter = 1;

    cout << "\nProses Pencarian:\n";

    while (left <= right) {
        int mid = (left + right + 1) / 2;
        Node* midNode = getNodeAt(head, mid);

        cout << "Iterasi " << iter++ << ": Mid = " << midNode->data << " (indeks tengah)";

        if (midNode->data == key) {
            cout << " - DITEMUKAN!" << endl;
            cout << "\nHasil: Nilai " << key << " DITEMUKAN pada linked list!" << endl;
            cout << "Alamat node: " << midNode << endl;
            cout << "Data node: " << midNode->data << endl;
            if (midNode->next)
                cout << "Node berikutnya: " << midNode->next->data << endl;
            else
                cout << "Node berikutnya: NULL" << endl;
            return midNode;
        }
            
        else if (midNode->data < key) {
            cout << " -> Cari di bagian kanan" << endl;
            left = mid + 1;
        } else {
            cout << " -> Cari di bagian kiri" << endl;
            right = mid - 1;
        }
     
        if(left >= right) break;
    }

    cout << "Tidak ada elemen tersisa" << endl;
    cout << "\nHasil: Nilai " << key << " TIDAK DITEMUKAN dalam linked list!" << endl;
    return nullptr;
}

int main() {
    Node* head = nullptr;

    cout << "BINARY SEARCH PADA LINKED LIST" << endl;
    cout << "Linked List yang dibuat: ";
    //Isi dari linked list yang sudah diurutkan
    append(head, 10);
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);
    append(head, 60);
    printList(head);

    //Pencarian pertama
    int key1 = 40;
    cout << "Mencari nilai: " << key1 << endl;
    binarySearch(head, key1);

    //Pencarian kedua
    int key2 = 25;
    cout << "Mencari nilai: " << key2 << endl;
    binarySearch(head, key2);

    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/Septian-AS/103112430103_Septian-Ardiansyah-Saputra/blob/main/Pertemuan5_Modul5/Output/Soal1.png)

Program ini mengimplementasikan algoritma binary search pada linked list untuk mencari elemen tertentu, sekaligus menampilkan proses pencarian, posisi tengah setiap iterasi, serta hasil akhir lengkap dengan alamat dan data node yang ditemukan.

### 2. Soal Unguided 2
Implementasikan program C++ yang menggunakan algoritma Linear Search pada Linked List untuk mencari elemen tertentu. Program harus mampu:
1. Membuat linked list dengan menambahkan node di akhir
2. Mengimplementasikan linear search pada linked list
3. Menampilkan detail proses pencarian dan hasil akhir
```C++
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

//Fungsi untuk menambahkan node baru di akhir linked list
void append(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr};
    if (!head) head = newNode;
    else {
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }
}

//Fungsi untuk menampilkan linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data;
        if (temp->next) cout << " -> ";
        temp = temp->next;
    }
    cout << " -> NULL" << endl;
}

//Fungsi Linear Search pada linked list
Node* linearSearch(Node* head, int key) {
    cout << "\nProses Pencarian:\n";
    Node* current = head;
    int index = 1;

    while (current != nullptr) {
        if (current->data == key) {
            cout << "Memeriksa node " << index << ": " << current->data 
                 << " (SAMA) - DITEMUKAN!" << endl;
            cout << "\nHasil: Nilai " << key << " DITEMUKAN pada linked list!" << endl;
            cout << "Alamat node: " << current << endl;
            cout << "Data node: " << current->data << endl;
            if (current->next)
                cout << "Node berikutnya: " << current->next->data << endl;
            else
                cout << "Node berikutnya: NULL" << endl;
            return current;
        } else {
            cout << "Memeriksa node " << index << ": " << current->data 
                 << " (tidak sama)" << endl;
        }
        current = current->next;
        index++;
    }

    cout << "Tidak ada node lagi yang tersisa" << endl;
    cout << "\nHasil: Nilai " << key << " TIDAK DITEMUKAN dalam linked list!" << endl;
    return nullptr;
}

int main() {
    Node* head = nullptr;

    cout << "LINEAR SEARCH PADA LINKED LIST" << endl;
    cout << "Linked List yang dibuat: ";
    //Isi dari linked list yang sudah diurutkan
    append(head, 10);
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);
    printList(head);

    //Pencarian pertama
    int key1 = 30;
    cout << "Mencari nilai: " << key1 << endl;
    linearSearch(head, key1);

    //Pencarian kedua
    int key2 = 25;
    cout << "Mencari nilai: " << key2 << endl;
    linearSearch(head, key2);

    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/Septian-AS/103112430103_Septian-Ardiansyah-Saputra/blob/main/Pertemuan5_Modul5/Output/Soal2.png)

Program ini mengimplementasikan algoritma linear search pada linked list untuk mencari elemen tertentu, sekaligus menampilkan proses pemeriksaan setiap node beserta hasil akhir, alamat, dan data node yang ditemukan.

## Kesimpulan
Materi _searching_ membahas tentang teknik pencarian data dalam struktur data untuk menemukan elemen tertentu secara efisien. Dua metode utama yang dipelajari adalah _linear search_ dan _binary search_. _Linear search_ melakukan pencarian secara berurutan dari awal hingga akhir, cocok untuk data yang tidak terurut. Sedangkan _binary search_ hanya dapat diterapkan pada data yang sudah terurut dan bekerja dengan membagi ruang pencarian menjadi dua secara berulang, hingga elemen ditemukan atau tidak ada lagi yang tersisa. Kedua algoritma ini menunjukkan pentingnya pemilihan metode pencarian yang tepat sesuai dengan struktur dan kondisi data agar proses pencarian menjadi lebih efektif dan efisien.

## Referensi
[1] Bhatnagar, S. R. (2018). _Speeding up search in singly linked list_. _International Journal of Computer Applications, 182_(18), 26–29. https://doi.org/10.5120/ijca2018917892
<br>[2] Datta, S., & Bhattacharjee, P. (2014). _Implementation of binary search on a singly linked list using dual pointers_. _International Journal of Computer Science and Information Technologies, 5_(2), 215–218.
<br>[3] Sanu, K. (2019). _Binary search in linked list_. _International Journal of Recent Technology and Engineering, 8_(4), 7296–7299. https://doi.org/10.35940/ijrte.D7296.118419
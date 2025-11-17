# <h1 align="center">Laporan Praktikum Modul 7 - Stack</h1>
<p align="center">Septian Ardiansyah Saputra - 103112430103</p>

## Dasar Teori
Stack adalah salah satu struktur data linear yang menerapkan prinsip _Last In First Out_ (LIFO), dimana elemen yang terakhir dimasukkan akan menjadi elemen pertama yang dikeluarkan [1]. Dalam implementasinya, stack hanya memungkinkan dua operasi utama, yaitu `push` untuk menambahkan elemen dan `pop` untuk menghapus elemen dari bagian teratas struktur [2]. Stack dapat diimplementasikan menggunakan _array_ atau _linked list_; pada implementasi _array_, ukuran stack bersifat statis dan diakses menggunakan indeks `top`, sedangkan _linked list_ memungkinkan ukuran stack bersifat dinamis sesuai jumlah node yang dibutuhkan [1]. Struktur data stack digunakan dalam berbagai proses komputasi seperti evaluasi ekspresi, mekanisme pemanggilan fungsi (_call stack_), algoritma pembalikan urutan (_reverse_), serta pengendalian alur program pada sistem rekursif [2][3].

### A. Pengertian Stack<br/>
Stack merupakan salah satu bentuk struktur data dimana prinsip operasi yang digunakan seperti tumpukan. Seperti halnya tumpukan, elemen yang bisa diambil terlebih dahulu adalah elemen yang paling atas, atau elemen yang pertama kali masuk, prinsip ini biasa disebut LIFO (Last In First Out).

### B. Komponen-Komponen dalam Stack<br/>
Komponen – komponen dalam stack pada dasarnya sama dengan komponen pada _Singly linked list_. Komponen utama dalam stack yang berfungsi untuk mengakses data dalam stack adalah elemen paling awal saja yang disebut _Top_.

### C. Operasi-Operasi dalam Stack<br/>
Dalam stack ada dua operasi utama, yaitu operasi penyisipan (_Push_) dan operasi pengambilan (_Pop_).
#### 1. Push
_Push_ adalah operasi menyisipkan elemen pada tumpukan data. Fungsi ini sama dengan fungsi _insert first_ pada list biasa.
#### 2. Pop
_Pop_ adalah operasi pengambilan data dalam list. Operasi ini mirip dengan operasi _delete first_ dalam list linear, karena elemen yang paling pertama kali diakses adalah elemen paling atas atau elemen paling awal saja.

### D. Primitif-Primitif dalam Stack<br/>
1. `createStack()`
2. `isEmpty()`
3. `alokasi()`
4. `dealokasi()`
5. Fungsi – fungsi pencarian.
6. Dan fungsi – fungsi primitif lainnya.

### E. Stack (Representasi Tabel)<br/>
Pada prinsipnya representasi menggunakan tabel sama halnya dengan menggunakan pointer. Perbedaannya terletak pada pendeklarasian struktur datanya, menggunakan _array_ berindeks dan jumlah tumpukan yang terbatas.

## Guided 

### 1. Guided 1

- stack.h
```C++
#ifndef STACK_H
#define STACK_H
#define Nil NULL

#include<iostream>
using namespace std;

typedef struct node *address;

struct node {
    int dataAngka;
    address next;
};

struct stack {
    address top;
};

bool isEmpty(stack listStack);
void createStack(stack &listStack);
address alokasi(int angka);
void dealokasi(address &node);
void push(stack &listStack, address nodeBaru);
void pop(stack &listStack);
void update(stack &listStack, int posisi);
void view(stack listStack);
void searchData(stack listStack, int data);

#endif
```
- stack.cpp
```C++
#include "stack.h"
#include <iostream>

using namespace std;

bool isEmpty(stack listStack){
    if(listStack.top == Nil){
        return true;
    } else {
        return false;
    }
}

void createStack(stack &listStack){
    listStack.top = Nil;
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

void push(stack &listStack, address nodeBaru){
    nodeBaru->next = listStack.top;
    listStack.top = nodeBaru;
    cout << "Node " << nodeBaru->dataAngka << " berhasil ditambahkan kedalam stack!" << endl;
}

void pop(stack &listStack){
    address nodeHapus;
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        nodeHapus = listStack.top;
        int data = nodeHapus->dataAngka;
        listStack.top = listStack.top->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "node " <<  data << " berhasil dihapus dari stack!" << endl;
    }
}

void update(stack &listStack, int posisi){
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        if(posisi <= 0){
            cout << "Posisi tidak valid!" << endl;
        } else {
            address nodeBantu = listStack.top;
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

void view(stack listStack){ //mencetak dari tumpukan paling atas ke tumpukan paling bawah
    if(isEmpty(listStack) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
        while(nodeBantu != Nil){
            cout << nodeBantu->dataAngka << " ";
            nodeBantu = nodeBantu->next;
        }
    }
    cout << endl;
}

void searchData(stack listStack, int data){
    if(isEmpty(listStack) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
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
            cout << "Data " << data << " tidak ditemukan didalam stack!" << endl;
            cout << endl;
        }
    }
}
```
- main.cpp
```C++
#include "stack.h"
#include <iostream>

using namespace std;

int main(){
    stack listStack;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createStack(listStack);

    nodeA = alokasi(1);
    nodeB = alokasi(2);
    nodeC = alokasi(3);
    nodeD = alokasi(4);
    nodeE = alokasi(5);

    push(listStack, nodeA);
    push(listStack, nodeB);
    push(listStack, nodeC);
    push(listStack, nodeD);
    push(listStack, nodeE);
    cout << endl;

    cout << "--- Stack setelah push ---" << endl;
    view(listStack);
    cout << endl;

    pop(listStack);
    pop(listStack);
    cout << endl;

    cout << "--- Stack setelah pop 2 kali ---" << endl;
    view(listStack);
    cout << endl;

    update(listStack, 2);
    update(listStack, 1);
    update(listStack, 4);
    cout << endl;

    cout << "--- Stack setelah update ---" << endl;
    view(listStack);
    cout << endl;

    searchData(listStack, 4);
    searchData(listStack, 9);

    return 0;
}
```
Guided 1 mengimplementasikan stack berbasis _linked list_ dengan operasi _push_, _pop_, _update_, tampil data, dan pencarian, lalu mendemonstrasikan semua fungsi tersebut di `main()`.

### 2. Guided 2

- stack.h
```C++
#ifndef Stack_H
#define MaxEl 20
#define Nil -1

#include <iostream>

typedef int infotype;

struct Stack{
    infotype info[MaxEl];
    int top;
};

void CreateStack(Stack &S);
bool isEmpty(Stack S);
bool isFull(Stack S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);

#endif
```
- stack.cpp
```C++
#include "stack.h"
using namespace std;
// Fungsi untuk membuat stack baru dengan menginisialisasi top = Nil
void CreateStack(Stack &S) {
    S.top = Nil;  // Inisialisasi top dengan nilai Nil mendakan stack kosong
}

// Fungsi untuk mengecek apakah stack kosong
bool isEmpty(Stack S) {
    return S.top == Nil;  // Mengembalikan true jika top bernilai Nil, false jika tidak
}

// Fungsi untuk mengecek apakah stack penuh
bool isFull(Stack S) {
    return S.top == MaxEl - 1;  // Mengembalikan true jika top mencapai batas maksimum (MaxEl-1)
}

// Fungsi untuk menambah elemen ke dalam stack (push)
void push(Stack &S, infotype x) {
    if (!isFull(S)) {  // Cek apakah stack belum penuh
        S.top++;  // Increment nilai top
        S.info[S.top] = x;  // Masukkan nilai x ke array info pada indeks top
    } else {
        cout << "Stack Penuh!" << endl;  // Tampilkan pesan jika stack penuh
    }
}

// Fungsi untuk mengambil elemen teratas dari stack (pop)
infotype pop(Stack &S) {
    infotype x = -999;  // Inisialisasi nilai default jika stack kosong
    if (!isEmpty(S)) {  // Cek apakah stack tidak kosong
        x = S.info[S.top];  // Ambil nilai teratas
        S.top--;  // Decrement nilai top
    } else {
        cout << "Stack Kosong!" << endl;  // Tampilkan pesan jika stack kosong
    }
    return x;  // Kembalikan nilai yang diambil
}

// Fungsi untuk menampilkan isi stack
void printInfo(Stack S) {
    if (isEmpty(S)) {  // Cek apakah stack kosong
        cout << "Stack Kosong" << endl;  // Tampilkan pesan jika kosong
    } else {
        cout << "[TOP] ";  // Tampilkan penanda posisi top
        for (int i = S.top; i >= 0; i--) {  // Loop dari top sampai dasar stack
            cout << S.info[i] << " ";  // Tampilkan setiap elemen
        }
        cout << endl;  // Pindah baris setelah selesai
    }
}

// Fungsi untuk membalik urutan elemen dalam stack
void balikStack(Stack &S) {
    if (!isEmpty(S)) {  // Cek apakah stack tidak kosong
        Stack temp1, temp2;  // Deklarasi dua stack temporary
        CreateStack(temp1); CreateStack(temp2);  // Inisialisasi kedua stack temporary

        while (!isEmpty(S)) { push(temp1, pop(S)); }  // Pindahkan semua elemen ke temp1 (urutan terbalik)

        while (!isEmpty(temp1)) { push(temp2, pop(temp1)); }  // Pindahkan ke temp2 (urutan terbalik lagi)

        while (!isEmpty(temp2)) { push(S, pop(temp2)); }  // Kembalikan ke stack asal (urutan sudah benar)
    }
}
```
- main.cpp
```C++
#include "stack.h"
#include <iostream>

using namespace std;

int main() {
    Stack S;
    CreateStack(S);

    push(S, 3);
    push(S, 4);
    push(S, 8);
    pop(S);
    push(S, 2);
    push(S, 3);
    pop(S);
    push(S, 9);

    cout << "Stack Awal:" << endl;
    printInfo(S);

    cout << "balik stack" << endl;
    balikStack(S);

    cout << "Stack Setelah dibalik:" << endl;
    printInfo(S);

    return 0;
}
```
Guided 2 mengimplementasikan stack berbasis _array_ dengan operasi dasar _push_, _pop_, _print_, dan fungsi untuk membalik isi stack, lalu mendemonstrasikannya dalam fungsi `main()`.

## Unguided 

### 1. Soal Unguided 1
Buatlah ADT Stack menggunakan ARRAY sebagai berikut di dalam file “stack.h”:
```
Type infotype : integer
Type Stack <
    info : array [20] of integer
    top : integer
>
procedure CreateStack(input/output S : Stack)
procedure push(input/output S : Stack, input x : infotype)
function pop(input/output t S : Stack) → infotype
procedure printInfo(input S : Stack)
procedure balikStack(input/output S : Stack)
```
Buatlah implementasi ADT Stack menggunakan Array pada file “stack.cpp” dan “main.cpp
```
int main()
{
    cout << "Hello world!" << endl;
    Stack S;
    createStack(S);
    Push(S,3);
    Push(S,4);
    Push(S,8);
    pop(S)
    Push(S,2);
    Push(S,3);
    pop(S);
    Push(S,9);
    printInfo(S);
    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);
    return 0;
}
```
- stack.h
```C++
#ifndef STACK_H
#define MaxEl 20
#define Nil -1

#include <iostream>

typedef int infotype;

struct Stack {
    infotype info[MaxEl];
    int top;
};

void CreateStack(Stack &S);
bool isEmpty(Stack S);
bool isFull(Stack S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);

#endif
```
- stack.cpp
```C++
#include "stack.h"
using namespace std;

void CreateStack(Stack &S) {
    S.top = Nil;
}

bool isEmpty(Stack S) {
    return (S.top == Nil);
}

bool isFull(Stack S) {
    return S.top == MaxEl - 1;
}

void push(Stack &S, infotype x) {
    if (!isFull(S)) {
        S.top++;
        S.info[S.top] = x;
    } else {
        cout << "Stack penuh!" << endl;
    }
}

infotype pop(Stack &S) {
    infotype x = -999;
    if (!isEmpty(S)) {
        x = S.info[S.top];
        S.top--;
    } else {
        cout << "Stack kosong!" << endl;
    }
    return x;
}

void printInfo(Stack S) {
    if (isEmpty(S)) {
        cout << "Stack kosong" << endl;
    } else {
        cout << "[TOP] ";
        for (int i = S.top; i >= 0; i--) {
            cout << S.info[i] << " ";
        }
        cout << endl;
    }
}

void balikStack(Stack &S) {
    if (!isEmpty(S)) {
        Stack temp1, temp2;
        CreateStack(temp1); CreateStack(temp2);

        while (!isEmpty(S)) { push(temp1, pop(S)); }

        while (!isEmpty(temp1)) { push(temp2, pop(temp1)); }

        while (!isEmpty(temp2)) { push(S, pop(temp2)); }
    }
}
```
- main.cpp
```C++
#include "stack.h"
using namespace std;

int main() {
    cout << "Hello world!" << endl;

    Stack S;
    CreateStack(S);

    push(S,3);
    push(S,4);
    push(S,8);
    pop(S);
    push(S,2);
    push(S,3);
    pop(S);
    push(S,9);

    printInfo(S);

    cout << "balik stack" << endl;
    balikStack(S);

    printInfo(S);

    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/Septian-AS/103112430103_Septian-Ardiansyah-Saputra/blob/main/Pertemuan7_Modul7/Output/Soal1.png)

Program ini membuat stack sederhana (_array_) dengan operasi _push_, _pop_, cetak, serta fungsi untuk membalik isi stack, lalu mendemonstrasikannya di fungsi `main`.

### 2. Soal Unguided 2
Tambahkan prosedur pushAscending(in/out S : Stack, in x : integer)
```
int main()
{
    cout << "Hello world!" << endl;
    Stack S;
    createStack(S);
    pushAscending(S,3);
    pushAscending(S,4);
    pushAscending(S,8);
    pushAscending(S,2);
    pushAscending(S,3);
    pushAscending(S,9);
    printInfo(S);
    cout<<"balik stack"<<endl;
    balikStack(S);
    printInfo(S);
    return 0;
}
```
- stack.h
```C++
void pushAscending(Stack &S, infotype x);
```
- stack.cpp
```C++
void pushAscending(Stack &S, infotype x) {
    Stack temp;
    CreateStack(temp);

    while (!isEmpty(S) && S.info[S.top] > x) {
        push(temp, pop(S));
    }

    push(S, x);

    while (!isEmpty(temp)) {
        push(S, pop(temp));
    }
}
```
- main.cpp
```C++
#include "stack.h"
using namespace std;

int main() {
    cout << "Hello world!" << endl;

    Stack S;
    CreateStack(S);

    pushAscending(S, 3);
    pushAscending(S, 4);
    pushAscending(S, 8);
    pushAscending(S, 2);
    pushAscending(S, 3);
    pushAscending(S, 9);

    printInfo(S);

    cout << "balik stack" << endl;
    balikStack(S);
    
    printInfo(S);

    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/Septian-AS/103112430103_Septian-Ardiansyah-Saputra/blob/main/Pertemuan7_Modul7/Output/Soal2.png)

Program ini membuat stack yang dapat diisi secara terurut naik menggunakan `pushAscending`, kemudian menampilkan isinya dan membalik urutannya dengan `balikStack`.

### 3. Soal Unguided 3
Tambahkan prosedur getInputStream(in/out S : Stack). Prosedur akan terus membaca dan menerima input user dan memasukkan setiap input ke dalam stack hingga user menekan tombol enter. Contoh: gunakan cin.get() untuk mendapatkan inputan user.
```
int main()
{
    cout << "Hello world!" << endl;
    Stack S;
    createStack(S);
    getInputStream(S);
    printInfo(S);
    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);
    return 0;
}
```
- stack.h
```C++
void getInputStream(Stack &S);
```
- stack.cpp
```C++
void getInputStream(Stack &S) {  
    char c;
    cin.get(c);

    if (c == '\n') cin.get(c);

    while (c != '\n') {
        if (!isFull(S) && c >= '0' && c <= '9') {
            push(S, c - '0');
        }
        cin.get(c);
    }
}
```
- main.cpp
```C++
#include "stack.h"
using namespace std;

int main() {
    cout << "Hello world!" << endl;

    Stack S;
    CreateStack(S);

    getInputStream(S);

    printInfo(S);

    cout << "balik stack" << endl;
    balikStack(S);

    printInfo(S);

    return 0;
}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/Septian-AS/103112430103_Septian-Ardiansyah-Saputra/blob/main/Pertemuan7_Modul7/Output/Soal3.png)

Program ini membaca deretan digit dari input sebagai stack, menampilkannya, lalu membalik urutannya menggunakan dua stack sementara.

## Kesimpulan
Stack merupakan struktur data linear yang bekerja dengan prinsip LIFO (_Last In, First Out_) sehingga elemen terakhir yang ditambahkan akan menjadi elemen pertama yang diambil. Dalam implementasinya menggunakan _array_, stack dikelola melalui variabel `top` yang menunjukkan posisi elemen teratas, dengan operasi dasar seperti _CreateStack_, _push_, _pop_, dan _printInfo_ untuk membentuk, menambah, menghapus, dan menampilkan isi stack. Materi ini juga memperkenalkan operasi lanjutan seperti _balikStack_ yang membalik urutan elemen menggunakan stack sementara _pushAscending_ yang menyisipkan elemen secara terurut agar stack tetap tersusun ascending dari bawah ke atas, serta _getInputStream_ yang membaca masukan karakter demi karakter hingga **ENTER** dan memasukkannya ke dalam stack. Secara keseluruhan, materi ini menekankan bagaimana stack dapat dimodifikasi dan diperluas fungsinya menggunakan konsep dasar LIFO serta kombinasi operasi tambahan untuk menghasilkan berbagai bentuk pengolahan data.

## Referensi
[1] Kaluti, M. K., Y. G., Shashank, A. R., & Harshith, K. S. (2018). Dynamic implementation of stack using single linked list. _International Research Journal of Engineering and Technology (IRJET), 5_(3). https://www.irjet.net/archives/V5/i3/IRJET-V5I3434.pdf
<br>[2] International Journal of Innovative Research in Technology. (2021). A comparative study of stack and queues in data structure. _International Journal of Innovative Research in Technology (IJIRT), 7_(4). https://ijirt.org/publishedpaper/IJIRT101022_PAPER.pdf
<br>[3] Kumbhar, A. S., Bedkyale, P., Kore, P., & Killedar, S. (2023). Basic operations on stack using data structure. _International Journal of Research Publication and Reviews, 4_(10), 2034–2036. https://ijrpr.com/uploads/V4ISSUE10/IJRPR18346.pdf
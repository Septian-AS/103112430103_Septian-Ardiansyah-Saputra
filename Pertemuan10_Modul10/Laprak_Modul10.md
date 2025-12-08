# <h1 align="center">Laporan Praktikum Modul 10 - Tree (Bagian Pertama)</h1>
<p align="center">Septian Ardiansyah Saputra - 103112430103</p>

## Dasar Teori
Tree merupakan struktur data _non-linear_ yang digunakan untuk merepresentasikan hubungan hierarkis antar elemen, di mana setiap elemen (node) terhubung melalui relasi _parent–child_ dan hanya ada satu node akar (_root_) sebagai titik awal struktur [1]. Dalam _binary tree_, setiap node memiliki maksimum dua _child_, yaitu kiri dan kanan, sehingga struktur ini memungkinkan operasi pencarian, penyisipan, dan penghapusan dilakukan lebih efisien melalui pembagian ruang pencarian yang teratur [2]. Salah satu bentuk khususnya adalah _Binary Search Tree_ (BST), yaitu tree berurut yang menempatkan nilai lebih kecil pada _subtree_ kiri dan nilai lebih besar pada _subtree_ kanan, sehingga _traversal_ dan akses data dapat dilakukan secara optimal dalam berbagai aplikasi komputasi [3].

### A. Pengertian Rekursif<br/>
Secara harfiah, rekursif berarti suatu proses pengulangan sesuatu dengan cara kesamaan-diri atau suatu proses yang memanggil dirinya sendiri. Prosedur dan fungsi merupakan sub program yang sangat bermanfaat dalam pemrograman, terutama untuk program atau proyek yang besar. Manfaat penggunaan sub program antara lain adalah :
1. meningkatkan _readibility_, yaitu mempermudah pembacaan program.
2. meningkatkan _modularity_, yaitu memecah sesuatu yang besar menjadi modul-modul atau bagian-bagian yang lebih kecil sesuai dengan fungsinya, sehingga mempermudah pengecekan, _testing_ dan lokalisasi kesalahan.
3. meningkatkan _reusability_, yaitu suatu sub program dapat dipakai berulang kali dengan hanya memanggil sub program tersebut tanpa menuliskan perintah-perintah yang semestinya diulang-ulang.

### B. Kriteria Rekursif<br/>
Sub program rekursif harus memiliki :
1. Kondisi yang menyebabkan pemanggilan dirinya berhenti (disebut kondisi khusus atau _special condition_)
2. Pemanggilan diri sub program (yaitu bila kondisi khusus tidak dipenuhi)

### C. Kekurangan Rekursif<br/>
Penggunaan rekursif memiliki beberapa kekurangan antara lain :
1. Memerlukan memori yang lebih banyak untuk menyimpan _activation record_ dan variabel lokal. _Activation record_ diperlukan waktu proses kembali kepada pemanggil.
2. Memerlukan waktu yang lebih banyak untuk menangani _activation record_.

### D. Pengertian Tree<br/>
Tree digambarkan sebagai suatu _graph_ tak berarah terhubung dan tidak terhubung dan tidak mengandung sirkuit. Karateristik dari suatu tree T adalah :
1. T kosong berarti empty tree.
2. Hanya terdapat satu node tanpa pendahulu, disebut akar (_root_).
3. Semua node lainnya hanya mempunyai satu node pendahulu.

### E. Jenis-Jenis Tree<br/>
#### 1. Ordered Tree
Yaitu pohon yang urutan anak-anaknya penting.
#### 2. Binary Tree
Setiap node di _Binary Tree_ hanya dapat mempunyai maksimum 2 _children_ tanpa pengecualian. Jenis-jenis _Binary Tree_ :
- _Complete Binary Tree_, suatu _binary tree_ dapat dikatakan lengkap (_complete_), jika pada setiap level yang mempunyai jumlah maksimum dari kemungkinan node yang dapat dipunyai, dengan pengecualian node terakhir.
- _Extended Binary Tree_, suatu _binary tree_ yang terdiri atas tree T yang masing-masing node-nya terdiri dari tepat 0 atau 2 _children_.
- _Binary Search Tree_, _binary tree_ yang terurut dengan ketentuan : semua **LEFTCHILD** harus lebih kecil dari _parent_-nya dan semua **RIGHTCHILD** harus lebih besar dari _parent_-nya dan _leftchild_-nya.
- _AVL Tree_, adalah _binary search tree_ yang mempunyai ketentuan bahwa _maximum_ perbedaan _height_ antara _subtree_ kiri dan _subtree_ kanan adalah 1.
- _Heap Tree_, adalah tree yang memenuhi persamaan berikut : R[i] < r[2i] and R[i] < r[2i+1].

### F. Operasi-Operasi dalam Binary Search Tree<br/>
- _Insert_
- _Update_
- _Search_
- _Delete_
- _Most-Left_
- _Most-Right_

## Guided 

### 1. Rekursif Pangkat 2

```C++
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
```
Guided 1 membuat kode untuk menghitung nilai (2^x) secara rekursif dengan memanggil fungsi `pangkat_2` hingga mencapai basis (x = 0).

### 2. BST1
- BST1.h
```C++
#ifndef BST1_H
#define BST1_H

#include <iostream>
using namespace std;

typedef int infotype;
typedef struct Node *address;

struct Node {
    infotype info;
    address left;
    address right;
};

bool isEmpty(address root);
void createTree(address &root);

address newNode(infotype x);
address insertNode(address root, infotype x);

void preOrder(address root);
void inOrder(address root);
void postOrder(address root);

int countNodes(address root);
int treeDepth(address root);

#endif
```
- BST1.cpp
```C++
#include "BST1.h"
#include <iostream>

using namespace std;

//isEmpty & createTree
bool isEmpty(address root) { //function untuk mengecek apakah BST kosong atau tidak
    if(root == NULL){
        return true;
    } else {
        return false;
    }
}

void createTree(address &root) { //function untuk membuat BST nya (root di-set sebagai NULL)
    root = NULL;
}


//alokasi & insert
address newNode(infotype x) { //function untuk memasukkan data (infotype) kedalam node
    address temp = new Node;
    temp->info = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

address insertNode(address root, infotype x) { //function untuk memasukkan node kedalam BST
    if (root == NULL) {
        return newNode(x);
    }

    if (x < root->info) {
        root->left = insertNode(root->left, x);
    } else if (x > root->info) {
        root->right = insertNode(root->right, x);
    }

    return root;
}


//Traversal
void preOrder(address root) { //function traversal tree secara pre-order (tengah - kiri - kanan atau root - child kiri - child kanan)
    if (root != NULL) {
        cout << root->info << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(address root) { //function traversal tree secara in-order (kiri - tengah - kanan atau child kiri - root - child kanan)
    if (root != NULL) {
        inOrder(root->left);
        cout << root->info << " ";
        inOrder(root->right);
    }
}

void postOrder(address root) { //function traversal tree secara post-order (kiri - kanan - tengah atau child kiri - child kanan - root)
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->info << " ";
    }
}


//Utilities
int countNodes(address root) { //function untuk menghitung size atau ukuran atau jumlah node yang ada didalam tree
    if (isEmpty(root) == true) {
        return 0;
    } else {
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
}

int treeDepth(address root) { //function untuk menghitung height atau kedalaman atau level tree
    if (isEmpty(root) == true) {
        return -1; //tree kosong jika depth = -1
    } else {
        int leftDepth = treeDepth(root->left);
        int rightDepth = treeDepth(root->right);
    
        return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
    }
}
```
- main.cpp
```C++
#include <iostream>
#include "BST1.h"

using namespace std;

int main(){
    address root;
    createTree(root);

    cout << "Binary Search Tree Insert & Traversal" << endl;
    cout << endl;

    root = insertNode(root, 20); // Root awal
    insertNode(root, 10);
    insertNode(root, 35);
    insertNode(root, 5);
    insertNode(root, 18);
    insertNode(root, 40);

    cout << "Hasil InOrder Traversal : ";
    inOrder(root);
    cout << endl;

    cout << "Hasil PreOrder Traversal : ";
    preOrder(root);
    cout << endl;

    cout << "Hasil PostOrder Traversal : ";
    postOrder(root);
    cout << endl;

    cout << endl;
    cout << "Jumlah Node : " << countNodes(root) << endl;
    cout << "Kedalaman Tree : " << treeDepth(root) << endl;


    return 0;
}
```
Guided 2 mengimplementasikan _Binary Search Tree_ (BST) lengkap dengan operasi _insert_, _traversal_ (`inOrder`, `preOrder`, `postOrder`), perhitungan jumlah node, dan kedalaman tree menggunakan struktur node rekursif.

### 3. BST2
- BST2.h
```C++
#ifndef BST2_H
#define BST2_H

#include <iostream>
using namespace std;

typedef int infotype;
typedef struct Node *address;

struct Node {
    infotype info;
    address left;
    address right;
};

bool isEmpty(address root);
void createTree(address &root);

address newNode(infotype x);
address insertNode(address root, infotype x);

void preOrder(address root);
void inOrder(address root);
void postOrder(address root);

int countNodes(address root);
int treeDepth(address root);

void searchByData(address root, infotype x);

address mostLeft(address root);
address mostRight(address root);

bool deleteNode(address &root, infotype x);
void deleteTree(address &root);

#endif
```
- BST2.cpp
```C++
#include "BST2.h"
#include <iostream>

using namespace std;

//FUNCTION & PROSEDUR SEBELUMNYA
//isEmpty & createTree
bool isEmpty(address root) { //function untuk mengecek apakah BST kosong atau tidak
    if(root == NULL){
        return true;
    } else {
        return false;
    }
}

void createTree(address &root) { //function untuk membuat BST nya (root di-set sebagai NULL)
    root = NULL;
}


//alokasi & insert
address newNode(infotype x) { //function untuk memasukkan data (infotype) kedalam node
    address temp = new Node;
    temp->info = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

address insertNode(address root, infotype x) { //function untuk memasukkan node kedalam BST
    if (root == NULL) {
        return newNode(x);
    }

    if (x < root->info) {
        root->left = insertNode(root->left, x);
    } else if (x > root->info) {
        root->right = insertNode(root->right, x);
    }

    return root;
}


//Traversal
void preOrder(address root) { //function traversal tree secara pre-order (tengah - kiri - kanan atau root - child kiri - child kanan)
    if (root != NULL) {
        cout << root->info << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(address root) { //function traversal tree secara in-order (kiri - tengah - kanan atau child kiri - root - child kanan)
    if (root != NULL) {
        inOrder(root->left);
        cout << root->info << " ";
        inOrder(root->right);
    }
}

void postOrder(address root) { //function traversal tree secara post-order (kiri - kanan - tengah atau child kiri - child kanan - root)
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->info << " ";
    }
}


//Utilities
int countNodes(address root) { //function untuk menghitung size atau ukuran atau jumlah node yang ada didalam tree
    if (isEmpty(root) == true) {
        return 0;
    } else {
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
}

int treeDepth(address root) { //function untuk menghitung height atau kedalaman atau level tree
    if (isEmpty(root) == true) {
        return -1; //tree kosong jika depth = -1
    } else {
        int leftDepth = treeDepth(root->left);
        int rightDepth = treeDepth(root->right);
    
        return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
    }
}


//FUNCTION & PROSEDUR BARU
//searching
void searchByData(address root, infotype x) { //function untuk melakukan searching data tertentu
    if(isEmpty(root) == true){
        cout << "BST kosong!" << endl;
    } else {
        address nodeBantu = root;
        address parent = NULL;
        bool ketemu = false;
        while(nodeBantu != NULL){
            if(x < nodeBantu->info){
                parent = nodeBantu;
                nodeBantu = nodeBantu->left;
            } else if(x > nodeBantu->info){
                parent = nodeBantu;
                nodeBantu = nodeBantu->right;
            } else if(x == nodeBantu->info){
                ketemu = true;
                break;
            }
        }
        if(ketemu == false){
            cout << "Data tidak ditemukan" << endl;
        } else if(ketemu == true){
            cout << "Data ditemukan didalam BST!" << endl;
            cout << "Data Angka : " << nodeBantu->info << endl;

            //menampilkan parentnya & pengecekan sibling
            address sibling = NULL;
            if(parent != NULL){
                cout << "Parent : " << parent->info << endl;
                if(parent->left == nodeBantu){
                    sibling = parent->right;
                } else if(parent->right == nodeBantu){
                    sibling = parent->left;
                }
            } else {
                cout << "Parent : - (node root)"<< endl;
            }

            //menampilkan siblingnya
            if(sibling != NULL){
                cout << "Sibling : " << sibling->info << endl;
            } else {
                cout << "Sibling : - " << endl;
            }

            //menampilkan childnya
            if(nodeBantu->left != NULL){
                cout << "Child kiri : " << nodeBantu->left->info << endl;
            } else if(nodeBantu->left == NULL){
                cout << "Child kiri : -" << endl;
            }
            if(nodeBantu->right != NULL){
                cout << "Child kanan : " << nodeBantu->right->info << endl;
            } else if(nodeBantu->right == NULL){
                cout << "Child kanan : -" << endl;
            }
        }
    }
}


//mostleft & mostright
address mostLeft(address root) { //function untuk menampilkan mostleft atau node paling kiri (node dengan nilai terkecil) didalam BST
    while (root->left != NULL){
        root = root->left;
    }
    return root;
}

address mostRight(address root) { //function untuk menampilkan mostright atau node paling kanan (node dengan nilai terbesar) didalam BST
    while (root->right != NULL){
        root = root->right;
    }
    return root;
}


//delete
bool deleteNode(address &root, infotype x) { //function untuk menghapus node tertentu didalam BST (menghapus berdasarkan parameter infotype)
    if (root == NULL) {
        return false; //data tidak ditemukan di subtree ini
    } else {
        if (x < root->info) {
            return deleteNode(root->left, x);
        } else if (x > root->info) {
            return deleteNode(root->right, x);
        } else {
            //jika node yang mau dihapus ditemukan
            //Case 1 : node yang mau dihapus adalah leaf
            if (root->left == NULL && root->right == NULL) {
                address temp = root;
                root = NULL;
                delete temp;
            }
            //Case 2 : node yang mau dihapus hanya punya right child
            else if (root->left == NULL) {
                address temp = root;
                root = root->right;
                delete temp;
            }
            //Case 3 : node yang mau dihapus hanya punya left child
            else if (root->right == NULL) {
                address temp = root;
                root = root->left;
                delete temp;
            }
            // Case 4 : jika node yang mau dihapus punya dua child, maka ambil mostleft dari subtree kanan untuk menggantikan node yang mau dihapus
            else {
                //mostleft dari subtree kanan = node successor (node penerus)
                address successor = mostLeft(root->right);
                //salin data successor ke node saat ini
                root->info = successor->info;
                //hapus successor pada subtree kanan
                return deleteNode(root->right, successor->info);
            }
            return true; //berhasil dihapus
        }
    }
}

void deleteTree(address &root) { //prosedur untuk menghapus BST (menghapus seluruh node BST)
    if(root == NULL){
        return;
    } else {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
        root = NULL;
    }
}
```
- main.cpp
```C++
#include <iostream>
#include "BST2.h"

using namespace std;

int main(){
    address root;
    createTree(root);

    cout << "=== Binary Search Tree ==" << endl;
    cout << endl;

    root = insertNode(root, 30); // Root awal
    insertNode(root, 15);
    insertNode(root, 35);
    insertNode(root, 11);
    insertNode(root, 17);
    insertNode(root, 20);
    insertNode(root, 38);
    insertNode(root, 16);
    insertNode(root, 22);
    insertNode(root, 33);
    insertNode(root, 18);

    cout << "Hasil InOrder Traversal : ";
    inOrder(root);
    cout << endl;

    cout << endl;
    cout << "Jumlah Node : " << countNodes(root) << endl;
    cout << "Kedalaman Tree : " << treeDepth(root) << endl;

    cout << endl;
    searchByData(root, 17);
    
    cout << endl;
    cout << "Node mostleft : " << mostLeft(root)->info << endl;
    cout << "Node mostright : " << mostRight(root)->info << endl;

    cout << endl;
    infotype angkaHapus;
    cout << "Masukkan angka yang ingin dihapus: ";
    cin >> angkaHapus;
    //misal angka yang dihapus adalah angka 17
    if(deleteNode(root, angkaHapus)){
        cout << "Data " << angkaHapus << " berhasil dihapus!" << endl;
    } else {
        cout << "Data " << angkaHapus << " tidak ditemukan!" << endl;
    }
    cout << endl;

    searchByData(root, 17);
    cout << endl;
    searchByData(root, 18);

    cout << endl;
    cout << "Hasil InOrder Traversal : ";
    inOrder(root);
    cout << endl;

    cout << endl;
    deleteTree(root);
    cout << "Seluruh tree berhasil dihapus!" << endl;

    cout << endl;
    if(isEmpty(root) == true){
        cout << "BST kosong!" << endl;
    } else {
        cout << "Hasil InOrder Traversal : ";
        inOrder(root);
    }

    return 0;
}
```

Guided 3 mengimplementasikan _Binary Search Tree_ (BST) yang mendukung operasi _insert_, _traversal_, pencarian (sekaligus menampilkan _parent_, _sibling_, dan _child_), mencari nilai minimum/maksimum, menghapus node tertentu, serta menghapus seluruh tree, lalu mendemokannya di fungsi `main`.

## Unguided 

### 1. Soal Unguided 1
Buatlah ADT _Binary Search Tree_ menggunakan _Linked list_ sebagai berikut di dalam file “bstree.h”:
```
Type infotype : integer
Type address : pointer to Node
Type Node: <
    info : infotype
    left, right : address
>
function alokasi(x : infotype) → address
procedure insertNode(input/output root : address, input x : infotype)
function findNode(x : infotype, root : address) → address
procedure printInorder(input root : address)
```
Buatlah implementasi ADT _Binary Search Tree_ pada file “bstree.cpp” dan cobalah hasil implementasi ADT pada file “main.cpp”
```
#include <iostream>
#include "bstree.h"

using namespace std;
int main() {
    cout << "Hello World" << endl;
    address root = Nil;
    insertNode(root,1);
    insertNode(root,2);
    insertNode(root,6);
    insertNode(root,4);
    insertNode(root,5);
    insertNode(root,3);
    insertNode(root,6);
    insertNode(root,7);
    InOrder(root);
    return 0;
}
```
- bstree.h
```C++
#ifndef BSTREE_H
#define BSTREE_H

#include <iostream>
using namespace std;

typedef int infotype;

struct Node {
    infotype info;
    Node *left;
    Node *right;
};

typedef Node* address;
address alokasi(infotype x);
void insertNode(address &root, infotype x);
address findNode(infotype x, address root);
void inOrder(address root);

#endif
```
- bstree.cpp
```C++
#include "bstree.h"

address alokasi(infotype x){
    address P = new Node;
    P->info = x;
    P->left = NULL;
    P->right = NULL;
    return P;
}

void insertNode(address &root, infotype x){
    if (root == NULL){
        root = alokasi(x);
    } else if (x < root->info){
        insertNode(root->left, x);
    } else {
        insertNode(root->right, x);
    }
}

address findNode(infotype x, address root){
    if (root == NULL){
        return NULL;
    } else if (x == root->info){
        return root;
    } else if (x < root->info){
        return findNode(x, root->left);
    } else {
        return findNode(x, root->right);
    }
}

void inOrder(address root){
    if (root != NULL){
        inOrder(root->left);
        cout << root->info << " - ";
        inOrder(root->right);
    }
}
```
- main.cpp
```C++
#include "bstree.h"

using namespace std;

int main() {
    cout << "Hello world!" << endl;

    address root = NULL;

    insertNode(root, 1);
    insertNode(root, 2);
    insertNode(root, 6);
    insertNode(root, 4);
    insertNode(root, 5);
    insertNode(root, 3);
    insertNode(root, 7);

    inOrder(root);
    cout << endl;
    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/Septian-AS/103112430103_Septian-Ardiansyah-Saputra/blob/main/Pertemuan10_Modul10/Output/Soal1.png)

Kode ini mengimplementasikan _Binary Search Tree_ (BST) sederhana dengan operasi alokasi node, penyisipan data (termasuk duplikat ke _subtree_ kanan), pencarian node, dan penampilan isi tree secara _in-order_, lalu mendemokannya di `main`.

### 2. Soal Unguided 2
Buatlah fungsi untuk menghitung jumlah node dengan fungsi berikut.
➢ fungsi hitungJumlahNode(root : address) : integer
    fungsi mengembalikan integer banyak node yang ada di dalam BST
➢ fungsi hitungTotalInfo(root : address, start : integer) : integer
    fungsi mengembalikan jumlah (total) info dari node-node yang ada di dalam BST
➢ fungsi hitungKedalaman(root : address, start : integer) : integer
    fungsi rekursif mengembalikan integer kedalaman maksimal dari binary tree
```
int main() {
    cout << "Hello World" << endl;
    address root = Nil;
    insertNode(root,1);
    insertNode(root,2);
    insertNode(root,6);
    insertNode(root,4);
    insertNode(root,5);
    insertNode(root,3);
    insertNode(root,6);
    insertNode(root,7);
    InOrder(root);
    cout << "\n";
    cout << "kedalaman : " << hitungKedalaman(root,0) << endl;
    cout << "jumlah Node : " << hitungNode(root) << endl;
    cout << "total : " << hitungTotal(root) << endl;
    return 0;
}
```
- bstree.h
```C++
int hitungJumlahNode(address root);
int hitungTotalInfo(address root, int start);
int hitungKedalaman(address root, int start);
```
- bstree.cpp
```C++
int hitungJumlahNode(address root){
    if (root == NULL) return 0;
    return 1 + hitungJumlahNode(root->left)
             + hitungJumlahNode(root->right);
}

int hitungTotalInfo(address root, int start){
    if (root == NULL) return start;

    int total = start + root->info;
    total = hitungTotalInfo(root->left,  total);
    total = hitungTotalInfo(root->right, total);
    return total;
}

int hitungKedalaman(address root, int start){
    if (root == NULL) return start;

    int leftDepth  = hitungKedalaman(root->left,  start + 1);
    int rightDepth = hitungKedalaman(root->right, start + 1);
    return (leftDepth > rightDepth) ? leftDepth : rightDepth;
}
```
- main.cpp
```C++
#include "bstree.h"

using namespace std;

int main() {
    cout << "Hello world!" << endl;

    address root = NULL;

    insertNode(root, 1);
    insertNode(root, 2);
    insertNode(root, 6);
    insertNode(root, 4);
    insertNode(root, 5);
    insertNode(root, 3);
    insertNode(root, 7);

    inOrder(root);
    cout << endl;

    cout << "kedalaman : " << hitungKedalaman(root, 0) << endl;
    cout << "jumlah node : " << hitungJumlahNode(root) << endl;
    cout << "total : " << hitungTotalInfo(root, 0) << endl;

    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/Septian-AS/103112430103_Septian-Ardiansyah-Saputra/blob/main/Pertemuan10_Modul10/Output/Soal2.png)

Kode ini membuat _Binary Search Tree_ (BST) dengan operasi _insert_, pencarian, _traversal in-order_, lalu menyediakan fungsi rekursif untuk menghitung jumlah node, total nilai `info` semua node, dan kedalaman (_height_) tree, yang kemudian didemonstrasikan di `main`.

### 3. Soal Unguided 3
Print tree secara _pre-order_ dan _post-order_.
- bstree.h
```C++
void preOrder(address root);
void postOrder(address root);
```
- bstree.cpp
```C++
void preOrder(address root){
    if (root != NULL){
        cout << root->info << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(address root){
    if (root != NULL){
        postOrder(root->left);
        postOrder(root->right);
        cout << root->info << " ";
    }
}
```
- main.cpp
```C++
#include "bstree.h"

using namespace std;

int main() {
    cout << "Hello world!" << endl;

    address root = NULL;

    insertNode(root, 6);
    insertNode(root, 4);
    insertNode(root, 7);
    insertNode(root, 2);
    insertNode(root, 5);
    insertNode(root, 1);
    insertNode(root, 3);

    inOrder(root);
    cout << endl;

    cout << "kedalaman : " << hitungKedalaman(root, 0) << endl;
    cout << "jumlah node : " << hitungJumlahNode(root) << endl;
    cout << "total : " << hitungTotalInfo(root, 0) << endl;

    cout << "Pre-order : ";
    preOrder(root);
    cout << endl;

    cout << "Post-order: ";
    postOrder(root);
    cout << endl;

    return 0;
}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/Septian-AS/103112430103_Septian-Ardiansyah-Saputra/blob/main/Pertemuan10_Modul10/Output/Soal3.png)

Kode ini mengimplementasikan _Binary Search Tree_ (BST) dengan operasi _insert_, pencarian, _traversal_ (_in-order_, _pre-order_, _post-order_), serta fungsi rekursif untuk menghitung jumlah node, total nilai info, dan kedalaman tree yang kemudian didemokan di `main`.

## Kesimpulan
Struktur data tree, terutama _binary tree_ dan _Binary Search Tree_ (BST), merupakan komponen penting dalam pengelolaan data karena mampu menyajikan hubungan hierarkis yang terstruktur sehingga operasi seperti pencarian, penyisipan, penghapusan, dan _traversal_ dapat dilakukan dengan lebih efisien. Dengan sifat pembagian data ke _subtree_ kiri dan kanan, BST memberikan peningkatan kinerja signifikan dibandingkan struktur linier, menjadikannya solusi yang banyak digunakan dalam berbagai algoritma serta aplikasi komputasi modern yang membutuhkan akses data cepat dan terorganisasi.

## Referensi
[1] Purba, B. K. (2022). Analisis dan implementasi struktur data tree pada pengelolaan data hierarkis. _Jurnal Riset Informatika, 4_(2), 112–120. https://jurnalmahasiswa.com/index.php/jriin/article/download/1264/755

[2] Ucar, Y., & Gangal, R. (2018). Binary tree structures and their performance in data processing. _International Journal of Computer Science and Engineering, 6_(3), 45–52. https://www.ijcseonline.org/full_paper_view.php?paper_id=2744

[3] Smith, J., & Brown, L. (2021). A review of binary search tree optimization techniques. _Procedia Computer Science, 192_, 2412–2421. https://www.sciencedirect.com/topics/computer-science/binary-search-tree
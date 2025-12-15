# <h1 align="center">Laporan Praktikum Modul 13 - Multi Linked List</h1>
<p align="center">Septian Ardiansyah Saputra - 103112430103</p>

## Dasar Teori
Multi Linked List (MLL) merupakan pengembangan dari struktur data _linked list_ yang memungkinkan satu node memiliki lebih dari satu relasi _pointer_ sehingga dapat merepresentasikan hubungan data bertingkat atau relasi satu-ke-banyak (_one_-_to_-_many_) [1]. Struktur ini sangat efektif digunakan pada sistem yang memerlukan pengelompokan data secara hierarkis karena setiap node _parent_ dapat memiliki _linked list child_ yang berdiri sendiri dan dikelola secara dinamis [1]. Penerapan multi linked list juga terbukti mampu meningkatkan efisiensi dalam pengolahan data kompleks, seperti pencarian dan pengelompokan elemen, karena fleksibilitas hubungan antar node, meskipun implementasinya memerlukan pengelolaan _pointer_ yang cermat untuk menjaga konsistensi dan integritas data [2].

### A. Multi Linked List<br/>
Multi List merupakan sekumpulan list yang berbeda yang memiliki suatu keterhubungan satu sama lain. Tiap elemen dalam multi link list dapat membentuk list sendiri. Biasanya ada yang bersifat sebagai list induk dan list anak.
#### 1. Insert
- _Insert_ Anak, dalam penambahan elemen anak harus diketahui dulu elemen induknya.
- _Insert_ Induk, untuk _insert_ elemen induk sama dengan konsep _insert_ pada _Singly_, _Doubly_ dan _Circular Linked List_.
#### 2. Delete
- _Delete_ Anak, sama dengan _insert_ anak, untuk _delete_ anak maka harus diketahui dulu induknya.
- _Delete_ Induk, untuk _delete_ elemen induk saat di hapus maka seluruh anak dengan induk tersebut juga harus dihapus.

## Guided 

### 1. Multilist
- multilist.h
```C++
#ifndef MULTILIST_H
#define MULTILIST_H

#include <iostream>

using namespace std;

typedef struct nodeParent *NodeParent;
typedef struct nodeChild *NodeChild;

struct nodeChild {
    string idMakanan;
    string namaMakanan;
    NodeChild next;
    NodeChild prev;
};

struct listAnak {
    NodeChild first;
    NodeChild last;
};

struct nodeParent {
    string idKategoriMakanan;
    string namaKategoriMakanan;
    NodeParent next;
    NodeParent prev;
    listAnak L_Anak;
};

struct listInduk {
    NodeParent first;
    NodeParent last;
};

void createListInduk(listInduk &LInduk);
void createListAnak(listAnak &LAnak);

NodeParent alokasiNodeParent(string idKategoriMakanan, string namaKategoriMakanan);
void dealokasiNodeParent(NodeParent &nodeInduk);

NodeChild alokasiNodeChild(string idMakanan, string namaMakanan);
void dealokasiNodeChild(NodeChild &nodeAnak);

void insertLastParent(listInduk &LInduk, NodeParent nodeBaruParent);
void hapusListAnak(listAnak &LAnak);
void deleteAfterParent(listInduk &LInduk, NodeParent nodePrev);

void insertLastChild(listAnak &LAnak, NodeChild nodeBaruChild);
void deleteAfterChild(listAnak &LAnak, NodeChild nodePrev);
void findChildByID(listInduk &LInduk, string IDCari);

void printStrukturMLL(listInduk &LInduk);

#endif
```
- multilist.cpp
```C++
#include "multilist.h"
#include <iostream>

using namespace std;

//create list
void createListInduk(listInduk &LInduk){
    LInduk.first = LInduk.last = NULL;
}

void createListAnak(listAnak &LAnak){
    LAnak.first = LAnak.last = NULL;
}

//alokasi & dealokasi parent
NodeParent alokasiNodeParent(string idKategoriMakanan, string namaKategoriMakanan){
    NodeParent nodeBaruParent = new nodeParent;
    nodeBaruParent->idKategoriMakanan = idKategoriMakanan;
    nodeBaruParent->namaKategoriMakanan = namaKategoriMakanan;
    nodeBaruParent->next = NULL;
    nodeBaruParent->prev = NULL;
    createListAnak(nodeBaruParent->L_Anak);
    return nodeBaruParent;
}

void dealokasiNodeParent(NodeParent &nodeInduk){
    if(nodeInduk != NULL) {
        nodeInduk->next = nodeInduk->prev = NULL;
        delete nodeInduk;
        nodeInduk = NULL;
    }
}

//alokasi & delaokasi child
NodeChild alokasiNodeChild(string idMakanan, string namaMakanan){
    NodeChild nodeBaruChild = new nodeChild;
    nodeBaruChild->idMakanan = idMakanan;
    nodeBaruChild->namaMakanan = namaMakanan;
    nodeBaruChild->next = NULL;
    nodeBaruChild->prev = NULL;
    return nodeBaruChild;
}

void dealokasiNodeChild(NodeChild &nodeAnak){
    if(nodeAnak != NULL) {
        nodeAnak->next = nodeAnak->prev = NULL;
        delete nodeAnak;
        nodeAnak = NULL;
    }
}

//operasi pada parent
void insertLastParent(listInduk &LInduk, NodeParent nodeBaruParent){
    if(LInduk.first == NULL) {
        LInduk.first = LInduk.last = nodeBaruParent;
    } else {
        nodeBaruParent->prev = LInduk.last;
        LInduk.last->next = nodeBaruParent;
        LInduk.last = nodeBaruParent;
    }
    cout << "Node parent "<< nodeBaruParent->namaKategoriMakanan << " berhasil ditambahkan kedalam urutan terakhir di list Induk!" << endl;
}

void hapusListAnak(listAnak &LAnak){
    NodeChild nodeBantu = LAnak.first;
    while(nodeBantu != NULL) {
        NodeChild nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasiNodeChild(nodeHapus);
    }
    LAnak.first = LAnak.last = NULL;
}

void deleteAfterParent(listInduk &LInduk, NodeParent nodePrev){
    if(LInduk.first == NULL){
        cout << "List induk kosong!" << endl;
    } else {
        if(nodePrev != NULL && nodePrev->next != NULL){
            NodeParent nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            if (nodeHapus->next != NULL){
                (nodeHapus->next)->prev = nodePrev;
            } else {
                LInduk.last = nodePrev;
            }
            nodeHapus->next = NULL;
            if(nodeHapus->L_Anak.first != NULL){
                hapusListAnak(nodeHapus->L_Anak);
            }
            dealokasiNodeParent(nodeHapus);
            cout << "Node parent setelah node " << nodePrev->namaKategoriMakanan << " berhasil dihapus beserta anak-anaknya!" << endl;
        } else {
            cout << "Node prev tidak valid!" << endl;
        }
    }
}

//operasi pada child
void insertLastChild(listAnak &LAnak, NodeChild nodeBaruChild){
    if(LAnak.first == NULL) {
        LAnak.first = LAnak.last = nodeBaruChild;
    } else {
        nodeBaruChild->prev = LAnak.last;
        LAnak.last->next = nodeBaruChild;
        LAnak.last = nodeBaruChild;
    }
    cout << "Node child "<< nodeBaruChild->namaMakanan << " berhasil ditambahkan kedalam urutan terakhir di list Anak!" << endl;
}

void deleteAfterChild(listAnak &LAnak, NodeChild nodePrev){
    if(LAnak.first == NULL){
        cout << "List anak kosong!" << endl;
    } else {
        if(nodePrev != NULL && nodePrev->next != NULL){
            NodeChild nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            if (nodeHapus->next != NULL){
                (nodeHapus->next)->prev = nodePrev;
            } else {
                LAnak.last = nodePrev;
            }
            nodeHapus->next = NULL;
            dealokasiNodeChild(nodeHapus);
            cout << "Node child setelah node " << nodePrev->namaMakanan << " berhasil dihapus!" << endl;
        } else {
            cout << "Node prev tidak valid!" << endl;
        }
    }
}
void findChildByID(listInduk &LInduk, string IDCari){
    if(LInduk.first == NULL){
        cout << "List induk kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        int indexParent = 1;
        int ketemu = false;
        while(nodeBantuParent != NULL){
            NodeChild nodeBantuChild = nodeBantuParent->L_Anak.first;
            int indexChild = 1;
            while(nodeBantuChild != NULL){
                if(nodeBantuChild->idMakanan == IDCari) {
                    cout << "Data ID child ditemukan pada list anak dari node parent " << nodeBantuParent->namaKategoriMakanan << " pada posisi ke-" << indexChild << "!" << endl;
                    cout << "--- Data Child ---" << endl;
                    cout << "ID Child (ID Makanan) : " << nodeBantuChild->idMakanan << endl;
                    cout << "Posisi dalam list anak : posisi ke-" << indexChild << endl;
                    cout << "Nama Makanan : " << nodeBantuChild->namaMakanan << endl;
                    cout << "---------------------------" << endl;
                    cout << "--- Data Parent ---" << endl;
                    cout << "ID Parent (ID Kategori Makanan): " << nodeBantuParent->idKategoriMakanan << endl;
                    cout << "Posisi dalam list induk : posisi ke-" << indexParent << endl;
                    cout << "Nama Kategori Makanan : " << nodeBantuParent->namaKategoriMakanan << endl;
                    ketemu = true;
                    break;
                } else {
                    nodeBantuChild = nodeBantuChild->next;
                    indexChild++;
                }
            }
            if(ketemu){
                break;
            } else {
                nodeBantuParent = nodeBantuParent->next;
                indexParent++;
            }
        }
        if(!ketemu){
            cout << "Data ID child tidak ditemukan didalam list anak!" << endl;
        }
    }
}

//operasi print
void printStrukturMLL(listInduk &LInduk){
    if(LInduk.first == NULL) {
        cout << "List induk kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        int indexParent = 1;
        while(nodeBantuParent != NULL) {
            cout << "=== Parent " << indexParent << " ===" << endl;
            cout << "ID Kategori Makanan : " << nodeBantuParent->idKategoriMakanan << endl;
            cout << "Nama Kategori Makanan : " << nodeBantuParent->namaKategoriMakanan << endl;

            //print list anak dari node parentnya
            NodeChild nodeBantuChild = nodeBantuParent->L_Anak.first;
            if(nodeBantuChild == NULL) {
                cout << "  (tidak ada child)" << endl;
            } else {
                int indexChild = 1;
                while(nodeBantuChild != NULL) {
                    cout << "  - Child " << indexChild << " :" << endl;
                    cout << "      ID Makanan : " << nodeBantuChild->idMakanan << endl;
                    cout << "      Nama Makanan : " << nodeBantuChild->namaMakanan << endl;
                    nodeBantuChild = nodeBantuChild->next;
                    indexChild++;
                }
            }
            cout << "---------------------------" << endl;
            nodeBantuParent = nodeBantuParent->next;
            indexParent++;
        }
    }
}
```
- main.cpp
```C++
#include "multilist.h"
#include <iostream>

using namespace std;

int main() {
    listInduk LInduk;
    createListInduk(LInduk);

    NodeParent K01 = alokasiNodeParent("K01", "Makanan Berat");
    insertLastParent(LInduk, K01);
    NodeParent K02 = alokasiNodeParent("K02", "Minuman");
    insertLastParent(LInduk, K02);
    NodeParent K03 = alokasiNodeParent("K03", "Dessert");
    insertLastParent(LInduk, K03);
    cout << endl;

    NodeChild M01 = alokasiNodeChild("M01", "Nasi Goreng Spesial");
    insertLastChild(K01->L_Anak, M01);
    NodeChild M02 = alokasiNodeChild("M02", "Ayam Bakar Madu");
    insertLastChild(K02->L_Anak, M02);
    NodeChild D02 = alokasiNodeChild("D02", "Jus Alpukat");
    insertLastChild(K02->L_Anak, D02);
    NodeChild D01 = alokasiNodeChild("D01", "Es Teh Manis");
    insertLastChild(K02->L_Anak, D01);
    NodeChild S01 = alokasiNodeChild("S01", "Puding Coklat");
    insertLastChild(K03->L_Anak, S01);

    printStrukturMLL(LInduk);
    cout << endl;
    findChildByID(LInduk, "D01");
    cout << endl;
    deleteAfterChild(K01->L_Anak, M01);
    cout << endl;
    deleteAfterParent(LInduk, K02);
    cout << endl;
    printStrukturMLL(LInduk);
    cout << endl;

    return 0;
}
```
Guided 1 mengimplementasikan _multilist double linked list_ untuk mengelola kategori makanan sebagai _parent_ dan daftar makanan sebagai _child_, lengkap dengan operasi alokasi, penambahan, penghapusan, pencarian, serta pencetakan struktur data secara terstruktur.

## Unguided 

### 1. Soal Unguided 1
Buatlah ADT Multi Linked List sebagai berikut didalam file “MultiLL.h” :
```
Type Struct golonganHewan <
     idGolongan : String
     namaGolongan : String
>

Type Struct dataHewan < 
     idHewan : String
     namaHewan : String
     habitat : String
     ekor : Boolean //TRUE jika berekor, FALSE jika tidak berekor
     bobot : float //dalam kg
>

typedef struct nodeParent *NodeParent; //alias pointer ke struct nodeParent
typedef struct nodeChild *NodeChild; //alias pointer ke struct nodeChild

Type Struct nodeChild <
     isidata : dataHewan
     next : NodeChild
     prev : NodeChild
>

Type Struct listChild <
     first : NodeChild 
     last : NodeChild
>

Type Struct nodeParent <
     isidata : golonganHewan
     next : NodeParent
     prev : NodeParent
     L_Child : listChild
>

Type Struct listParent <
     first : NodeParent
     last : NodeParent
>

Function isEmptyParent(input/output LParent : listParent) : Boolean
Function isEmptyChild(input/output LChild : listChild) : Boolean
Procedure createListParent(input/output LParent : listParent)
Procedure createListChild(input/output LChild : listChild)

Function allocNodeParent(input idGol : String, namaGol : String) : NodeParent
Function allocNodeChild(input idHwn : String, namaHwn : String, habitat : String, tail : Boolean, weight : float) : NodeChild

Procedure deallocNodeParent(input/output NParent : NodeParent)
Procedure deallocNodeChild(input/output NChild : NodeChild)

Procedure insertFirstParent(input/output LParent : listParent, newNParent : NodeParent)
Procedure insertLastParent(input/output LParent : listParent, newNParent : NodeParent)
Procedure deleteFirstParent(input/output LParent : listParent)
Procedure deleteAfterParent(input/output LParent : listParent, NPrev : NodeParent)

Procedure insertFirstChild(input/output LChild : listChild, newNChild : NodeChild)
Procedure insertLastChild(input/output LChild : listChild, newNChild : NodeChild)
Procedure deleteFirstChild(input/output LChild : listChild)
Procedure deleteAfterChild(input/output LChild : listChild, NPrev : NodeChild)

Procedure printMLLStructure(input/output LParent : listParent)
Procedure deleteListChild(input/output LChild : listChild)
```
Kemudian buatlah implementasi ADT Multi Linked List tersebut pada file “MultiLL.cpp”.
<br>Kemudian pada file “main.cpp” lakukan operasi INSERT.
<br>Keterangan isi data setiap node :
<br>❖ List Parent : 
1. idGolongan : G001
<br>namaGolongan : Aves
2. idGolongan : G002
<br>namaGolongan : Mamalia
3. idGolongan : G003
<br>namaGolongan : Pisces
4. idGolongan : G004
<br>namaGolongan : Amfibi
5. idGolongan : G005
<br>namaGolongan : Reptil

<br>❖ List Child G001 : 
1. idHewan : AV001
<br>namaHewan : Cendrawasih
<br>habitat : Hutan
<br>ekor : True
<br>bobot : 0,3
2. idHewan : AV002
<br>namaHewan : Bebek
<br>habitat : Air
<br>ekor : True
<br>bobot : 2

<br>❖ List Child G002 : 
1. idHewan : M001
<br>namaHewan : Harimau
<br>habitat : Hutan
<br>ekor : True
<br>bobot : 200
2. idHewan : M003
<br>namaHewan : Gorila
<br>habitat : Hutan
<br>ekor : False
<br>bobot : 160
3. idHewan : M002
<br>namaHewan : Kucing
<br>habitat : Darat
<br>ekor : True
<br>bobot : 4

<br>❖ List Child G004 : 
1. idHewan : AM001
<br>namaHewan : Kodok
<br>habitat : Sawah
<br>ekor : False
<br>bobot : 0,2

<br>Setelah melakukan INSERT, lakukan operasi PRINT dengan memanggil prosedur `printMLLStructure()`.

- MultiLL.h
```C++
#ifndef MULTILL_H
#define MULTILL_H

#include <iostream>
#include <string>
using namespace std;

struct golonganHewan {
    string idGolongan;
    string namaGolongan;
};

struct dataHewan {
    string idHewan;
    string namaHewan;
    string habitat;
    bool ekor;
    float bobot;
};

typedef struct nodeParent *NodeParent;
typedef struct nodeChild *NodeChild;

struct nodeChild {
    dataHewan isidata;
    NodeChild next;
    NodeChild prev;
};

struct listChild {
    NodeChild first;
    NodeChild last;
};

struct nodeParent {
    golonganHewan isidata;
    NodeParent next;
    NodeParent prev;
    listChild L_Child;
};

struct listParent {
    NodeParent first;
    NodeParent last;
};

bool isEmptyParent(listParent LParent);
bool isEmptyChild(listChild LChild);

void createListParent(listParent &LParent);
void createListChild(listChild &LChild);

NodeParent allocNodeParent(string idGol, string namaGol);
NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight);

void deallocNodeParent(NodeParent &NParent);
void deallocNodeChild(NodeChild &NChild);

void insertFirstParent(listParent &LParent, NodeParent newNParent);
void insertLastParent(listParent &LParent, NodeParent newNParent);

void deleteFirstParent(listParent &LParent);
void deleteAfterParent(listParent &LParent, NodeParent NPrev);

void insertFirstChild(listChild &LChild, NodeChild newNChild);
void insertLastChild(listChild &LChild, NodeChild newNChild);

void deleteFirstChild(listChild &LChild);
void deleteAfterChild(listChild &LChild, NodeChild NPrev);

void deleteListChild(listChild &LChild);

void printMLLStructure(listParent &LParent);

#endif
```
- MultiLL.cpp
```C++
#include "MultiLL.h"

bool isEmptyParent(listParent LParent) {
    return (LParent.first == nullptr && LParent.last == nullptr);
}

bool isEmptyChild(listChild LChild) {
    return (LChild.first == nullptr && LChild.last == nullptr);
}

void createListParent(listParent &LParent) {
    LParent.first = nullptr;
    LParent.last = nullptr;
}

void createListChild(listChild &LChild) {
    LChild.first = nullptr;
    LChild.last = nullptr;
}

NodeParent allocNodeParent(string idGol, string namaGol) {
    NodeParent p = new nodeParent;
    p->isidata.idGolongan = idGol;
    p->isidata.namaGolongan = namaGol;
    p->next = nullptr;
    p->prev = nullptr;
    createListChild(p->L_Child);
    return p;
}

NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight) {
    NodeChild c = new nodeChild;
    c->isidata.idHewan = idHwn;
    c->isidata.namaHewan = namaHwn;
    c->isidata.habitat = habitat;
    c->isidata.ekor = tail;
    c->isidata.bobot = weight;
    c->next = nullptr;
    c->prev = nullptr;
    return c;
}

void deallocNodeParent(NodeParent &NParent) {
    delete NParent;
    NParent = nullptr;
}

void deallocNodeChild(NodeChild &NChild) {
    delete NChild;
    NChild = nullptr;
}

void insertFirstParent(listParent &LParent, NodeParent newNParent) {
    if (newNParent == nullptr) return;

    if (isEmptyParent(LParent)) {
        LParent.first = newNParent;
        LParent.last = newNParent;
    } else {
        newNParent->next = LParent.first;
        LParent.first->prev = newNParent;
        LParent.first = newNParent;
    }
}

void insertLastParent(listParent &LParent, NodeParent newNParent) {
    if (newNParent == nullptr) return;

    if (isEmptyParent(LParent)) {
        LParent.first = newNParent;
        LParent.last = newNParent;
    } else {
        newNParent->prev = LParent.last;
        LParent.last->next = newNParent;
        LParent.last = newNParent;
    }
}

void deleteFirstParent(listParent &LParent) {
    if (isEmptyParent(LParent)) return;

    NodeParent del = LParent.first;

    deleteListChild(del->L_Child);

    if (LParent.first == LParent.last) {
        LParent.first = nullptr;
        LParent.last = nullptr;
    } else {
        LParent.first = del->next;
        LParent.first->prev = nullptr;
        del->next = nullptr;
    }
    deallocNodeParent(del);
}

void deleteAfterParent(listParent &LParent, NodeParent NPrev) {
    if (isEmptyParent(LParent)) return;
    if (NPrev == nullptr) return;
    if (NPrev->next == nullptr) return;

    NodeParent del = NPrev->next;

    deleteListChild(del->L_Child);

    NPrev->next = del->next;
    if (del->next != nullptr) {
        del->next->prev = NPrev;
    } else {
        LParent.last = NPrev;
    }

    del->next = nullptr;
    del->prev = nullptr;
    deallocNodeParent(del);
}

void insertFirstChild(listChild &LChild, NodeChild newNChild) {
    if (newNChild == nullptr) return;

    if (isEmptyChild(LChild)) {
        LChild.first = newNChild;
        LChild.last = newNChild;
    } else {
        newNChild->next = LChild.first;
        LChild.first->prev = newNChild;
        LChild.first = newNChild;
    }
}

void insertLastChild(listChild &LChild, NodeChild newNChild) {
    if (newNChild == nullptr) return;

    if (isEmptyChild(LChild)) {
        LChild.first = newNChild;
        LChild.last = newNChild;
    } else {
        newNChild->prev = LChild.last;
        LChild.last->next = newNChild;
        LChild.last = newNChild;
    }
}

void deleteFirstChild(listChild &LChild) {
    if (isEmptyChild(LChild)) return;

    NodeChild del = LChild.first;

    if (LChild.first == LChild.last) {
        LChild.first = nullptr;
        LChild.last = nullptr;
    } else {
        LChild.first = del->next;
        LChild.first->prev = nullptr;
        del->next = nullptr;
    }
    deallocNodeChild(del);
}

void deleteAfterChild(listChild &LChild, NodeChild NPrev) {
    if (isEmptyChild(LChild)) return;
    if (NPrev == nullptr) return;
    if (NPrev->next == nullptr) return;

    NodeChild del = NPrev->next;

    NPrev->next = del->next;
    if (del->next != nullptr) {
        del->next->prev = NPrev;
    } else {
        LChild.last = NPrev;
    }

    del->next = nullptr;
    del->prev = nullptr;
    deallocNodeChild(del);
}

void deleteListChild(listChild &LChild) {
    while (!isEmptyChild(LChild)) {
        deleteFirstChild(LChild);
    }
}

void printMLLStructure(listParent &LParent) {
    if (isEmptyParent(LParent)) {
        cout << "(List Parent kosong)\n";
        return;
    }

    NodeParent p = LParent.first;
    int idxParent = 1;

    while (p != nullptr) {
        cout << "=== Parent " << idxParent << " ===\n";
        cout << "ID Golongan   : " << p->isidata.idGolongan << "\n";
        cout << "Nama Golongan : " << p->isidata.namaGolongan << "\n";

        if (isEmptyChild(p->L_Child)) {
            cout << "(tidak ada child)\n";
        } else {
            NodeChild c = p->L_Child.first;
            int idxChild = 1;
            while (c != nullptr) {
                cout << "  - Child " << idxChild << " :\n";
                cout << "     ID Hewan   : " << c->isidata.idHewan << "\n";
                cout << "     Nama Hewan : " << c->isidata.namaHewan << "\n";
                cout << "     Habitat    : " << c->isidata.habitat << "\n";
                cout << "     Ekor       : " << (c->isidata.ekor ? 1 : 0) << "\n";
                cout << "     Bobot      : " << c->isidata.bobot << "\n";
                c = c->next;
                idxChild++;
            }
        }

        cout << "-----------------------\n";
        p = p->next;
        idxParent++;
    }
}
```
- main.cpp
```C++
#include "MultiLL.h"

int main() {
    listParent LP;
    createListParent(LP);

    insertLastParent(LP, allocNodeParent("G001", "Aves"));
    insertLastParent(LP, allocNodeParent("G002", "Mamalia"));
    insertLastParent(LP, allocNodeParent("G003", "Pisces"));
    insertLastParent(LP, allocNodeParent("G004", "Amfibi"));
    insertLastParent(LP, allocNodeParent("G005", "Reptil"));

    auto findParent = [&](const string &id) -> NodeParent {
        NodeParent p = LP.first;
        while (p != nullptr) {
            if (p->isidata.idGolongan == id) return p;
            p = p->next;
        }
        return nullptr;
    };

    NodeParent pG001 = findParent("G001");
    if (pG001 != nullptr) {
        insertLastChild(pG001->L_Child, allocNodeChild("AV001", "Cendrawasih", "Hutan", true, 0.3f));
        insertLastChild(pG001->L_Child, allocNodeChild("AV002", "Bebek", "Air", true, 2.0f));
    }

    NodeParent pG002 = findParent("G002");
    if (pG002 != nullptr) {
        insertLastChild(pG002->L_Child, allocNodeChild("M001", "Harimau", "Hutan", true, 200.0f));
        insertLastChild(pG002->L_Child, allocNodeChild("M003", "Gorila", "Hutan", false, 160.0f));
        insertLastChild(pG002->L_Child, allocNodeChild("M002", "Kucing", "Darat", true, 4.0f));
    }

    NodeParent pG004 = findParent("G004");
    if (pG004 != nullptr) {
        insertLastChild(pG004->L_Child, allocNodeChild("AM001", "Kodok", "Sawah", false, 0.2f));
    }

    printMLLStructure(LP);

    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/Septian-AS/103112430103_Septian-Ardiansyah-Saputra/blob/main/Pertemuan11_Modul13/Output/Soal1.png)

Kode ini mengimplementasikan _Multilevel Linked List_ (MLL) _double linked list_ untuk merepresentasikan golongan hewan sebagai _parent_ dan data hewan sebagai _child_, lengkap dengan operasi pembuatan list, alokasi/dealokasi node, penambahan, penghapusan, serta pencetakan struktur data secara hierarkis.

### 2. Soal Unguided 2
Tambahkan prosedur `searchHewanByEkor(input/output LParent : listParent, input tail : Boolean)` yang digunakan untuk melakukan operasi SEARCHING hewan-hewan yang memiliki EKOR FALSE (pencarian dilakukan dengan menelusuri list child yang ada pada masing-masing node parent). Kemudian panggil prosedur tersebut pada main.cpp.
- MultiLL.h
```C++
void searchHewanByEkor(listParent &LParent, bool tail);
```
- MultiLL.cpp
```C++
void searchHewanByEkor(listParent &LParent, bool tail) {
    if (isEmptyParent(LParent)) {
        cout << "List parent kosong\n";
        return;
    }

    NodeParent p = LParent.first;
    int posParent = 1;
    bool found = false;

    while (p != nullptr) {
        NodeChild c = p->L_Child.first;
        int posChild = 1;

        while (c != nullptr) {
            if (c->isidata.ekor == tail) {
                found = true;

                cout << "Data ditemukan pada list anak dari node parent "
                     << p->isidata.namaGolongan
                     << " pada posisi ke-" << posChild << "!\n";

                cout << "--- Data Child ---\n";
                cout << "ID Child               : " << c->isidata.idHewan << endl;
                cout << "Posisi dalam list anak : posisi ke-" << posChild << endl;
                cout << "Nama Hewan             : " << c->isidata.namaHewan << endl;
                cout << "Habitat                : " << c->isidata.habitat << endl;
                cout << "Ekor                   : " << (c->isidata.ekor ? 1 : 0) << endl;
                cout << "Bobot                  : " << c->isidata.bobot << endl;

                cout << "----------------------------\n";
                cout << "--- Data Parent ---\n";
                cout << "ID Parent               : " << p->isidata.idGolongan << endl;
                cout << "Posisi dalam list induk : posisi ke-" << posParent << endl;
                cout << "Nama golongan           : " << p->isidata.namaGolongan << endl;
                cout << "----------------------------------------------\n";
            }

            c = c->next;
            posChild++;
        }

        p = p->next;
        posParent++;
    }

    if (!found) {
        cout << "Data dengan ekor = " << (tail ? "TRUE" : "FALSE") << " tidak ditemukan.\n";
    }
}
```
- main.cpp
```C++
#include "MultiLL.h"

int main() {
    listParent LP;
    createListParent(LP);

    insertLastParent(LP, allocNodeParent("G001", "Aves"));
    insertLastParent(LP, allocNodeParent("G002", "Mamalia"));
    insertLastParent(LP, allocNodeParent("G003", "Pisces"));
    insertLastParent(LP, allocNodeParent("G004", "Amfibi"));
    insertLastParent(LP, allocNodeParent("G005", "Reptil"));

    auto findParent = [&](const string &id) -> NodeParent {
        NodeParent p = LP.first;
        while (p != nullptr) {
            if (p->isidata.idGolongan == id) return p;
            p = p->next;
        }
        return nullptr;
    };

    NodeParent pG001 = findParent("G001");
    if (pG001 != nullptr) {
        insertLastChild(pG001->L_Child, allocNodeChild("AV001", "Cendrawasih", "Hutan", true, 0.3f));
        insertLastChild(pG001->L_Child, allocNodeChild("AV002", "Bebek", "Air", true, 2.0f));
    }

    NodeParent pG002 = findParent("G002");
    if (pG002 != nullptr) {
        insertLastChild(pG002->L_Child, allocNodeChild("M001", "Harimau", "Hutan", true, 200.0f));
        insertLastChild(pG002->L_Child, allocNodeChild("M003", "Gorila", "Hutan", false, 160.0f));
        insertLastChild(pG002->L_Child, allocNodeChild("M002", "Kucing", "Darat", true, 4.0f));
    }

    NodeParent pG004 = findParent("G004");
    if (pG004 != nullptr) {
        insertLastChild(pG004->L_Child, allocNodeChild("AM001", "Kodok", "Sawah", false, 0.2f));
    }

    printMLLStructure(LP);

    cout << "\n=== SEARCH HEWAN DENGAN EKOR FALSE ===\n\n";
    searchHewanByEkor(LP, false);

    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/Septian-AS/103112430103_Septian-Ardiansyah-Saputra/blob/main/Pertemuan11_Modul13/Output/Soal2.png)

Kode ini mengimplementasikan _multilevel double linked list_ untuk menyimpan golongan hewan (_parent_) dan data hewan (_child_) dengan operasi CRUD serta fitur pencarian hewan berdasarkan atribut ekor (_true_/_false_) yang menelusuri seluruh _child_ pada setiap _parent_ dan menampilkan detail posisi serta datanya.

### 3. Soal Unguided 3
Lakukan operasi DELETE dengan menghapus node G004 yang ada pada list parent (list child dari node tersebut juga terhapus), kemudian lakukan lagi operasi PRINT dengan memanggil prosedur `printMLLStructure()`. Sehingga bentuk dari multi linked listnya berubah.
<br>Untuk `MultiLL.h` dan `MultiLL.cpp` tidak ada perubahan.

- main.cpp
```C++
#include "MultiLL.h"

int main() {
    listParent LP;
    createListParent(LP);

    insertLastParent(LP, allocNodeParent("G001", "Aves"));
    insertLastParent(LP, allocNodeParent("G002", "Mamalia"));
    insertLastParent(LP, allocNodeParent("G003", "Pisces"));
    insertLastParent(LP, allocNodeParent("G004", "Amfibi"));
    insertLastParent(LP, allocNodeParent("G005", "Reptil"));

    auto findParent = [&](const string &id) -> NodeParent {
        NodeParent p = LP.first;
        while (p != nullptr) {
            if (p->isidata.idGolongan == id) return p;
            p = p->next;
        }
        return nullptr;
    };

    NodeParent pG001 = findParent("G001");
    if (pG001 != nullptr) {
        insertLastChild(pG001->L_Child, allocNodeChild("AV001", "Cendrawasih", "Hutan", true, 0.3f));
        insertLastChild(pG001->L_Child, allocNodeChild("AV002", "Bebek", "Air", true, 2.0f));
    }

    NodeParent pG002 = findParent("G002");
    if (pG002 != nullptr) {
        insertLastChild(pG002->L_Child, allocNodeChild("M001", "Harimau", "Hutan", true, 200.0f));
        insertLastChild(pG002->L_Child, allocNodeChild("M003", "Gorila", "Hutan", false, 160.0f));
        insertLastChild(pG002->L_Child, allocNodeChild("M002", "Kucing", "Darat", true, 4.0f));
    }

    NodeParent pG004 = findParent("G004");
    if (pG004 != nullptr) {
        insertLastChild(pG004->L_Child, allocNodeChild("AM001", "Kodok", "Sawah", false, 0.2f));
    }

    printMLLStructure(LP);

    cout << "\n=== SEARCH HEWAN DENGAN EKOR FALSE ===\n";
    searchHewanByEkor(LP, false);

    NodeParent prev = nullptr;
    NodeParent cur  = LP.first;

    while (cur != nullptr && cur->isidata.idGolongan != "G004") {
        prev = cur;
        cur  = cur->next;
    }

    if (cur == nullptr) {
        cout << "Node G004 tidak ditemukan!\n";
    } else {
        if (prev == nullptr) {
            deleteFirstParent(LP);
        } else {
            deleteAfterParent(LP, prev);
        }
    }

    cout << "\n=== SETELAH DELETE G004 ===\n";
    printMLLStructure(LP);

    return 0;
}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/Septian-AS/103112430103_Septian-Ardiansyah-Saputra/blob/main/Pertemuan11_Modul13/Output/Soal3.png)

Kode pada `main` ini menambahkan proses penghapusan _parent_ golongan G004 (Amfibi) beserta seluruh _child_-nya dengan menelusuri list _parent_, menentukan apakah node berada di awal atau setelah node tertentu, lalu menampilkan kembali struktur _multilevel linked list_ setelah penghapusan.

## Kesimpulan
Multi Linked List merupakan struktur data yang efektif untuk merepresentasikan data bertingkat dengan relasi satu-ke-banyak, karena memungkinkan setiap node _parent_ terhubung dengan sekumpulan node _child_ secara dinamis. Struktur ini memberikan fleksibilitas tinggi dalam proses penyimpanan, pencarian, dan penghapusan data tanpa bergantung pada ukuran statis memori, sehingga cocok digunakan pada sistem dengan data kompleks dan hierarkis. Namun, implementasi multi linked list menuntut pengelolaan _pointer_ yang cermat agar integritas data tetap terjaga dan tidak menimbulkan kesalahan memori.

## Referensi
[1] Stojisavljević, Đ. (2015). Multi linked lists: An object-oriented approach. _Proceedings of the 5th International Conference on Information Society and Technology (ICIST 2015)_. https://www.eventiotic.com/eventiotic/files/Papers/URL/icist2015_71.pdf
<br>[2] Patel, S. H., & Mahariba, A. J. (2019). Word search puzzle using multi-linked lists. _International Journal of Engineering and Advanced Technology (IJEAT), 8_(4S2). https://www.ijeat.org/wp-content/uploads/papers/v8i4s2/D10050484S219.pdf
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
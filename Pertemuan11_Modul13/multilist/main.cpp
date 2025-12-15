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
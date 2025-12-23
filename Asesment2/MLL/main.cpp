#include "MLL.h"

int main() {
    ListParent LP;
    createListParent(LP);

    adrParent G004 = alokasiNodeParent("G004", "Romance");
    adrParent G003 = alokasiNodeParent("G003", "Horror");
    adrParent G002 = alokasiNodeParent("G002", "Comedy");
    adrParent G001 = alokasiNodeParent("G001", "Action");

    insertFirstParent(LP, G004);
    insertFirstParent(LP, G003);
    insertFirstParent(LP, G002);
    insertFirstParent(LP, G001);

    adrParent P = LP.first;
    while (P != NULL) {
        if (P->IDGenre == "G001") {
            insertLastChild(P->child, alokasiNodeChild("FA001", "The Raid", 101, 2011, 7.6));
        } else if (P->IDGenre == "G002") {
            insertLastChild(P->child, alokasiNodeChild("FC001", "Agak Laen", 119, 2024, 8.0));
            insertLastChild(P->child, alokasiNodeChild("FC002", "My Stupid Boss", 108, 2016, 6.8));
        } else if (P->IDGenre == "G003") {
            insertLastChild(P->child, alokasiNodeChild("FH001", "Pengabdi Setan", 107, 2017, 8.4));
        } else if (P->IDGenre == "G004") {
            insertLastChild(P->child, alokasiNodeChild("FR001", "Habibie & Ainun", 118, 2012, 7.6));
            insertLastChild(P->child, alokasiNodeChild("FR002", "Dilan 1990", 110, 2018, 6.6));
        }
        P = P->next;
    }

    cout << "=== Struktur MLL Awal ===\n";
    printStrukturMLL(LP);

    cout << "\n=== searchFilmByRatingRange (8.0 - 8.5) ===\n";
    searchFilmByRatingRange(LP, 8.0, 8.5);

    adrParent prec = LP.first;

    while (prec != NULL && prec->IDGenre != "G001") {
        prec = prec->next;
    }

    adrParent del;
    deleteAfterParent(LP, prec, del);

    cout << "\n=== Struktur MLL Setelah deleteAfterParent (hapus G002) ===\n";
    printStrukturMLL(LP);

    return 0;
}
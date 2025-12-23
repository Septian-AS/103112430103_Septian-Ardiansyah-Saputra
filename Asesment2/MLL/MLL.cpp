#include "MLL.h"

void createListParent(ListParent &LP) {
    LP.first = NULL;
    LP.last = NULL;
}

void createListChild(ListChild &LC) {
    LC.first = NULL;
    LC.last = NULL;
}

adrParent alokasiNodeParent(string idGenre, string namaGenre) {
    adrParent P = new Parent;
    P->IDGenre = idGenre;
    P->namaGenre = namaGenre;
    P->next = NULL;
    P->prev = NULL;
    createListChild(P->child);
    return P;
}

adrChild alokasiNodeChild(string idFilm, string judul, int durasi, int tahun, float rating) {
    adrChild C = new Child;
    C->IDFilm = idFilm;
    C->judulFilm = judul;
    C->durasiFilm = durasi;
    C->tahunTayang = tahun;
    C->ratingFilm = rating;
    C->next = NULL;
    C->prev = NULL;
    return C;
}

void dealokasiNodeParent(adrParent &P) {
    if (P != NULL) {
        delete P;
        P = NULL;
    }
}

void dealokasiNodeChild(adrChild &C) {
    if (C != NULL) {
        delete C;
        C = NULL;
    }
}

void insertFirstParent(ListParent &LP, adrParent P) {
    if (P == NULL) return;

    if (LP.first == NULL) {
        LP.first = P;
        LP.last = P;
    } else {
        P->next = LP.first;
        LP.first->prev = P;
        LP.first = P;
    }
}

void insertLastChild(ListChild &LC, adrChild C) {
    if (C == NULL) return;

    if (LC.first == NULL) {
        LC.first = C;
        LC.last = C;
    } else {
        LC.last->next = C;
        C->prev = LC.last;
        LC.last = C;
    }
}

void hapusListChild(adrParent P) {
    if (P == NULL) return;

    adrChild cur = P->child.first;
    while (cur != NULL) {
        adrChild del = cur;
        cur = cur->next;
        dealokasiNodeChild(del);
    }
    P->child.first = NULL;
    P->child.last = NULL;
}

void deleteAfterParent(ListParent &LP, adrParent Prec, adrParent &Pdel) {
    Pdel = NULL;
    if (Prec == NULL) return;
    if (Prec->next == NULL) return;

    Pdel = Prec->next;

    Prec->next = Pdel->next;
    if (Pdel->next != NULL) {
        Pdel->next->prev = Prec;
    } else {
        LP.last = Prec;
    }

    Pdel->next = NULL;
    Pdel->prev = NULL;

    hapusListChild(Pdel);
    dealokasiNodeParent(Pdel);
}

void printStrukturMLL(ListParent LP) {
    adrParent P = LP.first;
    int i = 1;

    while (P != NULL) {
        cout << "=== Parent " << i << " ===\n";
        cout << "ID Genre : " << P->IDGenre << "\n";
        cout << "Nama Genre : " << P->namaGenre << "\n";

        adrChild C = P->child.first;
        int j = 1;
        while (C != NULL) {
            cout << " - Child " << j << " :\n";
            cout << "    ID Film : " << C->IDFilm << "\n";
            cout << "    Judul Film : " << C->judulFilm << "\n";
            cout << "    Durasi Film : " << C->durasiFilm << " menit\n";
            cout << "    Tahun Tayang : " << C->tahunTayang << "\n";
            cout << "    Rating Film : " << C->ratingFilm << "\n";
            C = C->next;
            j++;
        }

        cout << "------------------------------\n";
        P = P->next;
        i++;
    }
}

void searchFilmByRatingRange(ListParent LP, float minRating, float maxRating) {
    adrParent P = LP.first;
    int posParent = 1;
    bool ada = false;

    while (P != NULL) {
        adrChild C = P->child.first;
        int posChild = 1;

        while (C != NULL) {
            if (C->ratingFilm >= minRating && C->ratingFilm <= maxRating) {
                ada = true;
                cout << "Data Film ditemukan pada list child dari node parent " << P->namaGenre
                     << " pada posisi ke-" << posChild << "!\n";
                cout << "------------------------------\n";
                cout << "--- Data Film (Child) ---\n";
                cout << "Judul Film : " << C->judulFilm << "\n";
                cout << "Posisi dalam list child : posisi ke-" << posChild << "\n";
                cout << "ID Film : " << C->IDFilm << "\n";
                cout << "Durasi Film : " << C->durasiFilm << " menit\n";
                cout << "Tahun Tayang : " << C->tahunTayang << "\n";
                cout << "Rating Film : " << C->ratingFilm << "\n";
                cout << "------------------------------\n";
                cout << "--- Data Genre (Parent) ---\n";
                cout << "ID Genre : " << P->IDGenre << "\n";
                cout << "Posisi dalam list parent : posisi ke-" << posParent << "\n";
                cout << "Nama Genre : " << P->namaGenre << "\n";
                cout << "====================================\n";
            }
            C = C->next;
            posChild++;
        }

        P = P->next;
        posParent++;
    }

    if (!ada) {
        cout << "Data Film tidak ditemukan pada rentang rating tersebut.\n";
    }
}
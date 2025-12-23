#ifndef MLL_H
#define MLL_H

#include <iostream>
#include <string>
using namespace std;

struct Child;
struct Parent;

typedef Parent* adrParent;
typedef Child* adrChild;

struct ListChild {
    adrChild first;
    adrChild last;
};

struct ListParent {
    adrParent first;
    adrParent last;
};

struct Parent {
    string IDGenre;
    string namaGenre;
    adrParent next;
    adrParent prev;
    ListChild child;
};

struct Child {
    string IDFilm;
    string judulFilm;
    int durasiFilm;
    int tahunTayang;
    float ratingFilm;
    adrChild next;
    adrChild prev;
};

void createListParent(ListParent &LP);
void createListChild(ListChild &LC);
adrParent alokasiNodeParent(string idGenre, string namaGenre);
adrChild alokasiNodeChild(string idFilm, string judul, int durasi, int tahun, float rating);
void dealokasiNodeParent(adrParent &P);
void dealokasiNodeChild(adrChild &C);
void insertFirstParent(ListParent &LP, adrParent P);
void insertLastChild(ListChild &LC, adrChild C);
void deleteAfterParent(ListParent &LP, adrParent Prec, adrParent &Pdel);
void hapusListChild(adrParent P);
void searchFilmByRatingRange(ListParent LP, float minRating, float maxRating);
void printStrukturMLL(ListParent LP);

#endif
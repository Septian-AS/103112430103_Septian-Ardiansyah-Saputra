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
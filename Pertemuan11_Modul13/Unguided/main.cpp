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
#include <iostream>
#include <string>
using namespace std;

struct Node {
    string nama;
    Node* next;
};

Node* head = NULL;

void insertAkhir(string nama) {
    Node* baru = new Node();
    baru->nama = nama;
    baru->next = NULL;

    if (head == NULL) {
        head = baru;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = baru;
    }
}

void deleteNama(string nama) {
    if (head == NULL) return;

    if (head->nama == nama) {
        Node* hapus = head;
        head = head->next;
        delete hapus;
        return;
    }

    Node* p = head;
    while (p->next != NULL && p->next->nama != nama) {
        p = p->next;
    }

    if (p->next != NULL) {
        Node* hapus = p->next;
        p->next = hapus->next;
        delete hapus;
    }
}

void printList() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->nama << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void hitungGenap() {
    int count = 0;
    Node* temp = head;
    while (temp != NULL) {
        if (temp->nama.length() % 2 == 0)
            count++;
        temp = temp->next;
    }
    cout << "Jumlah nama dengan huruf genap: " << count << endl;
}

int main() {
    int menu;
    string nama;

    do {
        cout << "Menu: 1 insert, 2 delete, 3 view, 4 hitung genap, 0 exit" << endl;
        cin >> menu;

        if (menu == 1) {
            cout << "Masukkan nama: ";
            cin >> nama;
            insertAkhir(nama);
        }
        else if (menu == 2) {
            cout << "Masukkan nama untuk delete: ";
            cin >> nama;
            deleteNama(nama);
        }
        else if (menu == 3) {
            printList();
        }
        else if (menu == 4) {
            hitungGenap();
        }

    } while (menu != 0);

    return 0;
}
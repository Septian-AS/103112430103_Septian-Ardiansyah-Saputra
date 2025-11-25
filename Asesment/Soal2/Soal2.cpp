#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

Node* head = NULL;
Node* tail = NULL;

void insertAkhir(int x) {
    Node* baru = new Node;
    baru->data = x;
    baru->next = NULL;
    baru->prev = NULL;

    if (head == NULL) {
        head = tail = baru;
    } else {
        tail->next = baru;
        baru->prev = tail;
        tail = baru;
    }
}

void deleteAkhir() {
    if (tail == NULL) return;

    if (head == tail) {
        delete tail;
        head = tail = NULL;
        return;
    }

    Node* hapus = tail;
    tail = tail->prev;
    tail->next = NULL;
    delete hapus;
}

void viewDepan() {
    Node* p = head;
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

void reverseList() {
    Node* curr = head;
    Node* temp = NULL;

    while (curr != NULL) {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;  
    }

    if (temp != NULL) {
        head = temp->prev;
    }
}

int main() {
    int menu, nilai;

    do {
        cout << "Menu: 1 insert (end), 2 delete (last), 3 view (depan), 4 reverse & view (depan), 0 exit" << endl;
        cin >> menu;

        if (menu == 1) {
            cout << "Masukkan nilai: ";
            cin >> nilai;
            insertAkhir(nilai);
        }
        else if (menu == 2) {
            deleteAkhir();
        }
        else if (menu == 3) {
            viewDepan();
        }
        else if (menu == 4) {
            reverseList();
            cout << "List setelah di-reverse: ";
            viewDepan();
        }

    } while (menu != 0);

    return 0;
}
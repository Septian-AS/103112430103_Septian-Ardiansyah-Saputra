#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

//Fungsi untuk menambahkan node baru di akhir linked list
void append(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr};
    if (!head) head = newNode;
    else {
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }
}

//Fungsi untuk menampilkan linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data;
        if (temp->next) cout << " -> ";
        temp = temp->next;
    }
    cout << " -> NULL" << endl;
}

//Fungsi Linear Search pada linked list
Node* linearSearch(Node* head, int key) {
    cout << "\nProses Pencarian:\n";
    Node* current = head;
    int index = 1;

    while (current != nullptr) {
        if (current->data == key) {
            cout << "Memeriksa node " << index << ": " << current->data 
                 << " (SAMA) - DITEMUKAN!" << endl;
            cout << "\nHasil: Nilai " << key << " DITEMUKAN pada linked list!" << endl;
            cout << "Alamat node: " << current << endl;
            cout << "Data node: " << current->data << endl;
            if (current->next)
                cout << "Node berikutnya: " << current->next->data << endl;
            else
                cout << "Node berikutnya: NULL" << endl;
            return current;
        } else {
            cout << "Memeriksa node " << index << ": " << current->data 
                 << " (tidak sama)" << endl;
        }
        current = current->next;
        index++;
    }

    cout << "Tidak ada node lagi yang tersisa" << endl;
    cout << "\nHasil: Nilai " << key << " TIDAK DITEMUKAN dalam linked list!" << endl;
    return nullptr;
}

int main() {
    Node* head = nullptr;

    cout << "LINEAR SEARCH PADA LINKED LIST" << endl;
    cout << "Linked List yang dibuat: ";
    //Isi dari linked list yang sudah diurutkan
    append(head, 10);
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);
    printList(head);

    //Pencarian pertama
    int key1 = 30;
    cout << "Mencari nilai: " << key1 << endl;
    linearSearch(head, key1);

    //Pencarian kedua
    int key2 = 25;
    cout << "Mencari nilai: " << key2 << endl;
    linearSearch(head, key2);

    return 0;
}

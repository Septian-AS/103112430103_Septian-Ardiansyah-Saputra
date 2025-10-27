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

//Fungsi untuk menghitung panjang linked list
int getLength(Node* head) {
    int count = 0;
    while (head) {
        count++;
        head = head->next;
    }
    return count;
}

//Fungsi untuk mengambil node berdasarkan indeks tertentu
Node* getNodeAt(Node* head, int index) {
    for (int i = 0; i < index && head; i++) head = head->next;
    return head;
}

//Fungsi Binary Search pada linked list
Node* binarySearch(Node* head, int key) {
    int left = 0;
    int right = getLength(head) - 1;
    int iter = 1;

    cout << "\nProses Pencarian:\n";

    while (left <= right) {
        int mid = (left + right + 1) / 2;
        Node* midNode = getNodeAt(head, mid);

        cout << "Iterasi " << iter++ << ": Mid = " << midNode->data << " (indeks tengah)";

        if (midNode->data == key) {
            cout << " - DITEMUKAN!" << endl;
            cout << "\nHasil: Nilai " << key << " DITEMUKAN pada linked list!" << endl;
            cout << "Alamat node: " << midNode << endl;
            cout << "Data node: " << midNode->data << endl;
            if (midNode->next)
                cout << "Node berikutnya: " << midNode->next->data << endl;
            else
                cout << "Node berikutnya: NULL" << endl;
            return midNode;
        }
            
        else if (midNode->data < key) {
            cout << " -> Cari di bagian kanan" << endl;
            left = mid + 1;
        } else {
            cout << " -> Cari di bagian kiri" << endl;
            right = mid - 1;
        }
     
        if(left >= right) break;
    }

    cout << "Tidak ada elemen tersisa" << endl;
    cout << "\nHasil: Nilai " << key << " TIDAK DITEMUKAN dalam linked list!" << endl;
    return nullptr;
}

int main() {
    Node* head = nullptr;

    cout << "BINARY SEARCH PADA LINKED LIST" << endl;
    cout << "Linked List yang dibuat: ";
    //Isi dari linked list yang sudah diurutkan
    append(head, 10);
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);
    append(head, 60);
    printList(head);

    //Pencarian pertama
    int key1 = 40;
    cout << "Mencari nilai: " << key1 << endl;
    binarySearch(head, key1);

    //Pencarian kedua
    int key2 = 25;
    cout << "Mencari nilai: " << key2 << endl;
    binarySearch(head, key2);

    return 0;
}

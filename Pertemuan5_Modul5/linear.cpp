#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* linearSearch(Node* head, int key) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == key)
            return current;
        current = current->next;
    }
    return nullptr;
}

void append(Node*&head, int value) {
    Node* newNode = new Node{value, nullptr};
    if (!head) head = newNode;
    else {
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }
}

int main() {
    Node* head = nullptr;
    append(head, 10); append(head, 20); append(head, 30);
    
    Node* result = linearSearch(head, 20);
    cout << (result ? "Found" : "Not Found") << endl;

    return 0;
}
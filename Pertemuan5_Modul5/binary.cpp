#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void append(Node*&head, int value) {
    Node* newNode = new Node{value, nullptr};
    if (!head) head = newNode;
    else {
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }
}

Node* binarySearch(Node* head, int key) {
    int size = 0;
    for (Node* current = head; current; current = current->next) size++;
    Node* start = head;
    Node* end = nullptr;

    while (size > 0) {
        int mid = size / 2;
        Node* midNode = start;

        for (int i = 0; i < mid; ++i) midNode = midNode->next;

        if (midNode->data == key) return midNode;
        if (midNode->data < key) {
            start = midNode->next;
        }
        else {
            end = midNode;
        }
        size -= mid;
    }
    return nullptr;
}

int main() {
    Node* head = nullptr;
    append(head, 10); append(head, 20); append(head, 30); append(head, 40); append(head, 50);
    
    Node* result = binarySearch(head, 20);
    cout << (result ? "Found" : "Not Found") << endl;

    return 0;
}
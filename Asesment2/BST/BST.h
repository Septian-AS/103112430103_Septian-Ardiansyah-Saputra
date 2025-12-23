#ifndef BST_H
#define BST_H

#include <iostream>
#include <string>
using namespace std;

struct Node {
    string namaMember;
    float beratBadan;
    string tierMember;
    Node *left;
    Node *right;
};

struct BST {
    Node *root;
};

bool isEmpty(BST T);
void createTree(BST &T);
Node* newNode(string nama, float bb, string tier);
void insertNode(BST &T, Node *p);
Node* searchByBeratBadan(BST T, float bb, Node* &parent);
Node* mostLeft(BST T);
Node* mostRight(BST T);
void inOrder(Node *root);

#endif
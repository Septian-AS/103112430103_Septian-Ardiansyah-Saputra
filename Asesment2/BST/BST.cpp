#include "BST.h"

bool isEmpty(BST T) {
    return T.root == NULL;
}

void createTree(BST &T) {
    T.root = NULL;
}

Node* newNode(string nama, float bb, string tier) {
    Node *p = new Node;
    p->namaMember = nama;
    p->beratBadan = bb;
    p->tierMember = tier;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void insertNode(BST &T, Node *p) {
    if (T.root == NULL) {
        T.root = p;
        return;
    }

    Node *cur = T.root;
    Node *prev = NULL;

    while (cur != NULL) {
        prev = cur;
        if (p->beratBadan < cur->beratBadan) 
            cur = cur->left;
        else
            cur = cur->right;
    }

    if (p->beratBadan < prev->beratBadan)
        prev->left = p;
    else
        prev->right = p;
}

Node* searchByBeratBadan(BST T, float bb, Node* &parent) {
    parent = NULL;
    Node *cur = T.root;

    while (cur != NULL) {
        if (bb < cur->beratBadan) {
            parent = cur;
            cur = cur->left;
        } else if (bb > cur->beratBadan) {
            parent = cur;
            cur = cur->right;
        } else {
            return cur;
        }
    }
    return NULL;
}

Node* mostLeft(BST T) {
    Node *cur = T.root;
    if (cur == NULL) return NULL;
    while (cur->left != NULL)
        cur = cur->left;
    return cur;
}

Node* mostRight(BST T) {
    Node *cur = T.root;
    if (cur == NULL) return NULL;
    while (cur->right != NULL)
        cur = cur->right;
    return cur;
}

void inOrder(Node *root) {
    if (root == NULL) return;
    inOrder(root->left);
    cout << (int)root->beratBadan << " - ";
    inOrder(root->right);
}
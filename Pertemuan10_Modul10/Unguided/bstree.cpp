#include "bstree.h"

address alokasi(infotype x){
    address P = new Node;
    P->info = x;
    P->left = NULL;
    P->right = NULL;
    return P;
}

void insertNode(address &root, infotype x){
    if (root == NULL){
        root = alokasi(x);
    } else if (x < root->info){
        insertNode(root->left, x);
    } else {
        insertNode(root->right, x);
    }
}

address findNode(infotype x, address root){
    if (root == NULL){
        return NULL;
    } else if (x == root->info){
        return root;
    } else if (x < root->info){
        return findNode(x, root->left);
    } else {
        return findNode(x, root->right);
    }
}

void inOrder(address root){
    if (root != NULL){
        inOrder(root->left);
        cout << root->info << " - ";
        inOrder(root->right);
    }
}

int hitungJumlahNode(address root){
    if (root == NULL) return 0;
    return 1 + hitungJumlahNode(root->left)
             + hitungJumlahNode(root->right);
}

int hitungTotalInfo(address root, int start){
    if (root == NULL) return start;

    int total = start + root->info;
    total = hitungTotalInfo(root->left,  total);
    total = hitungTotalInfo(root->right, total);
    return total;
}

int hitungKedalaman(address root, int start){
    if (root == NULL) return start;

    int leftDepth  = hitungKedalaman(root->left,  start + 1);
    int rightDepth = hitungKedalaman(root->right, start + 1);
    return (leftDepth > rightDepth) ? leftDepth : rightDepth;
}

void preOrder(address root){
    if (root != NULL){
        cout << root->info << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(address root){
    if (root != NULL){
        postOrder(root->left);
        postOrder(root->right);
        cout << root->info << " ";
    }
}
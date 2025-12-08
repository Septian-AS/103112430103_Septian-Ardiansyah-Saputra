#ifndef BST2_H
#define BST2_H

#include <iostream>
using namespace std;

typedef int infotype;
typedef struct Node *address;

struct Node {
    infotype info;
    address left;
    address right;
};

bool isEmpty(address root);
void createTree(address &root);

address newNode(infotype x);
address insertNode(address root, infotype x);

void preOrder(address root);
void inOrder(address root);
void postOrder(address root);

int countNodes(address root);
int treeDepth(address root);

void searchByData(address root, infotype x);

address mostLeft(address root);
address mostRight(address root);

bool deleteNode(address &root, infotype x);
void deleteTree(address &root);

#endif
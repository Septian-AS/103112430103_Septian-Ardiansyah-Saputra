#ifndef BST1_H
#define BST1_H

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

#endif
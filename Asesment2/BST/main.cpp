#include "BST.h"

void printNode(Node *p) {
    if (p == NULL) {
        cout << "Tidak Ada\n";
        return;
    }
    cout << "Nama Member : " << p->namaMember << endl;
    cout << "Berat Badan : " << (int)p->beratBadan << endl;
    cout << "Tier Member : " << p->tierMember << endl;
}

int main() {
    BST T;
    createTree(T);

    insertNode(T, newNode("Rizkina Azizah", 60, "Basic"));
    insertNode(T, newNode("Hakan Ismail", 50, "Bronze"));
    insertNode(T, newNode("Olivia Saevali", 65, "Silver"));
    insertNode(T, newNode("Felix Pedrosa", 47, "Gold"));
    insertNode(T, newNode("Gamel Al Ghifari", 56, "Platinum"));
    insertNode(T, newNode("Hanif Al Faiz", 70, "Basic"));
    insertNode(T, newNode("Mutiara Fauziah", 52, "Bronze"));
    insertNode(T, newNode("Davi Ilyas", 68, "Silver"));
    insertNode(T, newNode("Abdad Mubarok", 81, "Gold"));

    cout << "=== Traversal InOrder ===\n";
    inOrder(T.root);
    cout << endl << endl;

    cout << "Node MostLeft  : " << (int)mostLeft(T)->beratBadan << endl;
    cout << "Node MostRight : " << (int)mostRight(T)->beratBadan << endl << endl;

    Node *parent;
    Node *found = searchByBeratBadan(T, 70, parent);

    if (found != NULL) {
        cout << "Data ditemukan didalam BST!\n";
        cout << "--- Data Node Yang Dicari ---\n";
        printNode(found);
        cout << "----------------------------\n";

        cout << "--- Data Parent ---\n";
        printNode(parent);
        cout << "----------------------------\n";

        Node *sibling = NULL;
        if (parent != NULL) {
            if (parent->left == found)
                sibling = parent->right;
            else
                sibling = parent->left;
        }

        if (sibling == NULL) {
            cout << "Tidak Memiliki Sibling\n";
            cout << "----------------------------\n";
        } else {
            cout << "--- Data Sibling ---\n";
            printNode(sibling);
            cout << "----------------------------\n";
        }

        cout << "--- Data Child Kiri ---\n";
        printNode(found->left);
        cout << "----------------------------\n";
        cout << "--- Data Child Kanan ---\n";
        printNode(found->right);
        cout << "----------------------------\n";
    }

    return 0;
}
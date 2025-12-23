#include "Graph.h"

int main() {
    Graph G;
    createGraph(G);

    insertNode(G, 'A');
    insertNode(G, 'B');
    insertNode(G, 'C');
    insertNode(G, 'D');
    insertNode(G, 'E');

    adrNode A = searchNode(G, 'A');
    adrNode B = searchNode(G, 'B');
    adrNode C = searchNode(G, 'C');
    adrNode D = searchNode(G, 'D');
    adrNode E = searchNode(G, 'E');

    connectUndirectedByAdr(C, D);
    connectUndirectedByAdr(B, E);
    connectUndirectedByAdr(B, C);
    connectUndirectedByAdr(A, B);

    cout << "Membangun Jaringan Distribusi Vaksin\n";
    printGraphConnections(G);

    cout << "\nAnalisis Kota Kritis (Single Point of Failure)\n";
    analyzeCriticalCities(G);

    return 0;
}
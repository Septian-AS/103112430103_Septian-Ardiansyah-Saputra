#include "graph.h"

int main() {
    Graph G;
    CreateGraph(G);

    InsertNode(G, 'A');
    InsertNode(G, 'B');
    InsertNode(G, 'C');
    InsertNode(G, 'D');
    InsertNode(G, 'E');
    InsertNode(G, 'F');
    InsertNode(G, 'G');
    InsertNode(G, 'H');

    adrNode A = SearchNode(G, 'A');
    adrNode B = SearchNode(G, 'B');
    adrNode C = SearchNode(G, 'C');
    adrNode D = SearchNode(G, 'D');
    adrNode E = SearchNode(G, 'E');
    adrNode F = SearchNode(G, 'F');
    adrNode Gg = SearchNode(G, 'G');
    adrNode H = SearchNode(G, 'H');

    ConnectNode(G, A, B);
    ConnectNode(G, A, C);

    ConnectNode(G, B, D);
    ConnectNode(G, B, E);

    ConnectNode(G, C, F);
    ConnectNode(G, C, Gg);

    ConnectNode(G, D, H);
    ConnectNode(G, E, H);
    ConnectNode(G, F, H);
    ConnectNode(G, Gg, H);

    PrintInfoGraph(G);

    cout << "Hasil DFS : ";
    PrintDFS(G, A);
    cout << endl;

    cout << "Hasil BFS : ";
    PrintBFS(G, A);
    cout << endl;

    return 0;
}
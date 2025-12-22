#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;

typedef char infoGraph;
typedef infoGraph infotype;

typedef struct ElmtNode *adrNode;
typedef struct ElmtEdge *adrEdge;

struct ElmtEdge {
    adrNode Node;
    adrEdge Next;
};

struct ElmtNode {
    infoGraph info;
    int visited;
    adrEdge firstEdge;
    adrNode Next;
};

struct Graph {
    adrNode first;
};

void CreateGraph(Graph &G);
void InsertNode(Graph &G, infotype X);
void ConnectNode(Graph &G, adrNode N1, adrNode N2);
void PrintInfoGraph(Graph G);
adrNode SearchNode(Graph G, infotype X);

void PrintDFS(Graph G, adrNode N);
void PrintBFS(Graph G, adrNode N);

#endif
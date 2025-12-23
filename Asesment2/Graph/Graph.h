#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;

typedef char infotype;

struct ElmtNode;
struct ElmtEdge;

typedef ElmtNode* adrNode;
typedef ElmtEdge* adrEdge;

struct ElmtEdge {
    adrNode to;
    adrEdge next;
};

struct ElmtNode {
    infotype info;
    bool active;
    int visited;
    adrEdge firstEdge;
    adrNode next;
};

struct Graph {
    adrNode first;
};

void createGraph(Graph &G);
adrNode newNode(infotype x);
void insertNode(Graph &G, infotype x);
void connectUndirected(Graph &G, infotype a, infotype b);
void printGraphConnections(Graph G);
adrNode searchNode(Graph G, infotype x);
void resetVisited(Graph &G);
int dfsCount(Graph &G, adrNode start, adrNode disabled);
bool isCriticalCity(Graph &G, adrNode candidate);
void analyzeCriticalCities(Graph &G);
void connectUndirectedByAdr(adrNode A, adrNode B);

#endif
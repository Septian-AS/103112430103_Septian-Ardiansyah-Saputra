#include "graph.h"

static adrEdge NewEdge(adrNode to) {
    adrEdge e = new ElmtEdge;
    e->Node = to;
    e->Next = NULL;
    return e;
}

static bool HasEdge(adrNode from, adrNode to) {
    if (from == NULL || to == NULL) return false;
    for (adrEdge e = from->firstEdge; e != NULL; e = e->Next) {
        if (e->Node == to) return true;
    }
    return false;
}

void CreateGraph(Graph &G) {
    G.first = NULL;
}

void InsertNode(Graph &G, infotype X) {
    adrNode p = new ElmtNode;
    p->info = X;
    p->visited = 0;
    p->firstEdge = NULL;
    p->Next = NULL;

    if (G.first == NULL) {
        G.first = p;
    } else {
        adrNode q = G.first;
        while (q->Next != NULL) q = q->Next;
        q->Next = p;
    }
}

adrNode SearchNode(Graph G, infotype X) {
    for (adrNode p = G.first; p != NULL; p = p->Next) {
        if (p->info == X) return p;
    }
    return NULL;
}

void ConnectNode(Graph &G, adrNode N1, adrNode N2) {
    (void)G;

    if (N1 == NULL || N2 == NULL) return;
    if (N1 == N2) return;

    if (!HasEdge(N1, N2)) {
        adrEdge e1 = NewEdge(N2);
        e1->Next = N1->firstEdge;
        N1->firstEdge = e1;
    }

    if (!HasEdge(N2, N1)) {
        adrEdge e2 = NewEdge(N1);
        e2->Next = N2->firstEdge;
        N2->firstEdge = e2;
    }
}

void PrintInfoGraph(Graph G) {
    cout << "Adjacency List (Tidak Berarah)\n";
    cout << "---------------------------\n";
    for (adrNode p = G.first; p != NULL; p = p->Next) {
        cout << p->info << " : ";
        adrEdge e = p->firstEdge;

        if (e == NULL) {
            cout << "-";
        } else {
            while (e != NULL) {
                cout << e->Node->info;
                if (e->Next != NULL) cout << " -> ";
                e = e->Next;
            }
        }
        cout << "\n";
    }
}

void PrintDFS(Graph G, adrNode N) {
    if (N == NULL || N->visited == 1) {
        return;
    }

    N->visited = 1;
    cout << N->info << " ";

    for (adrEdge e = N->firstEdge; e != NULL; e = e->Next) {
        PrintDFS(G, e->Node);
    }
}

void PrintBFS(Graph G, adrNode N) {
    if (N == NULL) return;

    adrNode Q[100];
    int front = 0, rear = 0;

    N->visited = 1;
    Q[rear++] = N;

    while (front < rear) {
        adrNode cur = Q[front++];
        cout << cur->info << " ";

        for (adrEdge e = cur->firstEdge; e != NULL; e = e->Next) {
            if (e->Node->visited == 0) {
                e->Node->visited = 1;
                Q[rear++] = e->Node;
            }
        }
    }
}
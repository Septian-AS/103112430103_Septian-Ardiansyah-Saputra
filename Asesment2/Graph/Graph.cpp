#include "Graph.h"

void createGraph(Graph &G) {
    G.first = NULL;
}

adrNode newNode(infotype x) {
    adrNode p = new ElmtNode;
    p->info = x;
    p->active = true;
    p->visited = 0;
    p->firstEdge = NULL;
    p->next = NULL;
    return p;
}

adrNode searchNode(Graph G, infotype x) {
    adrNode p = G.first;
    while (p != NULL) {
        if (p->info == x) return p;
        p = p->next;
    }
    return NULL;
}

void insertNode(Graph &G, infotype x) {
    if (searchNode(G, x) != NULL) return;

    adrNode p = newNode(x);
    if (G.first == NULL) {
        G.first = p;
    } else {
        adrNode q = G.first;
        while (q->next != NULL) q = q->next;
        q->next = p;
    }
}

bool hasEdge(adrNode from, adrNode to) {
    adrEdge e = from->firstEdge;
    while (e != NULL) {
        if (e->to == to) return true;
        e = e->next;
    }
    return false;
}

void addEdgeOneWay(adrNode from, adrNode to) {
    if (from == NULL || to == NULL) return;
    if (hasEdge(from, to)) return;

    adrEdge e = new ElmtEdge;
    e->to = to;
    e->next = NULL;

    if (from->firstEdge == NULL) {
        from->firstEdge = e;
    } else {
        adrEdge p = from->firstEdge;
        while (p->next != NULL) p = p->next;
        p->next = e;
    }
}

void connectUndirected(Graph &G, infotype a, infotype b) {
    adrNode A = searchNode(G, a);
    adrNode B = searchNode(G, b);

    if (A == NULL) {
        insertNode(G, a);
        A = searchNode(G, a);
    }
    if (B == NULL) {
        insertNode(G, b);
        B = searchNode(G, b);
    }

    addEdgeOneWay(A, B);
    addEdgeOneWay(B, A);
}

void printGraphConnections(Graph G) {
    adrNode p = G.first;
    while (p != NULL) {
        cout << "Node " << p->info << " terhubung ke: ";
        adrEdge e = p->firstEdge;
        while (e != NULL) {
            cout << e->to->info;
            if (e->next != NULL) cout << " ";
            e = e->next;
        }
        cout << "\n";
        p = p->next;
    }
}

void resetVisited(Graph &G) {
    adrNode p = G.first;
    while (p != NULL) {
        p->visited = 0;
        p = p->next;
    }
}

int dfsCount(Graph &G, adrNode start, adrNode disabled) {
    if (start == NULL) return 0;
    if (start == disabled) return 0;
    if (!start->active) return 0;
    if (start->visited == 1) return 0;

    start->visited = 1;
    int count = 1;

    adrEdge e = start->firstEdge;
    while (e != NULL) {
        adrNode nxt = e->to;
        if (nxt != disabled && nxt->active && nxt->visited == 0) {
            count += dfsCount(G, nxt, disabled);
        }
        e = e->next;
    }
    return count;
}

bool isCriticalCity(Graph &G, adrNode candidate) {
    if (candidate == NULL) return false;

    int totalActiveExcept = 0;
    adrNode p = G.first;
    while (p != NULL) {
        if (p != candidate && p->active) totalActiveExcept++;
        p = p->next;
    }

    adrNode start = NULL;
    p = G.first;
    while (p != NULL) {
        if (p != candidate && p->active) {
            start = p;
            break;
        }
        p = p->next;
    }

    if (totalActiveExcept <= 1) return false;

    resetVisited(G);
    int reachable = dfsCount(G, start, candidate);

    return reachable != totalActiveExcept;
}

void analyzeCriticalCities(Graph &G) {
    adrNode p = G.first;
    while (p != NULL) {
        if (!p->active) {
            p = p->next;
            continue;
        }

        bool kritis = isCriticalCity(G, p);
        if (kritis) {
            cout << "[PERINGATAN] Kota " << p->info << " adalah KOTA KRITIS!\n";
            cout << "-> Jika " << p->info << " lockdown, distribusi terputus.\n";
        } else {
            cout << "Kota " << p->info << " aman (redundansi oke).\n";
        }
        p = p->next;
    }
}

void connectUndirectedByAdr(adrNode A, adrNode B) {
    addEdgeOneWay(A, B);
    addEdgeOneWay(B, A);
}
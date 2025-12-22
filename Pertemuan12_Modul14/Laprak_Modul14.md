# <h1 align="center">Laporan Praktikum Modul 14 - Graph</h1>
<p align="center">Septian Ardiansyah Saputra - 103112430103</p>

## Dasar Teori
Graph adalah struktur data _non-linier_ yang merepresentasikan hubungan antar objek melalui simpul (_vertex_) dan sisi (_edge_) yang menghubungkan pasangan simpul tersebut, yang banyak diterapkan dalam pemodelan jaringan dan berbagai masalah komputasi [1]; salah satu representasi graph yang efisien adalah _adjacency list_, di mana setiap simpul menyimpan daftar tetangga langsungnya sehingga traversal seperti _Depth First Search_ (DFS) yang mengeksplorasi simpul sampai sedalam mungkin sebelum _backtracking_ dan _Breadth First Search_ (BFS) yang menelusuri graph secara melebar dengan mengunjungi semua tetangga pada level yang sama terlebih dahulu dengan bantuan struktur data seperti _queue_, menjadi teknik dasar dalam analisis graph di bidang algoritma dan optimasi [2] [3].

### A. Pengertian<br/>
Graph merupakan himpunan tidak kosong dari node (_vertex_) dan garis penghubung (_edge_). Contoh sederhana tentang graph, yaitu antara Tempat Kost Anda dengan _Common Lab_. Tempat Kost Anda dan _Common Lab_ merupakan node (_vertex_). Jalan yang menghubungkan tempat Kost dan _Common Lab_ merupakan garis penghubung antara keduanya (_edge_).

### B. Jenis-Jenis Graph<br/>
#### 1. Graph Berarah (Directed Graph)
Merupakan graph dimana tiap node memiliki _edge_ yang memiliki arah, kemana node tersebut dihubungkan.
#### 2. Graph Tidak Berarah (Undirected Graph)
Merupakan graph dimana tiap node memiliki _edge_ yang dihubungkan ke node lain tanpa arah.

## Guided

### 1. Graph
- graph.h
```C++
#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
using namespace std;

typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

struct ElmNode {
    infoGraph info;
    bool visited;
    adrEdge firstEdge;
    adrNode next;
};

struct ElmEdge {
    adrNode node;
    adrEdge next;
};

struct Graph {
    adrNode first;
};

void createGraph(Graph &G);
adrNode allocateNode(infoGraph X);
void insertNode(Graph &G, infoGraph X);
void connectNode(Graph &G, infoGraph start, infoGraph end);
void printGraph(Graph G);

#endif
```
- graph_edge.cpp
```C++
#include "graph.h"

adrNode findNode(Graph G, infoGraph X) {
    adrNode P = G.first;
    while (P != NULL) {
        if (P->info == X) return P;
        P = P->next;
    }
    return NULL;
}

void connectNode(Graph &G, infoGraph start, infoGraph end) {
    adrNode pStart = findNode(G, start);
    adrNode pEnd = findNode(G, end);

    if (pStart != NULL && pEnd != NULL) {
        adrEdge newEdge = new ElmEdge;
        newEdge->node = pEnd;
        newEdge->next = pStart->firstEdge;
        pStart->firstEdge = newEdge;
    }
}
```
- graph_init.cpp
```C++
#include "graph.h"

void createGraph(Graph &G) {
    G.first = NULL;
}

adrNode allocateNode(infoGraph X) {
    adrNode P = new ElmNode;
    P->info = X;
    P->visited = false;
    P->firstEdge = NULL;
    P->next = NULL;
    return P;
}

void insertNode(Graph &G, infoGraph X) {
    adrNode P = allocateNode(X);
    if (G.first == NULL) {
        G.first = P;
    } else {
        adrNode Q = G.first;
        while (Q->next != NULL) {
            Q = Q->next;
        }
        Q->next = P;
    }
}
```
- graph_print.cpp
```C++
#include "graph.h"

void printGraph(Graph G) {
    adrNode P = G.first;
    while (P != NULL) {
        cout << "Node " << P->info << " terhubung ke: ";
        adrEdge E = P->firstEdge;
        while (E != NULL) {
            cout << E->node->info << " ";
            E = E->next;
        }
    cout << endl;
    P = P->next;
    }
}
```
- main.cpp
```C++
#include "graph.h"
using namespace std;

int main() {
    Graph G;
    createGraph(G);

    insertNode(G, 'A');
    insertNode(G, 'B');
    insertNode(G, 'C');
    insertNode(G, 'D');

    connectNode(G, 'A', 'B');
    connectNode(G, 'A', 'C');
    connectNode(G, 'B', 'D');
    connectNode(G, 'C', 'D');

    cout << "Isi Graph:" << endl;
    printGraph(G);

    return 0;
}
```
Guided 1 mengimplementasikan ADT graph berarah berbasis _adjacency list_ menggunakan _linked list_ untuk menyimpan _node_ dan _edge_, serta menyediakan operasi membuat graph, menambah node, menghubungkan node, dan menampilkan hubungan antar node.

## Unguided

### 1. Soal Unguided 1
Buatlah ADT Graph tidak berarah file “graph.h”:
```
Type infoGraph : char
Type adrNode : pointer to ElmNode
Type adrEdge : pointer to ElmNode
Type ElmNode <
    info : infoGraph
    visited : integer
    firstEdge : adrEdge
    Next : adrNode
>
Type ElmEdge <
    Node : adrNode
    Next : adrEdge
>
Type Graph <
    first : adrNode
>
procedure CreateGraph (input/output G : Graph)
procedure InsertNode (input/output G : Graph, input X : infotype)
procedure ConnectNode (input/output N1, N2 : adrNode)
procedure PrintInfoGraph (input G : Graph)
```
Buatlah implementasi ADT Graph pada file “graph.cpp” dan cobalah hasil implementasi ADT pada file “main.cpp”.

- graph.h
```C++
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

#endif
```
- graph.cpp
```C++
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
```
- main.cpp
```C++
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

    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/Septian-AS/103112430103_Septian-Ardiansyah-Saputra/blob/main/Pertemuan12_Modul14/Output/Soal1.png)

Kode ini membuat graph tidak berarah (_undirected_) dengan _adjacency list_ menggunakan _linked list_, lalu menyediakan fungsi untuk buat graph, tambah node, cari node, hubungkan dua node dua arah tanpa duplikat/_self-loop_, dan mencetak daftar ketetanggaan (_adjacency list_).

### 2. Soal Unguided 2
Buatlah prosedur untuk menampilkan hasil penelusuran DFS.
<br>prosedur PrintDFS (Graph G, adrNode N);

- graph.h
```C++
void PrintDFS(Graph G, adrNode N);
```
- graph.cpp
```C++
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
```
- main.cpp
```C++
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

    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/Septian-AS/103112430103_Septian-Ardiansyah-Saputra/blob/main/Pertemuan12_Modul14/Output/Soal2.png)

Fungsi `PrintDFS(Graph G, adrNode N)` melakukan penelusuran graph dengan _algoritma Depth First Search_ (DFS) secara rekursif, dimulai dari node N, dengan cara menandai node yang sudah dikunjungi (_visited_ = 1), mencetak node tersebut, lalu mengunjungi seluruh node tetangganya satu per satu hingga kedalaman maksimum sebelum _backtracking_.

### 3. Soal Unguided 3
Buatlah prosedur untuk menampilkan hasil penelusuran BFS.
<br>prosedur PrintBFS (Graph G, adrNode N);

- graph.h
```C++
void PrintBFS(Graph G, adrNode N);
```
- graph.cpp
```C++
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
```
- main.cpp
```C++
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

    cout << "Hasil BFS : ";
    PrintBFS(G, A);
    cout << endl;

    return 0;
}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/Septian-AS/103112430103_Septian-Ardiansyah-Saputra/blob/main/Pertemuan12_Modul14/Output/Soal3.png)

Fungsi `PrintBFS(Graph G, adrNode N)` melakukan penelusuran graph dengan _algoritma Breadth First Search_ (BFS) menggunakan _queue_ berbasis _array_, dimulai dari node N dengan cara menandai node sebagai _visited_, mencetak node secara berurutan per level (tetangga terdekat dulu), lalu memasukkan semua tetangga yang belum dikunjungi ke dalam _queue_ hingga seluruh graph terjelajahi.

## Kesimpulan
Graph adalah struktur data _non-linier_ yang digunakan untuk merepresentasikan hubungan antar objek, dan _adjacency list_ merupakan representasi yang efisien dalam penggunaan memori. Algoritma DFS dan BFS digunakan untuk menelusuri graph secara sistematis, di mana DFS menjelajah hingga kedalaman maksimum sedangkan BFS menelusuri graph berdasarkan level. Kedua algoritma ini penting dalam pemecahan masalah graf seperti pencarian jalur dan analisis jaringan.

## Referensi
[1] Wilson, R. J. (2008). _An introduction to graph theory_ (4th ed.) [Lecture notes]. University of Edinburgh. https://webhomes.maths.ed.ac.uk/~v1ranick/papers/wilsongraph.pdf
<br>[2] Putra, A. A. D., Nugroho, A., & Santoso, B. (2025). Comparison of breadth-first search (BFS) and depth-first search (DFS) algorithms. _JESICA: Journal of Enhanced Studies in Informatics and Computer Applications_. https://jesica.itsk-soepraoen.ac.id/index.php/jesica/article/download/14/18
<br>[3] Arul, S. M., Senthil, G., & Jayasudha, S. (2023). Graph theory and algorithms for network analysis. _E3S Web of Conferences, 399_, 08002. https://doi.org/10.1051/e3sconf/202339908002
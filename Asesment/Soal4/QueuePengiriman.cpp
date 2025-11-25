#include "QueuePengiriman.h"

bool isEmpty(QueueEkspedisi Q) {
    return Q.Head == -1 && Q.Tail == -1;
}

bool isFull(QueueEkspedisi Q) {
    return Q.Tail == MAX - 1;
}

void createQueue(QueueEkspedisi &Q) {
    Q.Head = -1;
    Q.Tail = -1;
}

void enQueue(QueueEkspedisi &Q, Paket P) {
    if (!isFull(Q)) {
        if (isEmpty(Q)) {
            Q.Head = 0;
            Q.Tail = 0;
        } else {
            Q.Tail++;
        }
        Q.dataPaket[Q.Tail] = P;
    } else {
        cout << "Queue penuh!" << endl;
    }
}

void deQueue(QueueEkspedisi &Q) {
    if (!isEmpty(Q)) {
        if (Q.Head == Q.Tail) {
            Q.Head = -1;
            Q.Tail = -1;
        } else {
            Q.Head++;
        }
    }
}

void viewQueue(QueueEkspedisi Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong" << endl;
        return;
    }
    for (int i = Q.Head; i <= Q.Tail; i++) {
        cout << i + 1 << ". "
             << Q.dataPaket[i].KodeResi << " | "
             << Q.dataPaket[i].NamaPengirim << " | "
             << Q.dataPaket[i].BeratBarang << " kg | "
             << Q.dataPaket[i].Tujuan << endl;
    }
}

int TotalBiayaPengiriman(QueueEkspedisi Q) {
    if (isEmpty(Q)) return 0;
    int totalBerat = 0;
    for (int i = Q.Head; i <= Q.Tail; i++) {
        totalBerat += Q.dataPaket[i].BeratBarang;
    }
    return totalBerat * 8250;
}
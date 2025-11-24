#include "queue.h"

void createQueue(Queue &Q){
    Q.head = -1;
    Q.tail = -1;
    Q.count = 0;
}

bool isEmptyQueue(Queue Q){
    return (Q.count == 0);
}

bool isFullQueue(Queue Q){
    return (Q.count == MAX);
}

void enqueue(Queue &Q, infotype x){
    if(isFullQueue(Q)){
        cout << "Queue penuh!" << endl;
        return;
    }
    if(isEmptyQueue(Q)){
        Q.head = 0;
        Q.tail = 0;
    } else {
        Q.tail = (Q.tail + 1) % MAX;
    }
    Q.info[Q.tail] = x;
    Q.count++;
}

infotype dequeue(Queue &Q){
    if(isEmptyQueue(Q)){
        cout << "Queue kosong!" << endl;
        return -1;
    }
    infotype x = Q.info[Q.head];
    Q.head = (Q.head + 1) % MAX;
    Q.count--;

    if(Q.count == 0){
        Q.head = -1;
        Q.tail = -1;
    }

    return x;
}

void printInfo(Queue Q){
    if(isEmptyQueue(Q)){
        cout << Q.head << " - " << Q.tail << " | ";
    } else {
        cout << Q.head << " - " << Q.tail << " \t| ";
    }

    if(isEmptyQueue(Q)){
        cout << "empty queue";
    } else {
        int i = Q.head;
        int n = 0;
        while(n < Q.count){
            cout << Q.info[i] << " ";
            i = (i + 1) % MAX;
            n++;
        }
    }
    cout << endl;
}
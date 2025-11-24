#include "queue.h"

void createQueue(Queue &Q){
    Q.head = 0;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q){
    return (Q.tail == -1);
}

bool isFullQueue(Queue Q){
    return (Q.tail == MAX - 1);
}

void enqueue(Queue &Q, infotype x){
    if(isFullQueue(Q)){
        cout << "Queue penuh!" << endl;
        return;
    }
    Q.tail++;
    Q.info[Q.tail] = x;
}

infotype dequeue(Queue &Q){
    if(isEmptyQueue(Q)){
        cout << "Queue kosong!" << endl;
        return -1;
    }
    infotype x = Q.info[0];

    for(int i = 0; i < Q.tail; i++){
        Q.info[i] = Q.info[i+1];
    }
    Q.tail--;

    return x;
}

void printInfo(Queue Q){
    if(isEmptyQueue(Q)){
        cout << Q.head-1 << " - " << Q.tail << " | ";
    } else {
        cout << Q.head << " - " << Q.tail << " \t| ";
    }

    if(isEmptyQueue(Q)){
        cout << "empty queue";
    } else {
        for(int i = Q.head; i <= Q.tail; i++){
            cout << Q.info[i] << " ";
        }
    }
    cout << endl;
}
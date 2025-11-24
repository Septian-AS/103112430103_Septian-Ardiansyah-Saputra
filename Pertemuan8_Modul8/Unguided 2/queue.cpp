#include "queue.h"

void createQueue(Queue &Q){
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q){
    return (Q.head == -1 && Q.tail == -1);
}

bool isFullQueue(Queue Q){
    return (Q.tail == MAX - 1);
}

void enqueue(Queue &Q, infotype x){
    if(isFullQueue(Q)){
        cout << "Queue penuh!" << endl;
        return;
    }
    if(isEmptyQueue(Q)){
        Q.head = Q.tail = 0;
    } else {
        Q.tail++;
    }
    Q.info[Q.tail] = x;
}

infotype dequeue(Queue &Q){
    if(isEmptyQueue(Q)){
        cout << "Queue kosong!" << endl;
        return -1;
    }
    infotype x = Q.info[Q.head];
    Q.head++;

    if (Q.head > Q.tail) {
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
        for(int i = Q.head; i <= Q.tail; i++){
            cout << Q.info[i] << " ";
        }
    }
    cout << endl;
}
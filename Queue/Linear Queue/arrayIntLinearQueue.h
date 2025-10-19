#include <iostream>
#define QUEUE_SIZE 50
using namespace std;

struct Queue {
    int item[QUEUE_SIZE];
    int rear;
    int front;
};


void Initialize(Queue* Q) {
    Q->rear = -1;
    Q->front = 0;
}


bool isEmpty(Queue* Q) {
    if ((Q->rear - Q->front + 1) == 0) {
        return true;
    }
    else {
        return false;
    }
}


void EnQueue(Queue* Q, int x) {
    if (Q->rear == QUEUE_SIZE-1) {
        cout << "Queue Overflows" << endl;
        exit(1);
    }
    else {
        Q->rear = Q->rear + 1;
        Q->item[Q->rear] = x;
    }
}


int DeQueue(Queue* Q) {
    if (isEmpty(Q)) {
        cout << "Queue Underflows" << endl;
        exit(1);
    }
    else {
        int x = Q->item[Q->front];
        Q->front = Q->front + 1;
        return x;
    }
}


int peek(Queue* Q) {
    if (isEmpty(Q)) {
        cout << "Queue is Empty" << endl;
        exit(1);
    }
    return Q->item[Q->front];
}


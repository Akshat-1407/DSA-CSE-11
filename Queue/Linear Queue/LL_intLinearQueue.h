#include <iostream>
#define QUEUE_SIZE 50
using namespace std;

struct node {
    int data;
    node* next;
};

node* GetNode() {
    node* p = (node*)malloc(sizeof(node));
    return p;
};


void Initialize(node** front, node** rear) {
    *front = NULL;
    *rear = NULL;
}


bool isEmpty(node** front, node** rear) {
    if (*front == NULL) {
        return true;
    }
    else {
        return false;
    }
}


void EnQueue(node** front, node** rear, int x) {
    node* P = GetNode();
    P->data = x;
    P->next = NULL;

    if (*rear != NULL) {
        (*rear)->next = P;
    }
    else {
        *front = P;
    }
    *rear = P;
}


int DeQueue(node** front, node** rear) {
    if (*front == NULL) {
        cout << "Queue Underflows" << endl;
        exit(1);
    }
    else {
        node* P = *front;
        *front = (*front)->next;
        
        if (*front == NULL) {
            *rear = NULL;
        }
        int x = P->data;
        free(P);
        return x;
    }
}


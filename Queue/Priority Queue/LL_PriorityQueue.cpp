#include <iostream>
using namespace std;

struct node {
    int data;
    struct node* next;
};

node* GetNode() {
    node* p = (node*)malloc(sizeof(node));
    return p;
};


void FreeNode(node* p) {
    free(p);
}

void Traversal(node *head) {
    node* p = head;
    
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

void insBeg(node** head, int x) {
    node* p = GetNode();
    p->data = x;
    p->next = *head;
    *head = p;
}

void insAfter(node** q, int x) {
    node* p = GetNode();
    p->data = x;
    node* r = (*q)->next;
    (*q)->next = p;
    p->next = r; 
}


int delBeg(node** head) {
    node* p = *head;
    *head = (*head)->next;
    int x = p->data;
    FreeNode(p);
    return x;
}

void EnQueue(node** PQ, int x) {
    node* Q = NULL;
    node* P = *PQ;

    while (P != NULL && x >= P->data) {
        Q = P;
        P = P->next;
    }

    if (Q == NULL) {
        insBeg(PQ, x);
    }
    else {
        insAfter(&Q, x);
    }
}

int DeQueue(node** PQ) {
    if (*PQ == NULL) {
        cout << "Void Deletion" << endl;
        exit(1);
    }
    else {
        int x = delBeg(PQ);
        return x;
    }
}

int main() {
    node* PQ = NULL;
    insBeg(&PQ, 6);
    insBeg(&PQ, 5);
    insBeg(&PQ, 3);

    Traversal(PQ);

    EnQueue(&PQ, 7);
    EnQueue(&PQ, 4);
    EnQueue(&PQ, 1);

    Traversal(PQ);

    DeQueue(&PQ);

    Traversal(PQ);


    return 0;
}
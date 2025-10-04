#include <iostream>
#include <stdlib.h>
using namespace std;

struct node {
    int data;
    struct node* next;
    struct node* prev;
};

node* GetNode() {
    node* p = (node*)malloc(sizeof(node));
    return p;
}

node* FreeNode(node* p) {
    free(p);
}

void Traversal(node* head) {
    node* p = head;

    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

node* insBeg(node* head, int x) {
    node* p = GetNode();
    p->data = x;
    p->prev = NULL;
    p->next = head;

    if (head != NULL)
        head->prev = p;

    head = p;

    return head;
}

node* insAfter(node* head, node* Q, int x) {
    node* P = GetNode();
    P->data = x;
    node* R = Q->next;

    Q->next = P;
    P->prev = Q;
    P->next = R;

    if (R != NULL)
        R->prev = P;

    return head;
}

node* insBefore(node* head, node* Q, int x) {
    node* P = GetNode();
    P->data = x;
    node* R = Q->prev;

    Q->prev = P;
    P->next = Q;
    P->prev = R;

    if (R != NULL)
        R->next = P;

    return head;
}


node* insEnd(node* head, int x) {
    node* P = GetNode();
    P->data = x;
    P->next = NULL;
    
    if (head != NULL) {
        node* Q = head;

        while (Q->next != NULL) {
            Q = Q->next;
        }

        Q->next = P;
        P->prev = Q;
    }
    else {
        P->prev = NULL;
        head = P;
    }

    return head;
}

node* delBeg(node* head) {
    if (head == NULL) {
        cout << "Void Deletion";
        exit(1);
    }
    else {
        node* P = head;
        head = head->next;
        
        if (head == NULL)
            head->prev = NULL;

        FreeNode(P);
        return head;
    }
}

node* delEnd(node* head) {
    if (head == NULL) {
        cout << "Void Deletion";
        exit(1);
    }
    node* P = head;

    while (P->next != NULL) {
        P = P->next;
    }

    node* Q = P->prev;
    
    if (Q != NULL) 
        Q->next = NULL;
    else
        head = NULL;

    FreeNode(P);
    return head;
}

node* delAfter(node* head, node* Q) {
    if (Q == NULL || Q->next == NULL) {
        cout << "Void Deletion";
        exit(1);
    }

    node* P = Q->next;
    node* R = P->next;
    Q->next = R;

    if (R != NULL)
        R->prev = Q;
    
    FreeNode(P);
    return head;
}



int main() {
    node* head = NULL;

    head = insBeg(head, 7);
    head = insBeg(head, 6);
    head = insBeg(head, 5);
    head = insBeg(head, 4);
    head = insBeg(head, 3);
    head = insBeg(head, 2);
    head = insBeg(head, 1);

    Traversal(head);

    head = delBeg(head);
    Traversal(head);

    head = delEnd(head);
    Traversal(head);
}



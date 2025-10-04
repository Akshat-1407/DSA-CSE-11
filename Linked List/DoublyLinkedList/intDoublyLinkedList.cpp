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

void insBeg(node** head, int x) {
    node* p = GetNode();
    p->data = x;
    p->prev = NULL;
    p->next = *head;

    if (*head != NULL)
        (*head)->prev = p;

    *head = p;
}

void insAfter(node* Q, int x) {
    node* P = GetNode();
    P->data = x;
    node* R = Q->next;

    Q->next = P;
    P->prev = Q;
    P->next = R;

    if (R != NULL)
        R->prev = P;
}

void insBefore(node* Q, int x) {
    node* P = GetNode();
    P->data = x;
    node* R = Q->prev;

    Q->prev = P;
    P->next = Q;
    P->prev = R;

    if (R != NULL)
        R->next = P;
}


void insEnd(node** head, int x) {
    if (*head == NULL) {
        cout << "Void Insertion";
        exit(1);
    }
    node* P = GetNode();
    P->data = x;
    P->next = NULL;
    
    if (*head != NULL) {
        node* Q = *head;

        while (Q->next != NULL) {
            Q = Q->next;
        }

        Q->next = P;
        P->prev = Q;
    }
    else {
        P->prev = NULL;
        *head = P;
    }
}

int delBeg(node** head) {
    if (*head == NULL) {
        cout << "Void Deletion";
        exit(1);
    }
    else {
        node* P = *head;
        *head = (*head)->next;
        
        if (*head == NULL)
            (*head)->prev = NULL;

        int x = P->data;
        FreeNode(P);
        return x;
    }
}

int delEnd(node** head) {
    if (*head == NULL) {
        cout << "Void Deletion";
        exit(1);
    }
    node* P = *head;

    while (P->next != NULL) {
        P = P->next;
    }

    node* Q = P->prev;
    
    if (Q != NULL) 
        Q->next = NULL;
    else
        head = NULL;

    int x = P->data;
    FreeNode(P);
    return x;
}




int main() {
    node* head = NULL;
    insBeg(&head, 7);
    insBeg(&head, 6);
    insBeg(&head, 5);
    insBeg(&head, 4);
    insBeg(&head, 3);
    insBeg(&head, 2);
    insBeg(&head, 1);

    Traversal(head);

    delBeg(&head);
    Traversal(head);

    delEnd(&head);
    Traversal(head);
}



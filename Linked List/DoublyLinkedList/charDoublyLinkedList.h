#include <iostream>
#include <stdlib.h>
using namespace std;

struct node {
    char data;
    struct node* next;
    struct node* prev;
};

node* GetNode() {
    node* p = (node*)malloc(sizeof(node));
    return p;
}

void Traversal(node* head) {
    node* p = head;

    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

void insBeg(node** head, char x) {
    node* p = GetNode();
    p->data = x;
    p->prev = NULL;
    p->next = *head;

    if (*head != NULL)
        (*head)->prev = p;

    *head = p;
}

void insAfter(node** Q, char x) {
    node* P = GetNode();
    P->data = x;
    node* R = (*Q)->next;

    (*Q)->next = P;
    P->prev = *Q;
    P->next = R;

    if (R != NULL)
        R->prev = P;
}

void insEnd(node** head, char x) {
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

char delBeg(node** head) {
    if (*head == NULL) {
        cout << "Void Deletion" << endl;
        exit(1);
    }
    else {
        node* P = *head;
        *head = (*head)->next;
        
        if (*head != NULL)
            (*head)->prev = NULL;

        char x = P->data;
        free(P);

        return x;
    }
}

char delEnd(node** head) {
    if (*head == NULL) {
        cout << "Void Deletion" << endl;
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
        *head = NULL;

    char x = P->data;
    free(P);
    return x;
}


char delAfter(node** Q) {
    if (Q == NULL || (*Q)->next == NULL) {
        cout << "Void Deletion";
        exit(1);
    }
    node* P = (*Q)->next;
    node* R = P->next;
    (*Q)->next = R;

    if (R != NULL) {
        R->prev = *Q;
    }
    char x = P->data;
    free(P);

    return x;
}




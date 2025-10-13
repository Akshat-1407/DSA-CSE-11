// Name = Akshat Rastogi    Class = CSE-11   RollNo = 2400320100133

// Doubly Linked List Primitive Operation

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

void insAfter(node** Q, int x) {
    node* P = GetNode();
    P->data = x;
    node* R = (*Q)->next;

    (*Q)->next = P;
    P->prev = *Q;
    P->next = R;

    if (R != NULL)
        R->prev = P;
}

void insEnd(node** head, int x) {
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
        cout << "Void Deletion" << endl;
        exit(1);
    }
    else {
        node* P = *head;
        *head = (*head)->next;
        
        if (*head != NULL)
            (*head)->prev = NULL;

        int x = P->data;
        free(P);

        return x;
    }
}

int delEnd(node** head) {
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

    int x = P->data;
    free(P);
    return x;
}


int delAfter(node** Q) {
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
    int x = P->data;
    free(P);

    return x;
}


int main() {
    node* head = NULL;
 
    // Test insBeg and insEnd
    insBeg(&head, 2);
    insBeg(&head, 1);
    insEnd(&head, 3);
    cout << "After insertions: ";
    Traversal(head);

    // Test insAfter
    node* p = head->next;
    insAfter(&p, 4);
    cout << "After insertion: ";
    Traversal(head);

    // Test delBeg and delEnd
    delBeg(&head);
    cout << "After deleting from beginning: ";
    Traversal(head);
    delEnd(&head);
    cout << "After deleting from end: ";
    Traversal(head);

    // Test delAfter
    node* q = head;
    delAfter(&q);
    cout << "After deleting: ";
    Traversal(head);
}



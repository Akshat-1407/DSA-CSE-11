#include <iostream>
using namespace std;

struct node {
    char data;
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


void insBeg(node** head, char x) {
    node* p = GetNode();
    p->data = x;
    p->next = *head;
    *head = p;
}


void insEnd(node** head, char x) {
    node* p = GetNode();
    p->data = x;
    p->next = NULL;
    
    node* q = *head;
    while (q->next != NULL) {
        q = q->next;
    }
    q->next = p;
}


void insAfter(node** q, char x) {
    node* p = GetNode();
    p->data = x;
    node* r = (*q)->next;
    (*q)->next = p;
    p->next = r; 
}


char delBeg(node** head) {
    node* p = *head;
    *head = (*head)->next;
    char x = p->data;
    FreeNode(p);
    return x;
}


char delEnd(node** head) {
    node* p = *head;
    node* q = NULL;
    while (p->next != NULL) {
        q = p;
        p = p->next;
    }
    q->next = NULL;
    char x = p->data;
    FreeNode(p);
    return x;
}


char delAfter(node** Q) {
    node* p = (*Q)->next;
    node* R = p->next;
    (*Q)->next = R;
    char x = p->data;
    FreeNode(p);
    return x;
}


void reverseLL(node** head) {
    node* p = NULL;
    node* c = *head;
    node* n = c->next;

    while (c != NULL) {
        c->next = p;
        p = c;
        c = n;
        if (n != NULL) {
            n = n->next;
        }
     }
     *head = p;
}


bool searchLL(node* head, char x) {
    node* p = head;
    while (p != NULL) {
        if(p->data == x) {
            return true;
        }
        p = p->next;
    }
    return false;
}


int countNodes(node* head) {
    node* p = head;
    int c = 0;
    while (p != NULL) {
        p = p->next;
        c++;
    }
    return c;
}

char middleNode(node* head) {
    node* T = head;
    node* R = head->next;
    while (R != NULL && R->next != NULL) {
        T = T->next;
        R = R->next;
        R = R->next;
    }
    return T->data;
}

node* concatenateLL(node** head1, node** head2) {
    if (*head1 == NULL && *head2 == NULL) 
        return NULL;
    if (*head1 == NULL)
        return *head2;
    if (*head2 == NULL)
        return *head1;
    
    node* p = *head1;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = *head2;

    return *head1;
}

void orderedInsertion(node** head, char x) {
    node* P = *head;
    node* Q = NULL;

    while (P != NULL && P->data <= x) {
        Q = P;
        P = P->next;
    }

    if (Q != NULL)
        insAfter(&Q, x);
    else 
        insBeg(head, x);
}

node* mergeSortedLL(node* head1, node* head2) {
    node* P = head1;
    node* Q = head2;
    node* head3 = NULL;

    while (P != NULL && Q != NULL) {
        if (P->data < Q->data) {
            insBeg(&head3, P->data);
            P = P->next;
        }
        else {
            insBeg(&head3, Q->data);
            Q = Q->next;
        }
    }

    while (P != NULL) {
        insBeg(&head3, P->data);
        P = P->next;
    }

    while (Q != NULL) {
        insBeg(&head3, Q->data);
        Q = Q->next;
    }
    
    reverseLL(&head3);

    return head3;
}



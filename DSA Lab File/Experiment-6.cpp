// Name = Akshat Rastogi    Class = CSE-11   RollNo = 2400320100133

// Linear Linked List Primitive Operation

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


struct node* head = NULL;


void Traversal() {
    node* p = head;
    
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}


void insBeg(char x) {
    node* p = GetNode();
    p->data = x;
    p->next = head;
    head = p;
}


void insEnd(char x) {
    node* p = GetNode();
    p->data = x;
    p->next = NULL;
    
    node* q = head;
    while (q->next != NULL) {
        q = q->next;
    }
    q->next = p;
}


void insAfter(node* q, char x) {
    node* p = GetNode();
    p->data = x;
    node* r = q->next;
    q->next = p;
    p->next = r; 
}


char delBeg() {
    node* p = head;
    head = head->next;
    char x = p->data;
    FreeNode(p);
    return x;
}


char delEnd() {
    node* p = head;
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


char delAfter(node* Q) {
    node* p = Q->next;
    node* R = p->next;
    Q->next = R;
    char x = p->data;
    FreeNode(p);
    return x;
}


int main() {

    // Test insBeg and insEnd
    insBeg('A');
    insEnd('C');
    insBeg('B');
    cout << "After insertions: ";
    Traversal();

    // Test insAfter
    node* p = head->next;
    insAfter(p, 'D');
    cout << "After insertion: ";
    Traversal();

    // Test delBeg and delEnd
    delBeg();
    cout << "After deleting from beginning: ";
    Traversal();
    delEnd();
    cout << "After deleting from end: ";
    Traversal();

    // Test delAfter
    node* q = head;
    if (q != NULL) {
        delAfter(q);
        cout << "After deleting: ";
        Traversal();
    }

    return 0;
}

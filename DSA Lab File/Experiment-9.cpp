// Name = Akshat Rastogi    Class = CSE-11   RollNo = 2400320100133

// Reverse the Linear Linked List

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


void reverseLL() {
    node* p = NULL;
    node* c = head;
    node* n = c->next;

    while (c != NULL) {
        c->next = p;
        p = c;
        c = n;
        if (n != NULL) {
            n = n->next;
        }
     }
     head = p;
}


int main() {

    insBeg('A');
    insBeg('B');
    insBeg('C');
    insBeg('D');

    cout << "Linked List before Reversal: " << endl;
    Traversal();

    reverseLL();

    cout << "Linked List after Reversal: " << endl;
    Traversal();

    return 0;
}
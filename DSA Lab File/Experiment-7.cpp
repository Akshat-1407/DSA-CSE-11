// Name = Akshat Rastogi    Class = CSE-11   RollNo = 2400320100133

// Searching the Linear Linked

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

void insBeg(char x) {
    node* p = GetNode();
    p->data = x;
    p->next = head;
    head = p;
}

node* searchLL(char x) {
    node* p = head;
    while (p != NULL) {
        if(p->data == x) {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

int main() {
    insBeg('A');
    insBeg('B');
    insBeg('C');
    insBeg('D');
    
    node* foundNode = searchLL('A');

    if (foundNode != NULL) cout << "Data Present"; else cout << "Data Not Present";
    return 0;
}
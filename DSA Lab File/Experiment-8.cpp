// Name = Akshat Rastogi    Class = CSE-11   RollNo = 2400320100133

// Count of nodes in Linear Linked List

#include <iostream>
#include <stdlib.h>
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

int countNodes() {
    node* p = head;
    int c = 0;
    while (p != NULL) {
        p = p->next;
        c++;
    }
    return c;
}

int main() {
    insBeg('A');
    insBeg('B');
    insBeg('C');
    insBeg('D');

    int totalNodes = countNodes();

    cout << "Total number of nodes are: " << totalNodes;

    return 0;
}
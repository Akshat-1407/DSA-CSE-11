#include <iostream>
#include <cstdarg> 
using namespace std;

struct node {
    int data;
    node* next;
};


node* GetNode() {
    node* p = (node*)malloc(sizeof(node));
    return p;
}


void Initialize(node** top) {
    *top = NULL;
}


bool isEmpty(node** top) {
    if (*top == NULL) {
        return true;
    }
    else {
        return false;
    }
}


void push(node** top, int x) {
    node* P = GetNode();
    P->data = x;
    P->next = *top;
    *top = P;
}


int pop(node** top) {
    if (*top == NULL) {
        cout << "Stack Underflows";
        exit(1);
    }

    node* P = *top;
    int x = (*top)->data;
    *top = (*top)->next;
    free(P);
    return x;
}


int StackTop(node** top) {
    return (*top)->data;
}


void Traversal(node *head) {
    node* p = head;
    
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}


void createStack(node** top, int count, ...) {
    Initialize(top); 

    // Setup va_list to handle variable arguments
    va_list args;
    // va_start points 'args' to the first variable argument after 'count'
    va_start(args, count); 

    // Iterate through all arguments
    for (int i = 0; i < count; ++i) {
        // va_arg retrieves the next argument, expecting an 'int'
        int value = va_arg(args, int);
        // Push the value onto the stack
        push(top, value);
    }

    // Clean up va_list
    va_end(args);
}

int main() {

    node* top;
    // Initialize(&top);
    createStack(&top, 5, 1, 2, 3, 4, 5);
    Traversal(top);

    return 0;
}
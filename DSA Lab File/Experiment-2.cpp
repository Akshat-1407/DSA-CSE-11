// Name = Akshat Rastogi    Class = CSE-11   RollNo = 2400320100133

// Array implementation of Stack

#include <iostream>
#define STACKSIZE 50
using namespace std;

struct STACK {
    int item[STACKSIZE];
    int Top;
};


void Initialize(STACK* Stack) {
    Stack->Top = -1;
}


bool isEmpty(STACK* Stack) {
    if(Stack->Top == -1) {
        return true;
    }
    else {
        return false;
    }
}


void push(STACK* Stack, int x) {
    if(Stack->Top == STACKSIZE-1) {        
        cout<<"Stack Overflows"<<endl;
        exit(1);
    }
    else {
        Stack->Top++;
        Stack->item[Stack->Top] = x;
    }
}


int pop(STACK* Stack) {
    int x;
    if (isEmpty(Stack)) {
        cout<<"Stack Underflows"<<endl;
        exit(1);
    }
    else {      
        x = Stack->item[Stack->Top];
        Stack->Top--;
    }
    return x;
}


int StackTop(STACK* Stack) {
    return Stack->item[Stack->Top];
}


int main() {
    struct STACK S;
    
    Initialize(&S);

    push(&S, 10);
    push(&S, 20);
    push(&S, 30);
    push(&S, 40);

    pop(&S);

    cout << isEmpty(&S) << endl;

    cout << StackTop(&S) << endl;

    while(!isEmpty(&S)) {
        cout << pop(&S) << " ";
    }

    return 0;
}
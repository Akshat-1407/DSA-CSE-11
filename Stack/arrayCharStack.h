#include <iostream>
#define STACKSIZE 50
using namespace std;

struct STACK {
    char item[STACKSIZE];
    char Top;
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


void push(STACK* Stack, char x) {
    if(Stack->Top == STACKSIZE-1) {        
        cout<<"Stack Overflows"<<endl;
        exit(1);
    }
    else {
        Stack->Top++;
        Stack->item[Stack->Top] = x;
    }
}


char pop(STACK* Stack) {
    char x;
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


char StackTop(STACK* Stack) {
    return Stack->item[Stack->Top];
}
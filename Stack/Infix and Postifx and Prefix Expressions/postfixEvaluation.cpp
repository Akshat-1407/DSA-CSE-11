#include <iostream>
#include <vector>
#include <cmath>
#define STACKSIZE 20
using namespace std;

struct STACK {
    int item[STACKSIZE];
    int Top;
};


void Initialize(STACK &Stack) {
    Stack.Top = -1;
}


bool isEmpty(STACK &Stack) {
    if(Stack.Top == -1) {
        return true;
    }
    else {
        return false;
    }
}


void push(STACK &Stack, int x) {
    if(Stack.Top == STACKSIZE-1) {        
        cout<<"Stack Overflows"<<endl;
        exit(1);
    }
    else {
        Stack.Top++;
        Stack.item[Stack.Top] = x;
    }
}


int pop(STACK &Stack) {
    int x;
    if (isEmpty(Stack)) {
        cout<<"Stack Underflows"<<endl;
        exit(1);
    }
    else {      
        x = Stack.item[Stack.Top];
        Stack.Top--;
    }
    return x;
}


int StackTop(STACK &Stack) {
    return Stack.item[Stack.Top];
}


int evaluate(int x, int y, char symbol) {
    switch(symbol) {
        case('+'): return x+y;
        case('-'): return x-y;
        case('*'): return x*y;
        case('/'): return x/y;
        case('^'): return pow(x, y);
    }
    return 0;
}

void postfixExpression(char postfix[]) {
    struct STACK operandStack;
    int i = 0;
    Initialize(operandStack);
    while(postfix[i] != '\0') {
        char symbol = postfix[i];
        if (symbol >= '0' && symbol <= '9') {
            push(operandStack, symbol - '0');
        }
        else {
            int y = pop(operandStack);
            int x = pop(operandStack);

            int value = evaluate(x, y, symbol);

            push(operandStack ,value);
        }
        i++;
        
    } 
    cout<<pop(operandStack);   
}

int main() {

    char expression[50];
    cin>>expression;

    postfixExpression(expression);
    
    return 0;
}




#include <iostream>
#include <vector>
#define STACKSIZE 50
using namespace std;

struct STACK {
    char item[STACKSIZE];
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


void push(STACK &Stack, char x) {
    if(Stack.Top == STACKSIZE-1) {        
        cout<<"Stack Overflows"<<endl;
        exit(1);
    }
    else {
        Stack.Top++;
        Stack.item[Stack.Top] = x;
    }
}


char pop(STACK &Stack) {
    char x;
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


char StackTop(STACK &Stack) {
    return Stack.item[Stack.Top];
}


bool precedence(char op1, char op2) {
    if (op1 == '^' || op1 == '*' || op1 == '/' || op1 == '%') {
        if(op2 == '^')
            return false;
        else
            return true;
    }
    else if (op1 == '+' || op1 == '-') {
        if (op2 == '+' || op2 == '-')
            return true;
        else 
            return false;
    }
}


int main() {
    struct STACK opStack;

    Initialize(opStack);

    char infix[30];
    vector<char> postfix;
    

    cout<<"Enter an Infix Expression: ";
    cin>>infix;

    int i = 0;
    while (infix[i] != '\0') {
        char symbol = infix[i];

        if(symbol >= 'a' && symbol <= 'z' || symbol >= 'A' && symbol <= 'Z' || symbol >= '0' && symbol <= '9') {
            postfix.push_back(symbol);
        }
        else {
            while (!isEmpty(opStack) && precedence(StackTop(opStack), symbol)) {
                char x = pop(opStack);
                postfix.push_back(x);
            }
            push(opStack, symbol); 
        }
        i++;
    }

    while (!isEmpty(opStack)) {
        char x = pop(opStack);
        postfix.push_back(x);
    }

    for (int i = 0; i < postfix.size(); i++) {
        cout<<postfix[i];
    }

    return 0;
}




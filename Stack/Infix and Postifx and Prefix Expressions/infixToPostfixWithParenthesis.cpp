#include <iostream>
#include <vector>
#include "../arrayCharStack.h"
using namespace std;

bool precedence(char op1, char op2) {
    if (op1 == '(' || op2 == '(') {
        return false;
    }
    else if (op2 == ')') {
        return true;
    }
    else if (op1 == '^' || op1 == '*' || op1 == '/' || op1 == '%') {
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

    Initialize(&opStack);

    char infix[30];
    vector<char> postfix;
    

    cout<<"Enter an Infix Expression: ";
    cin>>infix;

    int i = 0;
    while (infix[i] != '\0') {
        char symbol = infix[i];

        if (symbol >= 'a' && symbol <= 'z' || symbol >= 'A' && symbol <= 'Z' || symbol >= '0' && symbol <= '9') {
            postfix.push_back(symbol);
        }
        else {
            while (!isEmpty(&opStack) && precedence(StackTop(&opStack), symbol)) {
                char x = pop(&opStack);
                postfix.push_back(x);
            }
            if (symbol != ')')
                push(&opStack, symbol); 
            else {
                pop(&opStack);
            }
        }
        i++;
    }

    while (!isEmpty(&opStack)) {
        char x = pop(&opStack);
        postfix.push_back(x);
    }

    for (int i = 0; i < postfix.size(); i++) {
        cout<<postfix[i];
    }

    return 0;
}




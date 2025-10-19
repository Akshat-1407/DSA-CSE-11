#include <iostream>
#include <vector>
#include <string.h>
#include "../arrayCharStack.h"
using namespace std;


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

    Initialize(&opStack);

    char infix[30];
    vector<char> prefix;
    

    cout<<"Enter an Infix Expression: ";
    cin>>infix;
    strrev(infix);

    int i = 0;
    while (infix[i] != '\0') {
        char symbol = infix[i];

        if (symbol >= 'a' && symbol <= 'z' || symbol >= 'A' && symbol <= 'Z' || symbol >= '0' && symbol <= '9') {
            prefix.push_back(symbol);
        }
        else {
            while (!isEmpty(&opStack) && !precedence(symbol, StackTop(&opStack))) {
                char x = pop(&opStack);
                prefix.push_back(x);
            }
            push(&opStack, symbol); 
        }
        i++;
    }

    while (!isEmpty(&opStack)) {
        char x = pop(&opStack);
        prefix.push_back(x);
    }

    for (int i = prefix.size()-1; i >= 0; i--) {
        cout<<prefix[i];
    }

    return 0;
}




#include <iostream>
#include "../intStack.h"
#include <cmath>
using namespace std;

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
    Initialize(&operandStack);
    while(postfix[i] != '\0') {
        char symbol = postfix[i];
        if (symbol >= '0' && symbol <= '9') {
            push(&operandStack, symbol - '0');
        }
        else {
            int y = pop(&operandStack);
            int x = pop(&operandStack);

            int value = evaluate(x, y, symbol);

            push(&operandStack ,value);
        }
        i++;
    } 
    cout<<pop(&operandStack);   
}

int main() {

    char expression[50];
    cout << "Enter a Postfix Expression: ";
    cin>>expression;

    postfixExpression(expression);
    
    return 0;
}




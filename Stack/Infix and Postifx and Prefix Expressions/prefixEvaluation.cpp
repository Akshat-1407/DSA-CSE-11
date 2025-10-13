#include <iostream>
#include "../intStack.h"
#include <vector>
#include <algorithm>
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

void prefixExpression(vector<char> postfix) {
    struct STACK operandStack;
    int i = 0;
    Initialize(&operandStack);
    for (int i = 0; i < postfix.size(); i++) {
        char symbol = postfix[i];
        if (symbol >= '0' && symbol <= '9') {
            push(&operandStack, symbol - '0');
        }
        else {
            int x = pop(&operandStack);
            int y = pop(&operandStack);

            int value = evaluate(x, y, symbol);

            push(&operandStack ,value);
        }
    } 
    cout<<pop(&operandStack);   
}

int main() {

    vector<char> expression = {'+', '*', '2', '-', '4', '3', '6'};
    
    reverse(expression.begin(), expression.end());
    prefixExpression(expression);
    
    return 0;
}

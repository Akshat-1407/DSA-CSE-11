// Program to check if the given number is a palindrome using stacks

#include <iostream>
#include <vector>
#include <string>
#include <array>
#define STACKSIZE 20
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


int main() {
    struct STACK numStack;
    Initialize(numStack);
    int flag = 0;
    string number;
    cout<<"Enter a number: ";
    cin>>number;

    for(int i = 0; i < number.size(); i++) {
        push(numStack, number[i]);
    }

    int i = 0;
    while(!isEmpty(numStack)) {
        if(pop(numStack) != number[i]){
            flag++;
            break;
        }
        i++;
    }

    if (flag == 0) {
        cout<<"Palindrome";
    }
    else {
        cout<<"Not Palindrome";
    }

    
}



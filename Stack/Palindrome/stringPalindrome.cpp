// Program to check whether the given String is palindrome or not using Stack

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
    struct STACK wordStack;
    Initialize(wordStack);

    string word;
    string revWord = "";

    cout<<"Enter a number: ";
    cin>>word;

    for(int i = 0; i < word.size(); i++) {
        push(wordStack, word[i]);
    }

    while(!isEmpty(wordStack)) {
        revWord += pop(wordStack);
    }

    if(revWord == word) cout << "Palindrome"; else cout << "Not Palindrome";

    return 0;
    
}



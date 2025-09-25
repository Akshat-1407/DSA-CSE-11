#include <iostream>
#define STACKSIZE 5
using namespace std;

struct STACK {
    int item[STACKSIZE];
    int Top;
}S;


void Initialize() {
    S.Top = -1;
}


bool isEmpty() {
    if(S.Top == -1) {
        return true;
    }
    else {
        return false;
    }
}


void push(int x) {
    if(S.Top == STACKSIZE-1) {        
        cout<<"Stack Overflows"<<endl;
        exit(1);
    }
    else {
        S.Top++;
        S.item[S.Top] = x;
    }
}


int pop() {
    int x;
    if (isEmpty()) {
        cout<<"Stack Underflows"<<endl;
        exit(1);
    }
    else {      
        x = S.item[S.Top];
        S.Top--;
    }
    return x;
}


int StackTop() {
    return S.item[S.Top];
}

void decimalToOctal(int N) {
    Initialize();
    while (N != 0) {
        int r = N % 8;
        N = N / 8;
        push(r);
    }
    while (!isEmpty()) {
        int x = pop();
        cout<<x;
    };
    
}


int main() {
    decimalToOctal(123);
    return 0;
}
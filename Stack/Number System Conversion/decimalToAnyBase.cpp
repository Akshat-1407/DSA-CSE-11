#include <iostream>
#define STACKSIZE 20
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

void decimalToAnyBase(int N, int base) {
    Initialize();
    char DAT[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    while (N != 0) {
        int r = N % base;
        N = N / base;
        push(r);
    }
    while (!isEmpty()) {
        int x = pop();
        cout<<DAT[x];
    } 
}


int main() {
    decimalToAnyBase(15, 16);
    return 0;
}

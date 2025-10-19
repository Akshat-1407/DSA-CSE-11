// Design a strategy of implementation of two stacks on a single array.

#include <iostream>
#define STACKSIZE 50
using namespace std;

struct STACK {
    int item[STACKSIZE];
    int top1;
    int top2;
};


void Initialize(STACK* S) {
    S->top1 = -1;
    S->top2 = STACKSIZE;
}

void push1(STACK* S, int x) {
    if (S->top1 + 1 == S->top2) {
        cout << "Stack Overflows";
        exit(1);
    }
    else {
        S->top1 = S->top1 + 1;
        S->item[S->top1] = x;
    }
}

void push2(STACK* S, int x) {
    if (S->top2 - 1 == S->top1) {
        cout << "Stack Overflows";
        exit(1);
    }
    else {
        S->top2 = S->top2 - 1;
        S->item[S->top2] = x;
    }
}

int pop1(STACK* S) {
    if (S->top1 == -1) {
        cout << "Stack Underflows";
        exit(1);
    }
    else {
        int x = S->item[S->top1];
        S->top1 = S->top1 - 1;
        return x;
    }
}

int pop2(STACK* S) {
    if (S->top1 == STACKSIZE) {
        cout << "Stack Underflows";
        exit(1);
    }
    else {
        int x = S->item[S->top2];
        S->top1 = S->top1 + 1;
        return x;
    }
}

int peek1(STACK* S) {
    return S->item[S->top1];
}

int peek2(STACK* S) {
    return S->item[S->top2];
}
// Name = Akshat Rastogi    Class = CSE-11   RollNo = 2400320100133

// Balanced Parenthesis

#include <iostream>
#define STACKSIZE 50
using namespace std;

struct STACK {
    char item[STACKSIZE];
    int Top;
};


void Initialize(STACK* Stack) {
    Stack->Top = -1;
}


bool isEmpty(STACK* Stack) {
    if(Stack->Top == -1) {
        return true;
    }
    else {
        return false;
    }
}


void push(STACK* Stack, char x) {
    if(Stack->Top == STACKSIZE-1) {        
        cout<<"Stack Overflows"<<endl;
        exit(1);
    }
    else {
        Stack->Top++;
        Stack->item[Stack->Top] = x;
    }
}


char pop(STACK* Stack) {
    char x;
    if (isEmpty(Stack)) {
        cout<<"Stack Underflows"<<endl;
        exit(1);
    }
    else {      
        x = Stack->item[Stack->Top];
        Stack->Top--;
    }
    return x;
}


char StackTop(STACK* Stack) {
    return Stack->item[Stack->Top];
}


int main() {
    struct STACK parenthesisStack;
    Initialize(&parenthesisStack);

    int flag = 0;
    string parenthesis;

    cout<<"Enter an Expression: ";
    cin>>parenthesis;

    for(int i = 0; i < parenthesis.size(); i++) {
        if (parenthesis[i] == '(')
            push(&parenthesisStack, '(');
        else 
            if(!isEmpty(&parenthesisStack)) {
                pop(&parenthesisStack);
            }
            else {
                flag = 1;
                break;
            }
    }

    if(isEmpty(&parenthesisStack))
        if (flag == 0)
            cout << "Balanced Parenthesis";
        else
            cout << "Unbalanced Parenthesis";
    else
        cout << "Unbalanced Parenthesis";

    return 0;
}

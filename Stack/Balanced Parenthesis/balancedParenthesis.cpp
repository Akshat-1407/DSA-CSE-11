// Program to check the validity of Parenthesized Arithmetic Expression using Stack

#include <iostream>
#include "../charStack.h"
using namespace std;

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

    // if(isEmpty(parenthesisStack) && flag == 0)
    //     cout << "Balanced Parenthesis";      
    // else if (isEmpty(parenthesisStack) && flag == 1)
    //     cout << "Unbalanced Parenthesis";
    // else if (! isEmpty(parenthesisStack))
    //     cout << "Unbalanced Parenthesis";

    return 0;
    
}



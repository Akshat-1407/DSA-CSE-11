// Program to check if the given number is a palindrome using stacks

#include <iostream>
#include "../arrayCharStack.h"
using namespace std;

int main() {
    struct STACK numStack;
    Initialize(&numStack);
    int flag = 0;
    string number;
    cout<<"Enter a number: ";
    cin>>number;

    for(int i = 0; i < number.size(); i++) {
        push(&numStack, number[i]);
    }

    int i = 0;
    while(!isEmpty(&numStack)) {
        if(pop(&numStack) != number[i]){
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



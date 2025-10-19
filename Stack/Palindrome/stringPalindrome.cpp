// Program to check whether the given String is palindrome or not using Stack

#include <iostream>
#include "../arrayCharStack.h"
using namespace std;

int main() {
    struct STACK wordStack;
    Initialize(&wordStack);

    string word;
    string revWord = "";

    cout<<"Enter a number: ";
    cin>>word;

    for(int i = 0; i < word.size(); i++) {
        push(&wordStack, word[i]);
    }

    while(!isEmpty(&wordStack)) {
        revWord += pop(&wordStack);
    }

    if(revWord == word) 
        cout << "Palindrome"; 
    else 
        cout << "Not Palindrome";

    return 0;
    
}



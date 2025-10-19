// Program to Reverse the given String using Stack

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

    cout<<revWord;

    return 0;
    
}



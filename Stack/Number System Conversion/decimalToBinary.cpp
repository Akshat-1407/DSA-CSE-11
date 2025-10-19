#include <iostream>
#include "../arrayIntStack.h"
using namespace std;


void decimalToBinary(int N) {
    STACK num;
    Initialize(&num);
    while (N != 0) {
        int r = N % 2;
        N = N / 2;
        push(&num, r);
    }
    while (!isEmpty(&num)) {
        int x = pop(&num);
        cout<<x;
    };
    
}


int main() {
    decimalToBinary(7);
    return 0;
}
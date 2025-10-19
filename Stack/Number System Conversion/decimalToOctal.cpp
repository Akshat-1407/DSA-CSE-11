#include <iostream>
#include "../arrayIntStack.h"
using namespace std;


void decimalToOctal(int N) {
    STACK num;
    Initialize(&num);
    while (N != 0) {
        int r = N % 8;
        N = N / 8;
        push(&num, r);
    }
    while (!isEmpty(&num)) {
        int x = pop(&num);
        cout<<x;
    };
    
}


int main() {
    decimalToOctal(16);
    return 0;
}
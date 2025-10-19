#include <iostream>
#include "../arrayIntStack.h"
using namespace std;

void decimalToAnyBase(int N, int base) {
    STACK num;
    Initialize(&num);
    char DAT[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    while (N != 0) {
        int r = N % base;
        N = N / base;
        push(&num, r);
    }
    while (!isEmpty(&num)) {
        int x = pop(&num);
        cout<<DAT[x];
    } 
}


int main() {
    decimalToAnyBase(15, 16);
    return 0;
}

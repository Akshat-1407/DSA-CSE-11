#include <iostream>
#include "../intStack.h"
using namespace std;

void decimalToHexaDecimal(int N) {
    STACK num;
    Initialize(&num);
    char DAT[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    while (N != 0) {
        int r = N % 16;
        N = N / 16;
        push(&num, r);
    }
    while (!isEmpty(&num)) {
        int x = pop(&num);
        cout<<DAT[x];
    } 
}


int main() {
    decimalToHexaDecimal(15);
    return 0;
}

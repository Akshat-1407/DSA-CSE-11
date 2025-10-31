#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    else   
        return gcd(b, a % b);
}

int fact(int n) {
    if (n == 0)
        return 1;
    else 
        return n * fact(n-1);
}

int arrSum(int arr[], int n) { // Here n is the last index
    if (n <= 0) 
        return arr[0];
    else 
        return arr[n] + arrSum(arr, n-1);
}

int digitSum(int n){
    if(n == 0)
        return 0;
    else
        return (n % 10) + digitSum(n / 10);
}

// int revdigit(int n) {
//     static int reversed_num = 0; // Static variable to accumulate the result
//     if (n == 0) {
//         return reversed_num;
//     } else {
//         reversed_num = (reversed_num * 10) + (n % 10);
//         return revdigit(n / 10);
//     }
// }

// Normal
int Pow(int a, int n) {
    if(n == 0)
        return 1;
    else    
        return a * Pow(a, n-1);
}

// Binary Exponentiation
int Pow_BinExp(int a, int n) {
    if (n == 0) {
        return 1;
    }
    else {
        int x = Pow(a, n/2);
        if (n % 2 == 0) {
           return x * x; 
        }
        else {
            return a * x * x;
        }
    }
}

// O(2^n)
int fib(int n) {
    if (n <= 2) 
        return n-1;
    else 
        return fib(n-1) + fib(n-2);
}

// Optimized
int optimizedFib(int n) {
    int DAT[101] = {0};
    if (n <= 2) 
        return n-1;
    else 
        if (DAT[n] == 0 ) {
            DAT[n] = fib(n-1) + fib(n-2);
        }
        return DAT[n];
}







int main() {
    int arr[] = {1, 2, 3, 4, 5};

    cout << "GCD: " << gcd(60, 36) << endl;
    cout << "Fib: " << fib(5) << endl;
    cout << "Optimized Fib: " << optimizedFib(5) << endl;
    cout << "Power: " << Pow(2, 10) << endl;
    cout << "Power using Binary Exponentiaion: " << Pow_BinExp(2, 10) << endl;
    cout << "Factorial: " << fact(5) << endl;
    cout << "DigitSum: " << digitSum(123) << endl;
    cout << "Array Sum: " << arrSum(arr, 4) << endl;
    // cout << "Reverse the Number: " << revdigit(123) << endl;



    return 0;
}
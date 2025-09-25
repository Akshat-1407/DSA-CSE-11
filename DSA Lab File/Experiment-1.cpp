// Name = Akshat Rastogi    Class = CSE-11   RollNo = 2400320100133

// Array Insertion, Deletion, Traversal

#include <iostream>
using namespace std;

void Traversal(int arr[], int &N) {
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
}

void Insertion(int arr[], int &N, int pos, int x) {
    for(int i = N-1; i >= pos; i--) {
        arr[i+1] = arr[i];
    }
    arr[pos] = x;
    N = N+1;
}

int Deletion(int arr[], int &N, int pos) {
    int x = arr[pos];
    for (int i = pos; i < N-1; i++) {
        arr[i] = arr[i+1];
    }
    N = N-1;
    return x;

}

int main() {
    int n;
    int arr[100];

    cout << "Enter the Size of array: ";
    cin >> n;

    cout << "Enter the elements of the array: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Insertion(arr, n, 2, 9);
    Deletion(arr, n, 5);
    Traversal(arr, n);   
}
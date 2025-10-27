// Here the array is in Descending Order such that the complexity of insertion is O(N) and deletion is O(1);

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;


void ArrayInsertion(vector<int>& arr, int pos, int x) {
    arr.insert(arr.begin() + pos, x);
}

void Traversal(vector<int>& arr) {
    for(int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
}

void EnQueue(vector<int>& arr, int x) {
    int i = 0;
    while (i < arr.size() && x < arr[i]) {
        i = i + 1;
    }
    ArrayInsertion(arr, i , x);
}

int DeQueue(vector<int>& arr) {
    if (arr.empty()) {
        cout << "Void Deletion" << endl;
        exit(1);
    }
    int x = arr.back();
    arr.pop_back();  
    return x;
}

int main() {
    
    int n;
    cout << "Enter the Size of the array: ";
    cin >> n;

    vector<int>arr(n);
    
    cout << "Enter the elements of the array: " << endl;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end(), greater<int>());

    EnQueue(arr, 2);

    Traversal(arr);

    return 0;
}
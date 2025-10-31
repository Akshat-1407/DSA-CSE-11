// Data Structures Lab Practical Examination

// Program for counting nodes containing even and odd information

// Name - Akshat Rastogi     // Roll No - 2400320100133       // Class - CSE 11

#include <iostream>
#include <vector>
using namespace std;

struct node {
    int data;
    struct node* next;
};

node* GetNode() {
    node* p = (node*)malloc(sizeof(node));
    return p;
};

void insBeg(node** head, int x) {
    node* p = GetNode();
    p->data = x;
    p->next = *head;
    *head = p;
}

vector<int> CountEvenOddNodes(node** head) {
    int even = 0;
    int odd = 0;

    node* P = *head;
    vector<int> arr;

    if (head == NULL) {
        cout << "Invalid Node";
        exit(1);
    }

    while (P != NULL) {
        if (P->data % 2 == 0) {
            even++;
            P = P->next;
        } 
        else {
            odd++;
            P = P->next;
        }
    }
    arr.push_back(even);
    arr.push_back(odd);

    return arr;
}

int main() {
    node* head = NULL;

    insBeg(&head, 5);
    insBeg(&head, 4);
    insBeg(&head, 3);
    insBeg(&head, 2);
    insBeg(&head, 1);

    vector<int>ans = CountEvenOddNodes(&head);
    
    cout << "Even: " << ans[0] << endl;
    cout << "Odd: " << ans[1] << endl;

    return 0;
}


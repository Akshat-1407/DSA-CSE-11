#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include "intSinglyLinkedList.h"

node* addLL(node* head1, node* head2) {
    reverseLL(&head1);
    reverseLL(&head2);

    node* P = head1;
    node* Q = head2;
    node* head3 = NULL;

    int carry = 0;

    while (P != NULL && Q != NULL) {
        int total = P->data + Q->data + carry;
        int sum = total % 10;
        carry = total / 10 ;
        insBeg(&head3, sum);
        P = P->next;
        Q = Q->next;
    }

    while (P != NULL) {
        int total = P->data + carry;
        int sum = total % 10;
        carry = total / 10 ;
        insBeg(&head3, sum);
        P = P->next;
    }

    while (Q != NULL) {
        int total = Q->data + carry;
        int sum = total % 10;
        carry = total / 10 ;
        insBeg(&head3, sum);
        Q = Q->next;
    }

    if (carry == 1) {
        insBeg(&head3, carry);
    }

    return head3;
}

int main() {
    node* head1 = NULL; 
    node* head2 = NULL;

    // string number;
    // cout << "Enter a large number (up to 20 digits): ";
    // cin >> number;

    // vector<string> chunks;
    // int len = number.length();

    // // Process from the end in chunks of 4
    // for (int i = len; i > 0; i -= 4) {
    //     int start = max(0, i - 4);
    //     chunks.push_back(number.substr(start, i - start));
    // }

    // // Reverse to maintain original order from left to right
    // reverse(chunks.begin(), chunks.end());

    
    insBeg(&head1, 6);
    insBeg(&head1, 1);
    insBeg(&head1, 2);
    Traversal(head1);

    insBeg(&head2, 8);
    insBeg(&head2, 9);
    insBeg(&head2, 1);
    Traversal(head2);

    node* sum = addLL(head1, head2);

    Traversal(sum);
    
}


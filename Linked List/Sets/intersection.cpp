#include <iostream>
#include <stdlib.h>
#include "../intLinkedList.h"

node* intersectionLL(node* head1, node* head2) {
    node* P = head1;
    node* Q = head2;
    node* head3 = NULL;

    while (P != NULL && Q != NULL) {
        if (P->data < Q->data) {
            // insBeg(&head3, P->data);
            P = P->next;
        }
        else if (P->data > Q->data){
            // insBeg(&head3, Q->data);
            Q = Q->next;
        }
        else {
            insBeg(&head3, P->data);
            P = P->next;
            Q = Q->next;
        }
    }
    
    reverseLL(&head3);

    return head3;
}

int main() {

    node* head1 = NULL;
    node* head2 = NULL;

    // For first Linked List
    insBeg(&head1, 9);
    insBeg(&head1, 7);
    insBeg(&head1, 5);
    insBeg(&head1, 3);
    insBeg(&head1, 1);

    Traversal(head1);

    // For second Linked List
    insBeg(&head2, 8);
    insBeg(&head2, 7);
    insBeg(&head2, 6);
    insBeg(&head2, 5);
    insBeg(&head2, 4);
    insBeg(&head2, 3);
    insBeg(&head2, 2);
    insBeg(&head2, 1);

    Traversal(head2);

    node* head3 = intersectionLL(head1, head2);

    Traversal(head3);
    
    return 0;
}


#include <iostream>
using namespace std;
#include "intSinglyLinkedList.h"

void delAllOccurences(node** head, int x) {
    node* P = *head;
    node* Q = NULL;

    while (P != NULL) {
        if (P->data == x) {
            P = P->next;
            if (Q == NULL) {
                delBeg(head);
            }
            else {
                delAfter(&Q);
            }
        }
         else {
            Q = P;
            P = P->next;
        }
    }
}

int main() {
    node* head = NULL;
    insBeg(&head, 3);
    insBeg(&head, 5);
    insBeg(&head, 3);
    insBeg(&head, 3);
    insBeg(&head, 7);
    insBeg(&head, 6);
    insBeg(&head, 3);

    Traversal(head);

    delAllOccurences(&head, 3);

    Traversal(head);

    return 0;
}
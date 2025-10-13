// Name = Akshat Rastogi    Class = CSE-11   RollNo = 2400320100133

// Polynomial Arithmetic (Addition, Subtraction, Multiplication)

#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

struct node {
    int exp;
    int coef;
    struct node* next;
};


node* GetNode() {
    node* p = (node*)malloc(sizeof(node));
    return p;
};


void FreeNode(node* p) {
    free(p);
}


void Traversal(node *head) {
    node* p = head;
    
    while (p != NULL) {
        // To handle negative coefficients in the output
        if (p != head && p->coef >= 0) {
            cout << "+ ";
        }
        cout << p->coef << "x^" << p->exp << " ";
        p = p->next;
    }
    cout << endl;
}


void insBeg(node** head, int coef, int exp) {
    node* p = GetNode();
    p->coef = coef;
    p->exp = exp;
    p->next = *head;
    *head = p;
}


void reverseLL(node** head) {
    node* p = NULL;
    node* c = *head;
    node* n = c->next;

    while (c != NULL) {
        c->next = p;
        p = c;
        c = n;
        if (n != NULL) {
            n = n->next;
        }
     }
     *head = p;
}


node* polynomialAddition(node* poly1, node* poly2) {
    node* P = poly1;
    node* Q = poly2;
    node* poly3 = NULL;

    while (P != NULL && Q != NULL) {
        if (P->exp == Q->exp) {
            insBeg(&poly3, P->coef + Q->coef, P->exp);
            P = P->next;
            Q = Q->next;
        }
        else if (P->exp > Q->exp) {
            insBeg(&poly3, P->coef, P->exp);
            P = P->next;
        }
        else {
            insBeg(&poly3, Q->coef, Q->exp);
            Q = Q->next;
        }
    }

    while (P != NULL) {
        insBeg(&poly3, P->coef, P->exp);
        P = P->next;
    }

    while (Q != NULL) {
        insBeg(&poly3, Q->coef, Q->exp);
        Q = Q->next;
    }
    reverseLL(&poly3);
    return poly3;
}


node* polynomialSubtraction(node* poly1, node* poly2) {
    node* P = poly1;
    node* Q = poly2;

    while (Q != NULL) {
        Q->coef = -1 * Q->coef;
        Q = Q->next;
    }

    node* poly3 = polynomialAddition(poly1, poly2);

    return poly3;
}


node* polynomialMultiplication(node* poly1, node* poly2) {
    node* P = poly1;
    node* Q = poly2;
    node* poly3 = NULL;

    int N = poly1->exp + poly2->exp + 1;

    vector<int> DAT(N, 0);

    while (P != NULL) {
        while (Q != NULL) {
            int coef = P->coef * Q->coef;
            int exp = P->exp + Q->exp;
            DAT[exp] = DAT[exp] + coef;
            Q = Q->next;
        }
        P = P->next;
        Q = poly2;
    }

    for (int i = 0; i < N; i++) {
        if (DAT[i] != 0) {
            insBeg(&poly3, DAT[i], i);
        }
    }

    return poly3;
}


int main() {
    node* poly1 = NULL;
    node* poly2 = NULL;

    // Create poly1 = 5x^3 + 4x^1 + 2x^0
    insBeg(&poly1, 2, 0);
    insBeg(&poly1, 4, 1);
    insBeg(&poly1, 5, 3);
    
    // Create poly2 = 3x^2 + 4x^1 + 1x^0
    insBeg(&poly2, 1, 0);
    insBeg(&poly2, 4, 1);
    insBeg(&poly2, 3, 2);

    cout << "Polynomial 1:   ";
    Traversal(poly1);

    cout << "Polynomial 2:   ";
    Traversal(poly2);

    cout << "------------------------------------------\n";

    node* product = polynomialMultiplication(poly1, poly2);
    cout << "Multiplication: ";
    Traversal(product);

    node* sum = polynomialAddition(poly1, poly2);
    cout << "Sum:            ";
    Traversal(sum);

    node* diff = polynomialSubtraction(poly1, poly2);
    cout << "Difference:     ";
    Traversal(diff);

    return 0;
}

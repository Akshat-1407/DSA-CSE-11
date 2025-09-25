#include <stdio.h> 

int main(void) {
    int a[10][10], b[10][10], c[10][10], m, n, p, q;

    printf("Enter the order of first matrix: ");
    scanf("%d %d", &m, &n);

    printf("Enter the order of second matrix: ");
    scanf("%d %d", &p, &q);

    if (n == p) {
        printf ("Enter the elements of first matrix: ");
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                scanf("%d", &a[i][j]);
            }
        }
        printf ("Enter the elements of second matrix: ");
        for (int i=0; i<p; i++) {
            for (int j=0; j<q; j++) {
                scanf("%d", &b[i][j]);
            }
        }

        // matrix multiplication
        for (int i=0; i<m; i++) {
            for (int j=0; j<q; j++) {
                c[i][j] = 0;
                for (int k=0; k<n; k++) { 
                    c[i][j] += a[i][k] * b[k][j];
                }
            }
        }
        // Printing resultant matrix
        printf("The product of two matrices is: \n");
        for (int i=0; i<m; i++) {
            for (int j=0; j<q; j++) {
                printf("%d\t", c[i][j]);
            }
            printf("\n");
        }
    }
    else {
        printf("Matrix multiplication not possible");
    }
    return 0;
}
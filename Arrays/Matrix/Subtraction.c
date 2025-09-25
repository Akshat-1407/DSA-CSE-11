#include <stdio.h> 

int main(void) {
    int a[10][10], b[10][10], c[10][10], n;

    printf("Enter the order of matrix: ");
    scanf("%d", &n);

    printf ("Enter the elements of first matrix: ");
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    printf ("Enter the elements of second matrix: ");
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            scanf("%d", &b[i][j]);
        }
    }

    // matrix subtraction
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            c[i][j] += a[i][j] - b[i][j];
        }
    }
    // Printing resultant matrix
    printf("The subtraction of two matrices is: \n");
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            printf("%d\t", c[i][j]);
        }
        printf("\n");
    }
    

    return 0;
}
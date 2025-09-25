#include <stdio.h> 

int main(void) {
    int a[10][10], b[10][10], n, m, flag=0;

    printf("Enter the order of matrix: ");
    scanf("%d %d",&m, &n);

    printf ("Enter the elements of matrix: ");
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    // taking transpose
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            b[i][j] = a[j][i];
        }
    }

    // printing resultant matrix
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            printf("%d\t", b[i][j]);
        }
        printf("\n");
    }

}
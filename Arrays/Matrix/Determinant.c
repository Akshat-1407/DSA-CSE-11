#include <stdio.h>

// Function to get a submatrix for cofactor expansion
void getCofactor(int matrix[10][10], int temp[10][10], int p, int q, int n) {
    int i = 0, j = 0;
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            if (row != p && col != q) {
                temp[i][j++] = matrix[row][col];
                if (j == n - 1) {
                    j = 0;
                    i++;
                }
            }
        }
    }
}

// Recursive function to calculate the determinant
int determinantOfMatrix(int matrix[10][10], int n) {
    int D = 0;
    if (n == 1) {
        return matrix[0][0];
    }

    int temp[10][10];
    int sign = 1;

    for (int f = 0; f < n; f++) {
        getCofactor(matrix, temp, 0, f, n);
        D += sign * matrix[0][f] * determinantOfMatrix(temp, n - 1);
        sign = -sign;
    }
    return D;
}

int main() {
    int n;
    printf("Enter the size of the square matrix (max 10): ");
    scanf("%d", &n);

    if (n > 10) {
        printf("Matrix size too large. Exiting.\n");
        return 1;
    }

    int matrix[10][10];
    printf("Enter the elements of the %dx%d matrix:\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Enter element at [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("\nThe determinant of the matrix is: %d\n", determinantOfMatrix(matrix, n));
    return 0;
}
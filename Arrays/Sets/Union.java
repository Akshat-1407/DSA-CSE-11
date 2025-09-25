package Sets;
import java.util.*;

public class Union {
    public static void main(String[] args) {

        int m = 0;
        int n = 0;

        Scanner scanner = new Scanner(System.in);

        // Entering first array
        System.out.print("Enter the size of the first array: ");
        m = scanner.nextInt();
        
        int A[] = new int[m];

        System.out.println("Enter the Elements if the first array: ");
        for (int i = 0; i < m; i++) {
            A[i] = scanner.nextInt();
        }

        // Entering second array
        System.out.print("Enter the size of the second array: ");
        n = scanner.nextInt();

        int B[] = new int[n];

        System.out.println("Enter the Elements if the second array: ");
        for (int i = 0; i < n; i++) {
            B[i] = scanner.nextInt();
        }

        scanner.close();


        unionArray(A, m, B, n);   
    }

    
    public static void unionArray(int A[], int m, int B[], int n) {
        int i = 0, j = 0, k = 0;

        int C[] = new int[m+n];

        while (i < m && j < n) {
            if (A[i] < B[j]) {
                C[k] = A[i];
                i++; k++;
            }
            else if (B[j] < A[i]) {
                C[k] = B[j];
                j++; k++;
            }
            else {
                C[k] = B[j];
                i++; j++; k++;
            }
        }

        while (i < m) {
            C[k] = A[i];
            i++; k++;
        }

        while (j < n) {
            C[k] = B[j];
            j++; k++;
        }

        traversal(C, C.length);
    }

    public static void traversal(int C[], int n) {
        System.out.println("The sorted array is: ");
        for (int i = 0; i < n; i++) {
            System.out.print(C[i] + " ");
        }
    }
}



import java.util.Arrays;
public class Deletion {
    public static void main(String[] args) {
        int arr[] = {1, 2, 3, 4 ,8, 9};
        deletion(arr, 3);

    }

    public static void deletion(int arr[], int pos) {
        int newArr[] = Arrays.copyOf(arr, arr.length+1);
        for (int i = pos; i <= arr.length - 1; i++) {
            newArr[i] = newArr[i+1];
        }
        for(int e: newArr) {
            System.out.print(e + " ");
        }
    }
}
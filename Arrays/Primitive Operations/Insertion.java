import java.util.Arrays;

public class Insertion {
    public static void main(String[] args) {
        int arr[] = {1, 5, 6, 8, 7, 9, 10};
        insertion(arr, 2, 11);  
    }

    public static void insertion(int arr[], int pos, int x) {
        int newArr[] = new int[arr.length+1];
        newArr = Arrays.copyOf(arr, arr.length+1);

        for(int i = arr.length-1; i >= pos; i--) {
            newArr[i+1] = newArr[i];
        }

        newArr[pos] = x;
        
        for(int e: newArr) {
            System.out.print(e + " ");
        }
    }
}

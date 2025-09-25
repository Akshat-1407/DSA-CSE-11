import java.util.Arrays;
public class SortedInsertion {
    public static void main(String[] args) {
        int arr[] = {1, 2, 3, 5, 6, 7, 8};
        sortedInsertion(arr, 4);  
    }

    public static void sortedInsertion(int arr[], int x) {
        for(int i = 0; i < arr.length; i++) {
            if(arr[i] >= x && i < arr.length-1) {
                insertion(arr, i, x);
                break;
            }
        }
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

public class Traversal {
    public static void main(String[] args) {
        int arr[] = {1, 5, 6, 8, 7, 9, 10};
        if (traversal(arr, 5) == -1) 
            System.err.println("Key not found");
        else
            System.out.println("Key is at index " + traversal(arr, 5));
    }

    
    public static int traversal(int arr[], int key) {
        for(int i = 0; i<arr.length; i++) {
            if(arr[i] == key)
                return i;
        }
        return -1;
    }
}

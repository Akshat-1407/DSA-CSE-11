public class MissingNumberUsingDirectAddressTable {
    public static void main(String[] args) {
        // int arr[] = {7, 6, 3, 2, 9, 4, 1, 5};
        int arr[] = {8, 7, 6, 9, 11, 12};

        System.err.println("The missing number is: " + missingNumber(arr, largest(arr), smallest(arr)));
    }

    public static int missingNumber(int arr[], int largest, int smallest) {
        int DAT[] = new int[largest+1];

        // incrementing the frequency of the numbers
        for(int i = 0; i < arr.length; i++) {
            DAT[arr[i]]++;  
        }

        // finding the missing number
        for(int i = smallest; i < largest+1; i++) {
            if(DAT[i] == 0) {
                return i;
            }
        }
        return 0;
    }

    
    public static int largest(int arr[]) {
        int largest = Integer.MIN_VALUE;
        for(int i = 0; i < arr.length; i++) {
            if(arr[i] > largest) {
                largest = arr[i];
            }
        }
        return largest;
    }

    public static int smallest(int arr[]) {
        int smallest = Integer.MAX_VALUE;
        for(int i = 0; i < arr.length; i++) {
            if(arr[i] < smallest) {
                smallest = arr[i];
            }
        }
        return smallest;
    }
}

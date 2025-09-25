public class RepeatedNumberUsingDAT {
    public static void main(String[] args) {
        // int arr[] = {7, 6, 3, 2, 9, 4, 1, 5};
        int arr[] = {8, 7, 8, 8, 6, 11, 9, 11, 12};

        repeatedNumber(arr, largest(arr));
    }

    public static void repeatedNumber(int arr[], int largest) {
        int DAT[] = new int[largest+1];

        // Incrementing frequency count
        for(int i = 0; i < arr.length; i++) {
            DAT[arr[i]]++;  
        }

        // finding missing number
        for(int i = 0; i < DAT.length; i++) {
            if (DAT[i] > 1) {
                System.out.print(i + " ");
            }
        }
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
}

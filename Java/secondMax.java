public class secondMax {
    public static void main(String[] args) {
        int arr[] = {1, 4, 6, 2, 10, 5, 25, 11, 8};
        int max, secondMax;
        max = secondMax = Integer.MIN_VALUE;
        if(arr.length == 0){
            System.out.println("Array is empty");
        }
        else{
            for(int i=0; i<arr.length; i++){
                if(arr[i] > max){
                    secondMax = max;
                    max = arr[i];
                }
                else if(arr[i] < max && arr[i] > secondMax){
                    secondMax = arr[i];
                }
            }
        }
        System.out.printf("Maximum value is: %d\n", max);
        if(secondMax == Integer.MIN_VALUE){
            System.out.println("No second maximum value found");
        } else {
            System.out.println("Second maximum value is: " + secondMax);
        }
    }    
}

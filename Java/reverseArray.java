import java.util.*;

public class reverseArray {
    public static void reverse(Integer arr[]){
        int n = arr.length;
        for(int i=0; i< n/2; i++){
            int temp = arr[i];
            arr[i] = arr[n-i-1];
            arr[n-i-1] = temp;
        }
    }
    public static void main(String[] args){
        Integer arr[] = {5, 4, 9, 2, 1, 3, 8, 6, 7};
        System.out.println("Original array: " + Arrays.toString(arr));
        Arrays.sort(arr, Comparator.reverseOrder());
        System.out.println("Reversed array: " + Arrays.toString(arr));

        reverse(arr);
        System.out.println("Reversing the array using custom method:" + Arrays.toString(arr));
    }
}

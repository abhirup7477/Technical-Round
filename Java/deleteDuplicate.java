import java.util.Arrays;

public class deleteDuplicate {
    public static void main(String[] args) {
        Integer arr[] = {1, 8, 4, 1, 4, 1, 2, 2, 8, 1};
        int n = arr.length;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(arr[i] == arr[j]){
                    System.out.println(Arrays.toString(arr));
                    System.out.printf("i = %d, j = %d, arr[i] = %d, arr[j] = %d\n", i, j, arr[i], arr[j]);
                    for(int k = j; k<n-1; k++){
                        arr[k] = arr[k+1];
                    }
                    n--;
                    j--;
                }
            }
            System.out.println();
        }
        System.out.println(Arrays.toString(arr));
    }
}

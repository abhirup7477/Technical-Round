import java.util.*;

public class ProductSubarray {
    public static void main(String[] args) {
        int arr[] = {2, 3, -4, 1, -5, 9, 2, 2, -8};
        List<Integer> positives = new ArrayList<>();
        List<Integer> negatives = new ArrayList<>();
        for(int i=0; i < arr.length; i++){
            if(arr[i] < 0)
                negatives.add(arr[i]);
            else if(arr[i] > 0)
                positives.add(arr[i]);
        }
        positives.sort(Comparator.naturalOrder());
        negatives.sort(Comparator.naturalOrder());
        
        int product = 1;
        List<Integer> subarray = new ArrayList<>();
        if(negatives.size() % 2 == 1){
            negatives.remove(negatives.size() - 1);
        }
        for(int i : negatives){
            product *= i;
            subarray.add(i);
        }
        for(int i : positives){
            product *= i;
            subarray.add(i);
        }
        System.out.println(positives);
        System.out.println(negatives);
        System.out.println(subarray);
        System.out.println(product);
    }
}

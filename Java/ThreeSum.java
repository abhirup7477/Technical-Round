import java.util.*;

public class ThreeSum {
    public static void main(String[] args) {
        int arr[] = {1, 2, -3, 8, 4, 3, -2, 4, -1};
        int target = 0;

        Set<List<Integer>> triplets = new HashSet<List<Integer>>();
        for(int i=0; i<arr.length; i++){
            Set<Integer> hashSet = new HashSet<>();
            for(int j=i+1; j<arr.length; j++){
                int third = target - arr[i] - arr[j];
                if(hashSet.contains(third)){
                    List<Integer> temp = Arrays.asList(arr[i], arr[j], third);
                    temp.sort(Comparator.naturalOrder());
                    triplets.add(temp);
                }
                hashSet.add(arr[j]);

                System.out.println("Inner Loop : ");
                System.out.print("hashSet : ");
                System.out.println(hashSet);
                System.out.print("triplets : ");
                System.out.println(triplets);
                System.out.println();
            }
            System.out.println("Outer Loop : ");
            System.out.print("hashSet : ");
            System.out.println(hashSet);
            System.out.print("triplets : ");
            System.out.println(triplets);
            System.out.println();
        }

        System.out.println(triplets);
    }
}

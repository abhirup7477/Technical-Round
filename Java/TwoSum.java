import java.util.*;

public class TwoSum {
    public static String twoSum(int arr[], int target){
        Arrays.sort(arr);
        int left = 0;
        int right = arr.length-1;
        while(left < right){
            if(arr[left] + arr[right] == target){
                return "Yes";
            }
            else if(arr[left] + arr[right] < target){
                left++;
            }
            else{
                right--;
            }
        }
        return "No";
    }
    public static int[] twoSumHashing(int arr[], int target){
        int result[] = {-1, -1};
        Map<Integer, Integer> map = new HashMap<>();
        for(int i=0; i<arr.length; i++){
            int required = target - arr[i];
            if(map.containsKey(required)){
                result[0] = map.get(required);
                result[1] = i;
                
                return result;
            }
            map.put(arr[i], i);
        }
        return result;
    }
    public static void main(String[] args){
        int arr[] = {2, 6, 5, 8, 11};
        int target = 14;
        // String result = twoSum(arr, target);
        // System.out.println(result);
        int indices[] = twoSumHashing(arr, target);
        System.out.println(Arrays.toString(indices));
    }
}

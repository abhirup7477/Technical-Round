import java.util.*;

public class Sort{
    public static void display(int arr[], String prompt){
        System.out.print(prompt + ": ");
        for(int i : arr){
            System.out.print(i + " ");
        }
        System.out.println();
    }

    public static void merge(int arr[], int low, int mid, int high){
        int temp[] = new int[high - low + 1];
        int i = low, j = mid+1, k = 0;
        while(i <= mid && j <= high){
            if(arr[i] <= arr[j]){
                temp[k++] = arr[i++];
            }
            else{
                temp[k++] = arr[j++];
            }
        }
        while(i <= mid){
            temp[k++] = arr[i++];
        }
        while(j <= high){
            temp[k++] = arr[j++];
        }
        for(i = low, k = 0; i <= high; i++, k++){
            arr[i] = temp[k];
        }
    }

    public static void mergeSort(int arr[], int low, int high){
        if(low < high){
            int mid = (low + high) / 2;
            mergeSort(arr, low, mid);
            mergeSort(arr, mid+1, high);
            merge(arr, low, mid, high);
        }
    }

    public static void quickSort(int arr[], int low, int high){
        int i = low+1, j = high, pivot = arr[low];
        while(i <= j){
            while(i<=j && pivot > arr[i]){
                i++;
            }
            while(i<=j && pivot < arr[j]){
                j--;
            }
            if(i <= j){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                i++;
                j--;
            } 
        }
        arr[low] = arr[j];
        arr[j] = pivot;

        if(low < j){
            quickSort(arr, low, j-1);
        }
        if(i < high){
            quickSort(arr, i, high);
        }
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        int arr1[] = {5, 4, 9, 2, 1, 3, 8, 6, 7};
        int arr2[] = {5, 4, 9, 2, 1, 3, 8, 6, 7};

        quickSort(arr1, 0, arr1.length-1);
        mergeSort(arr2, 0, arr2.length-1);

        display(arr1, "Quick sort : ");
        display(arr2, "Merge sort : ");

        sc.close();
    }
}
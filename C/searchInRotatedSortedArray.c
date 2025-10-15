#include <stdio.h>

int rotatedSearch(int arr[], int low, int high, int target){
    if(low > high){
        return -1;
    }

    int mid = (low + high) / 2;
    if(arr[mid] == target){
        return mid;
    }
    if(arr[low] <= arr[mid]){
        if(arr[low] <= target && target < arr[mid]){
            return rotatedSearch(arr, low, mid-1, target);
        }
        else{
            return rotatedSearch(arr, mid+1, high, target);
        }
    }
    else{
        if(arr[mid] < target && target <= arr[high]){
            return rotatedSearch(arr, mid+1, high, target);
        }
        else{
            return rotatedSearch(arr, low, mid-1, target);
        }
    }
}

void main(){
    int n = 9;
    int arr[] = {7, 8, 9, 1, 2, 3, 4, 5, 6};
    int target = 1;

    printf("Index = %d\n", rotatedSearch(arr, 0, n-1, target));
}
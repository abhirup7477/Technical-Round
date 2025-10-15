#include <stdio.h>
#include <limits.h>

int min(int a, int b){
    return (a < b)? a : b;
}

int findMin(int arr[], int low, int high){
    int ans = INT_MAX;

    while(low <= high){
        int mid = (low + high) / 2;

        if(arr[low] <= arr[mid]){
            ans = min(ans, arr[low]);
            low = mid+1;
        }
        else{
            ans = min(ans, arr[mid]);
            high = mid-1;
        }
    }
    return ans;
}

int main(){
    int n = 7;
    int arr[] = {5, 6, 7, 1, 2, 3, 4};

    printf("Min = %d\n",findMin(arr, 0, n-1));
}
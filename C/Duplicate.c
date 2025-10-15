#include <stdio.h>

void display(int arr[], int n){
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void merge(int arr[], int low, int mid, int high){
    int n = high - low + 1;
    int temp[n];
    int i = low, j = mid+1, k = 0;
    while(i <= mid && j <= high){
        if(arr[i] <= arr[j]){
            temp[k++] = arr[i++];
        }
        else{
            temp[k++] = arr[j++];
        }
    }
    while(i<=mid){
        temp[k++] = arr[i++];
    }
    while(j<=high){
        temp[k++] = arr[j++];
    }
    for(k=0; k<n; k++){
        arr[low+k] = temp[k];
    }
}

void mergeSort(int arr[], int low, int high){
    if(low < high){
        int mid = (low + high)/2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);
        merge(arr, low, mid, high);
    }
}

int isDuplicate(int arr[], int n){
    for(int i=0; i < n-1; i++){
        if(arr[i] == arr[i+1]){
            return 1;
        }
    }
    return 0;
}

int main(){
    int n = 8;
    int arr[] = {1, 2, 5, 1, 5, 2, 8, 9};
    mergeSort(arr, 0, n-1);
    display(arr, n);
    if(isDuplicate(arr, n)){
        printf("Yes\n");
    }
    else{
        printf("No\n");
    }
    return 0;
}
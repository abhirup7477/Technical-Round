#include <stdio.h>

void display(int arr[], int low, int high){
    printf("Array: ");
    for(int i=low; i<=high; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void swap(int *a, int *b){
    // printf("Before swap: %d\t%d\n", *a, *b);
    int temp = *a;
    *a = *b;
    *b = temp;
    // printf("After swap: %d\t%d\n", *a, *b);
}

void quickSort(int arr[], int low, int high){
    // printf("\nlow = %d\thigh = %d\n", low, high);

    int pivot = arr[low];
    int i = low+1, j = high;

    while(i <= j){
        // printf("i = %d\tj = %d\n", i, j);
        while(pivot >= arr[i]){
            i++;
        }
        while(pivot < arr[j]){
            j--;
        }
        if(i <= j){
            swap(&arr[i], &arr[j]);
            i++;
            j--;
        }
    }

    if(low != j)
        swap(&arr[low], &arr[j]);
    // display(arr, low, high);

    if(low < j-1){
        quickSort(arr, low, j-1);
    }

    if(i < high){
        quickSort(arr, i, high);
    }
}

void main(){
    int arr[] = {3, 8, 2, 5, 1, 12, 1, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n-1);
    display(arr, 0, n-1);
}
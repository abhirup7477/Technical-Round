#include <stdio.h>

void display(int arr[], int n){
    printf("Array: ");
    for(int i=0; i<n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[],int n, int index){
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int largest = index;

    if(left < n && arr[left] > arr[largest]){
        largest = left;
    }
    if(right < n && arr[right] > arr[largest]){
        largest = right;
    }

    if(index != largest){
        swap(&arr[index], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void deleteHeap(int arr[], int index){
    swap(&arr[0], &arr[index]);
    heapify(arr, index, 0);
}

void heapSort(int arr[], int n){
    for(int i = n/2-1; i >= 0; i--){
        heapify(arr, n, i);
    }

    for(int i = n-1; i >= 0; i--){
        deleteHeap(arr, i);
    }
}

void main(){
    int sample[] = {4, 10, 3, 5, 1};
    int n = sizeof(sample)/sizeof(int);

    heapSort(sample, n);
    display(sample, n);
}
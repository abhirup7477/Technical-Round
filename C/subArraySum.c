#include <stdio.h>
#include <limits.h>

int main(){
    int n = 9;
    int arr[] = {2, 3, -4, 1, -5, 9, 2, 2, -8, -50};

    int i = 0;
    int maxSum = INT_MIN;
    int sum = 0;
    int start = -1, end = -1, temp = -1;
    for(i=0; i<n; i++){
        if(temp == -1){
            temp = i;
        }
        sum += arr[i];
        if(sum < 0){
            sum = 0;
            temp = -1;
        }
        else if(sum > maxSum){
            maxSum  = sum;
            start = temp;
            end = i;
        }
    }
    printf("Start = %d  End = %d  Max-Sum = %d\n", start, end, maxSum);

    return 0;
}
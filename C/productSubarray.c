#include <stdio.h>
#include <limits.h>

int max(int a, int b){
    if(a > b)
        return a;
    return b;
}

int main(){
    int n = 11;
    int arr[] = {2, 3, -4, -1, 0, 9, -2, 4, 2, -3, -5};
    int pre = 1, suff = 1;
    int maxi = INT_MIN;
    for(int i=0; i < n; i++){
        if(pre == 0) pre = 1;
        if(suff == 0) suff = 1;
        pre *= arr[i];
        suff *= arr[n-i-1];
        maxi = max(maxi, max(pre, suff));
    }
    printf("max product = %d\n", maxi);
}
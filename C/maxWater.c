#include <stdio.h>

int max(int a, int b){
    if(a>b)
        return a;
    return b;
}

int min(int a, int b){
    return a < b? a : b;
}

int main(){
    int n = 9;
    int height[] = {1,8,6,2,5,4,8,3,7};

    //Brute Force Approach
    // int area = 0;
    // for(int i=0; i < n; i++){
    //     for(int j = i+1; j < n; j++){
    //         int h = min(height[i], height[j]);
    //         int temp = h * (j - i);
    //         area = max(area, temp);
    //     }
    // }
    // printf("Max water : %d\n", area);


    int area = 0;
    int left = 0, right = n-1;
    while(left < right){
        int h = min(height[left], height[right]);
        int temp = h * (right - left);
        area = max(area, temp);

        if(height[left+1]-height[left] > height[right-1]-height[right]){
            left++;
        }
        else{
            right--;
        }
    }
    printf("Max water : %d\n", area);
    return 0;
}
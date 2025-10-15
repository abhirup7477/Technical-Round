/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>

int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int product = 1, count = 0;
    for(int i=0; i<numsSize; i++){
        if(nums[i] != 0){
            product *= nums[i];
        }
        else{
            count++;
        }
    }
    *returnSize = numsSize;
    int *ans = (int*) malloc((*returnSize) * sizeof(int));
    for(int i=0; i<*returnSize; i++){
        if(count > 1){
            ans[i] = 0;
        }
        else if(count == 0){
            ans[i] = product / nums[i];
        }
        else{
            if(nums[i] == 0){
                ans[i] = product;
            }
            else{
                ans[i] = 0;
            }
        }
    }
    return ans;
}

int main(){
    int numsSize = 5;
    int nums[] = {-1, 1, 0, -3, 3};
    int size;
    int *ans = productExceptSelf(nums, numsSize, &size);

    for(int i=0; i<size; i++){
        printf("%d ", ans[i]);
    }
    printf("\n");
}
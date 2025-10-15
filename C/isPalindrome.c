#include <stdio.h>
#include <stdbool.h>

int reverse(int n){
    int ans = 0;
    while(n){
        int r = n%10;
        ans = ans * 10 + r;
        n /= 10;
    }
    return ans;
}

bool isPalindrome(int n){
    int rev = reverse(n);
    printf("rev = %d\n",rev);
    if(n == rev)
        return true;
    return false;
}

int main(){
    int n = 121;
    if(isPalindrome(n))
        printf("Palindrome!\n");
    else
        printf("Not Palindrome!\n");
    return 0;
}
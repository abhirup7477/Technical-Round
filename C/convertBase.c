#include <stdio.h>
#include <math.h>

int binaryToDecimal(int n){
    int ans = 0, index = 0;
    while(n){
        int r = n % 10;
        ans = ans + r * pow(2, index++);
        n /= 10;
    }
    return ans;
}

int decimalToBinary(int n){
    int ans = 0, multiplier = 1;
    while(n){
        int r = n % 2;
        ans = multiplier * r + ans;
        n /= 2;
        multiplier *= 10;
    }
    return ans;
}

int main(){
    int decimal = 15;
    int binary = 111 ;
    printf("Binary of %d: %d\n",decimal, decimalToBinary(decimal));
    printf("Decimal of %d: %d\n",binary, binaryToDecimal(binary));
    return 0;
}
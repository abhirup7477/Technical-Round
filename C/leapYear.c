#include <stdio.h>
#include <stdbool.h>

bool isLeapYear(int n){
    if((n%100 == 0 && n%400 != 0) || (n%100 != 0 && n%4 != 0))
        return false;
    return true;
}

int main(){
    int n;
    printf("Input : ");
    scanf("%d",&n);
    if(isLeapYear(n))
        printf("Leap Year");
    else
        printf("Not Leap Year");
    
    return 0;
}
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define size 100

void input(char *str, int n){
    printf("Input-%d : ",n);
    fgets(str, size, stdin);
    str[strlen(str) - 1] = '\0';
}

bool isAnagram(char *str1, char *str2){
    int n1 = strlen(str1);
    int n2 = strlen(str2);
    if(n1 != n2)
        return false;
    
    int count[256] = {0};

    for(int i=0; i<n1; i++){
        count[(unsigned char)str1[i]]++;
    }

    for(int i=0; i<n2; i++){
        count[(unsigned char) str2[i]]--;
        if((unsigned char)str2[i] < 0)
            return false;
    }
    return true;
}

int main(){
    char str1[size], str2[size];
    input(str1, 1);
    input(str2, 2);
    if(isAnagram(str1, str2))
        printf("Anagram!");
    else
        printf("Not Anagram!");
    return 0;
}
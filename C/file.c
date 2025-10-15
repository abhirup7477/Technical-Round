#include <stdio.h>

int isVowel(char ch){
    if(ch=='a' || ch == 'e' || ch == 'i' || ch == 'o' || ch=='u')
        return 1;
    if(ch=='A' || ch == 'E' || ch == 'I' || ch == 'O' || ch=='U')
        return 1;
    return 0;
}

int main(){
    char str[100];
    FILE *fp;
    fp = fopen("abhi.txt", "a");
    if(fp == NULL)
        printf("File not found\n");
    else{
        fprintf(fp, "Hello Abhirup!\n");
        fputs("Append!", fp);
        fclose(fp);
    }

    return 0;
}
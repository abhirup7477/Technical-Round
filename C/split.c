#include <stdio.h>
#include <string.h>

void display(char **arr, int n){
    printf("\nArray of strings: \n");
    for(int i=0; i<n; i++){
        puts(arr[i]);
    }
}

void split_libraryFunction(char *str){
    char *ans[100];
    char *token = strtok(str, " ");
    int i = 0;
    while(token !=  NULL){
        ans[i++] = token;
        puts(token);
        token = strtok(NULL, " ");
    }
    
    display(ans, i);
}

int main(){
    char str[] = "I am pursuing BTECH from TMSL";
    puts(str);
    split_libraryFunction(str);
}
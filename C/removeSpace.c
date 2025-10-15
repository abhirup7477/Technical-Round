#include <stdio.h>

void removeSpace(char *str){
    int i = 0, j = 0;
    while(str[i] != '\0'){
        if(str[i] != ' '){
            str[j] = str[i];
            j++;
        }
        i++;
    }
    str[j] = '\0';
}

int main(){
    char str[] = " abh i rup  ";
    removeSpace(str);
    puts(str);
    return 0;
}
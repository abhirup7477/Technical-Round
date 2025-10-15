#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "stack.h"

#define size 100

int isnumber(char *token){
    if(isdigit(token[0]) || token[0] == '-' && isdigit(token[1]))
        return 1;
    return 0;
}

int isOperator(char *token){
    return (
        strcmp(token, "+") ||
        strcmp(token, "-") ||
        strcmp(token, "*") ||
        strcmp(token, "/") ||
        strcmp(token, "^")        
    );
}

int evaluate(int n1, int n2, char *operator){
    if(!strcmp(operator, "+"))
        return n2 + n1;
    if(!strcmp(operator, "-"))
        return n2 - n1;
    if(!strcmp(operator, "*"))
        return n2 * n1;
    if(!strcmp(operator, "/"))
        return n2 / n1;
    if(!strcmp(operator, "^"))
        return pow(n2, n1);
}

int postfixEvalute(char *postfix){
    stack *s = stack_init(size);
    char *token = strtok(postfix, " ");
    int n1, n2;
    while(token != NULL){
        if(isnumber(token)){
            push(s, atoi(token));
        }
        else if(isOperator(token)){
            display(s);
            pop(s, &n1);
            pop(s, &n2); 
            printf("operator = %s\n", token);
            printf("value = %d\n", evaluate(n1, n2, token));
            push(s, evaluate(n1, n2, token));
        }
        token = strtok(NULL, " ");
    }
    pop(s, &n1);
    return n1;
}

int main(){
    char postfix[size] = "10 20 + 5 *";
    printf("Answer = %d\n", postfixEvalute(postfix));
    
    char postfix1[size] = "6 2 3 + - 3 8 2 / + *";
    printf("Answer = %d\n", postfixEvalute(postfix1));

    return 0;
}
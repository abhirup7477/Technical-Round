#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define max 100

typedef struct Stack{
    int top, size;
    char *arr;
}stack;

stack* stack_init(int size){
    stack *s = (stack*) malloc(sizeof(stack));
    s->top = -1;
    s->size = size;
    s->arr = (char*) malloc(size * sizeof(char));
    return s;
}

int isEmpty(stack *s){
    return s->top == -1;
}

int isFull(stack* s){
    return s->top == s->size-1;
}

void push(stack *s, int key){
    s->arr[++s->top] = key;
}

char pop(stack *s){
    return s->arr[s->top--];
}

char peek(stack *s){
    return s->arr[s->top];
}

void display(stack *s){
    printf("Stack: ");
    for(int i=0; i<=s->top; i++)
        printf("%c ", s->arr[i]);
    printf("\n");
}

int isOperator(char ch){
    return (
        ch == '/' ||
        ch == '*' ||
        ch == '+' ||
        ch == '-' ||
        ch == '^'
    );
}

int precedence(char ch){
    if(ch == '^') return 3;
    if(ch == '*' || ch == '/') return 2;
    if(ch == '+' || ch == '-') return 1;
    return 0;
}

void infixToPostfix(char *infix, char *postfix){
    stack *s = stack_init(max);
    int i, j;
    for(i=0, j=0; i < strlen(infix); i++){
        char ch = infix[i];
        if(ch == ' ') continue;

        if(isdigit(ch)){
            while(isdigit(infix[i])){
                postfix[j++] = infix[i++];
            }
            i--;
            postfix[j++] = ' ';
        }
        else if(ch == '('){
            push(s, ch);
        }
        else if(ch == ')'){
            while(!isEmpty(s) && peek(s) != '('){
                postfix[j++] = pop(s);
            }
            pop(s);
            postfix[j++] = ' ';
        }
        else if(isOperator(ch)){
            while(!isEmpty(s) && precedence(peek(s)) >= precedence(ch)){
                postfix[j++] = pop(s);
            }
            push(s, ch);
            postfix[j++] = ' ';
        }        
    }
    while(!isEmpty(s)){
        postfix[j++] = pop(s);
        postfix[j++] = ' ';
    }
    postfix[j] = '\0';
}

int main(){
    char infix[max] = "10 + (6 / 2) * (3 + 1)";
    char postfix[max];
    infixToPostfix(infix, postfix);
    puts(postfix);

    char infix1[max] = "100 * (2 + 12) / 14 - (3 + 5) * 2";
    char postfix1[max];
    infixToPostfix(infix1, postfix1);
    puts(postfix1);

    return 0;
}
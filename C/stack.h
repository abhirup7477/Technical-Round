#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Stack{
    int top, size;
    int *arr;
}stack;

stack* stack_init(int size){
    stack *s = (stack*) malloc(sizeof(stack));
    s->top = -1;
    s->size = size;
    s->arr = (int*) malloc(size * sizeof(int));
    return s;
}

bool isEmpty(stack *s){
    return s->top == -1;
}

bool isFull(stack *s){
    return s->top == s->size-1;
}

bool push(stack *s, int key){
    if(isFull(s)){
        return false;
    }
    s->arr[++s->top] = key;
    return true;
}

bool pop(stack *s, int *key){
    if(isEmpty(s)){
        return false;
    }
    *key = s->arr[s->top--];
    return true;
}

bool pick(stack *s, int *key){
    if(isEmpty(s))
        return false;
    *key = s->arr[s->top];
    return true;
}

int size(stack *s){
    int size = 0;
    for(int i=0; i <= s->top; i++)
        size++;
    return size;
}

void display(stack *s){
    if(isEmpty(s)){
        printf("Stack is empty!\n");
        return;
    }
    for(int i=0; i <= s->top; i++)
        printf("%d ", s->arr[i]);
    printf("\n");
}

#endif
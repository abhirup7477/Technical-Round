#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 50 

typedef struct Queue{
    int front;
    int rear;
    int size;
    char *arr;
}queue;

queue* initialize(int size){
    queue *q = (queue*) malloc(sizeof(queue));
    q->front = q->rear = -1;
    q->size = size;
    q->arr = (char*) malloc(size * sizeof(char));
}

int isFull(queue *q){
    return (q->front == q->rear+1) || (q->rear == q->size-1);
}

int isEmpty(queue *q){
    return q->front == -1;
}

int enqueue(queue *q, char key){
    if(isFull(q))
        return 0;
    if(isEmpty(q))
        q->front = q->rear = 0;
    else
        q->rear = (q->rear + 1) % q->size;
    q->arr[q->rear] = key;
    return 1;
}

int dequeue(queue *q, char *data){
    if(isEmpty(q))
        return 0;
    *data = q->arr[q->front];
    printf("front = %d\trear = %d\tdata = %c\n", q->front, q->rear, *data);
    if(q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front = (q->front+1) % q->size;
    return 1;
}

void display(queue *q){
    if(isEmpty(q))
        return;
    int i;
    for(i = q->front; i != q->rear; i = (i+1) % q->size){
        printf("%c", q->arr[i]);
    }
    printf("%c\n", q->arr[i]);
}

int length(queue *q){
    int len = 0;
    if(isEmpty(q))
        return 0;
    int i;
    for(i = q->front; i != q->rear; i = (i+1)%q->size)
        len++;
    len++;
    return len; 
}

void appendChar(char *str, char ch){
    int len = strlen(str);
    str[len] = ch;
    str[len + 1] = '\0';
}

char* removeOuterParenthesis(char *str){
    queue* q = initialize(MAX);
    char *result = (char*) malloc(MAX * sizeof(char));
    strcpy(result, "");
    printf("result = %s\n", result);

    int len = strlen(str);
    printf("len = %d\n", len);
    int count = 0;
    for(int i=0; i<len; i++){
        char c = str[i];
        enqueue(q, c);

        if(c == '('){
            count++;
        }
        else if (c == ')'){
            count--;
        }
        printf("Stack1 = %d => ", i);
        display(q);

        if(count == 0){
            char ch;
            dequeue(q, &ch);
            printf("ch1 = %c\n", ch);
            while(length(q) > 1){
                dequeue(q, &ch);
                printf("ch2 = %c\n", ch);
                appendChar(result, ch);
                printf("result = %s\n", result);
            }
            dequeue(q, &ch);
            printf("ch3 = %c\n", ch);
        }
    }
    return result;
}


int main(){
    char str[] = "()(()())";
    // printf("Answer = %s\n", str);
    char *result = removeOuterParenthesis(str);
    printf("Answer = %s\n", result);
    // printf("Answer = %s\n", str);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Queue{
    int front, rear, size;
    int *arr;
}queue;

queue *queue_init(int size){
    queue *q = (queue*) malloc(size * sizeof(queue));
    q->front = q->rear = -1;
    q->size = size;
    q->arr = (int*) malloc(size * sizeof(int));

    return q;
}

bool isEmpty(queue* q){
    return q->front == -1;
}

bool isFull(queue* q){
    return (q->front == 0 && q->rear == q->size-1) || (q->front == q->rear+1);
}

bool enqueue(queue *q, int data){
    if(isFull(q)){
        return false;
    }
    if(isEmpty(q)){
        q->front = q->rear = 0;
    }
    else{
        q->rear = (q->rear + 1) % q->size;
    }
    q->arr[q->rear] = data;
    return true;
}

bool dequeue(queue* q, int *data){
    if(isEmpty(q)){
        return false;
    }
    *data = q->arr[q->front];
    if(q->front == q->rear){
        q->front = q->rear = -1;
    }
    else{
        q->front = (q->front + 1) % q->size;
    }
    return true;
}

void display(queue* q){
    if(isEmpty(q)){
        printf("Queue is empty!\n");
        return;
    }
    for(int i = q->front; i != q->rear; i = (i+1) % q->size){
        printf("%d ", q->arr[i]);
    }
    printf("%d\n", q->arr[q->rear]);
}
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}node;

node* createNode(int key){
    node *new = (node*) malloc(sizeof(node));
    new->data = key;
    new->next = NULL;
    return new;
}

node* insertEnd(node *head, int key){
    node *new = createNode(key);
    if(head == NULL){
        head = new;
    }
    else{
        node *ptr = head;
        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        ptr->next = new;
    }
    return head;
}

node* insertFront(node *head, int key){
    node *new = createNode(key);
    new->next = head;
    head = new;
    return head;
}

void display(node *head){
    if(head == NULL){
        printf("Empty!\n");
        return;
    }
    node *ptr = head;
    while(ptr->next != NULL){
        printf("%d => ", ptr->data);
        ptr = ptr->next;
    }
    printf("%d\n", ptr->data);
}

node* add(node *num1, node *num2){
    node *ptr1 = num1;
    node *ptr2 = num2;
    node *result = NULL;

    int carry = 0, sum = 0;
    while(ptr1 != NULL && ptr2 != NULL){
        sum = ptr1->data + ptr2->data + carry;
        result = insertFront(result, sum % 10);
        carry = sum / 10;   

        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    while(ptr1 != NULL){
        sum = ptr1->data + carry;
        result = insertFront(result, sum % 10);
        carry = sum / 10;

        ptr1 = ptr1->next;
    }
    while(ptr2 != NULL){
        sum = ptr2->data + carry;
        result = insertFront(result, sum % 10);
        carry = sum / 10;

        ptr2 = ptr2->next;
    }
    return result;
}

node *reverse(node *head){
    node *curr = head;
    node *prev = NULL;
    node *next = NULL;
    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    return head;
}

int main(){
    node *num1 = NULL;
    node * num2 = NULL;

    num1 = insertEnd(num1, 2);
    num1 = insertEnd(num1, 4);
    num1 = insertEnd(num1, 3);

    num2 = insertEnd(num2, 5);
    num2 = insertEnd(num2, 6);
    num2 = insertEnd(num2, 4);

    display(num1);
    display(num2);

    node* sum = add(num1, num2);
    sum = reverse(sum);
    display(sum);
}
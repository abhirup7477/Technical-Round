#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node{
    int value;
    struct Node *left;
    struct Node *right;
}node;

typedef struct Queue{
    struct Node* node;
    struct Queue *next;
}queue;

queue* createQueue(node *node){
    queue *new = (queue*) malloc(sizeof(queue));
    new->node = node;
    new->next = NULL;
    return new;
}

bool isEmpty(queue *front, queue *rear){
    return front == NULL && rear == NULL;
}

void enqueue(queue **front, queue **rear, node* node){
    queue *new = createQueue(node);
    if(isEmpty(*front, *rear)){
        *front = *rear = new;
    }
    else{
        (*rear)->next = new;
        *rear = new;
    }
}

node* dequeue(queue **front, queue **rear){
    if(isEmpty(*front, *rear)){
        printf("Queue is empty!\n");
        return NULL;
    }
    queue *temp = *front;
    node *key = (*front)->node;
    if(*front == *rear){
        *front = *rear = NULL;
    }
    else
        *front = (*front)->next;
    
    free(temp);
    return key;
}

void display(queue *front, queue *rear){
    queue *ptr = front;
    while(ptr != rear){
        printf("%d -> ", ptr->node->value);
        ptr = ptr->next;
    }
    printf("%d\n", rear->node->value);
}

node* createNode(int data){
    node *newNode = (node*) malloc(sizeof(node));
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->value = data;

    return newNode;
}

node* insert(node *root, int data){
    if(root == NULL){
        return createNode(data);
    }
    if(data < root->value){
        root->left = insert(root->left, data);
    }
    else{
        root->right = insert(root->right, data);
    }
}

// node* remove(node *root){

// }

void inorder(node *root){
    if(root != NULL){
        inorder(root->left);
        printf("%d ",root->value);
        inorder(root->right);
    }
}

void preorder(node *root){
    if(root != NULL){
        printf("%d ", root->value);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(node *root){
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->value);
    }
}

void levelOrder(node *root){
    queue *front = NULL, *rear = NULL;
    enqueue(&front, &rear, root);
    while(!isEmpty(front, rear)){
        node *ptr = dequeue(&front, &rear);
        printf("%d ", ptr->value);
        if(ptr->left != NULL)
            enqueue(&front, &rear, ptr->left);
        if(ptr->right != NULL)
            enqueue(&front, &rear, ptr->right);
    }
    printf("\n");
}

int size(node *root){
    if(root == NULL){
        return 0;
    }
    return size(root->left) + size(root->right) + 1;
}

int main(){
    node *root = NULL;
    root = insert(root, 10);
    root = insert(root, 4);
    root = insert(root, 8);
    root = insert(root, 20);
    root = insert(root, 15);

    printf("Pre order: ");
    preorder(root);
    printf("\n");
    
    printf("Inorder: ");
    inorder(root);
    printf("\n");
    
    printf("Post order: ");
    postorder(root);
    printf("\n");

    printf("Level order: ");
    levelOrder(root);
    printf("\n");


    printf("Size = %d\n", size(root));

}
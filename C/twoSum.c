#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define max 20

typedef struct Entry{
    int key;
    int index;
}entry;

typedef struct HashMap{
    int size;
    struct Entry **table;
}hash;

int hashFunction(hash *h, int key){
    return abs(key) % h->size;
}

hash* hash_init(int size){
    hash *h = (hash*) malloc(sizeof(hash));
    h->size = 20;
    h->table = (entry**) calloc(h->size, sizeof(entry*));
    return h;
}

entry* entry_init(int key, int index){
    entry *pair = (entry*) malloc(sizeof(entry));
    pair->key = key;
    pair->index = index;
    return pair;
}

void insert(hash *h, entry *pair){
    int index = hashFunction(h, pair->key);
    while(h->table[index] != NULL){
        index = (index + 1) % h->size;
    }
    h->table[index] = pair;
}

int containsKey(hash h, int key){
    int index = hashFunction(&h, key);
    int start = index;
    while(h.table[index] != NULL){
        if(h.table[index]->key == key){
            return h.table[index]->index;
        }
        index = (index + 1) % h.size;
        if(index == start){
            break;
        }
    }
    return -1;
}

void display(hash h){
    printf("Hash Table : \n");
    for(int i=0; i < h.size; i++){
        if(h.table[i] != NULL){
            printf("%d. %d => %d\n", i, h.table[i]->key, h.table[i]->index);
        }
    }
}

void twoSum(int arr[], int n, int target){
    hash *h = hash_init(max);
    int ans = 0;
    for(int i = 0; i < n; i++){
        int required = target - arr[i];
        int index = containsKey(*h, required);
        if(index != -1){
            printf("Pair-%d: %d and %d\n",++ans, arr[i], arr[index]);
        }
        entry *pair = entry_init(arr[i], i);
        insert(h, pair);
    }
    if(ans == 0)
        printf("No such pair exists!\n");
}

void main(){
    int arr[] = {4, 9, 5, 3, 1, 10, 13, 7, 6};
    int target = 16;
    int n = sizeof(arr) / sizeof(arr[0]);
    twoSum(arr, n, target);
}
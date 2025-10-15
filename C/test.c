#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int add(int a, int b){
    return (a + b);
}

int main(int argc, char const *argv[]) 
{
    // char str[] = "Abhi";
    // char *ptr = str;
    // int len = 0;
    // while(*ptr != '\0'){
    //     len++;
    //     ptr++;
    // }
    // printf("%d\n", len);
    

    
    // int a = 65;
    // int *ptr = &a;
    // void *ptr1 = (void*)ptr;
    // char *ptr2 = (char*)ptr1;
    // char* ptr3 = (char*)ptr;
    // printf("ptr = %d\t%p\t%u\n", ptr, ptr, ptr);
    // printf("ptr = %d\t%p\t%u\n", ptr1, ptr1, ptr1);
    // printf("ptr = %d\t%p\t%u\n", ptr2, ptr2, ptr2);
    // printf("ptr = %d\t%p\t%u\n", ptr3, ptr3, ptr3);

    // printf("%d\n", *ptr);
    // // printf("%d", *ptr1); //Error: deferencing void*
    // printf("%c\n", *ptr2);
    // printf("%c\n", *ptr3);



    // //2D dymanic array
    // int rows = 3, cols = 5;
    // int **arr = (int**) malloc(rows * sizeof(int*));
    // for(int i=0; i<rows; i++){
    //     arr[i] = (int*) malloc(cols * sizeof(int));
    // }

    // for(int i=0; i<rows; i++){
    //     for(int j=0; j<cols; j++){
    //         arr[i][j] = (i * cols + j) + 1;
    //     }
    // }

    // for(int i=0; i<rows; i++){
    //     for(int j=0; j<cols; j++){
    //         printf("%d\t", arr[i][j]);
    //     }
    //     printf("\n");
    // }

    // //Free memory in reverse order
    // for(int i=0; i<rows; i++){
    //     free(arr[i]);
    // }
    // free(arr);



    // int (*fptr) (int, int) = &add;
    // printf("Sum = %d\n", fptr(3, 7));



    // //strtok - like split based on delimeter
    // char str[] = "6 2 3 + - 3 8 2 / + *";
    // puts(str);
    // char *token = strtok(str, " ");
    // while(token != NULL){
    //     printf("%s ", token);
    //     token = strtok(NULL, " ");
    // }



    // printf("num = %d\n", atoi("-123ds"));



    // int *arr = (int*) malloc(10 * sizeof(int));
    // printf("Sizeof arr: %d\n", sizeof(arr));



    // char str[] = "abhirupbag";
    // int count[256] = {0};
    // int found = 0;
    // char *ch1 = NULL;
    // for(int i=0; str[i] != '\0'; i++){
    //     char token = (unsigned char)tolower(str[i]);
    //     count[token] += 1;
    //     if(!found && count[token] >= 1){
    //         ch1 = &str[i];
    //         found = 1;
    //     }
    // }

    // for(int i=0; i < 256; i++){
    //     printf("%d. %c => %d\n",i, (unsigned char)i, count[i]);
    // }

    // char *ch = NULL;
    // for(int i=0; str[i] != '\0'; i++){
    //     count[(unsigned char)str[i]] -= 1;
    //     if(count[(unsigned char)str[i]] == 0){
    //         ch = &str[i];
    //         break;
    //     }
    // }

    // printf("First repeating character: %c\n", *ch1);
    // printf("First non-repeating character: %c\n", *ch);


    int a = 4;
    int b = 6;
    char *ptr1 = (char*)&a, *ptr2 = (char*)&b;
    printf("ptr1 = %d\n", ptr1);
    printf("ptr2 = %d\n", ptr2);
    printf("ptr2 - ptr1 = %d\n", ptr2-ptr1);

    return 0;
}

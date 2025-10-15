#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

#define max 100

int isOperator(char ch){
    return (
        ch == '^' ||
        ch == '*' ||
        ch == '/' ||
        ch == '+' ||
        ch == '-'
    );
}

int precedence(char ch){
    if(ch == '^') return 3;
    if(ch == '*' || ch == '/') return 2;
    if(ch == '+' || ch == '-') return 1;
    return 0;
}

void displayOperand(int operand[], int top){
    printf("Operand: ");
    if(top == -1)
        printf("Empty!\n");
    for(int i=0; i<=top; i++)
        printf("%d ", operand[i]);
    printf("\n");
}

void displayOperator(char operator[], int top){
    printf("Operator: ");
    if(top == -1)
        printf("Empty!\n");
    for(int i=0; i<=top; i++)
        printf("%c ", operator[i]);
    printf("\n");
}

int evaluate(int operand[], int* operand_top, char op){
    int n1 = operand[(*operand_top)--];
    int n2 = operand[(*operand_top)--];

    switch(op){
        case '^':
            return (int)pow(n2, n1);
        case '*':
            return n2 * n1;
        case '/':
            return n2 / n1;
        case '+':
            return n2 + n1;
        case '-':
            return n2 - n1;
    }
}

int infixEvaluate(char *infix){
    int operand[max], operand_top = -1;
    char operator[max], operator_top = -1;
    int i=0;
    for(i=0; infix[i] != '\0'; i++){
        char ch = infix[i];
        if(ch == ' ') continue;

        if(ch == '('){
            operator[++operator_top] = ch;
        }
        else if(isdigit(ch)){
            int n = 0;
            while(isdigit(infix[i])){
                n = n * 10 + (infix[i++] - '0');
            }
            operand[++operand_top] = n;
            i--;
        }
        else if(ch == ')'){
            while(operator_top != -1 && operator[operator_top] != '('){
                int value = evaluate(operand, &operand_top, operator[operator_top--]);
                operand[++operand_top] = value;
            }
            operator_top--;
        }
        else if(isOperator(ch)){
            while(operator_top != -1 && precedence(operator[operator_top]) >= precedence(ch)){
                int value = evaluate(operand, &operand_top, operator[operator_top--]);
                operand[++operand_top] = value;
            }
            operator[++operator_top] = ch;
        }
    }

    while(operator_top != -1){
        int value = evaluate(operand, &operand_top, operator[operator_top--]);
        operand[++operand_top] = value;
    }
    return operand[operand_top];
}

int main(){
    char infix[] = "10 + (6 / 2) * (3 + 1)";
    printf("Answre = %d\n", infixEvaluate(infix));
    printf("\n");
    
    char infix1[] = "100 * (2 + 12) / 14 - (3 + 5) * 2";
    printf("Answre = %d\n", infixEvaluate(infix1));
    
    return 0;
}
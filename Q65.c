/*Problem: Convert an infix expression to postfix notation using stack.

Input:
- Single line: infix expression (operands are single characters)

Output:
- Print the postfix expression

Example:
Input:
A+B*C

Output:
ABC*+

Explanation:
Operator precedence: * > +
Use stack to handle operator precedence and associativity*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char data;
    struct node* next;
} node;

node* push(node* top, char c) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = c;
    newNode->next = top;
    return newNode;
}

node* pop(node* top, char* c) {
    *c = top->data;
    node* temp = top;
    top = top->next;
    free(temp);
    return top;
}

char peek(node* top) {
    return top->data;
}

int precedence(char op) {
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

int isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int main() {
    char expr[100];
    scanf("%s", expr);
    int len = strlen(expr);
    node* top = NULL;
    char c;

    for (int i = 0; i < len; i++) {
        char ch = expr[i];
        if (!isOperator(ch) && ch != '(' && ch != ')') {
            printf("%c", ch);
        } else if (ch == '(') {
            top = push(top, ch);
        } else if (ch == ')') {
            while (top != NULL && peek(top) != '(') {
                top = pop(top, &c);
                printf("%c", c);
            }
            if (top != NULL) top = pop(top, &c);
        } else {
            while (top != NULL && precedence(peek(top)) >= precedence(ch)) {
                top = pop(top, &c);
                printf("%c", c);
            }
            top = push(top, ch);
        }
    }

    while (top != NULL) {
        top = pop(top, &c);
        printf("%c", c);
    }
    printf("\n");
    return 0;
}
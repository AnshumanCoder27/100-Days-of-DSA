/*Problem: Implement push and pop operations on a stack and verify stack operations.

Input:
- First line: integer n
- Second line: n integers to push
- Third line: integer m (number of pops)

Output:
- Print remaining stack elements from top to bottom

Example:
Input:
5
10 20 30 40 50
2

Output:
30 20 10*/
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

node *top = NULL;

void push(int val) {
    node *t = (node*)malloc(sizeof(node));
    t->data = val;
    t->next = top;
    top = t;
}

void pop() {
    if (top == NULL) return;
    node *t = top;
    top = top->next;
    free(t);
}

int main() {
    int n, m, val;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        push(val);
    }

    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        pop();
    }

    node *t = top;
    int first = 1;
    while (t != NULL) {
        if (!first) printf(" ");
        printf("%d", t->data);
        t = t->next;
        first = 0;
    }
    printf("\n");

    return 0;
}
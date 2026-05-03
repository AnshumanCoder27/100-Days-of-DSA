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
#include <string.h>
#include <ctype.h>

#define MAX 100

char stk[MAX];
int top = -1;

void push(char c) { stk[++top] = c; }
char pop() { return stk[top--]; }
char peek() { return stk[top]; }
int empty() { return top == -1; }

int prec(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

int main() {
    char exp[MAX], res[MAX];
    int j = 0;
    scanf("%s", exp);

    for (int i = 0; i < strlen(exp); i++) {
        char c = exp[i];

        if (isalnum(c)) {
            res[j++] = c;
        } else if (c == '(') {
            push(c);
        } else if (c == ')') {
            while (!empty() && peek() != '(')
                res[j++] = pop();
            pop();
        } else {
            while (!empty() && prec(peek()) >= prec(c) && peek() != '(')
                res[j++] = pop();
            push(c);
        }
    }

    while (!empty())
        res[j++] = pop();

    res[j] = '\0';
    printf("%s\n", res);
    return 0;
}
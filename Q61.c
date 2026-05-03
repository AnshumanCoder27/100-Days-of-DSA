/*Problem: Implement a stack data structure using an array with the following operations: push, pop, and display.

Input:
- First line: integer n (number of operations)
- Next n lines: operation type and value (if applicable)
  - 1 value: push value
  - 2: pop
  - 3: display

Output:
- For display: print stack elements from top to bottom
- For pop: print popped element or 'Stack Underflow'

Example:
Input:
5
1 10
1 20
3
2
3

Output:
20 10
20
10*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    int *arr = malloc(n * sizeof(int));
    int top = -1;
    while (n--) {
        int op;
        scanf("%d", &op);
        if (op == 1) {
            int val;
            scanf("%d", &val);
            arr[++top] = val;
        } else if (op == 2) {
            if (top == -1) printf("Stack Underflow\n");
            else printf("%d\n", arr[top--]);
        } else {
            for (int i = top; i >= 0; i--)
                printf("%d ", arr[i]);
            printf("\n");
        }
    }
    free(arr);
    return 0;
}
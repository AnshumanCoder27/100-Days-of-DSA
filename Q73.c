/*Problem Statement:
Implement a Priority Queue using an array. An element with smaller value has higher priority.

Supported Operations:
- insert x
- delete
- peek

Input Format:
- First line contains integer N
- Next N lines contain operations

Output Format:
- Print the deleted or peeked element
- Print -1 if the queue is empty

Example:
Input:
5
insert 30
insert 10
insert 20
delete
peek

Output:
10
20*/
#include <stdio.h>
#include <string.h>

int a[1000];
int size = 0;

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        char op[10];
        scanf("%s", op);

        if (strcmp(op, "insert") == 0) {
            int x;
            scanf("%d", &x);
            a[size] = x;
            size++;
            for (int j = 0; j < size - 1; j++) {
                for (int k = j + 1; k < size; k++) {
                    if (a[j] > a[k]) {
                        int t = a[j];
                        a[j] = a[k];
                        a[k] = t;
                    }
                }
            }
        } else if (strcmp(op, "delete") == 0) {
            if (size == 0) {
                printf("-1\n");
            } else {
                printf("%d\n", a[0]);
                for (int j = 0; j < size - 1; j++) {
                    a[j] = a[j + 1];
                }
                size--;
            }
        } else if (strcmp(op, "peek") == 0) {
            if (size == 0) {
                printf("-1\n");
            } else {
                printf("%d\n", a[0]);
            }
        }
    }

    return 0;
}
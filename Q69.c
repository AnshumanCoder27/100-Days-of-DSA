/*Problem: Queue Using Array - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of elements)
- Second line: n space-separated integers

Output:
- Print queue elements from front to rear, space-separated

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50

Explanation:
Use array and front/rear pointers. Enqueue inserts at rear, dequeue removes from front. Display from front to rear.*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

void enqueue(int val) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = val;
    n->next = NULL;
    if (rear == NULL) {
        front = rear = n;
    } else {
        rear->next = n;
        rear = n;
    }
}

void display() {
    struct Node* t = front;
    while (t != NULL) {
        if (t->next == NULL)
            printf("%d", t->data);
        else
            printf("%d ", t->data);
        t = t->next;
    }
    printf("\n");
}

int main() {
    int n, val;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        enqueue(val);
    }
    display();
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int val) {
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = val;
    n->next = NULL;
    if (rear == NULL) {
        front = rear = n;
    } else {
        rear->next = n;
        rear = n;
    }
}

int dequeue() {
    if (front == NULL)
        return -1;
    int val = front->data;
    struct node *tmp = front;
    front = front->next;
    if (front == NULL)
        rear = NULL;
    free(tmp);
    return val;
}

int main() {
    int n;
    scanf("%d", &n);
    char op[20];
    for (int i = 0; i < n; i++) {
        scanf("%s", op);
        if (strcmp(op, "enqueue") == 0) {
            int val;
            scanf("%d", &val);
            enqueue(val);
        } else if (strcmp(op, "dequeue") == 0) {
            printf("%d\n", dequeue());
        }
    }
    return 0;
}

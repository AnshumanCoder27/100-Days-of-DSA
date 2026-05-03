#include <stdio.h>

int queue[1000];
int stack[1000];
int qfront = 0, qrear = 0;
int top = -1;

void enqueue(int val) {
    queue[qrear++] = val;
}

int dequeue() {
    return queue[qfront++];
}

void push(int val) {
    stack[++top] = val;
}

int pop() {
    return stack[top--];
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        enqueue(val);
    }
    while (qfront < qrear)
        push(dequeue());
    while (top >= 0)
        printf("%d ", pop());
    printf("\n");
    return 0;
}

/*Problem: Deque (Double-Ended Queue)

A Deque is a linear data structure that allows insertion and deletion of elements from both the front and the rear. It provides more flexibility than a standard queue or stack.

Common Operations:
1. push_front(value): Insert an element at the front of the deque.
2. push_back(value): Insert an element at the rear of the deque.
3. pop_front(): Remove an element from the front of the deque.
4. pop_back(): Remove an element from the rear of the deque.
5. front(): Return the front element of the deque.
6. back(): Return the rear element of the deque.
7. empty(): Check whether the deque is empty.
8. size(): Return the number of elements in the deque.

Additional Operations:
- clear(): Remove all elements from the deque.
- erase(): Remove one or more elements from the deque.
- swap(): Swap contents of two deques.
- emplace_front(): Insert an element at the front without copying.
- emplace_back(): Insert an element at the rear without copying.
- resize(): Change the size of the deque.
- assign(): Replace elements with new values.
- reverse(): Reverse the order of elements.
- sort(): Sort the elements in ascending order.

Time Complexity:
- push_front, push_back, pop_front, pop_back, front, back, empty, size: O(1)
- clear, erase, resize, assign, reverse: O(n)
- sort: O(n log n)

Input:
- Sequence of deque operations with values (if applicable)

Output:
- Results of operations such as front, back, size, or the final state of the deque after all operations*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10000

int dq[MAX];
int front = MAX / 2, rear = MAX / 2;

int empty() { return front == rear; }
int size() { return rear - front; }

void push_front(int val) { dq[--front] = val; }
void push_back(int val) { dq[rear++] = val; }
void pop_front() { if (!empty()) front++; }
void pop_back() { if (!empty()) rear--; }
int get_front() { return dq[front]; }
int get_back() { return dq[rear - 1]; }

void clear() { front = rear = MAX / 2; }

void reverse_dq() {
    int l = front, r = rear - 1;
    while (l < r) { int t = dq[l]; dq[l++] = dq[r]; dq[r--] = t; }
}

void sort_dq() {
    int n = size();
    for (int i = 0; i < n - 1; i++)
        for (int j = front; j < rear - i - 1; j++)
            if (dq[j] > dq[j + 1]) { int t = dq[j]; dq[j] = dq[j + 1]; dq[j + 1] = t; }
}

void erase(int idx) {
    if (idx < 0 || idx >= size()) return;
    for (int i = front + idx; i < rear - 1; i++) dq[i] = dq[i + 1];
    rear--;
}

void resize_dq(int sz) {
    while (size() < sz) push_back(0);
    while (size() > sz) pop_back();
}

void assign(int n, int val) {
    clear();
    for (int i = 0; i < n; i++) push_back(val);
}

int main() {
    int q;
    scanf("%d", &q);

    while (q--) {
        char op[20];
        scanf("%s", op);

        if (!strcmp(op, "push_front")) { int v; scanf("%d", &v); push_front(v); }
        else if (!strcmp(op, "push_back")) { int v; scanf("%d", &v); push_back(v); }
        else if (!strcmp(op, "pop_front")) pop_front();
        else if (!strcmp(op, "pop_back")) pop_back();
        else if (!strcmp(op, "front")) { if (!empty()) printf("%d\n", get_front()); }
        else if (!strcmp(op, "back")) { if (!empty()) printf("%d\n", get_back()); }
        else if (!strcmp(op, "empty")) printf("%s\n", empty() ? "true" : "false");
        else if (!strcmp(op, "size")) printf("%d\n", size());
        else if (!strcmp(op, "clear")) clear();
        else if (!strcmp(op, "erase")) { int i; scanf("%d", &i); erase(i); }
        else if (!strcmp(op, "emplace_front")) { int v; scanf("%d", &v); push_front(v); }
        else if (!strcmp(op, "emplace_back")) { int v; scanf("%d", &v); push_back(v); }
        else if (!strcmp(op, "resize")) { int s; scanf("%d", &s); resize_dq(s); }
        else if (!strcmp(op, "assign")) { int n, v; scanf("%d %d", &n, &v); assign(n, v); }
        else if (!strcmp(op, "reverse")) reverse_dq();
        else if (!strcmp(op, "sort")) sort_dq();
    }

    printf("Deque: ");
    for (int i = front; i < rear; i++) printf("%d ", dq[i]);
    printf("\n");

    return 0;
}
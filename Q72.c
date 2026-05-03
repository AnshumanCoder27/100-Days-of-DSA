/*
Topics
premium lock icon
Companies
Design your implementation of the circular double-ended queue (deque).

Implement the MyCircularDeque class:

MyCircularDeque(int k) Initializes the deque with a maximum size of k.
boolean insertFront() Adds an item at the front of Deque. Returns true if the operation is successful, or false otherwise.
boolean insertLast() Adds an item at the rear of Deque. Returns true if the operation is successful, or false otherwise.
boolean deleteFront() Deletes an item from the front of Deque. Returns true if the operation is successful, or false otherwise.
boolean deleteLast() Deletes an item from the rear of Deque. Returns true if the operation is successful, or false otherwise.
int getFront() Returns the front item from the Deque. Returns -1 if the deque is empty.
int getRear() Returns the last item from Deque. Returns -1 if the deque is empty.
boolean isEmpty() Returns true if the deque is empty, or false otherwise.
boolean isFull() Returns true if the deque is full, or false otherwise.
 

Example 1:

Input
["MyCircularDeque", "insertLast", "insertLast", "insertFront", "insertFront", "getRear", "isFull", "deleteLast", "insertFront", "getFront"]
[[3], [1], [2], [3], [4], [], [], [], [4], []]
Output
[null, true, true, true, false, 2, true, true, true, 4]

Explanation
MyCircularDeque myCircularDeque = new MyCircularDeque(3);
myCircularDeque.insertLast(1);  // return True
myCircularDeque.insertLast(2);  // return True
myCircularDeque.insertFront(3); // return True
myCircularDeque.insertFront(4); // return False, the queue is full.
myCircularDeque.getRear();      // return 2
myCircularDeque.isFull();       // return True
myCircularDeque.deleteLast();   // return True
myCircularDeque.insertFront(4); // return True
myCircularDeque.getFront();     // return 4
 */
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *arr;
    int f, r, sz, cap;
} MyCircularDeque;

MyCircularDeque* myCircularDequeCreate(int k) {
    MyCircularDeque *q = malloc(sizeof(MyCircularDeque));
    q->arr = malloc(k * sizeof(int));
    q->f = 0;
    q->r = 0;
    q->sz = 0;
    q->cap = k;
    return q;
}

bool myCircularDequeInsertFront(MyCircularDeque* obj, int value) {
    if (obj->sz == obj->cap) return false;
    obj->f = (obj->f - 1 + obj->cap) % obj->cap;
    obj->arr[obj->f] = value;
    obj->sz++;
    return true;
}

bool myCircularDequeInsertLast(MyCircularDeque* obj, int value) {
    if (obj->sz == obj->cap) return false;
    obj->arr[obj->r] = value;
    obj->r = (obj->r + 1) % obj->cap;
    obj->sz++;
    return true;
}

bool myCircularDequeDeleteFront(MyCircularDeque* obj) {
    if (obj->sz == 0) return false;
    obj->f = (obj->f + 1) % obj->cap;
    obj->sz--;
    return true;
}

bool myCircularDequeDeleteLast(MyCircularDeque* obj) {
    if (obj->sz == 0) return false;
    obj->r = (obj->r - 1 + obj->cap) % obj->cap;
    obj->sz--;
    return true;
}

int myCircularDequeGetFront(MyCircularDeque* obj) {
    if (obj->sz == 0) return -1;
    return obj->arr[obj->f];
}

int myCircularDequeGetRear(MyCircularDeque* obj) {
    if (obj->sz == 0) return -1;
    return obj->arr[(obj->r - 1 + obj->cap) % obj->cap];
}

bool myCircularDequeIsEmpty(MyCircularDeque* obj) {
    return obj->sz == 0;
}

bool myCircularDequeIsFull(MyCircularDeque* obj) {
    return obj->sz == obj->cap;
}

void myCircularDequeFree(MyCircularDeque* obj) {
    free(obj->arr);
    free(obj);
}
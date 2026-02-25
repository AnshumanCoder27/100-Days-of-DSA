/*Problem: Delete First Occurrence of a Key - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer key

Output:
- Print the linked list elements after deletion, space-separated

Example:
Input:
5
10 20 30 40 50
30

Output:
10 20 40 50

Explanation:
Traverse list, find first node with key, remove it by adjusting previous node's next pointer.*/
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

node *delete(node *head, int key) {
    node *p, *q;
    if (head != NULL && head->data == key) {
        p = head;
        head = head->next;
        free(p);
        return head;
    }
    q = head;
    while (q != NULL && q->next != NULL) {
        if (q->next->data == key) {
            p = q->next;
            q->next = p->next;
            free(p);
            return head;
        }
        q = q->next;
    }
    return head;
}

int main() {
    int n = 0;
    scanf("%d", &n);
    node *head = NULL;
    head = (node *)malloc(sizeof(node));
    scanf("%d", &head->data);
    head->next = NULL;
    node *temp = NULL;
    temp = head;
    for (int i = 1; i < n; i++) {
        temp->next = (node *)malloc(sizeof(node));
        temp = temp->next;
        scanf("%d", &temp->data);
        temp->next = NULL;
    }
    int key;
    scanf("%d", &key);
    head = delete(head, key);
    temp = head;
    while (temp != NULL) {
        if (temp->next == NULL) printf("%d", temp->data);
        else printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
    return 0;
}
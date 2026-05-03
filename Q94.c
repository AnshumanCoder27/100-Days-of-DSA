/*Problem: Level Order Traversal

Implement the solution for this problem.

Input:
- Input specifications

Output:
- Output specifications*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node *left, *right;
} Node;

Node *newNode(int val) {
    Node *n = malloc(sizeof(Node));
    n->val = val;
    n->left = n->right = NULL;
    return n;
}

void levelOrder(Node *root) {
    if (!root) return;

    Node *q[1024];
    int front = 0, back = 0;
    q[back++] = root;

    while (front < back) {
        int size = back - front;
        for (int i = 0; i < size; i++) {
            Node *node = q[front++];
            printf("%d ", node->val);
            if (node->left)  q[back++] = node->left;
            if (node->right) q[back++] = node->right;
        }
        printf("\n");
    }
}

int main() {
    Node *root = newNode(1);
    root->left  = newNode(2);
    root->right = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);
    root->right->left  = newNode(6);
    root->right->right = newNode(7);

    levelOrder(root);
    return 0;
}
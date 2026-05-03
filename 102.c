/*Problem Statement:
Perform zigzag (spiral) level order traversal of a binary tree. Alternate levels should be traversed left-to-right and right-to-left.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)

Output Format:
- Print traversal in zigzag order

Example:
Input:
7
1 2 3 4 5 6 7

Output:
1 3 2 4 5 6 7

Explanation:
Level 1 is printed left-to-right, level 2 right-to-left, and so on.*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node *left, *right;
} Node;

Node* newNode(int val) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->val = val;
    n->left = n->right = NULL;
    return n;
}

Node* build(int* arr, int n) {
    if (n == 0) return NULL;
    Node** q = (Node**)malloc(n * sizeof(Node*));
    int front = 0, back = 0;
    Node* root = newNode(arr[0]);
    q[back++] = root;
    int i = 1;
    while (i < n) {
        Node* cur = q[front++];
        if (i < n && arr[i] != -1) {
            cur->left = newNode(arr[i]);
            q[back++] = cur->left;
        }
        i++;
        if (i < n && arr[i] != -1) {
            cur->right = newNode(arr[i]);
            q[back++] = cur->right;
        }
        i++;
    }
    free(q);
    return root;
}

void zigzag(Node* root) {
    if (!root) return;

    Node** q = (Node**)malloc(1000 * sizeof(Node*));
    int front = 0, back = 0;
    q[back++] = root;
    int ltr = 1;

    int* out = (int*)malloc(1000 * sizeof(int));
    int first = 1;

    while (front < back) {
        int size = back - front;
        int* level = (int*)malloc(size * sizeof(int));

        for (int i = 0; i < size; i++) {
            Node* cur = q[front++];
            level[i] = cur->val;
            if (cur->left)  q[back++] = cur->left;
            if (cur->right) q[back++] = cur->right;
        }

        for (int i = 0; i < size; i++) {
            int idx = ltr ? i : size - 1 - i;
            if (!first) printf(" ");
            printf("%d", level[idx]);
            first = 0;
        }
        ltr = !ltr;
        free(level);
    }
    printf("\n");
    free(q);
    free(out);
}

int main() {
    int n;
    scanf("%d", &n);
    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    Node* root = build(arr, n);
    zigzag(root);
    free(arr);
    return 0;
}
/*Problem Statement:
Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Tree.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 represents NULL)
- Third line contains two node values

Output Format:
- Print the LCA value

Example:
Input:
7
1 2 3 4 5 6 7
4 5

Output:
2*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int data) {
    struct Node* node = malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

struct Node* buildTree(int* arr, int n) {
    if (n == 0) return NULL;
    struct Node** nodes = malloc(n * sizeof(struct Node*));
    for (int i = 0; i < n; i++)
        nodes[i] = (arr[i] == -1) ? NULL : newNode(arr[i]);
    for (int i = 0; i < n; i++) {
        if (nodes[i]) {
            if (2*i+1 < n) nodes[i]->left  = nodes[2*i+1];
            if (2*i+2 < n) nodes[i]->right = nodes[2*i+2];
        }
    }
    struct Node* root = nodes[0];
    free(nodes);
    return root;
}

struct Node* lca(struct Node* root, int a, int b) {
    if (!root) return NULL;
    if (root->data == a || root->data == b) return root;
    struct Node* left  = lca(root->left,  a, b);
    struct Node* right = lca(root->right, a, b);
    if (left && right) return root;
    return left ? left : right;
}

int main() {
    int n;
    scanf("%d", &n);
    int* arr = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    int a, b;
    scanf("%d %d", &a, &b);
    struct Node* root = buildTree(arr, n);
    printf("%d\n", lca(root, a, b)->data);
    return 0;
}
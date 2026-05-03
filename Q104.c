/*Problem Statement:
Convert a binary tree into its mirror image by swapping left and right children at every node.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)

Output Format:
- Print inorder traversal of mirrored tree

Example:
Input:
7
1 2 3 4 5 6 7

Output:
7 3 6 1 5 2 4

Explanation:
Each node’s left and right children are swapped recursively.*/
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
        if (i < n && arr[i] != -1) { cur->left = newNode(arr[i]); q[back++] = cur->left; }
        i++;
        if (i < n && arr[i] != -1) { cur->right = newNode(arr[i]); q[back++] = cur->right; }
        i++;
    }
    free(q);
    return root;
}

void mirror(Node* root) {
    if (!root) return;
    Node* tmp = root->left;
    root->left = root->right;
    root->right = tmp;
    mirror(root->left);
    mirror(root->right);
}

int first = 1;
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    if (!first) printf(" ");
    printf("%d", root->val);
    first = 0;
    inorder(root->right);
}

int main() {
    int n;
    scanf("%d", &n);
    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    Node* root = build(arr, n);
    mirror(root);
    inorder(root);
    printf("\n");
    free(arr);
    return 0;
}
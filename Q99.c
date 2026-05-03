/*Problem Statement:
Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Search Tree.

Input Format:
- First line contains integer N
- Second line contains N space-separated integers
- Third line contains two node values

Output Format:
- Print the LCA value

Example:
Input:
7
6 2 8 0 4 7 9
2 8

Output:
6*/
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* newNode(int val) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

TreeNode* insert(TreeNode* root, int val) {
    if (!root) return newNode(val);
    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}

TreeNode* lca(TreeNode* root, int p, int q) {
    if (!root) return NULL;
    if (p < root->val && q < root->val)
        return lca(root->left, p, q);
    if (p > root->val && q > root->val)
        return lca(root->right, p, q);
    return root;
}

int main() {
    int n;
    scanf("%d", &n);

    TreeNode* root = NULL;
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        root = insert(root, val);
    }

    int p, q;
    scanf("%d %d", &p, &q);

    TreeNode* result = lca(root, p, q);
    printf("%d\n", result->val);

    return 0;
}
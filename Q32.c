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
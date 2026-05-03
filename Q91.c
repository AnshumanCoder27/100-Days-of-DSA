/*Problem Statement:
Construct a Binary Tree from the given level-order traversal.

Input Format:
- First line contains integer N
- Second line contains N space-separated integers (-1 represents NULL)

Output Format:
- Print inorder traversal of the constructed tree

Example:
Input:
7
1 2 3 4 5 -1 6

Output:
4 2 5 1 3 6*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int val) {
    struct Node* node = malloc(sizeof(struct Node));
    node->data = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct Node* buildTree(int nodes[], int n) {
    if (n == 0 || nodes[0] == -1) return NULL;

    struct Node* queue[1000];
    struct Node* root = newNode(nodes[0]);
    queue[0] = root;

    int front = 0, back = 1, i = 1;

    while (front < back && i < n) {
        struct Node* curr = queue[front++];

        // left child
        if (i < n) {
            if (nodes[i] != -1) {
                curr->left = newNode(nodes[i]);
                queue[back++] = curr->left;
            }
            i++;
        }

        // right child
        if (i < n) {
            if (nodes[i] != -1) {
                curr->right = newNode(nodes[i]);
                queue[back++] = curr->right;
            }
            i++;
        }
    }

    return root;
}

void inorder(struct Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    int n;
    scanf("%d", &n);

    int nodes[1000];
    for (int i = 0; i < n; i++)
        scanf("%d", &nodes[i]);

    struct Node* root = buildTree(nodes, n);
    inorder(root);

    return 0;
}
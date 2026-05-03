/*Problem Statement:
Perform inorder, preorder, and postorder traversals of a given binary tree.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 represents NULL)

Output Format:
- Print inorder, preorder, and postorder traversals

Example:
Input:
7
1 2 3 4 5 6 7

Output:
4 2 5 1 6 3 7
1 2 4 5 3 6 7
4 5 2 6 7 3 1*/
#include <stdio.h>
#include <stdlib.h>

int arr[100];
int left_child[100], right_child[100];
int n;

void build_tree() {
    for (int i = 0; i < n; i++) {
        left_child[i] = -1;
        right_child[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        int l = 2 * i + 1;
        int r = 2 * i + 2;

        if (l < n && arr[l] != -1)
            left_child[i] = l;
        if (r < n && arr[r] != -1)
            right_child[i] = r;
    }
}

void inorder(int i) {
    if (i == -1) return;
    inorder(left_child[i]);
    printf("%d ", arr[i]);
    inorder(right_child[i]);
}

void preorder(int i) {
    if (i == -1) return;
    printf("%d ", arr[i]);
    preorder(left_child[i]);
    preorder(right_child[i]);
}

void postorder(int i) {
    if (i == -1) return;
    postorder(left_child[i]);
    postorder(right_child[i]);
    printf("%d ", arr[i]);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    build_tree();

    inorder(0);   printf("\n");
    preorder(0);  printf("\n");
    postorder(0); printf("\n");

    return 0;
}
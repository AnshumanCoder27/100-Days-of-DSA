/*Problem Statement:
Construct a binary tree from given inorder and postorder traversal arrays.

Input Format:
- First line contains integer N
- Second line contains inorder traversal
- Third line contains postorder traversal

Output Format:
- Print preorder traversal of constructed tree

Example:
Input:
5
4 2 5 1 3
4 5 2 3 1

Output:
1 2 4 5 3

Explanation:
Postorder gives root at end, inorder divides left and right subtrees.*/
#include <stdio.h>

int in[100], post[100], n;

int find(int val, int start, int end) {
    for (int i = start; i <= end; i++)
        if (in[i] == val) return i;
    return -1;
}

void preorder(int inStart, int inEnd, int postEnd) {
    if (inStart > inEnd) return;
    
    int root = post[postEnd];
    printf("%d ", root);
    
    int pos = find(root, inStart, inEnd);
    int leftSize = pos - inStart;
    
    preorder(inStart, pos - 1, postEnd - (inEnd - pos) - 1);
    preorder(pos + 1, inEnd, postEnd - 1);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &in[i]);
    for (int i = 0; i < n; i++) scanf("%d", &post[i]);
    
    preorder(0, n - 1, n - 1);
    return 0;
}


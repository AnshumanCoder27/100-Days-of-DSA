/*Problem Statement:
Construct a binary tree from given preorder and inorder traversal arrays.

Input Format:
- First line contains integer N
- Second line contains preorder traversal
- Third line contains inorder traversal

Output Format:
- Print postorder traversal of constructed tree

Example:
Input:
5
1 2 4 5 3
4 2 5 1 3

Output:
4 5 2 3 1

Explanation:
Preorder identifies root, inorder splits left and right subtrees.*/
#include <stdio.h>

int pre[100], in[100], n;

void build(int preStart, int inStart, int inEnd) {
    if (inStart > inEnd) return;
    
    int root = pre[preStart];
    int i;
    for (i = inStart; i <= inEnd; i++)
        if (in[i] == root) break;
    
    int left = i - inStart;
    
    build(preStart + 1, inStart, i - 1);
    build(preStart + left + 1, i + 1, inEnd);
    
    printf("%d ", root);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &pre[i]);
    for (int i = 0; i < n; i++) scanf("%d", &in[i]);
    
    build(0, 0, n - 1);
    return 0;
}

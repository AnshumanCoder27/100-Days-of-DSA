/*Problem Statement:
Check whether a given binary tree is symmetric around its center.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)

Output Format:
- Print YES if symmetric, otherwise NO

Example:
Input:
7
1 2 2 3 4 4 3

Output:
YES

Explanation:
Left subtree is a mirror image of the right subtree.*/
#include <stdio.h>
#include <stdlib.h>

int arr[1000];
int n;

int check(int l, int r) {
    if (l >= n && r >= n) return 1;
    if (l >= n || r >= n) return 0;
    if (arr[l] == -1 && arr[r] == -1) return 1;
    if (arr[l] == -1 || arr[r] == -1) return 0;
    if (arr[l] != arr[r]) return 0;
    return check(2*l+1, 2*r+2) && check(2*l+2, 2*r+1);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    printf("%s\n", check(1, 2) ? "YES" : "NO");
    return 0;
}



/*Problem Statement:
Find the height (maximum depth) of a given binary tree.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 represents NULL)

Output Format:
- Print the height of the tree

Example:
Input:
7
1 2 3 4 5 -1 -1

Output:
3*/
#include <stdio.h>

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

int height(int i) {
    if (i == -1) return 0;

    int left_h = height(left_child[i]);
    int right_h = height(right_child[i]);

    if (left_h > right_h)
        return left_h + 1;
    else
        return right_h + 1;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    build_tree();

    printf("%d\n", height(0));

    return 0;
}
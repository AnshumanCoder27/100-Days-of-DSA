/*Problem Statement:
Print the nodes visible when the binary tree is viewed from the right side.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)

Output Format:
- Print right view nodes

Example:
Input:
7
1 2 3 4 5 -1 6

Output:
1 3 6

Explanation:
At each level, the rightmost node is visible from the right view.*/
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int arr[1000];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    
    int q[1000];
    int idx[1000];
    int front = 0, back = 0;
    
    if (arr[0] != -1) {
        q[back] = 0;
        idx[back++] = 0;
    }
    
    int first = 1;
    while (front < back) {
        int size = back - front;
        int last = -1;
        
        for (int i = 0; i < size; i++) {
            int node = q[front];
            int ni = idx[front++];
            
            if (arr[ni] != -1)
                last = arr[ni];
            
            int l = 2 * node + 1;
            int r = 2 * node + 2;
            
            if (l < n && arr[l] != -1) { q[back] = l; idx[back++] = l; }
            if (r < n && arr[r] != -1) { q[back] = r; idx[back++] = r; }
        }
        
        if (last != -1) {
            if (!first) printf(" ");
            printf("%d", last);
            first = 0;
        }
    }
    printf("\n");
    return 0;
}
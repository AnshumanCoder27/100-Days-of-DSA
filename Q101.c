/*Problem Statement:
Given a binary tree, print its vertical order traversal. Nodes that lie on the same vertical line should be printed together from top to bottom and from left to right.

Input Format:
- First line contains integer N (number of nodes)
- Second line contains N space-separated integers representing level-order traversal (-1 indicates NULL)

Output Format:
- Print nodes column by column from leftmost to rightmost vertical line

Example:
Input:
7
1 2 3 4 5 6 7

Output:
4
2
1 5 6
3
7

Explanation:
Vertical lines are formed based on horizontal distance from root. Nodes sharing the same distance are printed together.*/
#include <stdio.h>
#include <stdlib.h>

int arr[100];
int hd[100];
int n;

struct Node {
    int val, left, right;
};

struct Node tree[100];
int built[100];

void build(int idx, int i) {
    if (i >= n || arr[i] == -1) return;
    tree[idx].val = arr[i];
    int l = 2*i+1, r = 2*i+2;
    if (l < n && arr[l] != -1) { tree[idx].left = l; build(l, l); }
    if (r < n && arr[r] != -1) { tree[idx].right = r; build(r, r); }
}

void bfs() {
    int q[100], d[100], f=0, b=0;
    q[b]=0; d[b]=0; b++;
    hd[0]=0;
    while (f<b) {
        int i=q[f], dist=d[f]; f++;
        hd[i]=dist;
        if (tree[i].left != -1) { q[b]=tree[i].left; d[b]=dist-1; b++; }
        if (tree[i].right != -1) { q[b]=tree[i].right; d[b]=dist+1; b++; }
    }
}

int main() {
    scanf("%d", &n);
    for (int i=0; i<n; i++) scanf("%d", &arr[i]);
    
    for (int i=0; i<n; i++) tree[i].left = tree[i].right = -1;
    build(0, 0);
    bfs();
    
    int mn=0, mx=0;
    for (int i=0; i<n; i++) {
        if (arr[i]==-1) continue;
        if (hd[i]<mn) mn=hd[i];
        if (hd[i]>mx) mx=hd[i];
    }
    
    for (int c=mn; c<=mx; c++) {
        int first=1;
        for (int i=0; i<n; i++) {
            if (arr[i]!=-1 && hd[i]==c) {
                if (!first) printf(" ");
                printf("%d", tree[i].val);
                first=0;
            }
        }
        printf("\n");
    }
    return 0;
}
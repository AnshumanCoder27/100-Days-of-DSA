/*Problem Statement
Given weighted undirected graph, compute total weight of Minimum Spanning Tree using Prim’s algorithm.

Input Format
n m
u v w
...

Output Format
Total weight of MST.

Sample Input
4 5
1 2 3
1 3 5
2 3 1
2 4 4
3 4 2

Sample Output
6

Explanation
One possible MST edges: (2-3), (3-4), (1-2)*/
#include <stdio.h>
#include <limits.h>

#define MAXN 1005

int adj[MAXN][MAXN];
int key[MAXN];
int inMST[MAXN];
int n, m;

int minKey() {
    int min = INT_MAX, idx = -1;
    for (int i = 1; i <= n; i++) {
        if (!inMST[i] && key[i] < min) {
            min = key[i];
            idx = i;
        }
    }
    return idx;
}

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            adj[i][j] = INT_MAX;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        adj[u][v] = w;
        adj[v][u] = w;
    }

    for (int i = 1; i <= n; i++) {
        key[i] = INT_MAX;
        inMST[i] = 0;
    }

    key[1] = 0;

    long long total = 0;

    for (int count = 0; count < n; count++) {
        int u = minKey();
        if (u == -1) break;
        inMST[u] = 1;
        total += key[u];

        for (int v = 1; v <= n; v++) {
            if (!inMST[v] && adj[u][v] != INT_MAX && adj[u][v] < key[v]) {
                key[v] = adj[u][v];
            }
        }
    }

    printf("%lld\n", total);
    return 0;
}

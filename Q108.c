/*Problem: Build a graph with n vertices and m edges using adjacency matrix representation.
The graph may be directed or undirected.

Input:
- n (vertices)
- m (edges)
- m pairs (u, v)

Output:
- n x n adjacency matrix*/
#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    int arr[n][n];
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            arr[i][j] = 0;
    
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        arr[u-1][v-1] = 1;
        arr[v-1][u-1] = 1; // remove this line for directed graph
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }
    
    return 0;
}
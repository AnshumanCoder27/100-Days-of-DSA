/*Problem: Build a graph with adjacency list representation. Use linked lists or dynamic arrays.

Input:
- n (vertices)
- m (edges)
- edges (u, v)

Output:
- List of adjacency lists for each vertex*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int **adj = malloc(n * sizeof(int *));
    int *size = malloc(n * sizeof(int));
    int *cap = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        adj[i] = malloc(2 * sizeof(int));
        size[i] = 0;
        cap[i] = 2;
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--; v--;

        if (size[u] == cap[u]) {
            cap[u] *= 2;
            adj[u] = realloc(adj[u], cap[u] * sizeof(int));
        }
        adj[u][size[u]++] = v;

        if (size[v] == cap[v]) {
            cap[v] *= 2;
            adj[v] = realloc(adj[v], cap[v] * sizeof(int));
        }
        adj[v][size[v]++] = u;
    }

    for (int i = 0; i < n; i++) {
        printf("%d: ", i + 1);
        for (int j = 0; j < size[i]; j++) {
            printf("%d ", adj[i][j] + 1);
        }
        printf("\n");
    }

    for (int i = 0; i < n; i++) free(adj[i]);
    free(adj);
    free(size);
    free(cap);

    return 0;
}
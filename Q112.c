/*Problem: Using DFS and parent tracking, detect if undirected graph has a cycle.

Output:
- YES or NO*/
#include <stdio.h>

int adj[100][100], visited[100];
int n, e;

int dfs(int node, int parent) {
    visited[node] = 1;
    for (int i = 0; i < n; i++) {
        if (adj[node][i]) {
            if (!visited[i]) {
                if (dfs(i, node)) return 1;
            } else if (i != parent) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    scanf("%d %d", &n, &e);
    for (int i = 0; i < e; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, -1)) {
                printf("YES\n");
                return 0;
            }
        }
    }
    printf("NO\n");
    return 0;
}
/*Problem: Detect cycle in directed graph using DFS and recursion stack.

Output:
- YES if cycle exists*/
#include <stdio.h>
#include <stdbool.h>

#define MAX 100

bool visited[MAX], recStack[MAX];
int adj[MAX][MAX], n;

bool dfs(int v) {
    visited[v] = true;
    recStack[v] = true;

    for (int i = 0; i < n; i++) {
        if (adj[v][i]) {
            if (!visited[i] && dfs(i)) return true;
            if (recStack[i]) return true;
        }
    }

    recStack[v] = false;
    return false;
}

int main() {
    int e, u, v;
    scanf("%d %d", &n, &e);
    while (e--) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
    }

    for (int i = 0; i < n; i++)
        if (!visited[i] && dfs(i)) { printf("YES"); return 0; }

    printf("NO");
}
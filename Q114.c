/*Problem: Print topological ordering of a Directed Acyclic Graph (DAG) using DFS.*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int stack[MAX];
int top = -1;

void dfs(int node, int n) {
    visited[node] = 1;
    for (int i = 0; i < n; i++) {
        if (adj[node][i] && !visited[i]) {
            dfs(i, n);
        }
    }
    stack[++top] = node;
}

int main() {
    int n, e, u, v;

    printf("Enter nodes and edges: ");
    scanf("%d %d", &n, &e);

    for (int i = 0; i < e; i++) {
        printf("Enter edge (u v): ");
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, n);
        }
    }

    printf("Topological Order: ");
    while (top >= 0) {
        printf("%d ", stack[top--]);
    }
    printf("\n");

    return 0;
}
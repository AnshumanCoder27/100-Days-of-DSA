/*Problem: Perform BFS from a given source using queue.

Input:
- n
- adjacency list
- source s

Output:
- BFS traversal order*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int adj[100][100], deg[100];
int queue[100], visited[100];

void bfs(int s, int n) {
    int front = 0, rear = 0;
    visited[s] = 1;
    queue[rear++] = s;

    while (front < rear) {
        int node = queue[front++];
        printf("%d ", node);

        for (int i = 0; i < deg[node]; i++) {
            int nb = adj[node][i];
            if (!visited[nb]) {
                visited[nb] = 1;
                queue[rear++] = nb;
            }
        }
    }
}

int main() {
    int n, e;
    scanf("%d %d", &n, &e);

    for (int i = 0; i < e; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][deg[u]++] = v;
        adj[v][deg[v]++] = u;
    }

    int s;
    scanf("%d", &s);

    bfs(s, n);
    return 0;
}
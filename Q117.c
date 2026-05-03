/*Problem: Compute shortest path from source and detect negative weight cycles using Bellman-Ford.

Input:
- n vertices
- m edges (u,v,w)

Output:
- Shortest distances OR NEGATIVE CYCLE*/
#include <stdio.h>

#define INF 1000000000

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int u[m], v[m], w[m];
    for (int i = 0; i < m; i++)
        scanf("%d %d %d", &u[i], &v[i], &w[i]);

    int src;
    scanf("%d", &src);

    int dist[n];
    for (int i = 0; i < n; i++)
        dist[i] = INF;
    dist[src] = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m; j++) {
            if (dist[u[j]] != INF && dist[u[j]] + w[j] < dist[v[j]])
                dist[v[j]] = dist[u[j]] + w[j];
        }
    }

    for (int j = 0; j < m; j++) {
        if (dist[u[j]] != INF && dist[u[j]] + w[j] < dist[v[j]]) {
            printf("NEGATIVE CYCLE\n");
            return 0;
        }
    }

    for (int i = 0; i < n; i++) {
        if (dist[i] == INF)
            printf("Node %d: INF\n", i);
        else
            printf("Node %d: %d\n", i, dist[i]);
    }

    return 0;
}
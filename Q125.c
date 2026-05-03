/*Problem Statement
Find shortest distances from source vertex in a weighted graph with non-negative weights.

Input Format
n m
u v w
source

Output Format
Distances to all vertices.

Sample Input
5 6
1 2 2
1 3 4
2 3 1
2 4 7
3 5 3
4 5 1
1

Sample Output
0 2 3 9 6

Explanation
Shortest distances computed via priority queue.*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAXN 100005
#define MAXM 200005

typedef struct {
    int to, w, next;
} Edge;

typedef struct {
    int dist, node;
} HeapNode;

Edge edges[MAXM];
int head[MAXN], cnt;
long long dist[MAXN];
int visited[MAXN];
HeapNode heap[MAXM];
int heap_size;

void add_edge(int u, int v, int w) {
    edges[cnt].to = v;
    edges[cnt].w = w;
    edges[cnt].next = head[u];
    head[u] = cnt++;
}

void push(int d, int node) {
    int i = ++heap_size;
    heap[i].dist = d;
    heap[i].node = node;
    while (i > 1 && heap[i].dist < heap[i / 2].dist) {
        HeapNode tmp = heap[i];
        heap[i] = heap[i / 2];
        heap[i / 2] = tmp;
        i /= 2;
    }
}

HeapNode pop() {
    HeapNode top = heap[1];
    heap[1] = heap[heap_size--];
    int i = 1;
    while (1) {
        int smallest = i;
        if (2 * i <= heap_size && heap[2 * i].dist < heap[smallest].dist)
            smallest = 2 * i;
        if (2 * i + 1 <= heap_size && heap[2 * i + 1].dist < heap[smallest].dist)
            smallest = 2 * i + 1;
        if (smallest == i) break;
        HeapNode tmp = heap[i];
        heap[i] = heap[smallest];
        heap[smallest] = tmp;
        i = smallest;
    }
    return top;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) head[i] = -1;
    cnt = 0;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        add_edge(u, v, w);
    }

    int src;
    scanf("%d", &src);

    for (int i = 1; i <= n; i++) dist[i] = LLONG_MAX;
    dist[src] = 0;

    heap_size = 0;
    push(0, src);

    while (heap_size > 0) {
        HeapNode cur = pop();
        int u = cur.node;
        if (visited[u]) continue;
        visited[u] = 1;
        for (int e = head[u]; e != -1; e = edges[e].next) {
            int v = edges[e].to;
            int w = edges[e].w;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                push(dist[v], v);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (i > 1) printf(" ");
        if (dist[i] == LLONG_MAX)
            printf("-1");
        else
            printf("%lld", dist[i]);
    }
    printf("\n");

    return 0;
}
/*Problem: Implement topological sorting using in-degree array and queue (Kahnâ€™s Algorithm).*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX], inDegree[MAX], queue[MAX];
int n, e, front, rear;

void enqueue(int x) { queue[rear++] = x; }
int dequeue() { return queue[front++]; }
int isEmpty() { return front == rear; }

void kahnTopSort() {
    front = rear = 0;

    for (int i = 0; i < n; i++)
        if (inDegree[i] == 0)
            enqueue(i);

    int count = 0;
    printf("Topological Order: ");

    while (!isEmpty()) {
        int node = dequeue();
        printf("%d ", node);
        count++;

        for (int i = 0; i < n; i++) {
            if (adj[node][i]) {
                inDegree[i]--;
                if (inDegree[i] == 0)
                    enqueue(i);
            }
        }
    }

    if (count != n)
        printf("\nCycle detected! Topological sort not possible.");
    else
        printf("\n");
}

int main() {
    printf("Enter vertices and edges: ");
    scanf("%d %d", &n, &e);

    for (int i = 0; i < e; i++) {
        int u, v;
        printf("Edge (u -> v): ");
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        inDegree[v]++;
    }

    kahnTopSort();
    return 0;
}
/*Problem: Perform DFS starting from a given source vertex using recursion.

Input:
- n
- adjacency list
- starting vertex s

Output:
- DFS traversal order*/
#include <stdio.h>

int visited[100];

void dfs(int arr[][100], int n, int s) {
    visited[s] = 1;
    printf("%d ", s);
    for (int i = 0; i < n; i++) {
        if (arr[s][i] == 1 && !visited[i]) {
            dfs(arr, n, i);
        }
    }
}

int main() {
    int n, s;
    int arr[100][100];

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &arr[i][j]);

    scanf("%d", &s);

    dfs(arr, n, s);

    return 0;
}
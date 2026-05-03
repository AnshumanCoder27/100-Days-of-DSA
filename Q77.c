/*Problem Statement:
Implement a Min Heap using an array where the smallest element is always at the root.

Supported Operations:
- insert x
- extractMin
- peek

Input Format:
- First line contains integer N
- Next N lines contain heap operations

Output Format:
- Print results of extractMin and peek
- Print -1 if operation cannot be performed

Example:
Input:
6
insert 40
insert 10
insert 30
peek
extractMin
peek

Output:
10
10
30*/
#include <stdio.h>

int arr[10000];
int n = 0;

void insert(int x) {
    arr[n] = x;
    int i = n++;
    while (i > 0 && arr[(i-1)/2] > arr[i]) {
        int t = arr[(i-1)/2];
        arr[(i-1)/2] = arr[i];
        arr[i] = t;
        i = (i-1)/2;
    }
}

int extractMin() {
    if (n == 0) return -1;
    int min = arr[0];
    arr[0] = arr[--n];
    int i = 0;
    while (1) {
        int s = i, l = 2*i+1, r = 2*i+2;
        if (l < n && arr[l] < arr[s]) s = l;
        if (r < n && arr[r] < arr[s]) s = r;
        if (s == i) break;
        int t = arr[s];
        arr[s] = arr[i];
        arr[i] = t;
        i = s;
    }
    return min;
}

int main() {
    int q;
    scanf("%d", &q);
    while (q--) {
        char op[20];
        scanf("%s", op);
        if (op[0] == 'i') {
            int x;
            scanf("%d", &x);
            insert(x);
        } else if (op[0] == 'e') {
            printf("%d\n", extractMin());
        } else {
            printf("%d\n", n == 0 ? -1 : arr[0]);
        }
    }
    return 0;
}
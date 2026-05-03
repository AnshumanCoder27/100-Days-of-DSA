/*Problem Statement
Implement a hash table using quadratic probing with formula:

h(k, i) = (h(k) + i*i) % m

Input Format
Same as previous.

Output Format
Result of SEARCH operations.

Sample Input
7
4
INSERT 49
INSERT 56
SEARCH 49
SEARCH 15

Sample Output
FOUND
NOT FOUND

Explanation
Collisions resolved using i² jumps.*/
#include <stdio.h>
#include <string.h>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int arr[m];
    for (int i = 0; i < m; i++) {
        arr[i] = -1;  // -1 means empty
    }

    for (int op = 0; op < n; op++) {
        char cmd[10];
        int key;
        scanf("%s %d", cmd, &key);

        if (strcmp(cmd, "INSERT") == 0) {
            int h = key % m;
            int i = 0;
            int index = h;

            while (arr[index] != -1 && arr[index] != key) {
                i++;
                index = (h + i * i) % m;
            }

            arr[index] = key;
        }
        else if (strcmp(cmd, "SEARCH") == 0) {
            int h = key % m;
            int i = 0;
            int index = h;
            int found = 0;

            while (arr[index] != -1) {
                if (arr[index] == key) {
                    found = 1;
                    break;
                }
                i++;
                index = (h + i * i) % m;
            }

            if (found) {
                printf("FOUND\n");
            } else {
                printf("NOT FOUND\n");
            }
        }
    }

    return 0;
}
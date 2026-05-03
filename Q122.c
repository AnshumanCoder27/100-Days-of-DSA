/*```
Problem Statement
Given an array of integers containing both positive and negative values, find the length of the longest contiguous subarray whose sum is equal to zero.

Input Format
An integer array arr[].

Output Format
Print the length of the longest subarray with sum equal to zero.

Sample Input
15 -2 2 -8 1 7 10 23

Sample Output
5

Explanation
The subarray [-2, 2, -8, 1, 7] has a sum of 0 and is the longest such subarray. in c no comments easy words and logic
```*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int arr[1000], n = 0;
    while (scanf("%d", &arr[n]) == 1) n++;

    int max_len = 0;

    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += arr[j];
            if (sum == 0) {
                if (j - i + 1 > max_len)
                    max_len = j - i + 1;
            }
        }
    }

    printf("%d\n", max_len);
    return 0;
}
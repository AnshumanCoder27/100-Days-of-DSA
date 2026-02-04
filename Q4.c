/*/ Given an array of n integers, reverse the array in-place using two-pointer approach.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the reversed array, space-separated

Example:
Input:
5
1 2 3 4 5

Output:
5 4 3 2 1

Explanation: Swap pairs from both ends: (1,5), (2,4), middle 3 stays */

#include <stdio.h>
int main(){
    int n = 0;
    scanf("%d",&n);
    int arr[n];
    for(int i = 0;i<n;i++){
        scanf("%d",&arr[i]);//Second line: n space-separated integers
    }
    for(int i = 0;i<n/2;i++){
        int cur = arr[i];
        int rev = arr[n-i-1];
        arr[i] = rev;
        arr[n-i-1] = cur;
        }
    for(int i = 0;i<n;i++){
        printf("%d\t",arr[i]);
    }
    return 0;
    
}
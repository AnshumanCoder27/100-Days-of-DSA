/* Implement linear search to find key k in an array. Count and display the number of comparisons performed.

Input:
- First line: integer n (array size)
- Second line: n space-separated integers
- Third line: integer k (key to search)

Output:
- Line 1: "Found at index i" OR "Not Found"
Line 2: "Comparisons = c"

Example:
Input:
5
10 20 30 40 50
30

Output:
Found at index 2
Comparisons = 3

Explanation: Compared with 10, 20, 30 (found at index 2 with 3 comparisons) */

#include<stdio.h>

int main(){

    int n = 0;
    scanf("%d", &n);

    int arr[n];

    for(int i = 0 ; i<n ; i++){
        printf("%d\t", &arr[i]);
    } 

    int k = 0;
    scanf("%d",&k);
    int count = 0;
    int isFound = 0;
    int index = 0;
    for(int i = 0;i<n;i++){
        count++;
        if(arr[i]==k){//this counts as a comparison too
            isFound = 1;
            index = i;
            break;
        }

    }
    
    (isFound == 1)?printf("Found at index %d\nComparisons = %d",index,count):printf("Not Found");
    return 0;





}

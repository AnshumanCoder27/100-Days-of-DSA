/*Problem: Read a string and check if it is a palindrome using two-pointer comparison.

Input:
- Single line: string s

Output:
- Print YES if palindrome, otherwise NO

Example:
Input:
level

Output:
YES

Explanation: String reads same forwards and backwards*/
#include <stdio.h>
#include<string.h>
void mirror(char arr[],int s){
    char arr2[101];
    strcpy(arr2,arr);
    int start = 0;
    int end = s-1;
    while(end>start){
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        end--;
        start++;
    }
    if(strcmp(arr2,arr)==0){
        printf("YES");
    }
    else{
        printf("NO");
    }

}

int main(void){
    char arr[101];
    fgets(arr,100,stdin);
    int s =strlen(arr);
    arr[s-1] = '\0';//removing newline
    int snew = strlen(arr);
    mirror(arr,snew);
    
    return 0;
}
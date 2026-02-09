/*Problem: A secret system stores code names in forward order. To display them in mirror format,
 you must transform the given code name so that its characters appear in the opposite order.

Input:
- Single line: a lowercase string containing only alphabetic characters (no spaces)

Output:
- Print the transformed code name after applying the mirror operation

Example:
Input:
hello

Output:
olleh

Explanation: The first character moves to the last position, the second to the second-last, 
and so on until the entire string is mirrored*/
#include <stdio.h>
#include <string.h>
//logic 1
/*void mirror(char arr[],int s){
    for(int i = 0;i<s/2;i++){
        int cur = arr[i];
        int rev = arr[s-i-1];
        arr[i] = rev;
        arr[s-i-1] = cur;
    }
}*/
//logic 2
void mirror(char arr[],int s){
    int start = 0;
    int end = s-1;
    while(end>start){
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        end--;
        start++;
    }

}

int main(void){
    char arr[101];
    fgets(arr,100,stdin);
    int s =strlen(arr);
    arr[s-1] = '\0';//removing newline
    int snew = strlen(arr);
    mirror(arr,snew);
    fputs(arr,stdout);
    return 0;
}
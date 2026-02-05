/*/A system receives two separate logs of user arrival times from two different servers. Each log is already sorted in ascending order. Your task is to create a single chronological log that preserves the correct order of arrivals.

Input:
- First line: integer p (number of entries in server log 1)
- Second line: p sorted integers representing arrival times from server 1
- Third line: integer q (number of entries in server log 2)
- Fourth line: q sorted integers representing arrival times from server 2)

Output:
- Print a single line containing all arrival times in chronological order, separated by spaces

Example:
Input:
5
10 20 30 50 70
4
15 25 40 60

Output:
10 15 20 25 30 40 50 60 70

Explanation: Compare the next unprocessed arrival time from both logs and append the earlier one to the final log until all entries are processed*/

#include <stdio.h>
#include <stdlib.h>
int main(){
    int p = 0;
    scanf("%d",&p);
    int *arr;
    arr =(int*)malloc(sizeof(int)*p);
    for(int i = 0;i<p;i++){
        scanf("%d",&arr[i]);//Second line: n space-separated integers
    }
    int q = 0;
    scanf("%d",&q);
    int *arr2;
    arr2 =(int*)malloc(sizeof(int)*q);
    for(int i = 0;i<q;i++){
        scanf("%d",&arr2[i]);//Second line: n space-separated integers
    }
    arr = (int*)realloc(arr,sizeof(int)*(p+q));
    for(int i = 0;i<q;i++){
        arr[p+i] = arr2[i];
    }
        for(int i = 0;i<p+q;i++){
        for(int j = i+1;j<p+q;j++){
            if(arr[j]<arr[i]){
                int temp = arr[j];
                arr[j]=arr[i];
                arr[i]=temp;
            }
        }
    }
    for(int i = 0;i<p+q;i++){
    printf("%d\t",arr[i]);
}
free(arr);
free(arr2);
return 0;


}
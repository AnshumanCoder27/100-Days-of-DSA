/*Problem: Write a program to perform addition of two matrices having the same dimensions. The sum of two matrices 
is obtained by adding corresponding elements of the matrices.

Input:
- First line: two integers m and n representing the number of rows and columns
- Next m lines: n integers each representing the elements of the first matrix
- Next m lines: n integers each representing the elements of the second matrix

Output:
- Print the resultant matrix after addition, with each row on a new line and elements separated by spaces

Example:
Input:
3 3
1 2 3
4 5 6
7 8 9
9 8 7
6 5 4
3 2 1

Output:
10 10 10
10 10 10
10 10 10

Explanation:
Each element of the result matrix is the sum of the corresponding elements from the two input matrices.

Test Cases:

Test Case 1:
Input:
2 2
1 2
3 4
5 6
7 8
Output:
6 8
10 12

Test Case 2:
Input:
1 3
10 20 30
1 2 3
Output:
11 22 33

Test Case 3:
Input:
3 1
1
2
3
4
5
6
Output:
5
7
9*/

#include <stdio.h>
void scan(int n,int m,int arr[n][m]);
void display(int n,int m,int arr[n][m]);
void sum(int n,int m,int arr[n][m],int n2, int m2,int arr2[n2][m2], int n1,int m1, int arrRes[n1][m1]);
int main(){
    int x, y;
    printf("Enter the size of the matrix:");
    scanf("%d %d",&x,&y);
    int arr1[x][y];
    int arr2[x][y];

    int Resultant[x][y];
    printf("======================================\n");
    scan(x,y,arr1);
    printf("======================================\n");
    printf("===================\n");
    display(x,y,arr1);
    printf("===================\n");
    printf("\n");
    printf("Enter the second matrix:\n");
    printf("======================================\n");
    scan(x,y,arr2);
    printf("======================================\n");
    printf("===================\n");
    display(x,y,arr2);
    printf("===================\n");
    printf("\n");
    printf("The sum of the 2 matrix is:\n");
    sum(x,y,arr1,x,y,arr2,x,y,Resultant);
    printf("===================\n");
    display(x,y,Resultant);
    printf("===================\n");
    return 0;

    
    
}

void scan(int n,int m,int arr[n][m]){
    for(int i = 0; i < n;i++){
        for(int j=0;j<m;j++){
        
            scanf("%d",&arr[i][j]);
        }
    }
}
void display(int n,int m,int arr[n][m]){
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            printf("%d\t",arr[i][j]);
        }
        printf("\n");
    }
}
void sum(int n,int m,int arr[n][m],int n2, int m2,int arr2[n2][m2], int n1,int m1, int arrRes[n1][m1]){
    for(int i =0;i<n;i++){
        for(int j = 0;j<m;j++){
            arrRes[i][j]=arr[i][j]+arr2[i][j];
        }
    }
}
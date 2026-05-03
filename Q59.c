/*Problem: Polynomial Using Linked List - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of terms)
- Next n lines: two integers (coefficient and exponent)

Output:
- Print polynomial in standard form, e.g., 10x^4 + 20x^3 + 30x^2 + 40x + 50

Example:
Input:
5
10 4
20 3
30 2
40 1
50 0

Output:
10x^4 + 20x^3 + 30x^2 + 40x + 50

Explanation:
Each node stores coefficient and exponent. Traverse nodes to print polynomial in decreasing exponent order.*/
#include <stdio.h>
#include <Stdlib.h>
typedef struct node{
    int data;
    int pow;
    struct node* next;
}node;
int main(){
    int n = 0;
    scanf("%d",&n);
    node *head = NULL;
    head = (node*)malloc(sizeof(node));
    scanf("%d",&head->data);
    scanf("%d",&head->pow);
    head->next = NULL;
    node* temp = NULL;
    temp = head;
    for(int i = 1;i<n;i++){
        temp->next = (node*)malloc(sizeof(node));
        temp=temp->next;
        scanf("%d",&temp->data);
        scanf("%d",&temp->pow);
        temp->next=NULL;
        
    }
    temp = head;
    while(temp!=NULL){
        if(temp->pow != 0){
        printf("%dx^%d + ",temp->data,temp->pow);
        temp=temp->next;
    }
        else{//when pow 0
       printf("%d",temp->data);
        temp=temp->next; 
    }
    }

    return 0;
}
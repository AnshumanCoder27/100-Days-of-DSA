/*Problem: Merge Two Sorted Linked Lists - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)

Output:
- Print the merged linked list elements, space-separated

Example:
Input:
5
10 20 30 40 50
4
15 25 35 45

Output:
10 15 20 25 30 35 40 45 50

Explanation:
Compare nodes of both lists, append smaller to result, continue until all nodes are merged.*/
#include <stdio.h>
#include <Stdlib.h>
typedef struct node{
    int data;
    struct node* next;
}node;
int main(){
    int n = 0;
    scanf("%d",&n);
    node *head = NULL;
    head = (node*)malloc(sizeof(node));
    scanf("%d",&head->data);
    head->next = NULL;
    node* temp = NULL;
    temp = head;
    for(int i = 1;i<n;i++){
        temp->next = (node*)malloc(sizeof(node));
        temp=temp->next;
        scanf("%d",&temp->data);
        temp->next=NULL;
        
    }
    int m = 0;
    scanf("%d",&m);
    node *head2 = NULL;
    head2 = (node*)malloc(sizeof(node));
    scanf("%d",&head2->data);
    head2->next = NULL;
    node* temp2 = NULL;
    temp2 = head2;
    for(int i = 1;i<m;i++){
        temp2->next = (node*)malloc(sizeof(node));
        temp2=temp2->next;
        scanf("%d",&temp2->data);
        temp2->next=NULL;  
    }
    temp= head;
    temp2 =head2;
    while(temp != NULL && temp2 != NULL){
        if(temp->data < temp2->data){
            printf("%d ", temp->data);
            temp = temp->next;
        }
        else{
            printf("%d ", temp2->data);
            temp2 = temp2->next;
        }
    }

    //only one will have elements left
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }

    while(temp2 != NULL){
        printf("%d ", temp2->data);
        temp2 = temp2->next;
    }

    return 0;
}
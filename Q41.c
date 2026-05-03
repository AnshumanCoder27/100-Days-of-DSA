/*Problem: Create and Traverse Singly Linked List

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the result

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50*/
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
    temp = head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    return 0;
}
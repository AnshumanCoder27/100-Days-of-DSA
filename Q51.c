/*Problem: Doubly Linked List Insertion and Traversal - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the linked list elements in forward order, space-separated

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50

Explanation:
Each node has data, next, prev. Insert nodes sequentially, traverse from head using next pointer.*/
#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    struct node*prev;
    int data;
    struct node*next;
}node;
int main(){
node *head = NULL;
head = (node*)malloc(sizeof(node));
int n = 0;
scanf("%d",&n);
scanf("%d",&head->data);
head->next = NULL;
head->prev=NULL;//NULL 10 20 30 40 50 NULL
node *temp = NULL;
temp = head;
for(int i = 1;i<n;i++){
temp->next = (node*)malloc(sizeof(node));
temp->next->prev = temp;
temp=temp->next;
scanf("%d",&temp->data);
temp->next = NULL;
}
temp=head;
while(temp!=NULL){
    printf("%d ",temp->data);
    temp=temp->next;
}
temp=head;
while(temp->next!=NULL){//moving to last node
    temp=temp->next;
}
printf("\n");
while(temp!=NULL){
    printf("%d ",temp->data);
    temp=temp->prev;
}
return 0;
}
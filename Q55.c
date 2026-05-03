/*Problem: Circular Linked List Creation and Traversal - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the circular linked list elements starting from head, space-separated

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50

Explanation:
Last node's next points to head. Traverse from head until returning to head to avoid infinite loop.*/
#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    struct node *prev;
    int data;
    struct node *next;
}node;
int main(){
    int n = 0;
    scanf("%d",&n);
    node *head = NULL;
    head = (node*)malloc(sizeof(node));
    scanf("%d",&head->data);
    head->next = NULL;
    head->prev = NULL;
    node *temp = NULL;
    temp = head;
    for(int i = 1;i<n;i++){
        temp->next = (node*)malloc(sizeof(node));
        temp->next->prev = temp;
        temp = temp->next;
        scanf("%d",&temp->data);
        temp->next = NULL;
    }
    temp = head;
    printf("\nForward Traversal\n");
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    printf("\nBackward Traversal\n");
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp = temp->prev;
    }
    return 0;
}
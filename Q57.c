/*Problem: Rotate Linked List Right by k Places - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer k

Output:
- Print the linked list elements after rotation, space-separated

Example:
Input:
5
10 20 30 40 50
2

Output:
40 50 10 20 30

Explanation:
Connect last node to head forming circular list. Traverse to (n-k)th node, set next to NULL, update head to (n-k+1)th node.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

int main(){
    int n = 0;
    scanf("%d",&n);

    node *temp,*head;
    head = (node*)malloc(sizeof(node));
    scanf("%d",&head->data);
    head->next = NULL;
    temp = head;

    for(int i = 1;i<n;i++){
        temp->next = (node*)malloc(sizeof(node));
        temp = temp->next;
        scanf("%d",&temp->data);
        temp->next = NULL;
    }

    int k = 0;
    scanf("%d",&k);

    k = k % n;

    temp = head;
    while(temp->next!=NULL){
        temp=temp->next;
    }

    temp->next = head;

    node *temp2 = head;
    for(int i = 1;i < n - k;i++){
        temp2 = temp2->next;
    }

    head = temp2->next;
    temp2->next = NULL;

    temp = head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }

    return 0;
}


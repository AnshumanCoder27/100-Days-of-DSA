/*Problem: Count Occurrences of an Element in Linked List - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of nodes)
- Second line: n space-separated integers (linked list elements)
- Third line: integer key (element to be counted)

Output:
- Print the number of times the key appears in the linked list

Example:
Input:
6
10 20 30 20 40 20
20

Output:
3

Explanation:
Traverse the linked list from head to end. Each time a node's data matches the given key, increment a counter. After traversal, print the final count.*/
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
    temp = head;
    int count = 0;
        while(temp != NULL){
        if(m==temp->data){
            count++;
        }
        temp = temp->next;
    }
    printf("%d",count);
    return 0;
}
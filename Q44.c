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
    node *prev,*curr,*front;
    curr = head;
    prev = NULL;
    front = NULL;
    while(curr!=NULL){
        front=curr->next;
        curr->next = prev;
        prev = curr;
        curr = front;
    }
    head = prev;
    printf("\n");
    
    temp = head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }

    return 0;
}
/*Given the head of a singly linked list, reverse the list, and return the reversed list.

 

Example 1:


Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]
Example 2:


Input: head = [1,2]
Output: [2,1]
Example 3:

Input: head = []
Output: []
 

Constraints:

The number of nodes in the list is the range [0, 5000].
-5000 <= Node.val <= 5000*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *prev,*curr,*front;
    prev = NULL;
    curr = head;
    front = NULL;
    while(curr!=NULL){
    front = curr->next;
    curr->next = prev;
    prev = curr;
    curr=front;
    }
    head = prev;
    return head;
}
/*Problem: Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)

Output:
- Print value of intersection node or 'No Intersection'

Example:
Input:
5
10 20 30 40 50
4
15 25 30 40 50

Output:
30

Explanation:
Calculate lengths, advance pointer in longer list, traverse both simultaneously. First common node is intersection.*/
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;

int length(node* head){
    int count = 0;
    while(head){
        count++;
        head = head->next;
    }
    return count;
}

int main(){
    int n = 0;
    scanf("%d",&n);

    node *head1 = NULL;
    head1 = (node*)malloc(sizeof(node));
    scanf("%d",&head1->data);
    head1->next = NULL;

    node* temp = head1;
    for(int i = 1;i<n;i++){
        temp->next = (node*)malloc(sizeof(node));
        temp = temp->next;
        scanf("%d",&temp->data);
        temp->next = NULL;
    }

    int m = 0;
    scanf("%d",&m);

    node *head2 = NULL;
    head2 = (node*)malloc(sizeof(node));
    scanf("%d",&head2->data);
    head2->next = NULL;

    temp = head2;
    for(int i = 1;i<m;i++){
        temp->next = (node*)malloc(sizeof(node));
        temp = temp->next;
        scanf("%d",&temp->data);
        temp->next = NULL;
    }

    int len1 = length(head1);
    int len2 = length(head2);

    node *p1 = head1;
    node *p2 = head2;

    if(len1 > len2){
        int d = len1 - len2;
        for(int i = 0;i<d;i++) p1 = p1->next;
    } else {
        int d = len2 - len1;
        for(int i = 0;i<d;i++) p2 = p2->next;
    }

    while(p1 && p2){
        if(p1->data == p2->data){
            printf("%d",p1->data);
            return 0;
        }
        p1 = p1->next;
        p2 = p2->next;
    }

    printf("No Intersection");
    return 0;
}
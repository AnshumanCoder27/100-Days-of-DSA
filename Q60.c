/*You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 

Example 1:


Input: l1 = [7,2,4,3], l2 = [5,6,4]
Output: [7,8,0,7]
Example 2:

Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [8,0,7]
Example 3:

Input: l1 = [0], l2 = [0]
Output: [0]
 

Constraints:

The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a num*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rev(struct ListNode* head){
    struct ListNode* cur = head;
    struct ListNode* prev = NULL;
    struct ListNode* front = NULL;
    while(cur != NULL){
        front = cur->next;
        cur->next = prev;
        prev = cur;
        cur = front;
    }
    return prev;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    l1 = rev(l1);
    l2 = rev(l2);
    struct ListNode* temp1 = l1;
    struct ListNode* temp2 = l2;
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->val = 0;
    dummy->next = NULL;
    struct ListNode* cur = dummy;
    int carry = 0;

    while(temp1 != NULL || temp2 != NULL || carry){
        int sum = carry;
        if(temp1 != NULL){ sum += temp1->val; temp1 = temp1->next; }
        if(temp2 != NULL){ sum += temp2->val; temp2 = temp2->next; }
        carry = sum / 10;
        struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
        node->val = sum % 10;
        node->next = NULL;
        cur->next = node;
        cur = cur->next;
    }

    return rev(dummy->next);
}
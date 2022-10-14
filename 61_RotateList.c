/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//#include <stdio.h>

struct ListNode* rotateRight(struct ListNode* head, int k){
    struct ListNode* curr;
    struct ListNode* next;
    struct ListNode* newHead;
    
    curr = head;
    size_t size;
    for(size=0 ; curr!=NULL;size++)
        curr = curr->next;
    
    if(size == 0) return head;
    k = k%size;
    if(k == 0) return head;
    
    curr = head;
    int i;
    for(i=1; i<(size-k); i++)
        curr = curr->next;
    next = curr->next;
    curr->next = NULL;

    newHead = next;
    while(next!=NULL){
        curr = next;
        next = next->next;
    }
    curr->next = head;
    return newHead;
}
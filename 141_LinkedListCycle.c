/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    struct ListNode *curr = head;
    while(curr != NULL){
        if(curr->val == 0x7fffffff) return true;
        curr->val = 0x7fffffff;
        curr = curr->next;
    }
    return false;
}
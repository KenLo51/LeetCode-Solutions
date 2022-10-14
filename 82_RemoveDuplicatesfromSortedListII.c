/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* deleteDuplicates(struct ListNode* head){
    struct ListNode* outList = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* outListEnd = outList;
    struct ListNode* currNode = head;
    int currVal;
    while(currNode != NULL){
        currVal = currNode->val;
        if(currNode->next != NULL){
            if(currVal == currNode->next->val){
                while(currNode->next != NULL){
                    if(currVal != currNode->next->val)break;
                    currNode = currNode->next;
                }
                currNode = currNode->next;
                continue;
            }
        }
        
        outListEnd->next = currNode;
        outListEnd = currNode;
        currNode = currNode->next;
    }
    outListEnd->next = NULL;
    return outList->next;
}
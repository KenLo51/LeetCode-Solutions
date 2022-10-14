/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* deleteMiddle(struct ListNode* head){
    unsigned int listSize;
    struct ListNode* currNode;
    
    // get the length of the list
    listSize = 0;
    for(currNode = head; currNode != NULL; currNode = currNode->next)
        listSize = listSize + 1;
    
    // index of the middle node
    unsigned int middleIdx = listSize/2;
    
    if(middleIdx == 0) return NULL;
    
    // locate the middle node
    currNode = head;
    for(unsigned int i=0; i<(middleIdx-1); i++)
        currNode = currNode->next;
    //skip node
    currNode->next = currNode->next->next;
    
    return head;
}
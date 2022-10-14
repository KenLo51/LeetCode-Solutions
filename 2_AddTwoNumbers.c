/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */



struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* curr1 = l1;
    struct ListNode* curr2 = l2;
    struct ListNode* outList = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* outCurr = outList;
    outList->next = NULL;
    
    int carryOut = 0;
    while(1){
        int val1 = (curr1 == NULL)? 0:curr1->val;
        int val2 = (curr2 == NULL)? 0:curr2->val;
        if(curr1 == NULL && curr2 == NULL && carryOut == 0) break;
        int sum = val1 + val2 + carryOut;
        struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->next = NULL;
        newNode->val = sum%10;
        carryOut = sum/10;
        outCurr = outCurr->next = newNode;
        
        if(curr1 != NULL) curr1 = curr1->next;
        if(curr2 != NULL) curr2 = curr2->next;
    }
    return outList->next;
}
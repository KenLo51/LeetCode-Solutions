/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    struct ListNode* sortedList = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* sortedListEnd = sortedList;
    while(list1 != NULL && list2 != NULL){
        if(list1->val < list2->val){
            sortedListEnd->next = list1;
            list1 = list1->next;
            sortedListEnd = sortedListEnd->next;
        }
        else{
            sortedListEnd->next = list2;
            list2 = list2->next;
            sortedListEnd = sortedListEnd->next;
        }
    }
    while(list1 != NULL && list2 == NULL){
        sortedListEnd->next = list1;
        list1 = list1->next;
        sortedListEnd = sortedListEnd->next;
    }
    while(list1 == NULL && list2 != NULL){
        sortedListEnd->next = list2;
        list2 = list2->next;
        sortedListEnd = sortedListEnd->next;
    }
    sortedListEnd->next = NULL;
    return sortedList->next;
}
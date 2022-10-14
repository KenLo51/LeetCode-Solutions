/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* oddEvenList(struct ListNode* head){
	struct ListNode* even = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* odd = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* evenEnd = even;
	struct ListNode* oddEnd = odd;
	even->next = NULL;
	odd->next = NULL;
	
	struct ListNode* curr = head;
	struct ListNode* next;
	while(curr != NULL){
		next = curr->next;
		oddEnd->next = curr;
		oddEnd = oddEnd->next;
		curr = next;
		if(curr == NULL) break;
		
		next = curr->next;
		evenEnd->next = curr;
		evenEnd = evenEnd->next;
		curr = next;
	}
	
	oddEnd->next = even->next;
	evenEnd->next = NULL;
	
	struct ListNode* retList = odd->next;
	free(even);
	free(odd);
	return retList;
}
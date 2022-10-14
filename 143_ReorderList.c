/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


void reorderList(struct ListNode* head){
	struct ListNode *p, *q;
	int idx;
	
	//count list size
	size_t size = 0;
	p = head;
	for(size=0; p!=NULL; size++)
		p = p->next;
	
	//divide to 2 list
	struct ListNode *firstHalf,*lastHalf;
	
	firstHalf = head;
	p = firstHalf;
	for(idx=0; idx<(size-1)/2; idx++){
		p = p->next;
	}
	lastHalf = p->next;
	p->next = NULL;
	
	//reorder lastHalf
	p = NULL;
	if(lastHalf != NULL){
		while(1){
			q = lastHalf->next;
			lastHalf->next = p;
			if(q == NULL) break;
			p = lastHalf;
			lastHalf = q;
		}
	}
	
	//combine
	p = head;
	firstHalf = firstHalf->next;
	while(1){
		if(lastHalf==NULL)break;
		p->next = lastHalf;
		lastHalf = lastHalf->next;
		p = p->next;
		
		if(firstHalf==NULL)break;
		p->next = firstHalf;
		firstHalf = firstHalf->next;
		p = p->next;
	}
}
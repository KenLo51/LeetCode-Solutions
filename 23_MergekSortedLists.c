struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
	int listIdx;
	struct ListNode *outList, *outListEnd;
	outList = (struct ListNode *)malloc(sizeof(struct ListNode));
	outListEnd = outList;
	while(1){
		int minimumVal, minimumValIdx;
		//initial minimum value
		//printf("initial minimum value\n");
		for(listIdx=0; listIdx<listsSize; listIdx++){
			if(lists[listIdx]!=NULL){
				minimumVal = lists[listIdx]->val;
				minimumValIdx = listIdx;
				break;
			}
		}
		if(listIdx == listsSize) break;//no more value
		
		//find minimum
		//printf("find minimum value\n");
		for(; listIdx<listsSize; listIdx++){
			if(lists[listIdx]!=NULL){
				if(minimumVal > lists[listIdx]->val){
					//printf("  update minimum\n");
					minimumVal = lists[listIdx]->val;
					minimumValIdx = listIdx;
				}
			}
		}
		
		//printf("min:%2d, idx:%2d\n", minimumVal, minimumValIdx);
		
		//push to output list
		outListEnd->next = lists[minimumValIdx];
		outListEnd = outListEnd->next;
		
		//remove from list
		lists[minimumValIdx] = lists[minimumValIdx]->next;
	}
	outListEnd->next = NULL;
	
	struct ListNode * headNode = outList;
	outList = outList->next;
	free(headNode);
	return outList;
}
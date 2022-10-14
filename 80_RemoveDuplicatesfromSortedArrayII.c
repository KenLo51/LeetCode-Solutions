int removeDuplicates(int* nums, int numsSize){
	
	if(numsSize == 0) return 0;
	
	int outSize = 0;
	int appearsCounter = 1;
	
	int readIdx, pushIdx;
	
	readIdx = 1; 
	pushIdx = 1;
	while(readIdx<numsSize){
		if(nums[readIdx-1] == nums[readIdx]){
			if(appearsCounter < 2){//appears less than twice
				nums[pushIdx] = nums[readIdx];
				pushIdx++;
			}
			readIdx++;
			appearsCounter++;
		}
		else{
			nums[pushIdx] = nums[readIdx];
			pushIdx++; readIdx++;
			appearsCounter = 1;
		}
	}
	return pushIdx;
}
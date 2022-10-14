int removeDuplicates(int* nums, int numsSize){
	int readIdx, saveIdx;
	for(saveIdx = readIdx = 0; readIdx < numsSize; readIdx++){
		if(readIdx+1 >= numsSize)//out of array
			nums[saveIdx++] = nums[readIdx];
		else if(nums[readIdx] != nums[readIdx+1])//different value
			nums[saveIdx++] = nums[readIdx];
	}
	return saveIdx;
}
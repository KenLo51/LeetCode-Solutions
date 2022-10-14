char ** summaryRanges(int* nums, int numsSize, int* returnSize){
	char **ranges = (char**)malloc( sizeof(char*)*numsSize );
	char *newRange;
	*returnSize = 0;
	
	if(numsSize == 0) return NULL;
	
	int rangeBeginVal = nums[0];
	int rangeEndVal = nums[0];
	int i;
	for(i=0; i<numsSize; i++){
		if(i == (numsSize-1)) goto AddRange;
		if(nums[i+1] != (rangeEndVal+1)) goto AddRange;
		rangeEndVal = nums[i+1];
		continue;

AddRange:		
		if(rangeBeginVal == rangeEndVal){
			newRange = (char*)malloc(15);
			sprintf(newRange, "%d", rangeBeginVal);
		}
		if(rangeBeginVal != rangeEndVal){
			newRange = (char*)malloc(30);
			sprintf(newRange, "%d->%d", rangeBeginVal, rangeEndVal);
		}
		ranges[*returnSize] = newRange;
		(*returnSize)++;
	
		if(i == (numsSize-1)) break;
		rangeBeginVal = rangeEndVal = nums[i+1];
	}
	
	return ranges;
}
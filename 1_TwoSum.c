int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    for(int i=0; i<numsSize; i++){
        for(int j=i+1; j<numsSize; j++){
            int sum = nums[i] + nums[j];
            if(sum == target){
                int *idx = (int*)malloc(sizeof(int)*2);
                idx[0] = i;
                idx[1] = j;
                *returnSize = 2;
                return idx;
            }
        }
    }
    *returnSize = 0;
    return NULL;
}
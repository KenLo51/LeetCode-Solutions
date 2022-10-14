class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        unsigned int readIndex = 0;
        unsigned int storeIndex = 0;
        for(unsigned int i=0; i<nums.size(); i++){
            if(nums[i] == val){
                readIndex++;
            }
            else{
                nums[storeIndex] = nums[readIndex];
                readIndex++;    storeIndex++;
            }
        }
        return storeIndex;
    }
};
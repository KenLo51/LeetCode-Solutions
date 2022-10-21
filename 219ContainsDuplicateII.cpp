class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map <int, int> appearIndices;
        for(int i=0; i<nums.size(); i++){
            if(appearIndices.count(nums[i])){
                int diff = i - appearIndices[nums[i]];
                if(diff <= k) return true;
            }
            appearIndices[nums[i]] = i;
        }
        return false;
    }
};
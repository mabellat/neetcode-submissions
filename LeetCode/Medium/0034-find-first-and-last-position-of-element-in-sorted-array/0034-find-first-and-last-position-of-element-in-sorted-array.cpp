class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        if(nums.empty()) return {-1, -1};
        int idx1 = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int idx2 = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        // If idx1 is out of bounds or the element at idx1 is not the target
        if (idx1 == nums.size() || nums[idx1] != target) {
            return {-1, -1};
        }
        
        return {idx1, idx2 - 1};
    }
};
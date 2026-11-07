class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int max_index = 0;
        for(int i = 0;i<n-1;i++){
            if(i>max_index) return false;
            max_index = max(nums[i]+i, max_index);
        }
        return max_index>=n-1;
    }
};
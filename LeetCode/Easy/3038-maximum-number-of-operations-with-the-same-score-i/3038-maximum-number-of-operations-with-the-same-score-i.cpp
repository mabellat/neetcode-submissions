class Solution {
public:
    int maxOperations(vector<int>& nums) {
        int n = nums.size();
        int score = nums[0]+nums[1];
        int ans = 1;
        for(int i = 2;i+1<n;i+=2){
            int sum = nums[i]+nums[i+1];
            if(sum!=score) return ans;
            ans++; 
        }
        return ans;
    }
};
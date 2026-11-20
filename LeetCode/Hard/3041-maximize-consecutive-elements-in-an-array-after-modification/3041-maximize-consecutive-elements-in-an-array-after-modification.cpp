class Solution {
public:
    int n;
    vector<vector<int>> memo;
    int findVal(int val, int idx, vector<int> &nums){
        int i = lower_bound(nums.begin()+idx, nums.end(), val) - nums.begin();
        if(i < n and nums[i] == val) return i;
        return -1;
    }
    int solve(int i, int inc, vector<int> &nums){
        if(i >= n) return -1;
        if(memo[i][inc]!=-1) return memo[i][inc];
        int val = nums[i]+inc;
        int len = 1;
        // 1st : we'll directly find val+1
        int j = findVal(val+1, i+1, nums);
        if(j!=-1){
            len = max(len, 1+solve(j, 0, nums));
        }
        // 2nd : we'll find the val and then inc 1
        j = findVal(val, i+1, nums);
        if(j!=-1){
            len = max(len, 1+solve(j, 1, nums));
        }
        return memo[i][inc] = len;
    }

    int maxSelectedElements(vector<int>& nums) {
        n = nums.size();
        int ans = 1;
        memo.assign(n, vector<int>(2, 1));
        sort(nums.begin(), nums.end());      
        for(int i = n-1;i>=0;i--){
            for(int inc = 0;inc<2;inc++){
                int val = nums[i]+inc;
                int len = 1;
                // 1st : we'll directly find val+1
                int j = findVal(val+1, i+1, nums);
                if(j!=-1){
                    len = max(len, 1+memo[j][0]);
                }
                // 2nd : we'll find the val and then inc 1
                j = findVal(val, i+1, nums);
                if(j!=-1){
                    len = max(len, 1+memo[j][1]);
                }
                memo[i][inc] = len;
                ans = max(ans, memo[i][inc]);
            }
        }
        return ans;
    }
};
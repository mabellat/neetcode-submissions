class Solution {
public:
    int n;
    vector<vector<int>> memo;
    int f(int i, int j, vector<int> &nums, int sum){
        if(i>j) return 0;
        if(i>n or j<0) return 0;
        if(j == i) return 0;
        if(j-i+1 == 2) return nums[j]+nums[i] == sum ? 1:0;
        if(memo[i][j]!=-1) return memo[i][j];
        int ans = 0;
        // we can take the first 2 elements
        if(nums[i]+nums[i+1]==sum){
            ans = max(ans, 1+f(i+2, j, nums, sum));
        }
        if(nums[i]+nums[j] == sum){
            ans = max(ans, 1+f(i+1, j-1, nums, sum));
        }
        if(nums[j]+nums[j-1] == sum){
            ans = max(ans, 1+f(i, j-2, nums, sum));
        }
        return memo[i][j] = ans;
    }


    int maxOperations(vector<int>& nums) {
        n = nums.size();
        int sum1 = nums[0] + nums[1];
        int sum2 = nums[0] + nums[n - 1];
        int sum3 = nums[n - 1] + nums[n - 2];

        memo.assign(n, vector<int>(n, -1));
        int ans = f(0, n - 1, nums, sum1);

        // Reset all existing rows back to -1 without deallocating
        for (auto& row : memo) {
            fill(row.begin(), row.end(), -1);
        }
        ans = max(ans, f(0, n - 1, nums, sum2));

        for (auto& row : memo) {
            fill(row.begin(), row.end(), -1);
        }
        ans = max(ans, f(0, n - 1, nums, sum3));

        return ans;
    }
};
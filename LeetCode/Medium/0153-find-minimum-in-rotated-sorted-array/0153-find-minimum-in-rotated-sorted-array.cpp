class Solution {
public:
    int f(int l, int h, vector<int>& nums){
        // if(l > h) return; // lowest one
        // int mid = l + (h-l)/2; 
        while(l<h){
            int mid = l + (h-l)/2;
            // if nums[l]>nums[h] and nums[mid]>nums[l], then we need to move left to mid
            if(nums[mid]>nums[h]){
                l = mid+1;
            }
            else{
                h = mid;
            }

        }
        return nums[l];
    }

    int findMin(vector<int>& nums) {
        int n = nums.size();
        return f(0, n-1, nums);
    }
};
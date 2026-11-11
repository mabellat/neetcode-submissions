class Solution {
public:
    int bs(int l, int h, vector<int>& nums, int target){
        while(l<=h){
            int mid = l+(h-l)/2;
            if(nums[mid] == target) return mid;
            if(nums[mid]>target)
            {
                h = mid-1;
            }else{
                l = mid+1;
            }
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, h = n-1;
        // find pivot index and do binary search on the tow parts
        while(l<h){
            int mid = l+(h-l)/2;
            if(nums[mid] > nums[h]){
                l = mid+1;
            }else h = mid;
        }
        int pivot_idx = l;
        int ans1 = bs(0, pivot_idx-1, nums, target);
        int ans2 = bs(pivot_idx, n-1, nums, target);
        if(ans1 == -1 and ans2 == -1) return -1;
        else{
            if(ans1==-1) return ans2;
            else return ans1;
        }
    }
};
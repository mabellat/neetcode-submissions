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

    bool search(vector<int>& nums, int target) {
    int l = 0, h = nums.size() - 1;
    while (l <= h) {
        int mid = l + (h - l) / 2;
        if (nums[mid] == target) return true;

        if (nums[mid] > nums[h]) {                 // left half sorted
            if (nums[l] <= target && target < nums[mid]) h = mid - 1;
            else l = mid + 1;
        } else if (nums[mid] < nums[h]) {          // right half sorted
            if (nums[mid] < target && target <= nums[h]) l = mid + 1;
            else h = mid - 1;
        } else {                                   // nums[mid] == nums[h]
            h--;                                   // safe: h isn't the target
        }
    }
    return false;
}
};
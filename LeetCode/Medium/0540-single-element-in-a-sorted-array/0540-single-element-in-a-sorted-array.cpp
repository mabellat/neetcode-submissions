class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int l = 0, h = n-1;
        while(l<h){
            int mid = l+(h-l)/2;
            // if there are even number of elements in the right side and nums[mid]!=nums[mid+1], we move to the left
            if(nums[mid] == nums[mid+1]){
                if((h-mid)%2 == 0){
                    l = mid+2;
                }else h = mid-1;
            }else{
                if((h-mid)%2 == 0){
                    h = mid;
                }else l = mid+1;
            }
        }
        return nums[l];
    }
};
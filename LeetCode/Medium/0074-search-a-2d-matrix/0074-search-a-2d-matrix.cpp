class Solution {
public:

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int l = 0, h = (n*m)-1;
        while(l<=h){
            int mid = l+(h-l)/2;
            int row = mid/m;
            int col = mid%m;
            if(matrix[row][col] == target) return true;
            if(matrix[row][col]>target){
                h = mid-1;
            }else{
                l = mid+1;
            }
            // col can be gotten by mod by number of cols
            // row can be gotten by divide by number of rows
        }
        return false;
    }
};
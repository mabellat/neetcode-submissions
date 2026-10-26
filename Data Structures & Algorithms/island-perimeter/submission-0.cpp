class Solution {
public:
    int f(int i, int j, vector<vector<int>>& grid, int n, int m){
        if(i < 0 or j<0 or i>=n or j>=m or grid[i][j] == 0) return 1; // contributes and edges
        if(grid[i][j] == -1) return 0;
        grid[i][j] = -1;
        int top = 0, bottom = 0, left = 0, right = 0;
        top = f(i-1, j, grid, n, m);
        bottom = f(i+1, j, grid, n, m);
        left = f(i, j-1, grid, n, m);
        right = f(i, j+1, grid, n, m);
        return top+bottom+left+right;
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == 1){
                    return f(i, j, grid, n, m);
                }
            }
        }
        return -1;
    }
};
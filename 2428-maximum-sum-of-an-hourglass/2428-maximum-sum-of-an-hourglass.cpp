class Solution {
public:
    int gethour(vector<vector<int>>& grid, int i, int j) {
        return  grid[i - 1][j - 1] + grid[i - 1][j] + grid[i - 1][j + 1] + 
                grid[i][j] + 
                grid[i + 1][j - 1] + grid[i + 1][j] + grid[i + 1][j + 1];
    }
    int maxSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int res = INT_MIN;
        for(int i = 1; i < n - 1; i++)
            for(int j = 1; j < m - 1; j++)
                res = max(res, gethour(grid, i, j));
        
        return res;
    }
};
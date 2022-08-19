class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp (m, vector<int> (n, -1));
        return countUnique(m-1, n-1, grid, dp);
    }
    
    int countUnique(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp)
    {
        if(i == 0 and j == 0 and !grid[i][j]) return 1;
        if(i < 0 or j < 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(grid[i][j]) return 0;
        int up = 0, left = 0;
        up = countUnique(i-1, j, grid, dp);
        left = countUnique(i, j-1, grid, dp);
        
        return dp[i][j] = up + left;
    }
};
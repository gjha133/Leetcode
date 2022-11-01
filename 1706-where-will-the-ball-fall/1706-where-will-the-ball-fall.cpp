class Solution {
public:
    int f(vector<vector<int>>&grid, int &rows , int &cols , vector<vector<int>>&dp,int i , int j)
    {
        if(i >= rows)return j;
        
        if(dp[i][j] != -2)return dp[i][j];
        
        int col = -1;
        
        if(grid[i][j] == 1 && j + 1 < cols && grid[i][j+1] != -1)
        {
            col = f(grid, rows, cols, dp, i+1, j+1);
        }
        if(grid[i][j] == -1 && j-1>=0 && grid[i][j-1] != 1)
        {
            col = f(grid, rows, cols, dp, i+1, j-1);
        } 
        
        return dp[i][j] = col;
    }
    
    vector<int> findBall(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        vector<int> ans(cols, 0);
        vector<vector<int>> dp(rows, vector<int>(cols, -2));
        
        for(int i = 0; i < cols; i++)
        {
            ans[i] = f(grid,rows,cols,dp,0,i);
        }
        
        return ans;
    }
};
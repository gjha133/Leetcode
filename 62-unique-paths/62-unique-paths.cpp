class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[m][n];
        
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i == 0 and j == 0) dp[i][j] = 1;
                else
                {
                    int up = 0, left = 0;
                    if(i > 0) up = dp[i-1][j];
                    if(j > 0) left = dp[i][j-1];
                    dp[i][j] = up + left;
                }                
            }
        }
        return dp[m-1][n-1];
    }
    
    
    // Memoization
    int countPaths(int row, int col, vector<vector<int>> &dp)
    {
        if(row == 0 and col == 0) return 1;
        
        if(row < 0 or col < 0) return 0;
        
        if(dp[row][col] != -1) return dp[row][col];
        
        int up = countPaths(row - 1, col, dp);
        int left = countPaths(row, col - 1, dp);
        
        return dp[row][col] = up + left;
    }
};
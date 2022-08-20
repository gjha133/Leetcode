class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int dp[n][n];
        
        for(int j = 0; j<n; j++) dp[n-1][j] = grid[n-1][j];
              
        for(int i = n-2; i >= 0; i--)
        {
            for(int j = 0; j < n; j++)
            {
                int ans = INT_MAX;  
                for(int x = 0; x < n; x++)
                {
                    if(x != j)
                        ans = min(ans, grid[i][j] + dp[i+1][x]);
                }
                dp[i][j] = ans;
            }
        }
        int ans = dp[0][0];
        for(int col = 1; col < n; col++) ans = min(ans, dp[0][col]);
        
        return ans;
    }
};
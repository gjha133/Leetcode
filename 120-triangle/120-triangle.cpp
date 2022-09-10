class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int dp[n][n];
        
        // Since we did recursion from (0 -> n-1). Tabulation should be reverse of that i.e, from (n-1 -> 0)
        
        // Base Case
        for(int j = 0; j < n; j++)
        {
            dp[n-1][j] = triangle[n-1][j];
        }
        
        for(int i = n-2; i >= 0; i--)
        {
            for(int j = 0; j <= i; j++)
            {
                int down = dp[i+1][j];
                int diagonal = dp[i+1][j+1];
                dp[i][j] = triangle[i][j] + min(down, diagonal);
            }
        }
        
        return dp[0][0];
    }
};
    
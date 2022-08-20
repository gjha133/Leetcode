class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int dp[n][n];
        
        for(int j = 0; j<n; j++) dp[n-1][j] = matrix[n-1][j];
        for(int i = n-2; i >= 0; i--)
        {
            for(int j = 0; j<n; j++)
            {
                int leftD = INT_MAX, rightD = INT_MAX;
                if(j > 0) leftD = dp[i+1][j-1];
                int straight = dp[i+1][j];
                if(j < n-1) rightD = dp[i+1][j+1];
                dp[i][j] = matrix[i][j] + min(straight, min(leftD, rightD));
            }
        }
        
        int ans = INT_MAX;
        for(int j = 0; j<n; j++)
        {
            ans = min(ans, dp[0][j]);
        }
        
        return ans;
    }
    
};
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp (n, vector<int> (amount + 1, 0));
        
        for(int i = 0; i < n; i++) dp[i][0] = 1;
        
        for(int j = 1; j <= amount; j++) if(j % coins[0] == 0) dp[0][j] = 1;
        
        for(int i = 1; i < n; i++)
        {
            for(int target = 1; target <= amount; target++)
            {
                int notTake = dp[i-1][target];
                int take = 0;
                if(target >= coins[i]) take = dp[i][target - coins[i]];
                
                dp[i][target] = notTake + take;
            }
        }
        
        return dp[n-1][amount];
    }
    
};
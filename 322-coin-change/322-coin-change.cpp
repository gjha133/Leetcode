class Solution {
public:
    int coinChange(vector<int>& coins, int target) {
        if(target == 0) return 0;
        int n = coins.size();
        int dp[n][target+1];
        
        for(int t = 0; t <= target; t++)
        {
            if(t % coins[0] == 0) dp[0][t] = t/coins[0];
            else dp[0][t] = 1e9;
        }
        
        for(int i = 1; i<n; i++)
        {
            for(int t = 0; t<=target; t++)
            {
                int notTake = dp[i-1][t];
                int take = INT_MAX;
                if(t >= coins[i]) take = 1 + dp[i][t - coins[i]];
                dp[i][t] = min(take, notTake);
            }
        }
        
        int ans = dp[n-1][target];
        if(ans >= 1e9) return -1;
        return ans;
    }
    
};
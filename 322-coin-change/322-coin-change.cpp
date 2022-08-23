class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        
        int n = coins.size();
        vector<vector<int>> dp (n, vector<int> (amount + 1, -1));
        
        int ans = f(n-1, amount, coins, dp);
        if(ans == 1e9) return -1;
        
        return ans;
    }
    
    int f(int i, int target, vector<int>& num, vector<vector<int>>& dp)
    {
        if(target == 0) return 0;
        if(i == 0)
        {
            if(target % num[0] == 0) return target/num[0];
            else return 1e9;
        }
        
        if(dp[i][target] != -1) return dp[i][target];
        
        int notTake = 0 + f(i-1, target, num, dp);
        int take = INT_MAX;
        if(target >= num[i]) take = 1 + f(i, target - num[i], num, dp);

        return dp[i][target] = min(take, notTake);
    }
};
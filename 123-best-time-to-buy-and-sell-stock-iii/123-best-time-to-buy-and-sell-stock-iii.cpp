class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp (n, vector<vector<int>> (2, vector<int> (3, -1)));
        return f(0, 1, 2, prices, dp);
    }
    
    int f(int i, int canBuy, int k, vector<int>& prices, vector<vector<vector<int>>>& dp)
    {
        int n = prices.size();
        
        // Base Case
        if(i == n or k == 0) return 0;
        if(dp[i][canBuy][k] != -1) return dp[i][canBuy][k];
        
        int profit = 0;
        if(canBuy)
        {
            profit = max( (-prices[i] + f(i+1, false, k, prices, dp)),   f(i+1, true, k, prices, dp) );
        }
        else
        {
            profit = max( (prices[i] + f(i+1, true, k-1, prices, dp)), (f(i+1, false, k, prices, dp)) );
        }   
        
        return dp[i][canBuy][k] = profit;
    }
};
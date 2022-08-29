class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp (n+1, vector<int> (2, -1));
        return f(0, 1, prices, dp);
    }
    
    int f(int i, bool canBuy, vector<int>& prices, vector<vector<int>>& dp)
    {
        if(i >= prices.size()) return 0;
        if(dp[i][canBuy] != -1) return dp[i][canBuy];
        
        int profit = 0;
        if(canBuy)
        {
            int Buy = -prices[i] + f(i + 1, false, prices, dp);
            int notBuy = 0 + f(i + 1, true, prices, dp);
            profit = max(Buy, notBuy);
        }
        else // Cant Buy->>> Going to Sell
        {
            int Sell = prices[i] + f(i + 2, true, prices, dp);
            int notSell = 0 + f(i + 1, false, prices, dp);
            profit = max(Sell, notSell);
        }
        
        return dp[i][canBuy] = profit;
    }
};
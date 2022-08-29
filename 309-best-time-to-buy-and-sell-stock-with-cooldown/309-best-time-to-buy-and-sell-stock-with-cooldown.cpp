class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp (n+2, vector<int> (2, 0));
        
        for(int i = n-1;i >= 0; i--)
        {
            for(int buy = 0; buy < 2; buy++)
            {
                int profit = 0;
                if(buy)
                {
                    profit = max(-prices[i]+dp[i+1][0],dp[i+1][1]);
                }
                else
                {
                    profit = max(prices[i]+dp[i+2][1],dp[i+1][0]);
                } 
                
                dp[i][buy]=profit;
            }
        }
        
        return dp[0][1];
        
        //return f(0, 1, prices, dp);
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
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        for(int i = n-1;i >= 0; i--)
        {
            for(int buy = 0; buy < 2; buy++)
            {
                int profit = 0;
                if(buy)
                {
                    profit = max(-prices[i] -fee + dp[i+1][0], dp[i+1][1]);
                }
                else
                {
                    profit = max(prices[i] + dp[i+1][1], dp[i+1][0]);
                } 
                
                dp[i][buy]=profit;
            }
        }
        
        return dp[0][1];
    }
    
    int fmemo(int i, bool canBuy, int fee, vector<int>& prices, vector<vector<int>>& dp)
    {
        if(i == prices.size()) return 0;
        if(dp[i][canBuy] != -1) return dp[i][canBuy];
        
        int profit = 0;
        if(canBuy)
        {
            int Buy = -prices[i] -fee + fmemo(i + 1, false, fee,  prices, dp);
            int notBuy = 0 + fmemo(i + 1, true, fee, prices, dp);
            profit = max(Buy, notBuy);
        }
        else // Cant Buy->>> Going to Sell
        {
            int Sell = prices[i] + fmemo(i + 1, true, fee, prices, dp);
            int notSell = 0 + fmemo(i + 1, false, fee, prices, dp);
            profit = max(Sell, notSell);
        }
        
        return dp[i][canBuy] = profit;
    }
};





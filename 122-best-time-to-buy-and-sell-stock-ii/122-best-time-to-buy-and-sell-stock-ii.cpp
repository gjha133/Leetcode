class Solution {
public:
    int maxProfit(vector<int>& prices) {
       vector<vector<int>>dp(prices.size()+2,vector<int>(2,0));
        for(int i=prices.size()-1;i>=0;i--){
            for(int j=0;j<2;j++){
        int take=0;
        if(j){
            take=max(-prices[i]+dp[i+1][0],dp[i+1][1]);
        }
        else{
            take=max(prices[i]+dp[i+1][1],dp[i+1][0]);
        } dp[i][j]=take;
            }
        }
        return dp[0][1];
    }
        
    int fmemo(int i, bool canBuy, vector<int>& prices, vector<vector<int>>& dp)
    {
        if(i == prices.size()) return 0;
        if(dp[i][canBuy] != -1) return dp[i][canBuy];
        
        int profit = 0;
        if(canBuy)
        {
            int Buy = -prices[i] + fmemo(i + 1, false, prices, dp);
            int notBuy = 0 + fmemo(i + 1, true, prices, dp);
            profit = max(Buy, notBuy);
        }
        else // Cant Buy->>> Going to Sell
        {
            int Sell = prices[i] + fmemo(i + 1, true, prices, dp);
            int notSell = 0 + fmemo(i + 1, false, prices, dp);
            profit = max(Sell, notSell);
        }
        
        return dp[i][canBuy] = profit;
    }
};
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp (n+1, vector<vector<int>> (2, vector<int> (3, 0)));
        return ftab(2, prices, dp);
    }
    
    int fmemo(int i, int canBuy, int k, vector<int>& prices, vector<vector<vector<int>>>& dp)
    {
        int n = prices.size();
        
        // Base Case
        if(i == n or k == 0) return 0;
        if(dp[i][canBuy][k] != -1) return dp[i][canBuy][k];
        
        int profit = 0;
        if(canBuy)
        {
            profit = max( (-prices[i] + fmemo(i+1, false, k, prices, dp)),   fmemo(i+1, true, k, prices, dp) );
        }
        else
        {
            profit = max( (prices[i] + fmemo(i+1, true, k-1, prices, dp)), fmemo(i+1, false, k, prices, dp) );
        }   
        
        return dp[i][canBuy][k] = profit;
    }
    
    int ftab(int cap, vector<int>& prices, vector<vector<vector<int>>>& dp)
    {
        int n = prices.size();
        // No need for base cases and 0 already assigned
        
        for(int i = n-1; i >= 0; i--)
        {
            for(int buy = 0; buy <= 1; buy++)
            {
                for(int k = 1; k <= 2; k++)
                {
                    int profit = 0;
                    if(buy)
                    {
                        profit = max( (-prices[i] + dp[i+1][false][k]),   dp[i+1][true][k] );
                    }
                    else
                    {
                        profit = max( (prices[i] + dp[i+1][true][k-1]),   dp[i+1][false][k] );
                    }   

                    dp[i][buy][k] = profit;
                }
            }
        }
        
        return dp[0][1][cap];
    }
};
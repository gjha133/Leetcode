class Solution {
public:
    int f(int i,int buy,int cap,vector<int>& prices,vector<vector<vector<int>>>& dp)
    {
        if(i==prices.size() || cap==0)
            return 0;

        if(dp[i][buy][cap]!=-1) return dp[i][buy][cap];

        int profit=0;
        if(buy)
        {
            profit= max(-prices[i]+f(i+1,0,cap,prices,dp),0+f(i+1,1,cap,prices,dp));
        }
        else
        {
            profit= max(prices[i]+f(i+1,1,cap-1,prices,dp),0+f(i+1,0,cap,prices,dp));
        }

        return dp[i][buy][cap]=profit;
    }
    
    int ftab(int cap, vector<int>& prices, vector<vector<vector<int>>>& dp)
    {
        int n = prices.size();
        // No need for base cases and 0 already assigned
        
        for(int i = n-1; i >= 0; i--)
        {
            for(int buy = 0; buy <= 1; buy++)
            {
                for(int k = 1; k <= cap; k++)
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
    int maxProfit(int k, vector<int>& prices) 
    {
        int n = prices.size();
        vector<vector<vector<int>>> dp (n+1, vector<vector<int>> (2, vector<int> (k+1, 0)));
        return ftab(k, prices, dp);


        /*for(int i=n-1;i>=0;i--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                for(int cap=0;i<=k;cap++)
                {
                    if(buy==1)
                    {
                        dp[i][buy][cap]=max(-prices[i]+dp[i+1][0][cap],0+dp[i+1][1][cap]);
                    }
                    else
                    {
                        dp[i][buy][cap]=max(prices[i]+dp[i+1][1][cap-1],0+dp[i+1][0][cap]);
                    }
                }
            }
        }

        return dp[0][1][k];*/
        //return f(0,1,k,prices,dp);

    }
};
class Solution {
public:
    /*
    int climbStairs(int n) 
    {
        vector<int> dp (n+1, -1);
        return helper(n,dp);       
    }
    
    int helper(int n, vector<int> &dp)
    {
        if(n == 0 || n == 1) return 1;
        
        if(dp[n] != -1) return dp[n];
        
        int byone = helper(n-1, dp);
        int bytwo = helper(n-2, dp);
        
        int ans = byone + bytwo;
        dp[n] = ans;
        return dp[n];
        
    }
    */
    
    int climbStairs(int n)
    {
        int prev2 = 1, prev1 = 1;
        
        for(int i = 2; i <= n; i++)
        {
            int curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        
        return prev1;
        
    }
    
};
class Solution {
public:
    /*
    int climbStairs(int n) 
    {
        vector<int> ways (n+1, -1);
        return helper(n,ways);       
    }
    
    int helper(int n, vector<int> &ways)
    {
        if(n == 0 || n == 1) return 1;
        
        if(ways[n] != -1) return ways[n];
        
        int byone = helper(n-1, ways);
        int bytwo = helper(n-2, ways);
        
        int ans = byone + bytwo;
        ways[n] = ans;
        return ways[n];
        
    }
    */
    
    int climbStairs(int n)
    {
        vector<int> dp(n+1);
        dp[0] = 1, dp[1] = 1;
        
        for(int i = 2; i<=n; i++)
        {
            dp[i] = dp[i-1] + dp[i-2];
        }
        
        return dp[n];
        
    }
    
};
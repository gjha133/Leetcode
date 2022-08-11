class Solution {
public:
    int tribonacci(int n) {
        
        vector<int> dp (n+1, -1);
        return memoize(n, dp);
    }
    
    int memoize(int n, vector<int> &dp)
    {
        if(n == 0) return 0;
        if(n == 1 or n == 2) return 1;
        
        if(dp[n] != -1) return dp[n];
        
        return dp[n] = memoize(n - 1, dp) + memoize(n - 2, dp) + memoize(n - 3, dp);
    }
};
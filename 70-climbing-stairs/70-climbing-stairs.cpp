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
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp (n, -1);
        return f(0, nums, dp);
    }
    
    int f(int i, vector<int>& nums, vector<int>& dp)
    {
        int n = nums.size();
        if(i >= n-1) return 0;
        
        if(dp[i] != -1) return dp[i];
        
        int mn = 1e9;
        for(int j = i + 1; j <= i + nums[i]; j++)
            mn = min(mn, 1 + f(j, nums, dp));
        
        return dp[i] = mn;
    }
};
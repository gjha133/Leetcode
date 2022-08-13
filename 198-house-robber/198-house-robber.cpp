class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, -1);
        return robber(0, n, nums, dp);
    }
    
private:
    int robber(int i, int n, vector<int> &nums, vector<int> &dp)
    {
        if(i >= n) return 0;
        if(i == n-1) return nums[i];
        if(dp[i] != -1) return dp[i];
        
        int pick = nums[i] + robber(i+2, n, nums, dp);
        int notpick = 0 + robber(i+1, n, nums, dp);
        
        return dp[i] = max(pick, notpick);
    }
};
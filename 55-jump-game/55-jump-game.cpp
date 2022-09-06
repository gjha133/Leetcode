class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<int> dp (nums.size(), -1);
        return f(0, nums, dp);
    }
    
    bool f(int i, vector<int>& nums, vector<int>& dp)
    {
        int n = nums.size();
        if(i == n - 1) return true;
        if(nums[i] == 0) return false;
        
        if(dp[i] != -1) return dp[i];
        
        for(int j = i + 1; j <= i + nums[i]; j++)
        {
            if(f(j, nums, dp)) return dp[i] = true;
        }
        
        return dp[i] = false;
    }
};
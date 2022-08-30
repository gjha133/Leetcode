class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp (n, 1);
        
        int mx = 1;
        for(int i = 0; i < n; i++)
        {
            for(int prev_i = 0; prev_i < i; prev_i++)
            {
                if(nums[i] > nums[prev_i])
                    dp[i] = max(dp[i], 1 + dp[prev_i]);
            }
            
            mx = max(mx, dp[i]);
        }
        
        return mx;
    }
};
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp (n, 0);
        dp[n-1] = 1;
        
        for(int i = n-2; i >= 0; i--)
        {
            if(nums[i] >= n - 1 - i) dp[i] = true;
            else
            {
                for(int j = i + 1; j <= i + nums[i]; j++)
                {
                    if(dp[j]) dp[i] = true;               
                }
            }
                
        }
        
        return dp[0];
    }
    
};
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp (n, 0);
        
        for(int i = n-2; i >= 0; i--)
        {
            if(nums[i] >= n - 1 - i) dp[i] = 1;
            else 
            {
                int mn = 1e9;
                for(int j = i + 1; j <= i + nums[i]; j++)
                    mn = min(mn, 1 + dp[j]);

                dp[i] = mn;
            }            
        }
        
        return dp[0];
    }
};
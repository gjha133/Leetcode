class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp (n, 1);
        
        for(int i = 0; i < n; i++) {
            for(int prev = 0; prev < i; prev++) {
                if(nums[i] > nums[prev])
                    dp[i] = max(dp[i], 1 + dp[prev]);
            }
        }
        
        int mx = 0;
        for(int num : dp) mx = max(num, mx);
        
        return mx;
    }
};
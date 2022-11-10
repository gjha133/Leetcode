class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int mn = nums[0];
        int ans = 0, n = nums.size();
        
        for(int i = 1; i < n; i++)
        {
            int diff = nums[i] - mn;
            ans = max(ans, diff);
            mn = min(mn, nums[i]);
        }
        
        return ans == 0? -1 : ans;
    }
};
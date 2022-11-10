class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int n = nums.size();
        int mx = nums[0], ans = 0;
        vector<int> mn (n, nums[n-1]);
        
        for(int i = n-2; i >= 0; i--)
            mn[i] = min(nums[i], mn[i+1]);
        
        for(int i = 1; i < n-1; i++)
        {
            if(nums[i] > mx and nums[i] < mn[i+1]) ans += 2;
            else if(nums[i] > nums[i-1] and nums[i] < nums[i+1]) ans++;
            mx = max(mx, nums[i]);
        }
        
        return ans;
    }
};
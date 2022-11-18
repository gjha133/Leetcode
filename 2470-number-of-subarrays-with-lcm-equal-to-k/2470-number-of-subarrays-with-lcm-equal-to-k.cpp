class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) {
        int ans = 0, n = size(nums);
        for (int i = 0; i < n; i++)
        {
            int currLcm = 1;
            for (int j = i; j < n; j++)
            {
                currLcm = lcm(currLcm, nums[j]);
                if (currLcm == k) ans++;
                if (currLcm > k) break;
            }
        }
        return ans; 
    }
};
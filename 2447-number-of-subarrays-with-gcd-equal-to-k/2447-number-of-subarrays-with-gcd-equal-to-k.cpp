class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int ans = 0, n = size(nums);
        for (int i = 0; i < n; i++)
        {
            int currGcd = 0;
            for (int j = i; j < n; j++)
            {
                currGcd = gcd(currGcd, nums[j]);
                if (currGcd == k) ans++;
                if(currGcd == 1 and k != 1) break;
            }
        }
        return ans; 
    }
};
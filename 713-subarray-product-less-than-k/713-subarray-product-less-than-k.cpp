class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1) return 0;
        int ans = 0, i = 0, j = 0, n = nums.size();
        int prod = 1;
        
        while(j < n)
        {
            prod = prod * nums[j];
            while(prod >= k)
            {
                prod = prod/nums[i];
                i++;
            }
            ans += j - i + 1;
            j++;
        }
        
        return ans;
    }
};
class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long ans = 1;
        int i = 0, j = 1, n = prices.size();
        
        while(j < n)
        {
            if(prices[j-1] - prices[j] == 1)
            {
                ans += j - i + 1;
                // Why ans += j - i + 1
                // Same concept as 
                //713. Subarray Product Less Than K
                //https://leetcode.com/problems/subarray-product-less-than-k/
            }
            else
            {
                i = j;
                ans += 1;
            }
            j++;
        }
        
        return ans;
    }
};
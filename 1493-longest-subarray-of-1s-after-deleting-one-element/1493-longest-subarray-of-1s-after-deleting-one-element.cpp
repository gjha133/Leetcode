class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int zero = 0, one = 0, mx = INT_MIN, i = 0, j = 0, n = nums.size();
        
        while(j < n)
        {
            if(nums[j] == 0) zero++;
            else one++;
            if(zero == 1)
            {
                mx = max(mx, j - i + 1 - zero);
            }
            
            while(zero == 2)
            {
                if(nums[i] == 0) zero--;
                i++;
            }
            
            j++;
        }
        
        
        return mx == INT_MIN ? one - 1 : mx;
    }
};
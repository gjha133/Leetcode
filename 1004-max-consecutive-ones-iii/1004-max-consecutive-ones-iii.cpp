class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i = 0, j = 0, mx = 0, zero_count = 0, n = nums.size();
        
        while(j < n)
        {
            if(nums[j] == 0) zero_count++;
            while(zero_count > k)
            {
                if(nums[i] == 0) zero_count--;
                i++;
            }
            mx = max(mx, j - i + 1);
            j++;
        }
        
        return mx;
    }
};
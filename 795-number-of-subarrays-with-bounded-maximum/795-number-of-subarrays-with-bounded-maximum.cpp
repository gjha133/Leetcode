class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int ans = 0, n = nums.size(), i = 0, j = 0;
        int prev_window = 0;
        while(j < n)
        {
            if(nums[j] >= left and nums[j] <= right)
            {
                ans += j - i + 1;
                prev_window = j - i + 1;
                j++;
            }
            else if(nums[j] < left)
            {
                ans += prev_window;
                j++;
            }
            else if(nums[j] > right)
            {
                j++;
                i = j;
                prev_window = 0;
            }
        }
        
        return ans;
    }
};
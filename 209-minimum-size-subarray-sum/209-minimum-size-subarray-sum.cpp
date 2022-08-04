class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int mn = INT_MAX, sum = 0, i = 0, j = 0, n = nums.size();
        
        while( j < n )
        {
            sum += nums[j];
            if(sum < target) j++;
            else
            {
                while(sum >= target)
                {
                    mn = min(mn, j - i + 1);
                    sum -= nums[i];
                    i++;
                }
                j++;
            }
        }
        
        return mn == INT_MAX ? 0 : mn;
    }
};
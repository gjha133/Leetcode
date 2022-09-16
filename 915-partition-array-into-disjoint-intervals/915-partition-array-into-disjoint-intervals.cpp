class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size();
        int maxLeft = nums[0], max = nums[0], ans = 0;
        
        for(int i = 1; i < n; i++)
        {
            if(nums[i] < maxLeft)
            {
                maxLeft = max;
                ans = i;
            }
            else if(max < nums[i])
            {
                max = nums[i];
            }
        }
        
        return ans + 1;
    }
};
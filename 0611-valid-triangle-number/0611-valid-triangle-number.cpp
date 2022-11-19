class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), ans = 0;
        for(int third = 2; third < n; third++)
        {
            int first = 0, second = third-1;
            while(first < second)
            {
                if(nums[first] + nums[second] > nums[third])
                {
                    ans += second-first;
                    second--;
                }
                else
                    first++;
            }
        }
        
        return ans;
    }
};
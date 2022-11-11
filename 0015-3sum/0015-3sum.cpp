class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> threesome;
        
        for(int i = 0; i < n-2; i++)
        {
            if(i > 0 and nums[i] == nums[i-1]) continue;
            int start = i + 1, end = n-1;
            
            while(start < end)
            {
                int sum = nums[start] + nums[end] + nums[i];
                if(sum < 0) start++;
                else if(sum > 0) end--;
                else
                {
                    vector<int> ans = {nums[i], nums[start], nums[end]};
                    threesome.push_back(ans);
                    
                    while(start + 1 < end and nums[start] == nums[start+1]) start++;
                    while(start < end - 1 and nums[end] == nums[end-1]) end--;
                    start++;    end--;
                }
            }
        }
        
        
        
        return threesome;
    }
};
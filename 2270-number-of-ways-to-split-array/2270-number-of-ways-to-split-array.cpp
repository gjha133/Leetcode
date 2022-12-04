class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        long sumStart = 0, sumEnd = 0;
        
        for (auto& num : nums) sumEnd += num;
        
        for(int i = 0; i < n-1; i++)
        {
            sumStart += nums[i];
            sumEnd   -= nums[i];
            
            if(sumStart >= sumEnd) ans++;
        }
        
        return ans;
    }
};
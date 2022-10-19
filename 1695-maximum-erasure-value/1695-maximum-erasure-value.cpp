class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int, int> mp;
        int n = nums.size(), i = 0, j = 0, mx = INT_MIN, sum = 0;
        
        while(j < n)
        {
            mp[nums[j]]++;
            sum += nums[j];
            if(j - i + 1 == mp.size()) mx = max(mx, sum);
            while(j - i + 1 > mp.size())
            {
                sum -= nums[i];
                mp[nums[i]]--;
                if(mp[nums[i]] == 0) mp.erase(nums[i]);
                i++;
                if(j - i + 1 == mp.size()) mx = max(mx, sum);
            }
            
            j++;
        }
        
        return mx;
    }
};
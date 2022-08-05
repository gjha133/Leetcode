class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {   
        unordered_map<int, int> mp;
        mp[0] = 1;
        int sum = 0, ans = 0;     
        
        for(int num : nums)
        {
            sum += num % 2;
            ans += mp[sum-k];
            mp[sum]++;
        }       
        
        return ans;
    }
};
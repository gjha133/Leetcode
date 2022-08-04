class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> mp;         // Store prefixSum and value
        mp[0] = 1;
        int runningSum = 0, ans = 0;
        
        /*
        We are basically keeping track of remainders and if we get same remainders between two nums then the
        subarrays in between them are divisible by k as their remainder is 0 .
        */       
        
        for(auto num : nums)
        {
            runningSum += num;
            runningSum %= k;
            if(runningSum < 0) runningSum += k; // since -1 % 5 == 4 % 5
            if(mp.count(runningSum)) ans += mp[runningSum];
            
            mp[runningSum]++;
        }
        return ans;
    }
};
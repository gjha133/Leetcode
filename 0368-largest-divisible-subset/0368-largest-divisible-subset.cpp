class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        vector<int> dp(n, 1), hash(n, 1);
        
        for(int i = 0; i < n; i++) {
            hash[i] = i;
            for(int prev = 0; prev < i; prev++) {
                if(nums[i] % nums[prev] == 0 and 1 + dp[prev] > dp[i]) {
                    dp[i] = 1 + dp[prev];
                    hash[i] = prev;
                }
            }
        }
        
        int mx = -1, lastIndex = -1;
        for(int i = 0; i < n; i++) {
            if(dp[i] > mx) {
                mx = dp[i];
                lastIndex = i;
            }
        }
        
        vector<int> temp;
        temp.push_back(nums[lastIndex]);
        
        while(lastIndex != hash[lastIndex]) {
            lastIndex = hash[lastIndex];
            temp.push_back(nums[lastIndex]);
        }
        
        reverse(temp.begin(), temp.end());
        return temp;
    }
};
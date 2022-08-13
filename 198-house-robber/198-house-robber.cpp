class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(!n) return 0;
        vector<int> dp(n);
        int prev = nums[0], prev2 = 0;
        
        for(int i = 1; i<n; i++)
        {
            int take = nums[i];
            if(i > 1) take += prev2;
            int nottake = prev;
            int cur = max(take, nottake);
            
            prev2 = prev;
            prev = cur;
        }
        return prev;
    }

};
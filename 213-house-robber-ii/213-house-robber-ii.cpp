class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        vector<int> temp1;
        vector<int> temp2;
        
        for(int i=0; i<nums.size(); i++)
        {
            if(i != 0) temp1.push_back(nums[i]);
            if(i != nums.size()-1) temp2.push_back(nums[i]);            
        }
        
        return max(robbing(temp1), robbing(temp2));
    }
    
    int robbing(vector<int>& nums) {
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
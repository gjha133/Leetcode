class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int prod = 1;
        int zero = 0, zero_index = -1;
        for(int i = 0; i < nums.size(); i++)
        {
            int num = nums[i];
            if(!num)
            {
                zero++;
                num = 1;
                zero_index = i;
            }
            prod *= num;
        }
        
        vector<int> ans (nums.size(), 0);
        if(zero >= 2) return ans;
        else if(zero == 1)
        {
            ans[zero_index] = prod;
            return ans;
        }
        else
        {
            for(int i = 0; i < nums.size(); i++)
            {
                ans[i] = prod/nums[i];
            }
        }
        
        return ans;
        
    }
};
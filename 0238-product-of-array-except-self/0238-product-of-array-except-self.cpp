class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int prod = 1, n = nums.size();
        int zero_count = 0, zero_index = -1;
        for(int i = 0; i < n; i++)
        {
            int num = nums[i];
            if(!num)
            {
                zero_count++;
                num = 1;
                zero_index = i;
            }
            prod *= num;
        }
        
        vector<int> ans (n, 0);
        if(zero_count >= 2) return ans;
        else if(zero_count == 1)
        {
            ans[zero_index] = prod;
            return ans;
        }
        else       // If no zeroes
        {
            for(int i = 0; i < n; i++)
            {
                ans[i] = prod/nums[i];
            }
        }
        
        return ans;
        
    }
};
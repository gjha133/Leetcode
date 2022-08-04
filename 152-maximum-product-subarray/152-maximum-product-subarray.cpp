class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int left_product = 1, right_product = 1, mx = INT_MIN, n = nums.size();
        
        for(int i=0; i<n; i++)
        {
            left_product *= nums[i];            
            right_product *= nums[n - i - 1];
            
            mx = max(mx, max(left_product, right_product));
            
            if(left_product == 0) left_product = 1;
            if(right_product == 0) right_product = 1;
        }
        
        return mx;      
        
    }
};
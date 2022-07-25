class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        
        int min1 = INT_MAX, min2 = INT_MAX,
        max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
        
        for(int num : nums)
        {
            // For all maximums
            if(num >= max1)
            {
                max3 = max2;
                max2 = max1;
                max1 = num;
            }
            else if(num >= max2)
            {
                max3 = max2;
                max2 = num;
            }
            else if(num >= max3)
            {
                max3 = num;
            }
            
            // For all minimums
            
            if(num <= min1)
            {
                min2 = min1;
                min1 = num;
            }
            else if(num <= min2)
            {
                min2 = num;
            }            
        }
        
        return max( (min1*min2*max1), (max1*max2*max3) );
    }
};
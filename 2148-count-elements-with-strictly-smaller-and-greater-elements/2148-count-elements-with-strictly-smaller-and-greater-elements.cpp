class Solution {
public:
    int countElements(vector<int>& nums) {
        int max = INT_MIN, min = INT_MAX;
        for(int num : nums)
        {
            if(num > max) max = num;
            if(num < min) min = num;
        }
        
        int count = 0;
        for(int num : nums)
        {
            if(num > min and num < max) count++;
        }
        
        return count;       
        
    }
};
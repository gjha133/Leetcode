class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int j = 0, count = 0, mx = 0;        
        while(j < nums.size())
        {
            if(nums[j] == 1) mx = max(mx, ++count);
            else count = 0;
            j++;
        }
        
        return mx;
    }
};
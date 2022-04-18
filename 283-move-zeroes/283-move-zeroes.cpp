class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int zeroCount = 0;
        for(int num : nums)
        {
            if(num == 0) ++zeroCount;
        }
        
        int start = 0, i = 0;
        for(int i=0; i < nums.size(); i++)
        {
            if(nums[i] != 0)
            {
                nums[start++] = nums[i];
            }
        }
        
        while(start != nums.size())
        {
            nums[start++] = 0;
        }
    }
};
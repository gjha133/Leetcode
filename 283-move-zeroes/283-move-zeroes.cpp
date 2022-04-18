class Solution {
public:
    void moveZeroes(vector<int>& nums) {
                
        int start = 0, i = 0;
        for(; i < nums.size(); i++)
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
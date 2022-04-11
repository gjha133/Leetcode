class Solution {
public:
    int specialArray(vector<int>& nums) {
        int greater = 0;
        if(nums.size() == 1 and nums[0] >= 1) return 1;
        for(int i=2; i<=nums.size(); i++)
        {
            int count = 0;
            for(int j=0; j<nums.size(); j++)
            {
                if(nums[j] >= i) count++;
            }
            
            if(count == i) return count;
            
        }
        
        return -1;
    }
};
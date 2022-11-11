class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        
        for(auto& num : nums)
        {
            while(nums[num-1] != num) swap(num, nums[num-1]);
        }
        
        for(int i = 1; i <= nums.size(); i++)
        {
            if(i != nums[i-1]) ans.push_back(i);
        }
        
        return ans;
    }
};
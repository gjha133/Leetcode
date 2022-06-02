class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> build (nums.size());
        for(int i=0; i<nums.size(); i++)
        {
            build[i] = nums[nums[i]];
        }
        
        return build;
    }
};
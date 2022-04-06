class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for(int i=0; i<nums.size(); i++)
        {
           int b = nums[i], a = target - nums[i];
            if(map.count(a)) return {map[a], i};
            map[b] = i;
        }
        
        return {};
    }
};
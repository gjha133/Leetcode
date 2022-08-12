class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(), nums.end());
        subset(nums, ans, ds, 0);
        return ans;
    }
    
    void subset(vector<int> &nums, vector<vector<int>> &ans, vector<int> &ds, int index)
    {
        ans.push_back(ds);
        for(int i=index; i<nums.size(); i++)
        {
            if(i != index and nums[i] == nums[i-1]) continue;
            ds.push_back(nums[i]);
            subset(nums, ans, ds, i + 1);
            ds.pop_back();
        }
    }
};
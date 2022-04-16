class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        subset(nums, ds, ans, 0, 0, nums.size());
        return ans;
    }
    
    void subset(vector<int> &nums, vector<int> &ds, vector<vector<int>> &ans, int index, int sum, int n)
    {
        if(index > n) return;
        if(index == n)
        {
            ans.push_back(ds);
            return;
        }
        
        ds.push_back(nums[index]);
        subset(nums, ds, ans, index + 1, sum + nums[index], n);
        ds.pop_back();
        subset(nums, ds, ans, index + 1, sum, n);
    }
};
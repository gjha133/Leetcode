class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        combinations(0, target, candidates, ans, ds);
        return ans;
    }
    
    void combinations(int i, int target, vector<int>& arr, vector<vector<int>> &ans, vector<int> &ds)
    {
        if(i == arr.size())
        {
            if(target == 0) ans.push_back(ds);
            return;
        }
        
        // Pick the element
        if(arr[i] <= target)
        {
            ds.push_back(arr[i]);
            combinations(i, target-arr[i], arr, ans, ds);
            // Remove the element after function is over
             ds.pop_back();
        }
                             
        combinations(i + 1, target, arr, ans, ds);
    }
};
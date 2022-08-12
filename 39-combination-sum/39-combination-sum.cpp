class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        combinations(0, 0, target, candidates, ans, ds);
        return ans;
    }
    
    void combinations(int index, int currSum, int target, vector<int>& arr, vector<vector<int>> &ans, vector<int> &ds)
    {
        
        if(currSum > target) return;
        if(currSum == target)
        {
            ans.push_back(ds);
            return;
        }
        
        for(int i = index; i<arr.size(); i++)
        {
            // Pick
            ds.push_back(arr[i]);
            currSum += arr[i];
            combinations(i, currSum, target, arr, ans, ds);
            // Not Pick
            ds.pop_back();
            currSum -= arr[i];            
        }
    }
};
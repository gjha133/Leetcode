class Solution {
public:
    
    void findcombination(vector<int>& candidates, int target, int sum, vector<int> &ds, int index, int k, vector<vector<int>> &ans){
        if(k < 0) return;
        if(sum > target) return;
        
        if(k == 0)
        {
            if(sum == target) ans.push_back(ds);
            return;
        }
        
        for(int i = index; i < candidates.size(); i++)
        {
            ds.push_back(candidates[i]); 
            findcombination(candidates, target, sum + candidates[i], ds, i+1, k-1, ans);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> ds;
        vector<vector<int>> ans;
        vector<int> candidates;
        for(int i=1;i<=9;i++) candidates.push_back(i);     
        
        findcombination(candidates,n,0,ds,0,k, ans);
        
        return ans;
    }
};



















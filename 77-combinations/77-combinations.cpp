class Solution {
public:    
    void combination(int idx, int k, vector<int>&current, int n, vector<vector<int>> &ans)
    {
        if(k == 0)    // base case
        {
            ans.push_back(current);
            return;
        }
        
        for(int i = idx; i <= n; i++)
        {
            current.push_back(i);                        // consider the current element i
            combination(i+1, k-1, current, n, ans);        // generate combinations
            current.pop_back();                          // proceed to next element
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int>current;
        combination(1, k, current, n, ans);
        return ans; 
    }
};
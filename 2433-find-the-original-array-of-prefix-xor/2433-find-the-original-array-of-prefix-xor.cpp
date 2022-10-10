class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int> ans = {pref[0]};
        int _xor = pref[0], n = pref.size();
        
        for(int i = 1; i < n; i++)
        {
            ans.push_back(_xor ^ pref[i]);
            _xor = pref[i];
        }
        
        return ans;
    }
};
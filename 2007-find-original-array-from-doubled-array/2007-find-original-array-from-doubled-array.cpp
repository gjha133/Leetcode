class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        if(n&1) return {};
        
        sort(changed.begin(), changed.end());
        
        vector<int> ans;
        map<int, int> mp;
        
        for(int &num : changed) mp[num]++;
        
        for(int& num : changed)
        {
            if(mp[num] == 0) continue;
            if(mp[num * 2] == 0) return {};
            
            ans.push_back(num);
            
            mp[num]--;
            mp[num*2]--;
        }
        
        return ans;
    }
};
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        
        unordered_map<string, vector<string>> map;
        
        for(auto &s : strs)
        {
            string copy = s;
            sort(copy.begin(), copy.end());
            // With sorted copy as key push the original string in the map's vector
            map[copy].push_back(s);
        }
        
        for(auto &it : map)
        {
            ans.push_back(it.second);
        }
        
        return ans;
    }
};
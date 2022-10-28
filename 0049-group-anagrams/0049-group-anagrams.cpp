class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        
        // Map of key : string and value : vector of its anagrams
        unordered_map<string, vector<string>> map;
        
        for(auto &s : strs)
        {
            string copy = s;                            // copy = eat
            sort(copy.begin(), copy.end());             // copy = aet
            // With sorted copy as key push the original string in the map's vector
            map[copy].push_back(s);                     
        }
        
        // map[aet] = <eat, tea, ate>
        // map[ant] = <tan, nat>
        // map[abt] = <bat>
        
        for(auto &element : map)
        {
            ans.push_back(element.second);
        }
        
        //ans = < <eat, tea, ate>, <tan, nat>, <bat> >;
        
        return ans;
    }
};
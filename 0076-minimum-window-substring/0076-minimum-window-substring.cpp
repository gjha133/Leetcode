class Solution {
public:
    string minWindow(string s, string t) {
        
        unordered_map<char, int> mp;
        for(char &c : t) mp[c]++;
        
        int n = s.size(), count = mp.size(), i = 0, j = 0;
        int minLen = INT_MAX, index = -1;
        
        while(j < n)
        {
            // If front letter of window is in map
            if(mp.count(s[j]))
            {
                mp[s[j]]--;
                if(mp[s[j]] == 0) count--;
            }
            
            if(count == 0)
            {
                while(count == 0)
                {
                    // If window size < minLen, change minLen and store starting index i
                    if(minLen > j - i + 1)
                    {
                        minLen = j - i + 1;
                        index = i;
                    }
                    // If back letter of window is in map
                    if(mp.count(s[i]))
                    {
                        mp[s[i]]++;
                        if(mp[s[i]] == 1) count++;
                    }
                    // Decrease window from back
                    i++;
                }
            }
            // Increase window from front
            j++;
        }
        
        return minLen == INT_MAX ? "" : s.substr(index, minLen);
    }
};
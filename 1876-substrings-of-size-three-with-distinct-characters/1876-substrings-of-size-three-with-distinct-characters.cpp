class Solution {
public:
    int countGoodSubstrings(string s) {
        int ans = 0, i = 0, j = 0, n = s.size();
        unordered_map<char, int> mp;
        while( j < n )
        {
            mp[s[j]]++;
            while(j - i + 1 > 3)
            {
                mp[s[i]]--;
                if(mp[s[i]] == 0) mp.erase(s[i]);
                i++;
            }            
            if(mp.size() == 3 and j - i + 1 == 3) ans++;
            j++;
        }
        
        return ans;
    }
};
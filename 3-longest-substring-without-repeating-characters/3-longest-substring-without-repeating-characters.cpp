class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0) return 0;
        unordered_map<char, int> mp;
        int mx = INT_MIN, i = 0, j = 0, n = s.size();
        
        while( j < n )
        {
            mp[s[j]]++;
            while(mp.size() < j - i + 1)
            {
                mp[s[i]]--;
                if(mp[s[i]] == 0) mp.erase(s[i]);
                i++;
            }
            if(mp.size() == j - i + 1)
            {
                mx = max(mx, j - i + 1);
            }
            j++;
        }
        
        return mx;
    }
};
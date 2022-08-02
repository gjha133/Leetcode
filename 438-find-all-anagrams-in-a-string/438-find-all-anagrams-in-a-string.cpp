class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        vector<int> ans;
        vector<int> hash(26, 0);
        vector<int> phash(26, 0);
        int k = p.size(), n = s.size();
        
        if(n < k) return ans;
        
        int i = 0,j = 0;
        
        while(j < k)
        {
            phash[p[j] - 'a'] += 1;
            hash[s[j] - 'a'] += 1;
            j++;
        }
        j -=1;
        
        while(j < n)
        {
            if(phash == hash) ans.push_back(i);
            j++;
            if(j != n)
            {
                hash[s[j] - 'a']++;
            }
            hash[s[i] - 'a']--;
            i++;
        }
        return ans;
    }
};
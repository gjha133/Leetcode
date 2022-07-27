class Solution {
public:
    int minSteps(string s, string t) {
        int freq[26] = {0};
        /*
        for(int i=0; i<s.size(); i++)
        {
            freq[s[i] - 'a']++;
        }
        */
        for(int i=0; i<s.size(); i++)
        {
            freq[s[i] - 'a']++;
            freq[t[i] - 'a']--;
        }
        
        int ans = 0;
        /*
        for(int i=0; i<s.size(); i++)
        {
            if(freq[t[i] - 'a'] > 0) freq[t[i] - 'a']--;
            else ans++;
        }
        */
        for(int i=0; i<26; i++)
        {
            if(freq[i] > 0) ans += freq[i];
        }
        
        return ans;
        
    }
};
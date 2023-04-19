class Solution {
public:
    
    bool compare(string& s1, string& s2) {
        if(s1.size() != s2.size() + 1) return false;
        
        int first = 0, second = 0;
        while(first < s1.size()) {
            if(second < s2.size() and s1[first] == s2[second]) {
                first++;    
                second++;
            } else first++;
        }
        
        if(first == s1.size() and second == s2.size()) return true;
        else return false;
    }
    
    bool static comp(string& s1, string& s2) {
        return s1.size() < s2.size();
    }
    
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        
        sort(words.begin(), words.end(), comp);
        vector<int> dp(n, 1);
        
        int mx = 1;
        for(int i = 0; i < n; i++) {
            for(int prev = 0; prev < i; prev++) {
                if(compare(words[i], words[prev]) and 1 + dp[prev] > dp[i])
                    dp[i] = 1 + dp[prev];
            }
            
            mx = max(mx, dp[i]);
        }
        
        return mx;
        
    }
};
class Solution {
public:
    
    int beauty(vector<int>& alpha) {
        int mn = INT_MAX, mx = -1;
        for(int freq : alpha) {
            mx = max(mx, freq);
            if(freq >= 1) mn = min(mn, freq);
        }
        return mx - mn;
    }
    
    int beautySum(string s) {
        int res = 0;
        for(int i = 0; i < s.size(); i++) {
            vector<int> alpha(26, 0);
            for(int j = i; j < s.size(); j++) {
                alpha[s[j] - 'a']++;
                res += beauty(alpha);
            }
        }
        
        return res;
    }
};
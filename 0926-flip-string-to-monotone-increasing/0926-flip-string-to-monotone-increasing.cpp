class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        int zero = 0, one = 0;
        
        int i = 0;
        while(i < n and s[i] == '0') i++;
        
        for(; i < n; i++)
        {
            s[i] == '0' ? zero++ : one++;
            zero = min(zero, one);
        }
        
        return zero;
    }
};
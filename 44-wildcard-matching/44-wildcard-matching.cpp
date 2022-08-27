class Solution {
public:
    bool isMatch(string s, string p) {
        int n = p.size(), m = s.size();
        vector<vector<int>> dp (n, vector<int> (m, -1));
        // return f(p, s, n-1, m-1);
        return fmemo(p, s, n-1, m-1, dp);
    }
    
    bool f(string &pattern, string &text, int i, int j)
    {
        if(i < 0 and j < 0) return true;
        if(i < 0 and j >= 0) return false;
        if(j < 0 and i >= 0)
        {
            for(int q = 0; q <= i; q++)
            {
                if(pattern[q] != '*') return false;
            }
            return true;
        }
        if(pattern[i] == text[j] or pattern[i] == '?') return f(pattern,text,i-1,j-1);
        if(pattern[i] == '*')
        {
            return f(pattern,text,i-1,j) or f(pattern,text,i,j-1);
        }
        return false;
    }
    
    bool fmemo(string &pattern, string &text, int i, int j, vector<vector<int>>& dp)
    {
        if(i < 0 and j < 0) return true;
        if(i < 0 and j >= 0) return false;
        if(j < 0 and i >= 0)
        {
            for(int q = 0; q <= i; q++)
            {
                if(pattern[q] != '*') return false;
            }
            return true;
        }
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(pattern[i] == text[j] or pattern[i] == '?') return dp[i][j] = fmemo(pattern,text,i-1,j-1, dp);
        if(pattern[i] == '*')
        {
            return dp[i][j] = fmemo(pattern,text,i-1,j, dp) or fmemo(pattern,text,i,j-1, dp);
        }
        return dp[i][j] = false;
    }
};
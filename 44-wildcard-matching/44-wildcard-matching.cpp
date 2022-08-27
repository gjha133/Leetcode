class Solution {
public:
    bool isMatch(string s, string p) {
        int n = p.size(), m = s.size();
        vector<vector<bool>> dp (n + 1, vector<bool> (m + 1, 0));   // bool for ftab
        // return f(p, s, n-1, m-1);
        // return fmemo(p, s, n, m, dp);
        return ftab(p, s, n, m, dp);
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
        if(i == 0 and j == 0) return true;
        if(i == 0 and j > 0) return false;
        if(j == 0 and i > 0)
        {
            for(int q = 1; q <= i; q++)
            {
                if(pattern[q-1] != '*') return false;
            }
            return true;
        }
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(pattern[i-1] == text[j-1] or pattern[i-1] == '?') return dp[i][j] = fmemo(pattern,text,i-1,j-1, dp);
        if(pattern[i-1] == '*')
        {
            return dp[i][j] = fmemo(pattern,text,i-1,j, dp) or fmemo(pattern,text,i,j-1, dp);
        }
        return dp[i][j] = false;
    }
    
    bool ftab(string &pattern, string &text, int i, int j, vector<vector<bool>>& dp)
    {
        int n = pattern.size(), m = text.size();
        
        // Base Case
        dp[0][0] = true;
        for(int j = 1; j <= m; j++) dp[0][j] = false;
        for(int i = 1; i <= n; i++)
        {
            bool flag = true;
            for(int q = 1; q <= i; q++)
            {
                if(pattern[q-1] != '*')
                {
                    flag = false;
                    break;
                }
            }
            dp[i][0] = flag;
        }
        
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(pattern[i-1] == text[j-1] or pattern[i-1] == '?') dp[i][j] = dp[i-1][j-1];
                else if(pattern[i-1] == '*')
                {
                    dp[i][j] = dp[i-1][j] or dp[i][j-1];
                }
                else dp[i][j] = false;
            }
        }
        
        return dp[n][m];
    }
};
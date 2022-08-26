class Solution {
public:
    int longestCommonSubsequence(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp (n + 1, vector<int> (m + 1, -1));
        return fmemo(n, s, m, t, dp);
    }
    
    int f(int i, string &s, int j, string& t)
    {
        if(i == 0 or j == 0) return 0;

        if(s[i-1] == t[j-1]) return 1 + f(i-1, s, j-1, t);

        return max(f(i-1, s, j, t), f(i, s, j-1, t));
    }

    int fmemo(int i, string &s, int j, string& t, vector<vector<int>>& dp)
    {
        if(i == 0 or j == 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        if(s[i-1] == t[j-1]) return dp[i][j] = 1 + fmemo(i-1, s, j-1, t, dp);

        return dp[i][j] = max(fmemo(i-1, s, j, t, dp), fmemo(i, s, j-1, t, dp));
    }
};
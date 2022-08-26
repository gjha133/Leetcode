class Solution {
public:
    int minInsertions(string s) {
        return s.size() - lcs(s);
    }
    
    int ftab(int i, string &s, int j, string& t, vector<vector<int>>& dp)
    {
        int n = s.size();
        int m = t.size();
        for(int i = 0; i<=n; i++) dp[i][0] = 0;
        for(int j = 0; j<=m; j++) dp[0][j] = 0;

        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(s[i-1] == t[j-1]) 
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }

        /*
        // Printing of lcs
        int row = n, col = m;
        int len = dp[n][m], index = len-1;

        string ans = "";

        for(int i = 0; i < len; i++) ans += '#';

        while(row > 0 and col > 0)
        {
            if(s[row-1] == t[col-1]) 
            {
                ans[index--] = s[row-1];
                row--, col--;
            }
            else if(dp[row-1][col] > dp[row][col-1]) row--;
            else col--;        
        }

        cout << ans << endl;
        */

        return dp[n][m];
    }

    int lcs(string s) 
    {
        string t = s;
        reverse(s.begin(), s.end());
        int n = s.size();
        vector<vector<int>> dp (n + 1, vector<int> (n + 1, 0));
        return ftab(n, s, n, t, dp);
    }
};
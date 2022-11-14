class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(s.begin(), s.end());
        int n = s.size();
        vector<vector<int>> dp (n + 1, vector<int> (n + 1, 0));
        return ftab(n, s, n, t, dp);
    }
    
    int ftab(int i, string &s, int j, string& t, vector<vector<int>>& dp)
    {
        int n = s.size();
        int m = t.size();
        //for(int i = 0; i<=n; i++) dp[i][0] = 0;
        //for(int j = 0; j<=m; j++) dp[0][j] = 0;

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
        int i = n, j = m;
        int len = dp[n][m], index = len-1;

        string ans("#", len);

        while(i > 0 and j > 0)
        {
            if(s[i-1] == t[j-1]) 
            {
                ans[index--] = s[i-1];
                i--, j--;
            }
            else if(dp[i-1][j] > dp[i][j-1]) i--;
            else j--;        
        }

        cout << ans << endl;
        */

        return dp[n][m];
    }
};
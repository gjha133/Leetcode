class Solution {
public:
    int minDistance(string word1, string word2) {
        return word1.size() + word2.size() - 2 * lcs(word1, word2);
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

    int lcs(string s, string t)
    {
        //Write your code here
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp (n + 1, vector<int> (m + 1, 0));
        return ftab(n, s, m, t, dp);
    }
};
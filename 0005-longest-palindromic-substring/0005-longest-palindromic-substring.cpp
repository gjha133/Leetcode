class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        
        int dp[n][n];
        memset(dp, 0, sizeof(dp));
        
        int mx = 0;
        string ans = "";
        for(int k = 0; k < n; k++)
        {
            for(int i = 0, j = i + k; j < n; i++, j++)
            {
                // Single char are always palindrome
                if(i == j) dp[i][j] = 1;
                // i = 0, j = 1, first two chars
                else if(k == 1) dp[i][j] = (s[i] == s[j]) ? 2 : 0;
                else
                {
                    if(s[i] == s[j] and dp[i+1][j-1])
                        dp[i][j] = 2 + dp[i+1][j-1];
                }
                
                if(dp[i][j])
                {
                    if(j-i+1 > mx)
                    {
                        mx = j-i+1;
                        ans = s.substr(i, mx);
                    }
                }
            }
        }
        
        return ans;
    }
};
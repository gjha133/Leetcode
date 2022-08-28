class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<int>> dp (n, vector<int> (m, -1));
        //return f(n-1, m-1, s, p);
        return fmemo(n-1, m-1, s, p, dp);

    }
    
    int f(int i, int j, string& s, string& p)
    {
        // Base Case
        if(i < 0 and j < 0) return true;   // If s and p are both travelled completely
        if(j < 0 and i >= 0) return false; // If only p is travelled completely
        if(i < 0 and j >= 0)               // If only s is travelled completely
        {
            // Consider case : s = "a", p = "x*x*a". After 1st rec call, s gets exhausted then 
            //  "x*x*"" can be considered empty only if there is a * there.
            while(j >= 0)
            {
                if(p[j] == '*') j -= 2;
                else return false;
            }
            return true;
        }
        
        // Recursion Calls
        
        // If matching
        if(s[i] == p[j] or p[j] == '.') return f(i-1, j-1, s, p);
        
        // If '*'
        if(p[j] == '*')
        {
            if(s[i] != p[j-1] and p[j-1] != '.') 
                // If any char say 'x' before * is not equal to char at 'i'. We will consider "x*" to be empty
                return f(i, j-2, s, p); 
            else
                // Decrease s pointer 'i' because of preceding element and
                // If char* is considered to be empty
                return f(i-1, j, s, p) or f(i, j-2, s, p);
        }
        
        return false;       
    }
    
    int fmemo(int i, int j, string& s, string& p, vector<vector<int>> &dp)
    {
        // Base Case
        if(i < 0 and j < 0) return true;   // If s and p are both travelled completely
        if(j < 0 and i >= 0) return false; // If only p is travelled completely
        if(i < 0 and j >= 0)               // If only s is travelled completely
        {
            // Consider case : s = "a", p = "x*x*a". After 1st rec call, s gets exhausted then 
            //  "x*x*"" can be considered empty only if there is a * there.
            while(j >= 0)
            {
                if(p[j] == '*') j -= 2;
                else return false;
            }
            return true;
        }
        
        if(dp[i][j] != -1) return dp[i][j];
        
        // Recursion Calls
        
        // If matching
        if(s[i] == p[j] or p[j] == '.') return dp[i][j] = fmemo(i-1, j-1, s, p, dp);
        
        // If '*'
        if(p[j] == '*')
        {
            if(s[i] != p[j-1] and p[j-1] != '.') 
                // If any char say 'x' before * is not equal to char at 'i'. We will consider "x*" to be empty
                return dp[i][j] = fmemo(i, j-2, s, p, dp); 
            else
                // Decrease s pointer 'i' because of preceding element and
                // If char* is considered to be empty
                return dp[i][j] = fmemo(i-1, j, s, p, dp) or fmemo(i, j-2, s, p, dp);
        }
        
        return dp[i][j] = false;
    }
};
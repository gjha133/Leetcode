class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        
        string ans = "";
        int n = s.size(), increment = 2*(numRows-1);
        
        for(int r = 0; r < numRows; r++)
        {
            for(int i = r; i < n; i += increment)
            {
                ans += s[i];
                int new_inc = increment - 2*r;
                if(r != 0 and r != numRows - 1 and  i + new_inc < n) ans += s[i + new_inc];
            }
        }
        
        return ans;
    }
};
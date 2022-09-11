class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        f("", n, n, ans);
        return ans;
    }
    
    void f(string s, int open, int close, vector<string>& ans)
    {
        if(!open and !close)
        {
            ans.push_back(s);
            return;
        }
        
        if(open > 0) 
            f(s + "(", open-1, close, ans);
        if(open < close) 
            f(s + ")", open, close-1, ans);
    }
};
class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int open = 0, close = 0, start = 0;
        for(int i = 0; i < s.size(); i++) {
            if(!open and !close) start = i;
            
            if(s[i] == '(') open++;
            else if(s[i] == ')') close++;
            
            if(open == close) {
                string temp = s.substr(start + 1, i - start - 1);
                ans += temp;
                open = 0, close = 0;
            }
        }
        
        return ans;
        
    }
};
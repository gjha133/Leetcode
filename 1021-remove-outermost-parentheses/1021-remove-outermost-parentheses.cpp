class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int parenthesis = 0, start = 0;
        for(int i = 0; i < s.size(); i++) {
            if(!parenthesis) start = i;
            
            if(s[i] == '(') parenthesis++;
            else if(s[i] == ')') parenthesis--;
            
            if(!parenthesis) {
                string temp = s.substr(start + 1, i - start - 1);
                ans += temp;
            }
        }
        
        return ans;        
    }
};
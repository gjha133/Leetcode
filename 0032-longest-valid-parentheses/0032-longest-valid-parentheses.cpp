class Solution {
public:
    int longestValidParentheses(string s) {
        int mx = 0;
        stack<int> stk;
        stk.push(-1);
        
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(') stk.push(i);
            else {
                stk.pop();
                if(stk.empty()) stk.push(i);
                else mx = max(mx, i - stk.top());
            }
        }
        
        return mx;
    }
};
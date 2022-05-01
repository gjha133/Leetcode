class Solution {
public:
    bool backspaceCompare(string s, string t) {
        
        stack<char> st, rt;
        
        for(auto c : s)
        {
            if(c != '#') st.push(c);
            else if(!st.empty()) st.pop();
        }
        
        for(auto c : t)
        {
            if(c != '#') rt.push(c);
            else if(!rt.empty()) rt.pop();
        }
        
        if(st.size() != rt.size()) return false;
        while(!st.empty()) 
        {
            if(st.top() != rt.top()) return false;
                st.pop();   rt.pop();
        }
        
        return 1;
        
    }
};
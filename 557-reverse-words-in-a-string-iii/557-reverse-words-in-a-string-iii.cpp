class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        int i = 0;
        stack<char> st;
        while(s[i] != '\0')
        {
            if(s[i] != ' ')
            {
                st.push(s[i++]);
            }
            else
            {
                while(!st.empty())
                {
                    ans += st.top();
                    st.pop();
                }
                
                ans += ' ';
                i++;
            }
        }
        
        while(!st.empty())
        {
            ans += st.top();
            st.pop();
        }
        
        return ans;
    }
};
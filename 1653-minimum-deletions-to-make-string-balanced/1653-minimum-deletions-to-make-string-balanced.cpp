class Solution {
public:
    //Idea is to traverse from right to left & use stack to keep track if 'b' comes before 'a' in string
    //then we need to pop & need to delete that character
    int minimumDeletions(string s) {
        stack<char> st;
        int n = s.size();
        int ans = 0;
        
        for(int i = n-1; i >=0; i--)
        {
            if(!st.empty() and s[i] > st.top())
            {
                ans++;
                st.pop();
            }
            else st.push(s[i]);
        }
        
        return ans;
    }
};
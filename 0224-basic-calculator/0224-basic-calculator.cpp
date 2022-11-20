class Solution {
public:
    int calculate(string s) {
        stack<pair<int, int>> st;
        
        int sum = 0, sign = +1, n = s.size();
        
        for(int i = 0; i < n; i++)
        {
            char c = s[i];
            
            if(isdigit(c))
            {
                int num = 0;
                while(i < n and isdigit(s[i]))
                {
                    num = num*10 + (s[i]-'0');
                    i++;
                }
                i--;
                sum += num * sign;
                sign = +1;
            }
            else if(c == '(')
            {
                st.push({sum, sign});
                sum = 0;
                sign = +1;
            }
            else if(c == ')')
            {
                sum = st.top().first + sum * st.top().second;
                st.pop();
            }
            else if(c == '-')
            {
                sign = -1*sign;
            }
        }
        
        return sum;
    }
};
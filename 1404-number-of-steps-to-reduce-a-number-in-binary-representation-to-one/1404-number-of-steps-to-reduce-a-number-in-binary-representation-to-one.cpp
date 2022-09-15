class Solution {
public:
    int numSteps(string s) {
        int ans = 0, carry = 0, n = s.size();
        for(int i = n-1; i > 0; i--)
        {
            if(s[i] - '0' + carry == 1)
            {
                // 0 + 1 = 1 odd, need  two steps (add 1 and divided by 2), (carry = 1)
                // 1 + 0 = 1 odd, need  two steps (add 1 and divided by 2), (carry = 0)
                carry = 1;
                ans += 2;
            }
            else
            {
                // 0 + 0 = 0 even, need one step(divided by 2), (carry = 0)
                // 1 + 1 = 0 even, need one step(divided by 2), (carry = 1 ,  carry keeps 1 in next round.)
                ans++;
            }
        }
        
        return ans + carry;
    }
};
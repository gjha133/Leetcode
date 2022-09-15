class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        int i = a.size()-1, j = b.size()-1, carry = 0;
        
        while(i >= 0 or j >= 0)
        {
            int sum = carry;
            if(i >= 0) sum += a[i--] - '0';
            if(j >= 0) sum += b[j--] - '0';
            carry = sum > 1 ? 1 : 0;
            
            ans += to_string(sum % 2);
        }
        
        if(carry == 1) ans += to_string(1);
        reverse(begin(ans), end(ans));
        
        return ans;
    }
};
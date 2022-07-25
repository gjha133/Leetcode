class Solution {
public:
    string toHex(int num) {
        if(!num) return "0";
        
        unsigned int n = num;
        string ans = "";
        
        // Solution can be used for any base
        int base = 16;
        int rem;
        
        while(n)
        {
            rem = n % base;
            
            rem < 10 ? ans += ('0' + rem) : ans += ( ('a' - 10) + rem );
            
            n /= base;
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};
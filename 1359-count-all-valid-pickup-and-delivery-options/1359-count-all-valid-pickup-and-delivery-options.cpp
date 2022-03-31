class Solution {
public:
    int countOrders(int n) {
        long ans = 1;   
        long mod = 1000000007;
        
        for(int i=1; i<=n; i++)
        {
            ans *= i;
            ans = ans % mod;
            ans *= (2*i-1);
            ans = ans % mod;
        }
        
        return ans % mod;
    }
};
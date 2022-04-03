class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        long long N = n;
        if(N < 0) N = -1 * N;
        
        while(N)
        {
            if(N % 2 == 0)
            {
                x *= x;
                N = N/2;
            }
            else
            {
                ans *= x;
                N = N - 1;
            }
        }
        
        if(n < 0) ans = double(1.0)/double(ans);
        return ans;
    }
};
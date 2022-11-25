class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == divisor)
            return 1;
        bool positive = false;    // if both are of same sign, answer is positive
        if( (dividend < 0 and divisor < 0) or (dividend > 0 and divisor > 0) ) positive = true;
        unsigned int a = abs(dividend);
        unsigned int b = abs(divisor);
        unsigned int ans = 0;
        while(a >= b)                                   // while dividend is greater than or equal to divisor
        {  
            short q = 0;
            while(a > (b<<(q+1)))
                q++;
            
            ans += (1<<q);  // add the power of 2 found to the answer
            a = a - (b<<q);  // reduce the dividend by divisor * power of 2 found
        }
        if(ans == (1<<31) and positive)   // if ans cannot be stored in signed int
            return INT_MAX;
        return positive ? ans : -ans;
    }
};
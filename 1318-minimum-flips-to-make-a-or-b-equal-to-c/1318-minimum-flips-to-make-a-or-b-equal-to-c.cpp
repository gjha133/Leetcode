class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans = 0;
        while(c or a or b)
        {
            if(c&1)     // If c's LSB is 1
            {           
                if( (a&1) == 0 and (b&1) == 0) ans++;    // If a's and b's LSB is 0, we need to change any one of them. So ans + 1.
            }
            else        // If c's LSB is 0
            {           
                if(a&1 and b&1) ans+=2;             // If a's and b's LSB is 1, then we need to change both of them to 0. ans +2.
                else if(a&1 or b&1) ans++;          // 0 or 1.....1 or 0.....1 or 1 case taken care of. ans++.
            }
            
            a>>=1;
            b>>=1;
            c>>=1;
        }
        
        return ans;
    }
};
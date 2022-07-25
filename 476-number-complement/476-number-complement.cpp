class Solution {
public:
    int findComplement(int n) {
        int ans = 0;
        for(int i=0; n; i++)
        {
            if(!(n&1)) ans += 1<<i;
            n >>= 1;
        }
        
        return ans;
    }
};
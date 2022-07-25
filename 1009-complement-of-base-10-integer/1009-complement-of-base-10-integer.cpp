class Solution {
public:
    int bitwiseComplement(int n) {
        if(!n) return 1;
        int ans = 0;
        for(int i=0; n; i++)
        {
            if(!(n&1)) ans += 1<<i;
            n >>= 1;
        }
        
        return ans;
    }
};
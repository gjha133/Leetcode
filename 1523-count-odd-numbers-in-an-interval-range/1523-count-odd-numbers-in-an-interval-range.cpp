class Solution {
public:
    int countOdds(int low, int high) {
        
        if(!(low&1) and !(high&1)) return (high-low)>>1;
        else return ((high-low)>>1) + 1;
    }
    
    
    // low&1 == 1 ---->>low is odd
    // low&1 == 0 ---->>low is even
};
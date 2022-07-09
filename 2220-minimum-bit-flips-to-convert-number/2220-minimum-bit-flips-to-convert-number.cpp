class Solution {
public:
    int minBitFlips(int start, int goal) {
        int XOR = start ^ goal;
        return numSetBits(XOR);
    }
    
    int numSetBits(int n)
    {
        int count = 0;
        while(n)
        {
            n = n&(n-1);
            count++;
        }
        return count;
    }
};
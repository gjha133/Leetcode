class Solution {
public:
    int arrangeCoins(int n) {
        
        int start = 1, end = n;
        while(start + 1 < end)
        {
            long mid = start + (end-start)/2;
            long x = mid*(mid + 1)/2;
            if(x == n) return mid;
            if(x > n) end = mid;
            else start = mid;
        }
        
        return start;
    }
};
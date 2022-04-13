class Solution {
public:
    int mySqrt(int x) {
        if(x<=1) return x;
        int start = 1;
        int end = x/2;
        long square;
        int ans = -1;
        while(start <= end)
        {
            int mid = start + (end-start)/2;
            square = long(mid)*long(mid);            
            if(square == x) return mid;
            if(square < x) {start = mid + 1; ans = mid;}
            else end = mid - 1;
        }
        
        return ans;
    }
};
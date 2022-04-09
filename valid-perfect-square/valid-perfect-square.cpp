class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num == 1) return 1;
        long start = 1, end = num/2, mid;
        while(start <= end)
        {
            mid = start + (end-start)/2;
            if(mid*mid == num) return 1;
            else if(mid*mid < num) start = mid + 1;
            else end = mid - 1;
        }
        
        return 0;
    }
};
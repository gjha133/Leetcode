class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mn = INT_MAX, mx = INT_MIN;
        for(int& num : nums)
        {
            mn = min(mn, num);
            mx = max(mx, num);
        }
        
        return gcd(mn, mx);
    }
    
    int gcd(int a, int b)
    {
        if(b == 0) return a;
        return gcd(b, a % b);
    }
};
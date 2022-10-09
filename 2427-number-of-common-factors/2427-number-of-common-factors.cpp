class Solution {
public:
    int commonFactors(int a, int b) {
        int ans = 1;
        for(int i = 2; i <= gcd(a, b); i++)
            if(a % i == 0 and b % i == 0) ans++;
        return ans;        
    }
/*
private:
    int gcd(int a, int b)
    {
        int result = min(a, b);
        while(result > 0)
        {
            if(a % result == 0 and b % result == 0) break;
            result--;
        }
        return result;
    }
*/   
    
};